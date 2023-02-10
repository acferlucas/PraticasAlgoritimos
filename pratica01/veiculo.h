/*
 * veiculo.h
 *
 *  Created on: 22 de set. de 2022
 *      Author: acfer
 */

#include <iostream>

using namespace std;

#ifndef VEICULO_H_
#define VEICULO_H_


class Roda {
public:
	Roda(){
		cout << "Objeto do tipo Roda construido" << endl;
	}
	~Roda(){
			cout << "Objeto do tipo Roda DESTRUIDO" << endl;
		}
};


class Veiculo {
	string nome;
	int num_rodas = 0;
	Roda * rodas;

public:
	Veiculo(const char *str);
	~Veiculo() {
		delete[] rodas;
		cout << "Veiculo " << this->nome << " Destruido" << endl;
	};

	 void setNumRodas(int value);
	 int getNumRodas();

	string getName() {
		return this->nome;
	};

};


#endif /* VEICULO_H_ */
