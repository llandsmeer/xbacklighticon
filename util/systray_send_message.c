#include <string.h>
#include <stdint.h>
#include "../app.h"

void app_systray_send_event(struct app * app,
        uint32_t opcode, uint32_t a, uint32_t b, uint32_t c) {
    xcb_client_message_event_t event;
    memset(&event, 0, sizeof event);
    event.response_type = XCB_CLIENT_MESSAGE;
    event.window = app->tray_icon_window;
    event.type = app->atoms.net_system_tray_opcode;
    event.format = 32;
    event.data.data32[0] = XCB_CURRENT_TIME;
    event.data.data32[1] = opcode;
    event.data.data32[2] = a;
    event.data.data32[3] = b;
    event.data.data32[4] = c;
    xcb_send_event(app->xcb_connection, 0,
            app->system_tray_selection_owner_window,
            XCB_EVENT_MASK_STRUCTURE_NOTIFY, (const char*)&event);
    xcb_flush(app->xcb_connection);
}
