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

char a[550][550];
int  b[550][550];
bool vis[550][550];
int still;
int dfs(int i, int j){
	if (a[i][j] != '.' || vis[i][j]) return 0;
	vis[i][j] = true;
	int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
	rep(k, 0, 4)
		b[i][j] += dfs(i + dx[k], j + dy[k]);
	if (still && b[i][j] == 0){
		a[i][j] = 'X';
		--still;
		return 0;
	}
	return 1;
}

int main() {
	int n, m, k; cin >> n >> m >> k;
	still = k;
	rep(i, 0, n) scanf("%s",&a[i + 1][1]);
	int dfsed = false;
	for (int i = 1; i <= n && !dfsed; ++i)
	for (int j = 1; j <= m && !dfsed; ++j)
	if (a[i][j] == '.')
		dfs(i, j),
		dfsed = true;
	rep(i, 0, n)
		puts(&a[i + 1][1]);
	return 0;
}
#endif