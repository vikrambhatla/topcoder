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

int n, m, s;

int main() {
	cin >> n >> m >> s;
	vi a(n), b(m), c(n);
	rep(i, 0, m) cin >> b[i];
	rep(i, 0, n) cin >> a[i];
	return 0;
}
#endif