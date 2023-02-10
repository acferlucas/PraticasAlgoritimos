/*
 * lista_ligada.h
 *
 *  Created on: 18 de jan. de 2023
 *      Author: acfer
 */

#ifndef LISTA_LIGADA_H_
#define LISTA_LIGADA_H_


#include "lista.h"
#include <iostream>
using namespace std;

template<class T>
struct No {
	T dados;
	No *prox;
};

template<class T>
class ListaLigada : public  Lista<T> {
private:
	No<T> *fim;
	No<T> *inicio;
	//int capacidade, tamanhoLista;
public:
	ListaLigada(int capacidade) : Lista<T>(capacidade){
		//this->capacidade = capacidade;
		this->fim = NULL;
		this->inicio = NULL;
		//this->tamanhoLista = 0;
	}
	~ListaLigada() {

		No<T> *temp;
		while (fim != NULL) {
			temp = fim;
			fim = fim->prox;
			temp->prox = NULL;
			delete temp;
		}
		delete inicio;
		delete fim;
		this->tamanhoLista = 0;
	}
	// adiciona um item ao final da lista
	void adiciona(const T &item) {
		const char *erromessage = "list overflow”";
		if (this->tamanhoLista >= this->capacidade) {
			throw erromessage;
		}
		No<T> *novoNo = new No<T>();
		novoNo->dados = item;
		novoNo->prox = NULL;
		if (inicio == NULL) {
			inicio = novoNo;
		} else {
			fim->prox = novoNo;
		}
		fim = novoNo;
		this->tamanhoLista++;

	}
	// pega um item pelo indice (começa em 1);
	T pega(int idx) {
		const char *erromessage = "Item inválido";
		if (idx > this->capacidade || idx < 1) {
			throw erromessage;
		}

		No<T> *temp = inicio;
		idx--;
		while (idx != 0) {
			temp = temp->prox;
			idx--;
		}
		return temp->dados;
	}
	No<T>* pegaNo(int idx) {
		const char *erromessage = "Item inválido";
		if (idx > this->capacidade || idx < 1) {
			throw erromessage;
		}

		No<T> *temp = inicio;
		idx--;
		while (idx != 0) {
			temp = temp->prox;
			idx--;
		}
		return temp;
	}
	// insere um item na posição indicada (a partir de 1).
	void insere(int idx, const T &item) {
		const char *erromessage = "Lista cheia";
		if (this->tamanhoLista >= this->capacidade) {
			throw erromessage;
		}
		No<T> *temp;
		No<T> *novoNo = new No<T>();
		novoNo->dados = item;
		if (idx == 1) {
			novoNo->prox = inicio;
			inicio = novoNo;
		} else {
			temp = pegaNo(idx-1);
			novoNo->prox = temp->prox;
			temp->prox = novoNo;
		}
		this->tamanhoLista++;
	}
	// remove o item de uma posição indicada (a partir de 1)
	void remove(int idx) {
		const char *erromessage = "Item inválido";
		if (idx > this->capacidade || idx < 1) {
			throw erromessage;
		}
		if (this->tamanhoLista <= 0) {
			erromessage = "Lista vazia";
			throw erromessage;
		}
		No<T> *temp;
		if (idx == 1) {
			temp = inicio;
			inicio = temp->prox;
			if (fim == temp) {
				fim = NULL;
			}
		} else {

			No<T> *anterior = pegaNo(idx-1);
			temp = anterior->prox;
			anterior->prox = anterior->prox->prox;
			if (fim == temp) {
				fim = anterior;
			}
		}
		delete temp;
		this->tamanhoLista--;

	}
	void exibe() {
		for (int n = 0; n < this->tamanhoLista; n++) {
			cout << pega(n + 1) << " ";
		}
		cout << endl;
	}
	int tamanho() {
		return this->tamanhoLista;
	}
};


#endif /* LISTA_LIGADA_H_ */
