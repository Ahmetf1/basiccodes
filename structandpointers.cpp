#include <iostream>
#include <vector>
using namespace std;
struct Province;
struct Country{
	string name;
	Province* capital;
};
struct Province{
	string name;
	Country* domain;
};


int main(){
	Country turkiye;
	Country* ptr1=&turkiye;
	Province ankara;
	Province* ptr2=&ankara;
	turkiye.name="turkiye";
	turkiye.capital=ptr2;
	ankara.name="ankara";
	ankara.domain=ptr1;
	Province istanbul={"istanbul",ptr1};
	cout<<istanbul.domain->capital->domain->capital->name <<endl;
	
}
