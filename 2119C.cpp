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
#define npr(x) cout << (x) << '\n';
#define tpr(x) cout << (x) << '\n';
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
#define int long long

int nexter(int num) {
    int lbit;
    int ans = 0;
    for (lbit = 0; lbit < 64; lbit++) {
        if ((num & (1ll << lbit))) {
            ans = lbit;
        }
    }
    return ans + 1;
}
int solve() {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n == 2) return -1;
    if (n % 2 != 0)
        return l;
    else {
        int temp = (1ll << nexter(l));
        return (temp <= r) ? ((k > n - 2) ? temp : l) : -1;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        npr(solve());
    }
    return 0;
}

/*
n,l,r,k
1,4,4,1
4

4,6,9,2
_,_,_,_
&&&&=^^^^
0110 xor 0110 -> 0
6,7,8,9
   6    | 0110
   7    | 0111
   8    | 1000
   9    | 1001
        | 0000

    x = a1 ^ a2 ^ a3 ^ a4
    xors -> 1 1 1 1  , 111111,
    1011,  10 11 11

    10 -> 1
    11 -> 0
    00 -> 0
    01 -> 1

    1011 is 1
    1000
    11111
    0

    6789
    0110
    ..
    ..
    1001




Decimal | Binary
--------|--------
   1    | 0001
   2    | 0010
   3    | 0011
   4    | 0100
   5    | 0101
   6    | 0110
   7    | 0111
   8    | 1000
   9    | 1001
  10    | 1010
  useful props
  a^a=0
  a&a=1
  if [l,r] contains in b/w 2 powers all becomes zero
  if odd => l
  if even=> add 1 bit to left most 1 of l

    to make lexi small
    l&inv(l)=>0so last two is enough
    but l^inv(l) -> l^p=
    (a^a^a....even) -> 0
    (a^a.......odd) -> (a^0) -> a
    






  if even try to make 0s
  a&b=a^b
  a=~b


  nlrk
  4693
  6 to 9 in 4 spaces
  6^6 8^8
  0^0





*/