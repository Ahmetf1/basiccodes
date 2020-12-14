#include <iostream>
#include <clocale>
using namespace std;
string yuzler(int s){switch(s/100) {  //yüzler basamaðýný bulmak için fonksiyon
		case 1:
			return "yüz";
			break;
		case 2:
			return "ikiyüz";
			break;
		case 3:
			return "üçyüz";
			break;
		case 4:
			return "dörtyüz";
			break;
		case 5:
			return "beþyüz";
			break;
		case 6:
			return "altýyüz";
			break;			
		case 7:
			return "yediyüz";
			break;
		case 8:
			return "sekizyüz";
			break;
		case 9:
			return "dokuzyüz";
			break;
		case 0:
			return "";
			break;
	}
}
string onlar(int s){switch((s%100)/10) {   //onlar basamaðýný bulmak için fonksiyon
		case 1:
			return "on";
			break;
		case 2:
			return "yirmi";
			break;
		case 3:
			return "otuz";
			break;
		case 4:
			return "kýrk";
			break;
		case 5:
			return "elli";
			break;
		case 6:
			return "altmýþ";
			break;			
		case 7:
			return "yetmiþ";
			break;
		case 8:
			return "seksen";
			break;
		case 9:
			return "doksan";
			break;
		case 0:
			return "";
			break;
	}
}
string birler(int s){switch((s%100)%10) {  //birler basamaðýný bulmak için fonksiyon
		case 1:
			return "bir";
			break;
		case 2:
			return "iki";
			break;
		case 3:
			return "üç";
			break;
		case 4:
			return "dört";
			break;
		case 5:
			return "beþ";
			break;
		case 6:
			return "altý";
			break;			
		case 7:
			return "yedi";
			break;
		case 8:
			return "sekiz";
			break;
		case 9:
			return "dokuz";
			break;
		case 0:
			return "";
			break;
	}
}	

int main() {
	setlocale(LC_ALL, "Turkish");
	cout <<"lütfen sayý giriniz: "<< endl;
	int sayi;
	cin >> sayi;
	cout << yuzler(sayi) <<onlar(sayi) << birler(sayi);
	return 0;

}
