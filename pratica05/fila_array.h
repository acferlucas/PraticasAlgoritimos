/*
 * fila.h
 *
 *  Created on: 14 de nov. de 2022
 *      Author: acfer
 */

#ifndef FILA_ARRAY_H_
#define FILA_ARRAY_H_

#include "fila.h"

template<class T>
class FilaArray : public Fila<T> {
private:
	int inicio;
	int final;
	//int elementos;
	//int capacidade;
	T * items;

public:
	FilaArray(int capacidade) : Fila<T>(capacidade) {
		this->items = new T[capacidade];
		this->inicio = 0;
		this->final = capacidade - 1;
	}
	~FilaArray() {
		delete[] this->items;
	}
	void enfileira(T item) {
		if(this->elementos < this->capacidade) {
			this->final = (this->final + 1) % this->capacidade ;
			this->items[this->final] = item;
			this->elementos = this->elementos + 1;

		} else {
			throw "Estouro da Fila";
		};
	}
	T desenfileira() {
		if(this->elementos > 0 ) {
			T item = this->items[this->inicio];
			this->inicio = (this->inicio + 1) % this->capacidade;
			this->elementos = this->elementos - 1;

			return item;
		}else {
			throw "Fila vazia";
		};
	}
	int cheia() {
		if(this->elementos == this->capacidade) {
			return 1;
		}
		return 0;
	};

	int vazia() {
		if(this->elementos == 0) {
			return 1;
		}

		return 0;

	}
	int tamanho() {
		return this->elementos;
	}
};

#endif /* FILA_ARRAY_H_ */
