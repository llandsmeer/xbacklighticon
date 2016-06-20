#include "app_init.h"

void app_init_backlight_new(struct app * app) {
    app_xcb_intern_atom(app, &app->atoms.backlight_new, "Backlight");
    if (app->has_error) return;
    app->supports_new_backlight = app->atoms.backlight_new == XCB_NONE;
}
