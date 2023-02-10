/*
 * pilha.h
 *
 *  Created on: 18 de jan. de 2023
 *      Author: acfer
 */

#ifndef PILHA_H_
#define PILHA_H_


template<class T>
class Pilha {
protected:
	int capacidade;
public:
	Pilha(int cap):capacidade(cap) {}
	virtual ~Pilha() {}
	virtual void empilha(T item) = 0;
	virtual T desempilha() = 0;
	virtual int tamanho() = 0;
};



#endif /* PILHA_H_ */
