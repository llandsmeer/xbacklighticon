#include <stdlib.h>
#include "../app.h"

static int32_t app_get_backlight_for_output_using_atom(struct app * app,
        xcb_randr_output_t output, xcb_atom_t atom) {
    int32_t result;
    xcb_generic_error_t * error = 0;
    xcb_randr_get_output_property_reply_t * reply;
    xcb_randr_get_output_property_cookie_t cookie;
    cookie = xcb_randr_get_output_property(app->xcb_connection, output,
            atom, XCB_ATOM_NONE, 0, 4, 0, 0);
    reply = xcb_randr_get_output_property_reply(app->xcb_connection,
            cookie, &error);
    if (!error && reply && reply->type == XCB_ATOM_INTEGER &&
            reply->num_items == 1 && reply->format == 32) {
        result = *((int32_t *)xcb_randr_get_output_property_data(reply));
        free(reply);
        return result;
    } else {
        return -1;
    }
}

int32_t app_get_backlight_for_output(struct app * app,
        xcb_randr_output_t output) {
    int32_t backlight = -1;
    if (app->supports_new_backlight) {
        backlight = app_get_backlight_for_output_using_atom(app, output,
                    app->atoms.backlight_new);
    }
    if (backlight == -1) {
        backlight = app_get_backlight_for_output_using_atom(app, output,
                    app->atoms.backlight_legacy);
    }
    if (backlight == -1) {
        app_init_error(app, "could not get backlight");
        return -1;
    }
    return backlight;
}
