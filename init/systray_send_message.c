#include <stdlib.h>
#include <string.h>

#include "app_init.h"
#include "../systray_constants.h"

void app_init_systray_send_message(struct app * app) {
    app_xcb_intern_atom(app, &app->atoms.net_system_tray_opcode,
            NET_SYSTEM_TRAY_OPCODE);
}
