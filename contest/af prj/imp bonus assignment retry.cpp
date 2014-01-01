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

typedef vector<int> vi;
typedef vector<vi> vvi;

int n;
int gol;
int fitness_org(vi& v){
	vi r(n), c(n);
	int ds = 0, df = 0, ans = 0;
	rep(i, 0, n*n) r[i / n] += v[i], c[i%n] += v[i], ds += (i / n == i%n) ? v[i] : 0, df += (i / n == n - i%n - 1) ? v[i] : 0;
	rep(i, 0, n) ans += r[i] == gol, ans += c[i] == gol;
	ans += ds == gol; ans += df == gol;
	return ans;
}

int fitness(vi& v){
	vi r(n), c(n);
	int ds = 0, df = 0, ans = 0;
	rep(i, 0, n*n) r[i / n] += v[i], c[i%n] += v[i], ds += (i / n == i%n) ? v[i] : 0, df += (i / n == n - i%n - 1) ? v[i] : 0;
	rep(i, 0, n) ans += abs(r[i] - gol), ans += abs(c[i] - gol);
	ans += abs(ds - gol); ans += abs(df - gol);
	return -ans;
}

vi fits;// fitness of each instance in population
vvi population; // population
int best_fitness = 0;

inline void add_child(vi& v){
	fits.push_back(fitness(v));
	population.push_back(v);
}

// merge population[i] and population[j] with a pivod and insert new child if its better than i,j
void new_child(int i, int j, int pivot){
	vi nv; nv.reserve(n*n);
	vi vis(n*n + 1);
	rep(z, 0, pivot)
		nv.push_back(population[i][z]),
		vis[population[i][z]] = true;
	rep(z, 0, n*n)
	if (!vis[population[j][z]])
		nv.push_back(population[j][z]);
	int f = fitness(nv);
	if (f >= min(fits[i], fits[j]))
		fits.push_back(f),
		population.push_back(nv);
	if (f > best_fitness)
		best_fitness = f,
		cout << fitness_org(nv) << ' ' << best_fitness << endl;

}

int main() {
	best_fitness = INT_MIN;
	cin >> n;
	vi v(n*n); rep(i, 0, n*n) v[i] = i + 1;
	//insert 2 differnt states into population
	add_child(v);
	random_shuffle(v.begin(), v.end());
	add_child(v);

	gol = n*(n*n + 1) / 2;
	for (int i = 0; i < population.size(); ++i){
		for (int j = i + 1; j < population.size(); ++j){
			rep(z, 1, n*n + 1) new_child(i, j, z);
		}
	}

	return 0;
}