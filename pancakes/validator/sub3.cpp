#include "common.h"

Checker c;

int main() {
    c.validate();
    ensuref(c.Q == 0, "Q = 0");
    ensuref(c.N <= 1000, "N <= 1000");
    ensuref(c.p_hi <= 1000, "max pancakes <= 1000");
    return 0;
}
