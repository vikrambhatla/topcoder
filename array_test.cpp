#ifdef no_compile
#include<array>
#include<iostream>
using namespace std;

template<class T, unsigned int N>
ostream& operator<<(ostream& os, const array<T, N>& arr){
	for (int i = 0; i < N; ++i)
		os << arr[i] << (i < N - 1 ? "," : "");
	os << endl;
	return os;
}

int main(){
	array<array<int, 3>, 4> a;
	a[1][1] = 5;
	++a[0][4];
	cout << a[1][1] << endl;
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