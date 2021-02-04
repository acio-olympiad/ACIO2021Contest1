#include "common.h"

int main() {
    Checker c{}; c.validate();
    ensuref(c.SB2, "Does not match sub2 bounds");
    return 0;
}
