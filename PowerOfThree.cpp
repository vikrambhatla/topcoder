#ifdef no_compile_tc
// PowerOfThree.cpp
#include<algorithm>
#include<iostream>
#include<climits>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define all(v) v.begin(),v.end()
#define rep(i,f,t) for(int i = (f),e_##i = (t); i < e_##i; ++i)
typedef long long ll;
ll dp[1 << 19][20];

class PowerOfThree {
public:
	string ableToGet(int x, int y)  {
		ll a[20]; a[0] = 1;
		rep(i, 1, 20) a[i] = a[i - 1] * 3;

		int xx = (x == y && x == 0) ? 3 : 0;
		if (xx == 0)
			rep(j, 1, 20) rep(i, 0, 1 << j) {
				int I = ((i&(1 << (j - 1))) ? (i - (1 << (j - 1))) : i);
				dp[i][j] = dp[I][j - 1] + ((i & (1 << (j - 1))) ? a[j - 1] : -a[j - 1]);
				if (dp[i][j] == x + y) ++xx;
				if (dp[i][j] == x - y) ++xx;
				if (dp[i][j] == y - x) ++xx;
				//if (abs(dp[i][j]) < 7) cout << dp[i][j] << endl;
			}
		//cout << xx << endl;
		if (xx == 3)
			return "Possible";
		return "Impossible";
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 2; string Arg2 = "Possible"; verify_case(1, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 9; string Arg2 = "Impossible"; verify_case(2, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 0; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "Impossible"; verify_case(4, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = -6890; int Arg1 = 18252; string Arg2 = "Possible"; verify_case(5, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 1000000000; int Arg1 = -1000000000; string Arg2 = "Impossible"; verify_case(6, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 0; int Arg1 = 0; string Arg2 = "Possible"; verify_case(7, Arg2, ableToGet(Arg0, Arg1)); }

	// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
	PowerOfThree ___test;
	___test.run_test(-1);
}

/* PROBLEM STATEMENT
Fox Ciel has a robot.
The robot is located on an infinite plane.
At the beginning, the robot starts at the coordinates (0, 0).
The robot can then make several steps.
The steps are numbered starting from 0.

In each step, Ciel must choose one of four directions for the robot: left (x coordinate decreases),
right (x coordinate increases), up (y coordinate increases), or down (y coordinate decreases).
In step k, the robot will move 3^k units in the chosen direction.
It is not allowed to skip a step.

You are given ints x and y.
Return "Possible" (quotes for clarity) if it is possible that the robot reaches the point (x,y) after
some (possibly zero) steps.
Otherwise, return "Impossible".

DEFINITION
Class:PowerOfThree
Method:ableToGet
Parameters:int, int
Returns:string
Method signature:string ableToGet(int x, int y)


CONSTRAINTS
-x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-y will be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
1
3

Returns: "Possible"

In step 0 Ciel will send the robot right to (1,0). In step 1 she will send it up to (1,3).

1)
0
2

Returns: "Possible"

The robot will move from (0,0) down to (0,-1) and then up to (0,2).

2)
1
9

Returns: "Impossible"

Note that it is not allowed to move the robot right in step 0, skip step 1, and then move the robot up in step 2.

3)
3
0

Returns: "Impossible"



4)
1
1

Returns: "Impossible"



5)
-6890
18252

Returns: "Possible"



6)
1000000000
-1000000000

Returns: "Impossible"



7)
0
0

Returns: "Possible"


*/
// END CUT HERE
#endif
