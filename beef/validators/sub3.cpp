#include "common.h"

int main() {
    Checker c{}; c.validate();
    ensuref(c.SB3, "Does not match sub3 bounds");
    return 0;
}
