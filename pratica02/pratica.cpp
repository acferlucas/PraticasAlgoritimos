/*
 * pratica.cpp
 *
 *  Created on: 26 de set. de 2022
 *      Author: acfer
 */

#include<iostream>
#include "veiculo.h"

using namespace std;

int main () {

	Veiculo * terr, * aqua, * aereo, * anfi;

	terr = new Terrestre("VT1");
	//((Terrestre *)terr)->setCap_pass(45);
	dynamic_cast<Terrestre *>(terr)->setCap_pass(45);

	terr->mover();

	aqua = new Aquatico("VQ1");
	//((Aquatico *) aqua)->setCarga_max(12.5);
	dynamic_cast<Aquatico *>(aqua)->setCarga_max(12.5);

	aqua->mover();
;
	aereo = new Aereo("VA1");
	((Aereo *) aereo)->setVel_max(1040.5);
	aereo->mover();

	anfi = new Anfibio("Anfi");
	anfi->mover();

	delete terr;
	delete aqua;
	delete aereo;
	delete anfi;

}



