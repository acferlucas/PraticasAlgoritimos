/*
 * veiculo.cpp
 *
 *  Created on: 26 de set. de 2022
 *      Author: acfer
 */

#include "veiculo.h"
#include<iostream>

using namespace std;


void Terrestre :: mover() {
	cout << "Veiculo Terrestre " << this->nome <<  " moveu" << endl;
}

void Aquatico :: mover() {
	cout << "Veiculo Aquatico " << this->nome <<  " moveu" << endl;
}

void Aereo :: mover() {
	cout << "Veiculo Aereo " << this->nome <<  " moveu" << endl;
}

void Anfibio :: mover() {
	 Terrestre::mover();
	 Aquatico::mover();
}


void Terrestre :: setCap_pass(int cap){
	this->cap_pass = cap;
};
int Terrestre :: getCap_pass(){
	return this->cap_pass;
};


void  Aquatico :: setCarga_max(int carga) {
	this->carga_max = carga;
}
float Aquatico :: getCarga_max() {
	return this->carga_max;
};


void Aereo :: setVel_max(float vel) {
	this->vel_max = vel;
};

float Aereo :: getVel_max() {
	return this->vel_max;
};


