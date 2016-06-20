#include <stdio.h>
#include <stdlib.h>
#include "app.h"

int main() {
    struct app app;
    app_init(&app);
    if (app.has_error) {
        fprintf(stderr, "initialization error: %s\n", app.error_message);
        return EXIT_FAILURE;
    }
    app_run(&app);
    if (app.has_error) {
        fprintf(stderr, "error: %s\n", app.error_message);
    }
    app_dispose(&app);
    return EXIT_SUCCESS;
}
