#include <stdio.h>
#include <stdlib.h>
#include "app.h"

int main(int argc, const char ** argv) {
    struct app app;
    app_init(&app);
    if (app.has_error) {
        fprintf(stderr, "initialization error: %s\n", app.error_message);
    }
    app_run(&app);
    app_dispose(&app);
    return EXIT_SUCCESS;
}
