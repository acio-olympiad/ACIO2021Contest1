#include "common.h"

Checker c;

int main() {
    c.validate();
    ensuref(c.Q == 0);
    ensuref(c.K == 2);
    return 0;
}
