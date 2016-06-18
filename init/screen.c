#include "app_init.h"

void app_init_screen(struct app * app) {
    const xcb_setup_t * setup = xcb_get_setup(app->xcb_connection);
    xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);
    app->screen = iter.data;
}
