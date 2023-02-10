/*
 * lista.h
 *
 *  Created on: 18 de jan. de 2023
 *      Author: acfer
 */

#ifndef LISTA_H_
#define LISTA_H_

template<class T>
class Lista {
protected:
	int capacidade, tamanhoLista;
public:
	Lista(int capacidade) {
		this->capacidade = capacidade;
		this->tamanhoLista = 0;
	}
	virtual ~Lista() {
	}
	virtual void adiciona(const T &item) = 0;
	virtual T pega(int idx) = 0;
	virtual void insere(int idx, const T &item) = 0;
	virtual void remove(int idx) = 0;
	virtual void exibe() = 0;
	virtual int tamanho() = 0;
};


#endif /* LISTA_H_ */
