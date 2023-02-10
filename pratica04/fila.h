/*
 * fila.h
 *
 *  Created on: 14 de nov. de 2022
 *      Author: acfer
 */

#ifndef FILA_H_
#define FILA_H_

template<class T>
class Fila {
private:
	int inicio;
	int final;
	int elementos;
	int capacidade;
	T * items;

public:
	Fila(int cap): capacidade(cap) {
		this->items = new T[cap];
		this->inicio = 0;
		this->elementos = 0;
		this->final = capacidade - 1;
	}
	~Fila() {
		delete[] this->items;
	}
	void enfileira(const T &item) {
		if(this->elementos < this->capacidade) {
			this->final = (this->final + 1) % this->capacidade ;
			this->items[this->final] = item;
			this->elementos = this->elementos + 1;

		} else {
			throw "Estouro da pilha";
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

#endif /* FILA_H_ */
