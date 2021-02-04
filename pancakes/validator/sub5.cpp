#include "common.h"

Checker c;

int main() {
    c.validate();
    ensuref(c.Q == 0);
    return 0;
}
