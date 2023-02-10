/*
 * pratica03.cpp
 *
 *  Created on: 7 de out. de 2022
 *      Author: acfer
 */

#include<iostream>
using namespace std;

#include"funcoes.h"
using namespace funcoes;

#include"arranjo.h"
#include"aluno.h"

int main() {
	float x = 5.5, y = 10.15, z = 30.7;
	cout << "Antes: x = " << x << " y = " << y << endl;

	trocar(x, y);

	cout << "Depois : x = " << x << " y = " << y << endl;
	cout << "Minimo entre " << x << " e " << y << ": " << minimo(x, y) << endl;
	cout << "Maximo entre " << y << " e " << z << ": " << maximo(y, z) << endl;

	cout << "Minimo de \"strA\" e \"strB\": " << minimo("strA", "strB") << endl;
	cout << "Maximo de \"strA\" e \"strB\": " << maximo("strA", "strB") << endl;

	try {
		Arranjo<int> arr(10);
			arr.set(4, 5);
			arr.set(7, 15);
			arr.set(8, 22);
			//arr.exibir();

			cout << endl;

			Arranjo<float> fArr(10);
			fArr.set(4, 5.5);
			fArr.set(7, 15.3);
			fArr.set(9, 22.9);
			fArr.exibir();

			cout << endl;
	}catch(const char *e) {
		cout << e;
	}




	try {

		Arranjo<Aluno> turma(3);
		turma.set(0, Aluno("Joao","1234"));
		turma.set(1, Aluno("Maria","5235"));
		turma.set(2, Aluno("Jose","2412"));
		turma.exibir();

		}catch(const IndiceInvalido e) {
			cout << e.getMessage();
		}

}

