#include "common.h"

Checker c;

int main() {
    c.validate();
    ensuref(c.p_hi <= 100000, "max p <= 100000");
    return 0;
}
