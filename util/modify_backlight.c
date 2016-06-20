#include "../app.h"

void app_modify_backlight_normalized(struct app * app, double delta) {
    size_t i;
    int32_t value;
    double percentage;
    struct backlight_range range;
    for (i = 0; i < app->num_randr_outputs; i++) {
        app->has_error = 0;
        value = app_get_backlight_for_output(app, app->randr_outputs[i]);
        if (app->has_error || value == -1) {
            continue;
        }
        range = app_get_backlight_range_for_output(app, app->randr_outputs[i]);
        if (app->has_error) {
            continue;
        }
        percentage = 100 * (double)(value - range.min) /
                               (double)(range.max - range.min);
        percentage += delta;
        value = (range.min + percentage * (range.max - range.min) + 0.5) / 100;
        if (value < range.min + 1) {
            value = range.min + 1;
        } else if (value > range.max) {
            value = range.max;
        }
        app_set_backlight_for_output(app, app->randr_outputs[i], value);
    }
    app->has_error = 0;
}
