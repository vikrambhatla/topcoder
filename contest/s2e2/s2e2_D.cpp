#ifdef do_not_compile_this_file
#include<algorithm>
#include<iterator>
#include<iostream>
#include<cstring>
#include<climits>
#include<cstdio>
#include<string>
#include<vector>
#include<deque>
#include<set>
#include<map>
using namespace std;
#define all(v) begin(v),end(v)
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)


typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int nxt(int n){
	int rs = n;
	while (n)
		rs += n % 10,
		n /= 10;
	return rs;
}
int sf[5000 + 1];

int main() {
	ios_base::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	vector<bool> dp(n + 1);
	//vector<int> sf;
	//sf.reserve(1000 * 1000);
	int tmp;
	int tot = 0;
	rep(i, 1, n + 1){
		if (!dp[i] && tot <= k)
			sf[tot] = i;
		if (!dp[i])
			++tot;
		//sf.push_back(i);
		tmp = nxt(i);
		if (tmp <= n)
			dp[tmp] = true;
	}
	//cout << "---> " << sf.size() << ' ' << sf.back() << ' ' << sf.capacity() << endl;
	//cout << upper_bound(sf.begin(), sf.end(), n) - sf.begin() << endl;
	cout << (upper_bound(sf, sf + tot, n) - sf) << endl;
	rep(i, 0, k)
		cin >> tmp,
		cout << sf[tmp - 1] << ' ';
	cout << endl;
	return 0;
}
#endif