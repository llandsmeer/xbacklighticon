#ifndef APP_H
#define APP_H

#include <xcb/xcb.h>

struct app {
    xcb_connection_t * xcb_connection;
    int has_error;
    char error_message[32];
    struct {
        xcb_atom_t net_system_tray_sdefault;
        xcb_atom_t net_system_tray_opcode;
        xcb_atom_t xembed;
        xcb_atom_t backlight_new;
        xcb_atom_t backlight_legacy;
    } atoms;
    xcb_window_t tray_icon_window;
    xcb_window_t system_tray_selection_owner_window;
    xcb_screen_t * screen;
    int default_screen;
    int supports_new_backlight;
};

void app_init(struct app *);
void app_run(struct app *);
void app_dispose(struct app *);
void app_init_error(struct app *, const char *);
void app_systray_send_event(struct app *, uint32_t,
        uint32_t, uint32_t, uint32_t);
void app_xcb_intern_atom(struct app *, xcb_atom_t *, const char *);

#endif
