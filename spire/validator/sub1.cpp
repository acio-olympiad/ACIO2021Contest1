#include "common.h"

Checker c;

int main() {
    c.validate();
    for (int i = 0; i < c.N; i++) {
        ensuref(c.w[i] == 1, "c.w[i] = 1");
    }
    return 0;
}
