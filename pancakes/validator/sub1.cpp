#include "common.h"

Checker c;

int main() {
    c.validate();
    ensuref(c.Q == 0, "Q = 0");
    ensuref(c.N == 3, "N = 3");
    ensuref(c.K == 2, "K = 2");
    return 0;
}
