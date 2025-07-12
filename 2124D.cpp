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
    for (auto& x : v) cout << x << ' '; \
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
int tc = 1;

bool solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), s(n);
    FOR(i, n) {
        cin >> v[i];
        s[i] = v[i];
    }

    if (k <= 2) return true;
    // 1 1 2 2 5 6

    sortv(s);
    int ak = s[k-2];
    vector<int> f;
    int rmAllows = 0;
    // nprint(ak);

    int counts = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > ak) continue;
        if (++counts >= (k-1) && v[i] == ak) rmAllows++;
        f.pb(v[i]);
    }
    int l = 0, r = f.size() - 1;
    // nprint(rmAllows);
    // printv(f);
    // 1 1 2 2
    while ((l < r) && rmAllows >= 0) {
        if (f[l] == f[r]) {
            l++;
            r--;
        } else {
            if (rmAllows == 0) return false;
            if (f[l] == ak)
                l++, rmAllows--;
            else if (f[r] == ak)
                r--, rmAllows--;
            else
                return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        bool sol = solve();
        cout << ((sol) ? "YES" : "NO") << '\n';
        tc++;
    }
    return 0;
}

/*
8 5
4 7 1 2 3 1 3 4
5 4
1 2 1 2 2
6 6
2 3 4 7 6 3 2
2 2 3 3 4 6 7
9 6
1 2 3 4 5 5 0 4 3 2 1
=========



take subarr min size of k and remove kth element
after taking n-k+1 elements if still not possible NO
In a window if all elements on right side of window is more than
    kth element position stays

For an element to be removable(kth):
- It has to be starting from more than k when sorted.
- for ai to be at k(removable),it has to have atleast k-1 elements less than
equal itself beside it on either side
- eliminating highest is always beneficial
- question turns to, you know all the removable elements now -> make it
palindrome
-   if k<=2 YES

>ak to be deleted
<ak are fixed
=ak is meh

1 2 2 1 3 1 3



----------------------------
8 5
4 7 1 2 2 1 3 4

1 1 0 0 0 0 1 1  -> removable

4 7 1 2 2 1 2 4
1 2 2 1 2

abbbbaa

M M F F F F M M
1 1 2 2 3 4 4 7
N N N N

16734431

when palindrome is not possible?
__x___x______
8 5
4 7 1 2 3 1 3 4
0 0 1 1 1 1 1 0





------------------------------
if curr length is even
    remove both ends if not equal


*/