#include "common.h"
#include <iostream>
using namespace std;
int main() {
    Checker c{}; c.validate();
    ensuref(c.SB1, "Does not match sub1 bounds");
    return 0;
}
