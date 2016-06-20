#include "../app.h"

void app_init_xcb_connection(struct app *);
void app_init_systray_send_message(struct app *);
void app_init_tray_icon_window(struct app * app);
void app_init_screen(struct app*);
void app_init_tray_icon_window(struct app*);
void app_init_tray_icon_window_dock(struct app*);
void app_init_tray_icon_window_xembed(struct app*);
void app_init_system_tray_selection_owner_window(struct app*);
void app_init_system_tray_selection_owner_name(struct app*);
void app_init_backlight_new(struct app*);
void app_init_backlight_legacy(struct app*);
void app_init_randr_output(struct app*);
void app_init_graphics_context(struct app*);
