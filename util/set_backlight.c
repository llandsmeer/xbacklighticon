#include "../app.h"

void app_set_backlight_for_output(struct app * app, xcb_randr_output_t output,
        int32_t value) {
    xcb_randr_change_output_property(app->xcb_connection, output,
            app->supports_new_backlight ? app->atoms.backlight_new
                                        : app->atoms.backlight_legacy,
            XCB_ATOM_INTEGER, 32, XCB_PROP_MODE_REPLACE, 1, (char *)&value);
}

void app_set_backlight(struct app * app, int32_t value) {
    size_t i;
    for (i = 0; i < app->num_randr_outputs; i++) {
        app_set_backlight_for_output(app, app->randr_outputs[i], value);
    }
}
