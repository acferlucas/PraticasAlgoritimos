/*
 * veiculo.h
 *
 *  Created on: 26 de set. de 2022
 *      Author: acfer
 */

#ifndef VEICULO_H_
#define VEICULO_H_


#include<iostream>

using namespace std;

class Veiculo {
protected:
	string nome;

public:
	Veiculo(const char *str): nome(string(str)) {

		cout << "Novo Veiculo " << this->nome << " Criado com sucesso!" << endl;
	};

	virtual void mover() = 0;

	virtual ~Veiculo(){
		cout << "Veiculo " << this->nome << " Destruido" << endl;
	};


};


class Terrestre :  public virtual Veiculo {
private:
	int cap_pass = 5;

protected:
	Terrestre(): Veiculo("Qualquer_nome_terrestre"){
		cout << "chamou o construtor protegido de Terrestre" << endl;
	};

public:
	Terrestre(const char *str): Veiculo(str) {
		cout << "Veiculo Terrestre " << this->nome  << " Criado com sucesso!" << endl;
	};

	void setCap_pass(int cap);
	int getCap_pass();

	void mover();

	virtual ~Terrestre(){
		cout << "Veiculo Terrestre :" << this->nome << " Destruido" << endl;
	};

};


class Aquatico :  public virtual Veiculo {
private:
	float carga_max = 10;
protected:
	Aquatico(): Veiculo("Qualquer_nome_aquatico"){
		cout << "chamou o construtor protegido de Terrestre " << endl;
	};
public:
	Aquatico(const char *str): Veiculo(str) {
		cout << "Veiculo Aquatico :" << this->nome  << " Criado com sucesso!" << endl;
	};

	void setCarga_max(int carga);
	float getCarga_max();

	void mover();

	virtual ~Aquatico(){
		cout << "Veiculo Aquatico : " << this->nome << " Destruido" << endl;
	};
};


class Aereo : public Veiculo {
private:
	float vel_max = 100;
public:
	Aereo(const char *str) : Veiculo(str){
		cout << "Veiculo Aereo :" << this->nome  << " Criado com sucesso!" << endl;
	};

	void setVel_max(float vel);
	float getVel_max();

	void mover();

	virtual ~Aereo(){
		cout << "Veiculo Aereo : " << this->nome << " Destruido" << endl;
	};

};

class Anfibio : public Terrestre, public Aquatico {
public:
	Anfibio (const char * nome) : Veiculo("Anfibio"), Terrestre(), Aquatico() {
		cout << "Construtor de Anfibio.."  << endl;
	};

	void mover();
};




#endif /* VEICULO_H_ */
