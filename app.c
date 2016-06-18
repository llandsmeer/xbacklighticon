#include "app.h"
#include "setup/appsetup.h"

void app_init(struct app * app) {
    if (!app) return;
#include "setup/appsetup.def"
}

void app_run(struct app * app) {
}

void app_dispose(struct app * app) {
}
