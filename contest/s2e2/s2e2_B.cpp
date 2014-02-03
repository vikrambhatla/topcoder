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

int cnt = 1;
int a[6000];
inline int nxt(int n){
	int N = n;
	while (n)
		N += n % 10,
		n /= 10;
	return N;
}

vi pr;
#define MX 1000000

bool ok[MX];
bool is_prime(int n){
	if (n < MX) return !ok[n];
	if (n != 2 && n % 2 == 0) return false;
	for (int i = 3; i*i <= n; i += 2)
		if (n%i == 0) return false;
	return true;
}

bool is_nearly(int n){
	for(int i = 0; i < pr.size() && pr[i] < n; ++i)
	if (n%pr[i] == 0 && is_prime(n / pr[i]))
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	for(int i = 2; i < MX; ++i)
	if (!ok[i]){
		pr.push_back(i);
		for (int j = i * 2; j < MX; j += i)
			ok[j] = true;
	}
	int T; cin >> T;
	int tmp;
	while (T--){
		cin >> tmp;
		if (is_nearly(tmp))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
#endif