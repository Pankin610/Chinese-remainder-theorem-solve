/*

Code by: Pavel Sankin
github.com/Pankin610

Solves the equation from the chinese remainder theorem.
Time Complexity: O(R * log A), small constant.
R - number of remainders. A - biggest remainder.

Possible use: Competetive Programming.

*/

#include <bits/stdc++.h>

using namespace std;

long long mul(long long a, long long b, long long m) {
    a %= m, b %= m;
    long long q = (long long)((long double)a * (long double)b / (long double)m);
    long long res = a * b - q * m;
    while(res < 0)
        res += m;
    return res % m;
}

long long bin_pow(long long num, long long st, long long mod) {
    if (st == 0)
        return 1;
    if (st % 2 == 1)
        return mul(bin_pow(num, st - 1, mod), num, mod);
    else {
        long long qz = bin_pow(num, st / 2, mod);
        return mul(qz, qz, mod);
    }
}

long long solveCRT(vector<long long> r, vector<long long> a) {
    long long prod = 1, ans = 0;
    vector<long long> m(r.size());

    for (int i = 0; i < a.size(); i++)
        prod *= a[i];
    for (int i = 0; i < m.size(); i++) {
        m[i] = prod / a[i];

        ans += (((r[i] * m[i]) % prod) * bin_pow(m[i] % a[i], a[i] - 2, a[i])) % prod;
        ans %= prod;
    }

    return ans;
}
