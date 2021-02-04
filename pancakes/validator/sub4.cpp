#include "common.h"

Checker c;

int main() {
    c.validate();
    ensuref(c.Q == 0, "Q = 0");
    ensuref(c.p_hi <= 100000, "max pancakes <= 100000");
    return 0;
}
