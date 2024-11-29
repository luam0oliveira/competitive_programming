#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

unordered_map<int, int> m; // if multiply queries, no need to recompute inverse :)
int rv(int x) {
	if (m.count(x)) return m[x];
	return m[x] = qpow(x, mod - 2);
}

int interpolate(int x, int k, bool bf = false) {
	if (k == 0) return x;
	// find 1^k + 2^k + ... + x^k
	// (k+1) degree polynomial -> (k+2) points
	if (x <= k + 1 || bf) {
		int s = 0;
		for (int i = 1; i <= x; i ++) {
			s = (s + qpow(i, k)) % mod;
		}
		return s;
	}
	vector<int> pre(k + 2), suf(k + 2), inv(k + 2);
	inv[0] = 1;
	pre[0] = x;
	suf[k + 1] = x - (k + 1);
	for (int i = 1; i <= k; i ++) pre[i] = pre[i - 1] * (x - i) % mod; //numerator prefix product
	for (int i = k; i >= 1; i --) suf[i] = suf[i + 1] * (x - i) % mod; //numerator suffix product
	for (int i = 1; i <= k + 1; i ++) inv[i] = inv[i - 1] * rv(i) % mod; // denominator factorial
	int ans = 0;
	int yi = 0; // 0^k +~ i^k
	int num, denom;
	for (int i = 0; i <= k + 1; i ++) {
		yi = (yi + qpow(i, k)) % mod; // interpolate point: (i, yi)

		if (i == 0) num = suf[1];
		else if (i == k + 1) num = pre[k];
		else num = pre[i - 1] * suf[i + 1] % mod; // numerator

		denom = inv[i] * inv[k + 1 - i] % mod; // denominator

		if ((i + k) & 1) ans += (yi * num % mod) * denom % mod; // (-1)^(i-deg) however deg is k+1 here so :)
		else ans -= (yi * num % mod) * denom % mod;

		ans = (ans % mod + mod) % mod;
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); // grhkm orz
	int x, k; cin >> x >> k;
	cout << interpolate(x, k) << endl;
}