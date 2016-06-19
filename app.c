#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "init/app_init.h"

typedef void (*app_initializer)(struct app * app);

static app_initializer app_initializers[] = {
#include "init/app_init.def"
};

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
                printf("expose\n");
                break;
            case XCB_BUTTON_PRESS:
                printf("button press\n");
            case XCB_REPARENT_NOTIFY:
                printf("reparent\n");
                break;
            case XCB_DESTROY_NOTIFY:
                printf("destroy\n");
                return;
                break;
            case XCB_CONFIGURE_NOTIFY:
                printf("configure\n");
                break;
            case XCB_MAP_NOTIFY:
                printf("notify\n");
                break;
            case XCB_UNMAP_NOTIFY:
                printf("unmap\n");
                break;
            case XCB_MAPPING_NOTIFY:
                printf("mapping\n");
                break;
            case XCB_CLIENT_MESSAGE:
                printf("client message\n");
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
