#include "common.h"

Checker c;

int main() {
    c.validate();
    ensuref(c.N <= 8, "N <= 8");
    return 0;
}
