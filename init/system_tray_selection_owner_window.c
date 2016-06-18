#include <stdlib.h>

#include "app_init.h"

void app_init_system_tray_selection_owner_window(struct app * app) {
    xcb_generic_error_t * error;
    xcb_get_selection_owner_cookie_t cookie;
    xcb_get_selection_owner_reply_t * reply;
    cookie = xcb_get_selection_owner(app->xcb_connection,
            app->atoms.net_system_tray_sdefault);
    reply = xcb_get_selection_owner_reply(app->xcb_connection, cookie, &error);
    if (error || !reply) {
        app_init_error(app, "could not get system tray selection owner");
        return;
    }
    app->system_tray_selection_owner_window = reply->owner;
    free(reply);
}
