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
	int a, b, c = 0; cin >> a >> b;
	int ans = 0;
	while (a)
		ans += a,
		a += c,
		c = a > b ? a%b : 0,
		a /= b;
	cout << ans << endl;
	return 0;
}
#endif