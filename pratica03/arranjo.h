/*
 * arranjo.h
 *
 *  Created on: 7 de out. de 2022
 *      Author: acfer
 */

#ifndef ARRANJO_H_
#define ARRANJO_H_

#include<iostream>

using namespace std;


class IndiceInvalido {
	string mensagem;
public:
	IndiceInvalido(string str):mensagem(str) {};
	string getMessage() const {
		return this->mensagem;
	}
};

template <class T>
class Arranjo {
	private:
	int tamanho;
	T * items;

public:
	Arranjo(int tam): tamanho(tam) {
		this->items = new T[tam];
};

	virtual ~Arranjo() {
		delete[] this->items;
};

	virtual T get(int idx) {
		if(idx < 0 || idx > this->tamanho) throw IndiceInvalido("Mensagem de erro");
		return this->items[idx];
};

	virtual void set(int idx, const T & item) {
		if(idx < 0 || idx > this->tamanho) throw IndiceInvalido("Mensagem de erro");
		this->items[idx] = item;
};

	virtual void exibir();
};

template<class T>
void Arranjo<T>::exibir() {
	for(int i = 0; i < this->tamanho; i++) {
		cout << i <<": "<< this->items[i] << endl;
	}
}


#endif /* ARRANJO_H_ */
