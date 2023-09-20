#include <iostream>

using std::string, std::cout, std::cin, std::getline, std::endl;

void AdicionarNumero(){
	int value = 0;
	cout << "Números digitados: " << endl;
	while(true){
		int local_value;
		cin >> local_value;
		if (local_value >= 0){
			value += local_value;
		}
		else{
			cout << endl;
			cout << "Resposta: " << value << endl;
			break;
		}
	}
}