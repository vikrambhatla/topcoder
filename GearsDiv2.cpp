#ifdef no_compile // acc
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define rep(i,m,n) for(int i=(m),end##_i=(n);i < end##_i;++i)
#define repe(i,m,n) for(int i=(m), end##_i =(n);i <= end##_i;++i)
typedef long long ll;
using namespace std;

class GearsDiv2
{
public:
	int test(const string& d){
		if (d.size() <= 1)
			return 0;
		if (d[0] != d[1])
			return test(d.substr(1));
		return 1 + test(d.substr(2));
	}
	int getmin(string d)
	{
		int n = d.size();
		if (n <= 1)
			return 0;
		int ans = n - 1;
		if (d[0] != d[n - 1])
			ans = test(d);
		ans = min(1 + test(d.substr(1)), ans);
		ans = min(1 + test(d.substr(0, n - 1)), ans);
		return ans;
	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LRRR"; int Arg1 = 1; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "RRR"; int Arg1 = 2; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "LRLR"; int Arg1 = 0; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "LRLLRRLLLRRRLLLL"; int Arg1 = 6; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR"; int Arg1 = 14; verify_case(4, Arg1, getmin(Arg0)); }

	// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	GearsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE

#endif
