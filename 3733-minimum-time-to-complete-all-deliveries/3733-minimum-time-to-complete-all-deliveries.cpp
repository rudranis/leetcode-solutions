class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    bool check(ll t, ll d1, ll d2, ll r1, ll r2, ll lcm) {
        ll can1 = t - t / r1;
        ll can2 = t - t / r2;
        ll total = t - t / lcm;

        return can1 >= d1 &&
               can2 >= d2 &&
               total >= d1 + d2;
    }

    long long minimumTime(vector<int>& d, vector<int>& r) {
        ll d1 = d[0], d2 = d[1];
        ll r1 = r[0], r2 = r[1];

        ll lcm = r1 / gcd(r1, r2) * r2;

        ll lo = 1, hi = 1;

        while (!check(hi, d1, d2, r1, r2, lcm))
            hi <<= 1;

        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;

            if (check(mid, d1, d2, r1, r2, lcm))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};