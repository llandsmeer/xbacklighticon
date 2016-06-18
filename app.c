#include "app.h"
#include "init/app_init.h"

void app_init(struct app * app) {
    if (!app) return;
#include "init/app_init.def"
}

void app_run(struct app * app) {
}

void app_dispose(struct app * app) {
}
