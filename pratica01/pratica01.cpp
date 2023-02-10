#include <iostream>
#include "veiculo.h"

using namespace std;

//class Veiculo {
//	string nome;
//	int num_rodas = 0;
//public:
//	Veiculo(const char *str);
//	~Veiculo() {
//		cout << "Veiculo " << this->nome << " Destruido" << endl;
//	};
//
//	 void setNumRodas(int value);
//	 int getNumRodas();
//
//	string getName(){
//		return this->nome;
//	};
//
//};




int main() {

	Veiculo carro("Corolla");

	carro.setNumRodas(4);

	cout << "Num de rodas " << carro.getNumRodas() << endl;


//	{
//		Veiculo * obj1 = new Veiculo("v1");
//		{
//			Veiculo * obj2 = new Veiculo("v2");
//				{
//					Veiculo * obj3 = new Veiculo("v3");
//					delete obj3;
//				}
//				delete obj2;
//		}
//		delete obj1;
//	}

//	{
//		Veiculo veiculo1("v1");
//			{
//				Veiculo veiculo2("v2");
//					{
//						Veiculo veiculo3("v3");
//					}
//			}
//		}
}

