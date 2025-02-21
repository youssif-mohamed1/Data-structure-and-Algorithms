#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
tconst int N = 1e6 + 1, MOD = 1e9 + 7;

/////////////////////////////////////////////////Pascal Triangle Recursive
ll dp1[N][N];

ll nCr_rec(ll n, ll r) { //O(1000,1000)
    if(n < r) return 0;
    if (n == r || r == 0) return 1;
    ll &ret = dp1[n][r];
    if (~ret) return ret;
    return nCr_rec(n - 1, r - 1) + nCr_rec(n - 1, r);
}

/////////////////////////////////////////////////Pascal Triangle Iterative

ll nCr_iter(ll n, ll r) { // O(1000, 1000)
    if(n < r) return 0;
    vector<vll>dp(n + 1, vll(r + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= min(n, r); j++) {
            dp[i + 1][j] += dp[i][j];
            if(j < r) dp[i + 1][j + 1] += dp[i][j];
        }
    }
    return dp[n][r];
}

///////////////////////////////////////////////// nCr

int C(int n, int k) {
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i) // n! / (n - k)!
        res *= i;
    for (int i = 2; i <= k; ++i)// / k!
        res /= i;
    return res;
}

///////////////////////////////////////////////// nCr

int C(int n, int k) { // O(1e6)
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

/////////////////////////////////////////////////nCr with Modulo

ll fact[N + 1];
ll inv_fact[N + 1];

ll modPow(ll x, ll n, ll mod) {
    x %= mod;
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % mod; }
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

/////////////////////////////////////////////////Precompute Factorials

void factorial(ll p) {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) { fact[i] = fact[i - 1] * i % p; }
}

/////////////////////////////////////////////////Precompute Inverse Factorials
 
void inv_factorial(ll p) {
    inv_fact[N] = modPow(fact[N], p - 2, p);
    for (int i = N; i >= 1; i--) { inv_fact[i - 1] = inv_fact[i] * i % p; }
}

ll NPR(ll n, ll r, ll p){
	return fact[n] * inv_fact[n - r] % p;
}

ll NCR(ll n, ll r, ll p) {
    return fact[n] * inv_fact[r] % p * inv_fact[n - r] % p;
}

void pre_process(ll p){
    factorial(p);
    inv_factorial(p);
}

void solve() {
    ll n, r;
    cin >> n >> r;
    cout << nCr_rec(n, r) << " " << nCr_iter(n, r) ;
}

signed main() {
    int t = 1;
    pre_process(MOD); // pre-process for nCr with modulo
    cin >> t;
    memset(dp1,-1,sizeof dp1); // memset for dp
    while(t--) {
        solve();
        cout<<"\n";
    }
    return 0;
}
