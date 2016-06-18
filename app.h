#ifndef APP_H
#define APP_H

#include <xcb/xcb.h>

struct app {
    xcb_connection_t * xcb_connection;
    int has_error;
    char error_message[32];
    struct {
        xcb_atom_t net_system_tray_opcode;
    } atoms;
    xcb_window_t tray_icon_window;
    xcb_screen_t * screen;
};

void app_init(struct app *);
void app_run(struct app *);
void app_dispose(struct app *);
void app_init_error(struct app *, const char *);
void app_systray_send_event(struct app *, uint32_t,
        uint32_t, uint32_t, uint32_t);

#endif
