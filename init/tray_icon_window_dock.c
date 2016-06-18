#include "app_init.h"
#include "../systray_constants.h"

void app_init_tray_icon_window_dock(struct app * app) {
    app_systray_send_event(app, SYSTEM_TRAY_REQUEST_DOCK,
            app->tray_icon_window, 0, 0);
}
