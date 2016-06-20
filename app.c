#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "init/app_init.h"

#define ICON_MARGIN 0.1

typedef void (*app_initializer)(struct app * app);

static app_initializer app_initializers[] = {
#include "init/app_init.def"
};

void app_handle_button_press(struct app * app,
        xcb_button_press_event_t * event) {
    if (event->detail == 4) {
        app_modify_backlight_normalized(app, +3.0);
    } else if (event->detail == 5) {
        app_modify_backlight_normalized(app, -3.0);
    }
}

void app_handle_expose(struct app * app, xcb_expose_event_t * event) {
    if (event->window != app->tray_icon_window) {
        return;
    }
    xcb_arc_t circle;
    circle.x = ICON_MARGIN * event->width + 0.5;
    circle.y = ICON_MARGIN * event->height + 0.5;
    circle.width = (1-2*ICON_MARGIN) * event->width + 0.5;
    circle.height = (1-2*ICON_MARGIN) * event->height + 0.5;
    circle.angle1 = 0 << 6;
    circle.angle2 = 360 << 6;
    xcb_poly_fill_arc(app->xcb_connection, app->tray_icon_window,
            app->xcb_gc, 1, &circle);
    xcb_flush(app->xcb_connection);
}

void app_init(struct app * app) {
    size_t i;
    if (!app) {
        return;
    }
    app->has_error = 0;
    for (i = 0; i < sizeof app_initializers / sizeof *app_initializers; i++) {
        (*app_initializers[i])(app);
        if (app->has_error) {
            return;
        }
    }
}

void app_run(struct app * app) {
    xcb_generic_event_t * event;
    while ((event = xcb_wait_for_event(app->xcb_connection))) {
        switch (event->response_type & ~0x80) {
            case XCB_EXPOSE:
                app_handle_expose(app, (xcb_expose_event_t *)event);
                break;
            case XCB_BUTTON_PRESS:
                app_handle_button_press(app, (xcb_button_press_event_t*)event);
                break;
            case XCB_DESTROY_NOTIFY:
                if (((xcb_destroy_notify_event_t*)event)->window ==
                        app->tray_icon_window) {
                    return;
                }
                break;
            case XCB_REPARENT_NOTIFY:
                break;
            case XCB_CONFIGURE_NOTIFY:
                break;
            case XCB_MAP_NOTIFY:
                break;
            case XCB_UNMAP_NOTIFY:
                break;
            case XCB_MAPPING_NOTIFY:
                break;
            case XCB_CLIENT_MESSAGE:
                break;
            default:
                printf("unknown event %d\n", event->response_type);
        }
        free(event);
        if (app->has_error) {
            return;
        }
    }
}

void app_dispose(struct app * app) {
    xcb_disconnect(app->xcb_connection);
}

void app_init_error(struct app * app, const char * message) {
    app->has_error = 1;
    strncpy(app->error_message, message, sizeof app->error_message);
    app->error_message[sizeof app->error_message - 1] = 0;
}
