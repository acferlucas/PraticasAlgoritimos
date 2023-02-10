/*
 * lista.h
 *
 *  Created on: 16 de nov. de 2022
 *      Author: acfer
 */

#ifndef LISTA_H_
#define LISTA_H_

#include <iostream>
using namespace std;

template<class T>
class Lista {
private:
	int elementos;
	int capacidade;
	T *items;
public:
	Lista(int cap) :
			capacidade(cap) {
		this->items = new T[cap];
		this->elementos = 0;
	}
	~Lista() {
		delete[] this->items;
	}
	void adiciona(const T &item) {
		if (this->elementos < this->capacidade) {

			this->items[this->elementos] = item;
			this->elementos = this->elementos + 1;
		} else {
			throw "Lista cheia";
		};

	}
	T pega(int idx) {
		if (idx >= 1 && idx <= this->capacidade) {
			T item = this->items[idx - 1];
			return item;
		} else {
			throw "Item inválido";
		};

	}
	void insere(int idx, const T &item) {
		if (this->elementos < this->capacidade) {
			if (idx >= 1 && idx <= this->capacidade && idx < this->elementos) {
				for (int i = this->elementos; i >= idx; i--) {
					this->items[i] = this->items[i - 1];
				}
				this->items[idx - 1] = item;
				this->elementos = this->elementos + 1;
			} else {
				throw "Item inválido";
			}

		} else {
			throw "Lista Cheia";
		}
	}

	void remove(int idx) {
		if (this->elementos == 0) {
			throw "Lista vazia";
		}

		if (idx >= 1 && idx <= this->capacidade) {

			for (int i = idx - 1; i < this->elementos - 1; i++) {
				this->items[i] = this->items[i + 1];
			}
			this->elementos = this->elementos - 1;

		} else {
			throw "Item inválido";
		};
	}
	void exibe() {
		for (int i = 0; i <= this->elementos; i++) {
			cout << i << ":" << this->items[i] << "   ";
		}

	}
	int tamanho() {
		return this->elementos;
	}
};

#endif /* LISTA_H_ */
