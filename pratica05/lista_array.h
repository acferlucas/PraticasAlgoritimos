/*
 * lista_array.h
 *
 *  Created on: 18 de jan. de 2023
 *      Author: acfer
 */

#ifndef LISTA_ARRAY_H_
#define LISTA_ARRAY_H_

#include "lista.h"
#include <iostream>
using namespace std;

template<class T>
class ListaArray : public  Lista<T> {
private:
	T *items;
	//int capacidade, tamanhoAtual;
public:
	ListaArray(int capacidade) : Lista<T>(capacidade) {
		//this->capacidade = capacidade;
		items = new T[capacidade]();
		//this->tamanhoAtual = 0;
	}
	~ListaArray() {
		delete[] items;
	}
	// adiciona um item ao final da lista
	void adiciona(const T &item) {
		const char *erromessage = "Lista cheia";
		if (this->tamanhoLista >= this->capacidade) {
			throw erromessage;
		}
		items[this->tamanhoLista] = item;
		this->tamanhoLista++;

	}
	// pega um item pelo indice (começa em 1);
	T pega(int idx) {
		const char *erromessage = "Item inválido";
		if (idx > this->capacidade || idx < 1) {
			throw erromessage;
		}
		return items[idx - 1];

	}
	// insere um item na posição indicada (a partir de 1).
	void insere(int idx, const T &item) {
		const char *erromessage = "Lista cheia";
		if (this->tamanhoLista >= this->capacidade) {
			throw erromessage;
		}

		if (idx > this->capacidade || idx < 1) {
			erromessage = "Item inválido";
			throw erromessage;
		}
		for (int n = this->tamanhoLista ; n >= idx ; n--) {
			items[n] = items[n - 1];
		}
		items[idx - 1] = item;
		this->tamanhoLista++;
	}
	// remove o item de uma posição indicada (a partir de 1)
	void remove(int idx) {
		const char *erromessage = "Item inválido";
		if (idx > this->capacidade || idx < 1) {
			throw erromessage;
		}
		if(this->tamanhoLista <= 0){
			erromessage = "Lista vazia";
			throw erromessage;
		}
		for (int n = idx - 1; n < this->tamanhoLista - 1; n++) {
			items[n] = items[n + 1];
		}
		this->tamanhoLista--;

	}
	void exibe() {
		for (int n = 0; n < this->tamanhoLista; n++) {
			cout << this->items[n] << " ";
		}
		cout << endl;
	}
	int tamanho() {
		return this->tamanhoLista;
	}
};



#endif /* LISTA_ARRAY_H_ */
