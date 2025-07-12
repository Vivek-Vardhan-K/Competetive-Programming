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
// #include<numeric>
using ll = long long;
using pii = pair<ll, ll>;
using vint = vector<ll>;
#define FOR(i, n) for (ll i = 0; i < (n); ++i)
#define FORN(i, a, b) for (ll i = (a); i < (b); ++i)
#define pb push_back
#define pf push_front
#define endl '\n'
#define nprint(x) cout << x << '\n';
#define tprint(x) cout << x << '\n';
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
#define int long long
#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

long long reduceByCommonFactors(long long a, long long b) {
    long long g;
    while ((g = gcd(a, b)) != 1) {
        a /= g;
    }
    return a;
}

ll solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    FOR(i, n) cin >> v[i];
    ll f = 1;
    FOR(i, n - 1) {
        if (v[i + 1] % v[i] != 0) {
            ll gd = gcd(v[i], v[i + 1]);
            ll cf = v[i] / gd;
            f = lcm(f, cf);
        }
    }

    return f;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        nprint(solve());
    }
    return 0;
}

/*


*/