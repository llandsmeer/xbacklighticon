#include "app_init.h"

void app_init_xcb_connection(struct app * app) {
    app->xcb_connection = xcb_connect(0, 0);
}
