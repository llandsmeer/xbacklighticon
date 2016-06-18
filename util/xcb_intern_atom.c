#include <stdlib.h>
#include <string.h>

#include "../app.h"
#include "../systray_constants.h"

void app_xcb_intern_atom(struct app * app, xcb_atom_t * dst,
        const char * name) {
    xcb_intern_atom_cookie_t cookie;
    xcb_intern_atom_reply_t * reply;
    cookie = xcb_intern_atom(app->xcb_connection, 0, strlen(name), name);
    reply = xcb_intern_atom_reply(app->xcb_connection, cookie, 0);
    if (reply) {
        *dst = reply->atom;
        free(reply);
    } else {
        app_init_error(app, "could not intern atom");
    }
}
