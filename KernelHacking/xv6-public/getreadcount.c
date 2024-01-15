#include "types.h"
#include "user.h"

int
main(void) {
    printf(1, "The amount of times read() was called: %d\n", grc());
    exit();
}