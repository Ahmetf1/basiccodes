#include <iostream>
#define _USE_MATH_DEFINES // M_PI
#include <cmath>
using namespace std;
class RegularPolygon {
	private:
		static int _count;
		int n;
		float angle;
	public:
		const int& count=_count;
		RegularPolygon(int n);
		~RegularPolygon();
		
		float area(float lenght);
		float lenght(float area);
		
		int get_count();	
};
RegularPolygon::RegularPolygon(int n) {
		this->n=n;
		angle=(M_PI)*(n-2)/n;	
		_count++;				
}
RegularPolygon::~RegularPolygon() {
	_count--;
}
float RegularPolygon::area(float lenght) {
	return lenght*lenght*n/4/tan(M_PI/n);
}
float RegularPolygon::lenght(float area) {
	return sqrt((4*area)/n*tan(M_PI/n));

}
int RegularPolygon::get_count() {
	return count;
}
int RegularPolygon::_count=0;
int main(){
	RegularPolygon square(4);
	RegularPolygon square2(4);
	cout<<square.count;				
}
