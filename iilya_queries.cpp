/*

user: Atul Bahuguna
problem link: https://codeforces.com/problemset/problem/313/B
*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i,st,en) for(ll i=st;i<en;i++)
#define F first
#define S second
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

/*****************************GCD function***********************/

int gcd(int a, int b) {

	if (a == 0) {
		return b;
	}

	// make sure always pass abs(a) and abs(b);

	return gcd(b, a % b);
}


ll power(ll base, ll n) {
	ll res = 1;
	while (n) {
		if (n % 2 == 1) {
			res = res * base;
			n--;
		}
		base = base * base;
		n /= 2;
	}

	return res;
}

bool is_prime[10000001];

void sieve() {

	ll maxN = 10000000;

	for (ll i = 1; i <= maxN; i++) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;

	for (ll i = 2; i * i <= maxN; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= maxN; j += i) {
				is_prime[j] = false;
			}
		}
	}


}


/*******************************Main function Program*******************/


void solve() {

	string s; cin >> s;
	int n = s.length();
	int check[n] = {0};
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			check[i] = 1;
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	cout << check[i] << " ";
	// }
	// cout << endl;

	int pre[n];
	pre[0] = check[0];
	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + check[i];
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << pre[i] << " ";
	// }
	// cout << endl;

	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		l--, r--;
		if (l > 0)
			cout << pre[r - 1] - pre[l - 1] << endl;
		else {
			cout << pre[r - 1] << endl;
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false); cin.tie(NULL);
	sieve();
	ll T = 1;
	// cin >> T;
	while (T--) {
		solve();

	}
	return 0;
}