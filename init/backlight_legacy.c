#include "app_init.h"

void app_init_backlight_legacy(struct app * app) {
    if (app->supports_new_backlight) return;
    app_xcb_intern_atom(app, &app->atoms.backlight_legacy, "BACKLIGHT");
    if (app->has_error) return;
    if (app->atoms.backlight_legacy == XCB_NONE) {
        app_init_error(app, "no backlight support");
    }
}
