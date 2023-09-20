#include <iostream>

using std::string, std::cout, std::cin, std::getline, std::endl;

string StringPedirAno() {
	int year;
	cout << "Qual ano: ";
	cin >> year;
	if ((year % 400 == 0) || ((year % 4 == 0) && !(year % 100 == 0))){
		cout << "Ano de " << year << " é bissexto" << endl;
	}
	else{
		cout << "Ano de " << year << " não é bissexto" << endl;
	}
	return "";
}