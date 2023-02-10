/*
 * aluno.h
 *
 *  Created on: 7 de out. de 2022
 *      Author: acfer
 */

#ifndef ALUNO_H_
#define ALUNO_H_

#include<iostream>
using namespace std;

#include"arranjo.h"


class Aluno {

private:
	string nome;
	string mat;

public:
	Aluno() {};
	Aluno(const char * nome, const char * mat) : nome(nome), mat(mat) {};
	friend class Arranjo<Aluno>;
};

template<>
void Arranjo<Aluno>::set(int idx, const Aluno & aluno) {
	//this->items[idx] = aluno;

	this->items[idx].nome = aluno.nome;
	this->items[idx].mat = aluno.mat;
};

template<>
void Arranjo<Aluno>::exibir() {
	for(int i = 0; i < this->tamanho; i++) {
			cout << i <<": "<< this->items[i].mat << " = "<< this->items[i].nome << endl;
	}
};


#endif /* ALUNO_H_ */
