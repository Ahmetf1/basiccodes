#include <iostream>
#include <clocale>
using namespace std;
string yuzler(int s){switch(s/100) {  //y�zler basama��n� bulmak i�in fonksiyon
		case 1:
			return "y�z";
			break;
		case 2:
			return "ikiy�z";
			break;
		case 3:
			return "��y�z";
			break;
		case 4:
			return "d�rty�z";
			break;
		case 5:
			return "be�y�z";
			break;
		case 6:
			return "alt�y�z";
			break;			
		case 7:
			return "yediy�z";
			break;
		case 8:
			return "sekizy�z";
			break;
		case 9:
			return "dokuzy�z";
			break;
		case 0:
			return "";
			break;
	}
}
string onlar(int s){switch((s%100)/10) {   //onlar basama��n� bulmak i�in fonksiyon
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
			return "k�rk";
			break;
		case 5:
			return "elli";
			break;
		case 6:
			return "altm��";
			break;			
		case 7:
			return "yetmi�";
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
string birler(int s){switch((s%100)%10) {  //birler basama��n� bulmak i�in fonksiyon
		case 1:
			return "bir";
			break;
		case 2:
			return "iki";
			break;
		case 3:
			return "��";
			break;
		case 4:
			return "d�rt";
			break;
		case 5:
			return "be�";
			break;
		case 6:
			return "alt�";
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
	cout <<"l�tfen say� giriniz: "<< endl;
	int sayi;
	cin >> sayi;
	cout << yuzler(sayi) <<onlar(sayi) << birler(sayi);
	return 0;

}
