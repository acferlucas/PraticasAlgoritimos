/*
 * pilha2.h
 *
 *  Created on: 17 de out. de 2022
 *      Author: acfer
 */

#ifndef PILHA_ARRAY_H_
#define PILHA_ARRAY_H_

#include<iostream>
#include"pilha.h"
using namespace std;

template<class T>
class PilhaArray : public Pilha<T> {
private:
	T *items;
	int topo;
	//int capacidade;
public:
	PilhaArray(int capacidade): Pilha<T>(capacidade) {
		this->items = new T[capacidade];
		this->topo = -1;
	}

	~PilhaArray() {
		delete[] this->items;
	}

	void empilha(T item) {
		if (topo < this->capacidade && item < this->capacidade) {
			//cout << "Adicionando..." << item << endl;
			this->topo++;
			this->items[this->topo] = item;
		} else {
			throw "Estouro da pilha";
		}

	}

	T desempilha() {
		if ( this->topo == -1 ) {
			throw "Pilha vazia";
		}

		T item;
		item = this->items[this->topo--];

		return item;

	}

	int tamanho() {
		return this->topo + 1;
	}

};

#endif /* PILHA_ARRAY_H_ */
