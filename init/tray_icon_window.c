#include "app_init.h"

void app_init_tray_icon_window(struct app * app) {
    uint32_t values[] = {
        0xffffffff,
        XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_STRUCTURE_NOTIFY};
    app->tray_icon_window = xcb_generate_id(app->xcb_connection);
    xcb_create_window(app->xcb_connection, XCB_COPY_FROM_PARENT,
            app->tray_icon_window, app->screen->root,
            0, 0, 16, 16, 0,
            XCB_WINDOW_CLASS_INPUT_OUTPUT,
            app->screen->root_visual,
            XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK,
            values);
    xcb_flush(app->xcb_connection);
}
