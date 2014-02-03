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

int main() {
	ios_base::sync_with_stdio(false);
	//ll i = 10000;
	//while (true){
	//	while ((i*i) % (1000 * 1000 * 1000) != 987654321)
	//		++i;
	//	cout << i << endl;
	//	++i;
	//}
	int n; cin >> n;
	if (n < 9) puts("0");
	else if (n == 9) puts("8");
	else {
		n -= 9;
		cout << 9*8;
		rep(i, 1, n) cout << '0';
		cout << endl;
	}
	return 0;
}
#endif