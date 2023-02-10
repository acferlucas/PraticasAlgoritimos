/*
 * funcoes.h
 *
 *  Created on: 7 de out. de 2022
 *      Author: acfer
 */

#ifndef FUNCOES_H_
#define FUNCOES_H_

#include <cstring>

#include<iostream>

namespace funcoes {

	template <class T>
	void trocar(T & a, T & b) {
		T value = a;
		a = b;
		b = value;
	};

	template <class T>
	T maximo(const T a, const T b) {
		return a >= b ? a : b;
	};

	template <>
	const char * maximo(const char *a, const char *b) {
		if (strcmp(a ,b) < 0) {
				return a;
		 }
		 return b;
	};

	template <class T>
	T minimo(const T a, const T b) {
		return a < b ? a : b;
	};

	template <>
	const char * minimo(const char *a, const char *b) {
		if (strcmp(a ,b) < 0) {
				return b;
		 }
		 return a;
	};
}

#endif /* FUNCOES_H_ */
