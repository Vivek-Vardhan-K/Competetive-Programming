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
#define printv(v)                       \
    for (auto &x : v) cout << x << ' '; \
    cout << '\n'
#define readv(v, n) \
    vint v(n);      \
    FOR(i, n) cin >> v[i]
#define sortv(v) sort((v).begin(), (v).end())
#define rsortv(v) sort((v).rbegin(), (v).rend())
#define minheap(T) priority_queue<T, vector<T>, greater<T>>
#define maxheap(T) priority_queue<T>

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

void solve() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#define endl '\n'

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}