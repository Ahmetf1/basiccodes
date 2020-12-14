#include <iostream>
#include <vector>
using namespace std;

template <typename T>
vector <vector<T>> create_matrix (T x,int r,int c) {
	
	vector<T> vec_1 (r,x);
	vector<vector<T>> vec_2 (c,vec_1);
	return vec_2;
}
			

 













int main() {
	cout << create_matrix(3,4,5)[0][0];	
}
