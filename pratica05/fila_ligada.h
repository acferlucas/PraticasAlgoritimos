/*
 * fila_ligada.h
 *
 *  Created on: 17 de jan. de 2023
 *      Author: acfer
 */

#ifndef FILA_LIGADA_H_
#define FILA_LIGADA_H_

#include <iostream>
#include "fila.h"
using namespace std;

template<class T>
struct Node {
	T data;
	Node *next;
};

template<class T>
class FilaLigada : public Fila<T> {
private:
	Node<T> *inicio;
	Node<T> *final;
	//int elementos;
	//int capacidade;
public:
	FilaLigada(int capacidade) : Fila<T>(capacidade) {
		inicio = nullptr;
		final = nullptr;
	}

	~FilaLigada() {
		while (!IsEmpty()) {
			desenfileira();
		}
	}

	void enfileira(int data) {
		if (this->elementos == this->capacidade) {
			throw "Fila overflow";
		}
		Node<T> *newNode = new Node<T>();
		newNode->data = data;
		newNode->next = nullptr;
		if (inicio == nullptr) {
			inicio = newNode;
			final = newNode;
		} else {
			final->next = newNode;
			final = newNode;
		}
		this->elementos++;
	}

	T desenfileira() {
		if (inicio == nullptr) {
			throw "Fila underflow";
		}

		Node<T> *temp = inicio;
		inicio = inicio->next;

		T item = temp->data;

		if (inicio == nullptr) {
			final = nullptr;
		}
		delete temp;
		this->elementos--;

		return item;
	}

	T Front() {
		if (inicio == nullptr) {
			throw "Queue is empty";
		}
		return inicio->data;
	}

	int tamanho() {
		return this->elementos;
	}

	bool IsEmpty() {
		return (inicio == nullptr);
	}
};

#endif /* FILA_LIGADA_H_ */
