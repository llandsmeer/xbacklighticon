#include <string.h>

#include "app.h"
#include "init/app_init.h"

typedef void (*app_initializer)(struct app * app);

static app_initializer app_initializers[] = {
#include "init/app_init.def"
};

void app_init(struct app * app) {
    size_t i;
    if (!app) {
        return;
    }
    app->has_error = 0;
    for (i = 0; i < sizeof app_initializers / sizeof *app_initializers; i++) {
        (*app_initializers[i])(app);
        if (app->has_error) {
            return;
        }
    }
}

void app_run(struct app * app) {
}

void app_dispose(struct app * app) {
}

void app_init_error(struct app * app, const char * message) {
    app->has_error = 1;
    strncpy(app->error_message, message, sizeof app->error_message);
    app->error_message[sizeof app->error_message - 1] = 0;
}
