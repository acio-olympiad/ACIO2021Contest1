#ifndef COMMON_H
#define COMMON_H
#include "testlib.h"
#include "bounds.h"
using namespace std;

struct Checker {
    int N;
    int l[100005], w[100005], h[100005];
	void validate() {
		registerValidation();
        
        N = inf.readInt(MIN_N, MAX_N, "N");
		inf.readEoln();
        for (int i = 0; i < N; i++) {
            l[i] = inf.readInt(MIN_LWH, MAX_LWH, "l[i]");
            inf.readSpace();
            w[i] = inf.readInt(MIN_LWH, MAX_LWH, "w[i]");
            inf.readSpace();
            h[i] = inf.readInt(MIN_LWH, MAX_LWH, "h[i]");
            inf.readEoln();
        }
		inf.readEof();
	}
};
#endif
