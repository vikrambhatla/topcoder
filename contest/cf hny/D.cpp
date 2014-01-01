#include<iostream>
#include<queue>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)
typedef long long ll;
int k, x, n, m;
void slv(int x, int y, int pre, int aft, int special = 0){
	deque<char> a, b;
	rep(i, 0, x) a.push_back('A'), a.push_back('C');
	rep(i, 0, y) b.push_back('A'), b.push_back('C');
	rep(i, 0, n - 2 * x - pre - aft) a.push_back('X');
	rep(i, 0, m - 2 * y - pre - aft - special - (special && !aft && !pre)) b.push_back('X');
	if (pre) a.push_back('A'), b.push_front('C');
	if (aft) b.push_back('A'), a.push_front('C');
	if (special && aft) b.push_front('C');
	if (special && pre) b.push_back('A');
	if (special && !aft && !pre) b.push_back('A'), b.push_front('C');
	cout << string(a.begin(), a.end()) << endl;
	cout << string(b.begin(), b.end()) << endl;
	exit(0);
}
int main() {
	cin >> k >> x >> n >> m; --k;
	vector<ll> f(55); f[1] = f[2] = 1; rep(i, 3, 55) f[i] = f[i - 2] + f[i - 1];
	vector<ll> g(55); g[5] = 1; rep(i, 6, 55) g[i] = g[i - 1] + g[i - 2] + i % 2;
	ll a = f[k - 1], b = f[k], c = g[k + 2], d = g[k + 1];
	rep(i, 0, n / 2 + 1)rep(j, 0, m / 2 + 1){
		if (x == a*i + b*j) slv(i, j, 0, 0);
		if (2 * i < n && 2 * j < m &&  x == a*i + b*j + a) slv(i, j, 1, 0);
		if (2 * i < n && 2 * j < m && x == a*i + b*j + c) slv(i, j, 0, 1);
		if (2 * i < n - 1 && 2 * j < m - 1 && x == a*i + b*j + a + c + d) slv(i, j, 1, 1);
		if (2 * i < n && 2 * j < m - 1 && x == a*i + b*j + c + d) slv(i, j, 0, 1, 1);
		if (2 * i < n && 2 * j < m - 1 && x == a*i + b*j + a + d) slv(i, j, 1, 0, 1);
		if (2 * j < m - 1 && x == a*i + b*j + d) slv(i, j, 0, 0, 1);
	}
	puts("Happy new year!");
	return 0;
}