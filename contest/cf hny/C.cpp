#ifdef no_compile
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)
#define _MAX 1000

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

typedef long long ll;

int main() {
	int n; cin >> n;
	vector<ii> v(n); rep(i, 0, n) cin >> v[i].first, v[i].second = i;
	vi a(n);
	sort(v.begin(), v.end());
	int mx = 0;
	for (auto& p : v)
	if (p.first > mx)
		mx = a[p.second] = p.first;
	else
		a[p.second] = ++mx;
	for (auto i : a)
		cout << i << ' ';
	cout << endl;
	return 0;
}
#endif