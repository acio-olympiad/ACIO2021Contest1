#include "common.h"

Checker c;

int main() {
    c.validate();
    ensuref(c.N <= 300, "N <= 300");
    return 0;
}
