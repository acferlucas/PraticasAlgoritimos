/*
 * fila.h
 *
 *  Created on: 18 de jan. de 2023
 *      Author: acfer
 */

#ifndef FILA_H_
#define FILA_H_


template<class T>
class Fila {
protected:
	int elementos;
	int capacidade;
public:
	Fila(int cap):capacidade(cap) {
		this->elementos = 0;
	}
	virtual ~Fila() {}
	virtual void enfileira(T item) = 0;
	virtual T desenfileira() = 0;
	virtual int tamanho() = 0;
};



#endif /* FILA_H_ */
