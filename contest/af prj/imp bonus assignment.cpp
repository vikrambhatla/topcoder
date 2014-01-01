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

typedef vector<int> vi;
typedef vector<vi> vvi;

int fitness(vvi& vv){
	int n = vv.size(), gol = n*(n*n + 1) / 2;
	vi r(n), c(n);
	int ds = 0, df = 0;
	rep(i, 0, n) rep(j, 0, n) r[i] += vv[i][j], c[j] += vv[i][j], ds += i == j ? vv[i][j] : 0, df += (i == n - j - 1) ? vv[i][j] : 0;
	int ans = int(ds == gol) + int(df == gol);
	rep(i, 0, n) ans += int(r[i] == gol) + int(c[i] == gol);
	return ans;
}

int main() {
	int n; cin >> n;
	int best_fitness = 0, gol_fitness = 2 * n + 2;
	vi nums(n*n); rep(i, 0, n*n) nums[i] = i + 1;
	vvi vv(n, vi(n));
	rep(i, 0, n) rep(j, 0, n) vv[i][j] = nums[i*n + j];
	vector<vvi> states; states.push_back(vv);
	for (int i = 0; i < states.size(); ++i){
		vvi vv = states[i];
		int cur_fitness = fitness(vv);
		rep(x1, 0, n)rep(y1, 0, n)
			rep(x2, 0, n)rep(y2, 0, n)
		if (!(x1 == x2 && y2 == y2)){
			swap(vv[x1][y1], vv[x2][y2]);
			int new_fitness = fitness(vv);
			if (new_fitness > cur_fitness)
				states.push_back(vv);
			if (new_fitness > best_fitness)
				best_fitness = new_fitness,
				cout << best_fitness << ' ' << i << endl;
			swap(vv[x1][y1], vv[x2][y2]);
		}
	}
	return 0;
}
#endif