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
ll min(ll a, ll b) {
    return (a < b) ? a : b;
}
ll solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    FOR(i, n) cin >> v[i];
    vector<int> sun;
    int mini = INF;
    int pv = 0;
    FOR(i, n) {
        mini = min(v[i], mini);
        sun.push_back(mini);
        pv += mini;
    }
    vector<int> pre(n, 0);
    pre[0] = v[0];
    FORN(i, 1, n) {
        pre[i] = pre[i - 1] + sun[i];
    }
    // printv(pre);
    int ans = pv;
    FOR(i, n - 1) {
        int x = (sun[i] == v[i]) ? v[i + 1] : 0;
        ans = min(ans, pre[i] + x);
    }
    return ans;
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