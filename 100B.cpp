#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vint = vector<ll>;
#define FOR(i, n) for (ll i = 0; i < (n); ++i)
#define FORN(i, a, b) for (ll i = (a); i < (b); ++i)
#define pb push_back
#define pf push_front
#define endl '\n'
#define nprint(x) cout << x << '\n';
#define tprint(x) cout << x << '\t';
#define printv(v)                       \
    for (auto &x : v) cout << x << ' '; \
    cout << '\n'
#define readv(v, n) \
    vint v(n);      \
    FOR(i, n) cin >> v[i]
#define sortv(v) sort((v).begin(), (v).end())
#define rsortv(v) sort((v).rbegin(), (v).rend())
#define minheap(T) priority_queue<T, vector<T>, greater<T> >
#define maxheap(T) priority_queue<T>

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll solve() {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    if (b < a && (a ^ 1) == b) return y;
    if (b < a) return -1;

    ll curr = a, cost = 0;
    ll temp;
    // nprint("---------------");
    while (a != b) {
        // nprint(a);
        int xr = (a ^ 1);
        if (xr > b || xr <= a) {
            a++;
            cost += x;
            continue;
        }
        int wxr = x * (xr - a);
        if (y <= wxr) {
            cost += y;
            a ^= 1;
        } else {
            cost += x;
            a++;
        }
    }
    return cost;
}
/*
1 -> 4
00001  - 1
00100  - 4
a xor 1
00001 XOR 00001

1 5 2 1
a = a xor 1
0010
0001
0011
2+1
00011
00001
00010


*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        int k;
        cout << solve() << '\n';
    }
    return 0;
}
