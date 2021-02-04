#include "common.h"

Checker c;

int main() {
    c.validate();
    ensuref(c.N <= 2000, "N <= 2000");
    return 0;
}
