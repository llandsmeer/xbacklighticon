#include <stdlib.h>
#include "app.h"

int main(int argc, const char ** argv) {
    struct app app;
    app_init(&app);
    app_run(&app);
    app_dispose(&app);
    return EXIT_SUCCESS;
}
