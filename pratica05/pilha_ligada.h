/*
 * pilha_ligada.h
 *
 *  Created on: 16 de jan. de 2023
 *      Author: acfer
 */

#ifndef PILHA_LIGADA_H_
#define PILHA_LIGADA_H_

#include <iostream>
#include"pilha.h"

using namespace std;

template<class T>
struct Node {
	T data;
	Node *next;
};

template<class T>
class PilhaLigada : public Pilha<T> {
private:
	Node<T> *top;
	int size;
public:
	PilhaLigada(int capacidade): Pilha<T>(capacidade) {
		top = NULL;
		size = 0;
	}

	~PilhaLigada() {
		while (!isEmpty()) {
			desempilha();
		}
	}

	void empilha(T item) {
		if (size == this->capacidade) {
			throw "Estouro da pilha";
			return;
		}
		Node<T> *newNode = new Node<T>();
		newNode->data = item;
		newNode->next = top;
		top = newNode;
		size++;
	}

	T desempilha() {
		if (size == 0) {
			throw "Pilha vazia";
		}
		T item = top->data;
		Node<T> *temp = top;
		top = top->next;
		delete temp;
		size--;
		return item;
	}

	bool isEmpty() {
		return size == 0;
	}

	int tamanho() {

		return this->size;
	}
};

#endif /* PILHA_LIGADA_H_ */
