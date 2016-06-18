#ifndef APP_H
#define APP_H

#include <xcb/xcb.h>

struct app {
    xcb_connection_t * xcb_connection;
    int has_error;
    char error_message[32];
};

void app_init(struct app *);
void app_run(struct app *);
void app_dispose(struct app *);
void app_init_error(struct app *, const char *);

#endif
