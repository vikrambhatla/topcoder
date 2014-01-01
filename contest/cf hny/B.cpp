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
	vi a(n); rep(i, 0, n) cin >> a[i];
	string ans;
	ans.reserve(1000 * 1000);
	rep(i, 0, n){
		while (a[i]){
			ans.push_back('P');
			--a[i];
			if (i < n - 1)
				ans.push_back('R'),
				ans.push_back('L');
			else
				ans.push_back('L'),
				ans.push_back('R');
		}
		if (i < n - 1)
			ans.push_back('R');
	}
	cout << ans << endl;
	return 0;
}
#endif