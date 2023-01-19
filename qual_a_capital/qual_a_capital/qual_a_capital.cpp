#include <iostream>
#include <string> 
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "pt_BR.UTF-8");

	string capitais[27][3] = {
		{"Alemanha", "Berlim", "berlim"}, {"Austria", "Viena", "viena"}, {"Belgica", "Bruxelas", "bruxelas"}, {"Bulgaria", "Sofia", "sofia"}, {"Chequia", "Praga", "praga"},
		{"Chipre", "Nicosia", "nicosia"}, {"Croacia", "Zagreb", "zagreb"}, {"Dinamarca", "Copenhagem", "copenhagem"}, {"Eslovaquia", "Bratislava", "bratislava"},
		{"Eslovenia", "Liubliana", "liubliana"}, {"Espanha", "Madrid", "madrid"}, {"Estonia", "Tallinn", "tallinn"}, {"Finlandia", "Helsinque", "helsinque"},
		{"Franca", "Paris", "paris"}, {"Grecia", "Atenas", "atenas"},{"Hungria", "Budapeste", "budapeste"}, {"Irlanda", "Dublin", "dublin"}, {"Italia", "Roma", "roma"},
		{"Letonia", "Riga", "riga"}, {"Lituania", "Vilnius", "vilnius"}, {"Luxemburgo", "Luxemburgo", "luxemburgo"}, {"Malta", "Valeta", "valeta"},
		{"Paises Baixos", "Amsterda", "amsterda"}, {"Polonia", "Varsovia", "varsovia"}, {"Portugal", "Lisboa", "lisboa"}, {"Romenia", "Bucareste", "bucareste"},
		{"Suecia", "Estocolmo", "estocolmo"}
	};

	fstream myFile;
	char resposta = ' ';

	cout << "Voce tera 3 chances para acertar a capital do pais selecionado. Vamos comecar!\n";


	do {
		string respostaUser;
		int tentativa = 0;
		int num = 0;
		srand(time(NULL));
		num = rand() % 26;
		//num = 0;


		cout << "Qual a capital da(o) " << capitais[num][0] << "?\n";
		//cout << capitais[num][1] << "\n\n";


		for (; tentativa <= 2; tentativa++) {
			cin >> respostaUser;

			if (respostaUser != capitais[num][1]) {
				if (tentativa == 2)
					break;
				cout << "\nVoce errou! Tente novamente.\n";
			}
			else if (respostaUser == capitais[num][1]) {
				cout << "\nVoce acertou! ";
				break;
			}

		}


		if (tentativa < 3) {
			cout << "A capital e': " << capitais[num][1] << ". Veja algumas informacoes sobre a cidade: " << endl;
		}


		myFile.open("capitais\\" + capitais[num][2] + ".txt", ios::in);
		string linha;
		while (getline(myFile, linha)) {
			cout << endl << linha << endl;
		}
		myFile.close();


		cout << "\n\nDeseja jogar novamente? Indique S para sim ou N para nao.\n";
		cin >> resposta;

		resposta = toupper(resposta);

	} while (resposta == 'S');











}
