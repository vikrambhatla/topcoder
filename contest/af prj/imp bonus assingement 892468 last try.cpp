#ifdef do_not_compile_this_file
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
using namespace std;
#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)

#define mary <<

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct crom
{
	static int n, gol;
	vector<int> v;
	int fitness;
	// copy a crom
	crom(const crom& _c) : v(_c.v), fitness(_c.fitness) { }
	// create a random crom
	crom(){
		v.reserve(n*n);
		rep(i, 1, n*n + 1) v.push_back(i);
		random_shuffle(v.begin(), v.end());
		fitness = calc_fitness();
	}
	crom(vi& _v){
		v = _v;
		fitness = calc_fitness();
	}

	bool operator>(const crom& b) const{
		return fitness > b.fitness;
	}
	crom operator mary(const crom& a){
		vector<bool> vis(n*n + 1);
		vi _v;
		int pivot = rand() % (n*n) + 1;
		rep(i, 0, pivot) _v.push_back(this->v[i]), vis[this->v[i]] = true;
		rep(i, 0, n*n) if (!vis[a.v[i]]) _v.push_back(a.v[i]);
		return crom(_v);
	}
	crom mry(const crom& a, int pivot){
		vector<bool> vis(n*n + 1);
		vi _v;
		rep(i, 0, pivot) _v.push_back(this->v[i]), vis[this->v[i]] = true;
		rep(i, 0, n*n) if (!vis[a.v[i]]) _v.push_back(a.v[i]);
		return crom(_v);
	}
	int calc_fitness(){
		vi r(n), c(n);
		int ds = 0, df = 0, ans = 0;
		rep(i, 0, n*n) r[i / n] += v[i], c[i%n] += v[i], ds += (i / n == i%n) ? v[i] : 0, df += (i / n == n - i%n - 1) ? v[i] : 0;
		//rep(i, 0, n) ans += abs(r[i] - gol), ans += abs(c[i] - gol);
		//ans += abs(ds - gol); ans += abs(df - gol);
		rep(i, 0, n) ans += (r[i] == gol), ans += (c[i] == gol);
		ans += (ds == gol); ans += (df == gol);
		return ans;
	}
};
ostream& operator<<(ostream& os, const crom& c){
	const vi& v = c.v;
	int n = crom::n;
	rep(i, 0, n){
		rep(j, 0, n)
			os << v[i*n + j] << ',';
		os << endl;
	}
	return os;
}
int crom::n, crom::gol;

const int psize = 100; // population size
int main() {
	cout << "enter magic square size (n) : ";
	cin >> crom::n;
	crom::gol = crom::n * 2 + 2;

	vector<crom> v(psize); // create 100 random crom 

	int best = 0;
	do{
		// mary 'psize' random croms and add new croms to population .
		rep(i, 0, psize) rep(j, i + 1, psize) rep(pivot, 1, crom::n*crom::n - 1)
			v.push_back(v[i].mry(v[j], pivot));
		sort(v.begin(), v.end(), std::greater<crom>());

		// replace 25% of good population eg. v[3*psize/4] till v[psize] with random bad ones
		rep(i, 0, psize / 4)
			swap(v[3 * psize / 4 + i], v[psize + rand() % psize]);
		v.resize(psize);
		if (v[0].fitness > best){
			best = v[0].fitness;
			cout << best << endl;
			cout << v[0] << endl;
		}

	} while (v.begin()->fitness < crom::gol);
	cout << v[0] << endl;
	return 0;
}
#endif