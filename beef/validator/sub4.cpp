#include "common.h"

int main() {
    Checker c{}; c.validate();
    ensuref(c.SB4, "Does not match sub4 bounds");
    return 0;
}
