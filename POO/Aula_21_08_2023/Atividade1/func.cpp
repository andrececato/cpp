#include <iostream>

using std::string, std::cout, std::cin, std::getline, std::endl;

string StringPedirNome() {
	string first_name;
	string last_name;
	string full_name;
	cout << "Qual é o seu primeiro nome?" << endl;
	getline(cin, first_name);
	cout << "Qual é o seu sobrenome?" << endl;
	getline(cin, last_name);
	full_name = first_name + " " + last_name;
	return full_name;
}