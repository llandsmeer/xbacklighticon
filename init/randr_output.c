#include <stdlib.h>
#include "app_init.h"

void app_init_randr_output(struct app * app) {
    xcb_generic_error_t * error = 0;
    xcb_randr_get_screen_resources_current_cookie_t cookie;
    xcb_randr_get_screen_resources_current_reply_t * reply;
    cookie = xcb_randr_get_screen_resources_current(app->xcb_connection,
            app->screen->root);
    reply = xcb_randr_get_screen_resources_current_reply(app->xcb_connection,
            cookie, &error);
    if (error) {
        app_init_error(app, "xcb_rand_get_screen_resources_current");
        return;
    }
    app->randr_outputs = xcb_randr_get_screen_resources_current_outputs(reply);
    app->num_randr_outputs = reply->num_outputs;
    free(reply);
}
