#include <bits/stdc++.h>

class Solution {
public:

    #define ll __int128_t

    ll gcd(ll u, ll v) {

        if(v == 0)
            return u;
        else
            return gcd(v,u%v);
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        a = (ll)a;
        b = (ll)b;
        c = (ll)c;
        n = (ll)n;

        ll lab = (a*b) / gcd(a,b);
        ll k = (ll) b*(ll)c;
        ll lbc = k / gcd(b,c);
        ll lac = (a*c) / gcd(a,c);
        ll labc = (c*lab) / gcd(c, lab);
        ll left = 1;
        ll right = 2000000000;

        while(left < right) {
            ll mid = (right + left)/2;

            ll g = 0;
            g += (mid/a);
            g += (mid/b);
            g += (mid/c);
            g -= (mid/lab);
            g -= (mid/lac);
            g -= (mid/lbc);
            g += (mid/labc);

            if(g==n && (mid%a == 0 || mid%b == 0 || mid%c == 0)) {
                cout << "here" << "\n";
                return (int)mid;
            }

            if(g>=n) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return (int)left;
    }
};
