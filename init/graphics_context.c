#include "app_init.h"

void app_init_graphics_context(struct app * app) {
    int32_t mask = XCB_GC_FOREGROUND;
    int32_t values[] = {0xffff00};
    app->xcb_gc = xcb_generate_id(app->xcb_connection);
    xcb_create_gc(app->xcb_connection, app->xcb_gc, app->tray_icon_window,
            mask, values);
}
