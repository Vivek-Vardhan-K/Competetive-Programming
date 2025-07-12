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
#define int long long
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

#include <cmath>  // for std::sqrt
long long euclideanDistance(int a, int b, int c, int d) {
    return 1LL * (a - c) * (a - c) + 1LL * (b - d) * (b - d);
}
ll k = 0;

string solve() {
    int n;
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int maxi = *max_element(v.begin(), v.end());
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    long long distSq = euclideanDistance(a, b, c, d);

    if (n == 1) {
        return (1LL * maxi * maxi == distSq) ? "YES" : "NO";
    }

    long long low = 1LL * (sum - 2 * maxi) * (sum - 2 * maxi);
    long long high = sum * sum;

    if (((maxi >= (sum - maxi) && distSq < low)) || distSq > high) {
        return "NO";
    }

    return "YES";
}

ll t;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    ll c = 1;
    while (t--) {
        k++;
        nprint(solve());
    }
    return 0;
}