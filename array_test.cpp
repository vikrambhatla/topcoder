#ifdef no_compile
#include<array>
#include<iostream>
#include<time.h>
using namespace std;
#define rep(i,f,t) for(int i = f; i < t; ++i)

//template<class T, unsigned int N>
//ostream& operator<<(ostream& os, const array<T, N>& arr){
//	for (int i = 0; i < N; ++i)
//		os << arr[i] << (i < N - 1 ? "," : "");
//	os << endl;
//	return os;
//}
//
//int A[1000 * 1000 * 100];
//clock_t clk;
int main(){
	//ios_base::sync_with_stdio(false);
	//int A[10] = { 1, 2, 3, 4, 5, 9, 8, 7, 6, 10 };
	//sort(begin(A), end(A));
	//copy(istream_iterator<int>(cin), begin(A));
	//copy(begin(A), end(A), ostream_iterator<int>(cout, " "));

	//clk = clock();
	//memset(A, -1, sizeof(A));
	//printf("CPU Clocks : %d\n", clock() - clk);
	//clk = clock();
	//fill(A, A + 1000 * 1000 * 100, -1);
	//printf("CPU Clocks : %d\n", clock() - clk);


	//int A[10] = { 1, 2 };
	//int B[10] = { 1, 2};
	//rep(i, 0, 10) cout << A[i] << ' '; cout << endl;
	//rep(i, 0, 10) cout << B[i] << ' '; cout << endl;
	//array<array<int, 3>, 4> a;
	//a[1][1] = 5;
	//++a[0][4];
	//cout << a[1][1] << endl;
	//array<array<int, 10>, 10> a;
	//for (int i = 0; i < a.size(); ++i) a[i].fill(i);
	//for (int i = 1; i < a.size(); i += 2) a[i].swap(a[i - 1]);
	//cout << a << endl;
	/* prints
	1,1,1,1,1,1,1,1,1,1
	,0,0,0,0,0,0,0,0,0,0
	,3,3,3,3,3,3,3,3,3,3
	,2,2,2,2,2,2,2,2,2,2
	,5,5,5,5,5,5,5,5,5,5
	,4,4,4,4,4,4,4,4,4,4
	,7,7,7,7,7,7,7,7,7,7
	,6,6,6,6,6,6,6,6,6,6
	,9,9,9,9,9,9,9,9,9,9
	,8,8,8,8,8,8,8,8,8,8 */
	return 0;
}
#endif