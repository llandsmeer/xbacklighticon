#include "../xembed_constants.h"
#include "app_init.h"

void app_init_tray_icon_window_xembed(struct app * app) {
    app_xcb_intern_atom(app, &app->atoms.xembed, "_XEMBED_INFO");
    uint32_t xembed_info[] = {XEMBED_VERSION, XEMBED_MAPPED};
    xcb_change_property(app->xcb_connection, XCB_PROP_MODE_REPLACE,
            app->tray_icon_window, app->atoms.xembed, app->atoms.xembed,
            32, 2, xembed_info);
}
