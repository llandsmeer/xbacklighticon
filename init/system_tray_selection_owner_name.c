#include <stdio.h>

#include "../systray_constants.h"
#include "app_init.h"

void app_init_system_tray_selection_owner_name(struct app * app) {
    char atom_name[24];
    snprintf(atom_name, sizeof atom_name, NET_SYSTEM_TRAY_S "%d",
            app->default_screen);
    app_xcb_intern_atom(app, &app->atoms.net_system_tray_sdefault, atom_name);
}
