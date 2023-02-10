/*
 * veiculo.cpp
 *
 *  Created on: 22 de set. de 2022
 *      Author: acfer
 */
#include <iostream>
#include "veiculo.h"

using namespace std;

Veiculo::Veiculo(const char *str){
	this->nome = string(str);
	this->rodas = NULL;

	cout << "Novo Veiculo " << this->nome << " Criado com sucesso!" << endl;
};

int Veiculo::getNumRodas(){
	return this->num_rodas;
}

void Veiculo::setNumRodas(int value) {
	this->num_rodas = value;

	this->rodas = new Roda[value];
};


