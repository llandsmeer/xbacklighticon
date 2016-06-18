#include <stdlib.h>
#include <string.h>

#include "app_init.h"
#include "../systray_constants.h"

void app_init_systray_send_message(struct app * app) {
    xcb_intern_atom_cookie_t cookie;
    xcb_intern_atom_reply_t * reply;
    cookie = xcb_intern_atom(app->xcb_connection, 0,
            strlen(NET_SYSTEM_TRAY_OPCODE), NET_SYSTEM_TRAY_OPCODE);
    reply = xcb_intern_atom_reply(app->xcb_connection, cookie, 0);
    if (reply) {
        app->atoms.net_system_tray_opcode = reply->atom;
        free(reply);
    } else {
        app_init_error(app, "could not intern atom " NET_SYSTEM_TRAY_OPCODE);
    }
}
