#ifndef APP_H
#define APP_H

#include <xcb/xcb.h>
#include <xcb/randr.h>

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
    xcb_randr_output_t * randr_outputs;
    size_t num_randr_outputs;
};

struct backlight_range {
    int32_t min;
    int32_t max;
};

void app_init(struct app *);
void app_run(struct app *);
void app_dispose(struct app *);
void app_init_error(struct app *, const char *);
void app_systray_send_event(struct app *, uint32_t,
        uint32_t, uint32_t, uint32_t);
void app_xcb_intern_atom(struct app *, xcb_atom_t *, const char *);
int32_t app_get_backlight_for_output(struct app *, xcb_randr_output_t);
void app_set_backlight(struct app *, int32_t);
void app_set_backlight_for_output(struct app *, xcb_randr_output_t,
        int32_t value);
struct backlight_range app_get_backlight_range_for_output(struct app * app,
        xcb_randr_output_t);
void app_modify_backlight_normalized(struct app *, double);

#endif
