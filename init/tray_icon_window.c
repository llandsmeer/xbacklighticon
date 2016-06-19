#include "app_init.h"

void app_init_tray_icon_window(struct app * app) {
    app->tray_icon_window = xcb_generate_id(app->xcb_connection);
    xcb_create_window(app->xcb_connection, XCB_COPY_FROM_PARENT,
            app->tray_icon_window, app->screen->root,
            0, 0, 16, 16, 0,
            XCB_WINDOW_CLASS_INPUT_OUTPUT,
            app->screen->root_visual,
            0,
            0);
    xcb_map_window(app->xcb_connection, app->tray_icon_window);
    xcb_flush(app->xcb_connection);
}
