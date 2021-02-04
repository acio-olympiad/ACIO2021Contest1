#ifndef COMMON_H
#define COMMON_H
#include "testlib.h"
#include "bounds.h"
using namespace std;

struct Checker {
	int N, K, Q, p_lo, p_hi;
	int p[100005];
    int qa[100005], qb[100005];
	void validate() {
		registerValidation();
        
        N = inf.readInt(MIN_N_K, MAX_N_K, "N");
		inf.readSpace();
        K = inf.readInt(MIN_N_K, N, "K");
		inf.readSpace();
        Q = inf.readInt(MIN_Q, MAX_Q, "Q");
		inf.readEoln();
        for (int i = 0; i < N; i++) {
            p[i] = inf.readInt(MIN_P, MAX_P, "p[i]");
            if (i == 0 || p[i] < p_lo) p_lo = p[i];
            if (i == 0 || p[i] > p_hi) p_hi = p[i];
            if (i < N-1) inf.readSpace();
            else inf.readEoln();
        }
        for (int i = 0; i < Q; i++) {
            qa[i] = inf.readInt(MIN_P, MAX_P, "a[i]");
            p_hi = max(p_hi, qa[i]);
            inf.readSpace();
            qb[i] = inf.readInt(1, N, "b[i]");
            inf.readEoln();
        }
		inf.readEof();
	}
};
#endif
