#include <iostream>
#include "soma.hpp"

using std::cout, std::cin, std::endl, std::string;

int main() {
	unsigned long long int num1, num2, soma;

	cout << "Linux Booting..." << endl << endl;


	cout << "Digite numero-1: ";
	cin >> num1;

	cout << "Digite numero-2: ";
	cin >> num2;

	soma = somar(num1, num2);
	cout << "Soma: " << soma << endl;
}