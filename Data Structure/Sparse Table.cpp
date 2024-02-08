#include<iostream>
#define ll long long
using namespace std;

const ll N = 2e5+1;
ll arr[N], T[N][22], LOG[N];

class Sparse_table {
private:
	const ll RET_INIT = 1e18;
	void pre_count() {
		LOG[1] = 0;
		for (int i = 2; i < N; i++) {
			LOG[i] = LOG[i / 2] + 1;
		}
	}
	ll merge(ll l, ll r) {
		return min(l, r);
	}
public:
	int n;
	Sparse_table() {
		pre_count();
	}
	Sparse_table(ll mx) {
		n = mx;
		pre_count();
	}
	void build() { //O(NlogN)
		for (int i = 0; i < n; i++) {
			T[i][0] = arr[i];
		}
		for (int pw = 1; (1ll << pw) <= n; pw++) {
			for (int i = 0; i + (1ll << pw) <= n; i++) {
				T[i][pw] = merge(T[i][pw - 1], T[i + (1ll << (pw-1))][pw - 1]);
			}
		}
	}
	ll query(ll l, ll r) { //O(logN)
		ll ret = RET_INIT, sze = r - l + 1;
		for (int i = 21; i >= 0; i--) {
			if ((sze >> i) & 1) {
				ret = merge(ret, T[l][i]);
				l += (1ll << i);
			}
		}
		return ret;
	}
	ll query2(ll l, ll r) { // idempotent query // O(1)
		ll pw = LOG[r - l + 1];
		return merge(T[l][pw], T[r - (1ll << pw) + 1][pw]);
	}
};


signed main() {
	int n,q;
	cin >> n>>q;
	Sparse_table table(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	table.build();
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << table.query(--l, --r)<<endl;
	}

}
