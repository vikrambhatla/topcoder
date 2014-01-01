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
const int V = 1000 * 100 + 1;
int l[V], v[V], r[V], dp[V];
int mx;
vector<vector<int> > stk;
bool g(int i, int j){
	//return (v[j] >= l[i] && v[j] <= r[i]);
	//return (v[i] >= l[j] && v[i] <= r[j]) || (v[j] >= l[i] && v[j] <= r[i]);
	return true;
}
set<int> _s;
int dfs(int n, int ns, int dep){
	puts("dfs");
	if (1 || 0 == ns){
		if (dep > mx) mx = dep;
		return 1;
	}
	int i, j, k, p, cnt;
	for (i = 0; i < ns; ++i){
		k = stk[dep][i]; cnt = 0;
		if (dep + n - k <= mx) return 0;
		if (dep + dp[k] <= mx) return 0;
		for (j = i + 1; j < ns; ++j){
			p = stk[dep][j];
			if (g(k, p)) stk[dep + 1][++cnt] = p;
		}
		dfs(n, cnt, dep + 1);
	}
	return 1;
}

int clique(int n){
	int i, j, ns;
	for (mx = 0, i = n - 1; i >= 0; --i){
		for (ns = 0, j = i + 1; j < n; ++j)
			if (g(i, j)) stk[1][++ns] = j;
		dfs(n, ns, 1);
		dp[i] = mx;
	}
	return mx;
}

int main() {
	int n; cin >> n;
	rep(i, 0, n) cin >> l[i] >> v[i] >> r[i];
	stk = vector<vector<int> >(n + 1, vi(n + 1));
	cout << clique(n) << endl;
	return 0;
}

//...#...........
//...#...........
//...#...........
//...#...........
//####...........
//...............
//...............