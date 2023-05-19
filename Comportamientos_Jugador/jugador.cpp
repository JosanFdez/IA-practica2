#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <queue>

/*Nivel 0*/
void AnularMatriz(vector<vector<unsigned char>> &matriz);
ubicacion NextCasilla(const ubicacion &pos);
list<Action> AvanzaASaltosDeCaballo();
bool CasillaTransitable(const ubicacion &x, const vector<vector<unsigned char>> &mapa);
stateN0 apply(const Action &a, const stateN0 &st, const vector<vector<unsigned char>> &mapa);
bool Find(const stateN0 &item, const list<stateN0> &lista);
bool Find(const stateN0 &item, const list<nodeN0> &lista);
list<Action> AnchuraSoloJugador(const stateN0 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa);


void ComportamientoJugador::VisualizaPlan(const stateN0 &st, const list<Action> &plan){

	AnularMatriz(mapaConPlan);
	stateN0 cst = st;

	auto it = plan.begin();

	while (it != plan.end()){

		switch (*it){

			case actFORWARD:
				cst.jugador = NextCasilla(cst.jugador);
				mapaConPlan[cst.jugador.f][cst.jugador.c] = 1;
				break;

			case actTURN_R:
				cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 2) % 8);
				break;

			case actTURN_L:
				cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 6) % 8);
				break;

			case actSON_FORWARD:
				cst.sonambulo = NextCasilla(cst.sonambulo);
				mapaConPlan[cst.sonambulo.f][cst.sonambulo.c] = 2;
				break;

			case actSON_TURN_SR:
				cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 1) % 8);
				break;

			case actSON_TURN_SL:
				cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 7) % 8);
				break;
		}
		it++;
	}
}

void ComportamientoJugador::VisualizaPlan1(const stateN1 &st, const list<Action> &plan){

	AnularMatriz(mapaConPlan);
	stateN1 cst = st;

	auto it = plan.begin();

	while (it != plan.end()){

		switch (*it){

			case actFORWARD:
				cst.jugador = NextCasilla(cst.jugador);
				mapaConPlan[cst.jugador.f][cst.jugador.c] = 1;
				break;

			case actTURN_R:
				cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 2) % 8);
				break;

			case actTURN_L:
				cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 6) % 8);
				break;

			case actSON_FORWARD:
				cst.sonambulo = NextCasilla(cst.sonambulo);
				mapaConPlan[cst.sonambulo.f][cst.sonambulo.c] = 2;
				break;

			case actSON_TURN_SR:
				cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 1) % 8);
				break;

			case actSON_TURN_SL:
				cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 7) % 8);
				break;
		}
		it++;
	}
}

void ComportamientoJugador::VisualizaPlan2(const stateN2 &st, const list<Action> &plan){

	AnularMatriz(mapaConPlan);
	stateN2 cst = st;

	auto it = plan.begin();

	while (it != plan.end()){

		switch (*it){

			case actFORWARD:
				cst.jugador = NextCasilla(cst.jugador);
				mapaConPlan[cst.jugador.f][cst.jugador.c] = 1;
				break;

			case actTURN_R:
				cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 2) % 8);
				break;

			case actTURN_L:
				cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 6) % 8);
				break;

			case actSON_FORWARD:
				cst.sonambulo = NextCasilla(cst.sonambulo);
				mapaConPlan[cst.sonambulo.f][cst.sonambulo.c] = 2;
				break;

			case actSON_TURN_SR:
				cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 1) % 8);
				break;

			case actSON_TURN_SL:
				cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 7) % 8);
				break;
		}
		it++;
	}
}

void ComportamientoJugador::VisualizaPlan3(const stateN3 &st, const list<Action> &plan){

	AnularMatriz(mapaConPlan);
	stateN3 cst = st;

	auto it = plan.begin();

	while (it != plan.end()){

		switch (*it){

			case actFORWARD:
				cst.jugador = NextCasilla(cst.jugador);
				mapaConPlan[cst.jugador.f][cst.jugador.c] = 1;
				break;

			case actTURN_R:
				cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 2) % 8);
				break;

			case actTURN_L:
				cst.jugador.brujula = (Orientacion)((cst.jugador.brujula + 6) % 8);
				break;

			case actSON_FORWARD:
				cst.sonambulo = NextCasilla(cst.sonambulo);
				mapaConPlan[cst.sonambulo.f][cst.sonambulo.c] = 2;
				break;

			case actSON_TURN_SR:
				cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 1) % 8);
				break;

			case actSON_TURN_SL:
				cst.sonambulo.brujula = (Orientacion)((cst.sonambulo.brujula + 7) % 8);
				break;
		}
		it++;
	}
}


int ComportamientoJugador::interact(Action accion, int valor){

    return false;
}

void AnularMatriz(vector<vector<unsigned char>> &matriz){

    for (int i = 0; i < matriz.size(); i++){

        for (int j = 0; j < matriz[0].size(); j++)

            matriz[i][j] = 0;
	}
}

ubicacion NextCasilla(const ubicacion &pos){

    ubicacion next = pos;

	switch (pos.brujula){

        case norte:
			next.f = pos.f-1;
			break;

		case noreste:
			next.f = pos.f-1;
			next.c = pos.c+1;
			break;

		case este:
			next.c = pos.c+1;
			break;

		case sureste:
			next.f = pos.f+1;
			next.c = pos.c+1;
			break;

		case sur:
			next.f = pos.f+1;
			break;

		case suroeste:
			next.f = pos.f+1;
			next.c = pos.c-1;
			break;

		case oeste:
			next.c = pos.c-1;
			break;

		case noroeste:
			next.f = pos.f-1;
			next.c = pos.c-1;
			break;
	}
	return next;
}

bool CasillaTransitable(const ubicacion &x, const vector<vector<unsigned char>> &mapa){

    return (mapa[x.f][x.c] != 'P' and mapa[x.f][x.c] != 'M');
}

/*Nivel 1*/
bool viendoSonambulo(const stateN1 & st){

	bool viendo = false;
	switch (st.jugador.brujula){

		case norte:

			if(st.jugador.f == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 2 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else {
				viendo = false;
			}
		break;

		case sur:
			if(st.jugador.f == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 2 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else {
				viendo = false;
			}


		break;

		case oeste:

			if(st.jugador.f == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 3 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 3 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else {

				viendo = false;
			}
		break;

		case este:

			if(st.jugador.f == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 3 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 3 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else {

				viendo = false;
			}
		break;
	}

	return viendo;

}

/*Nivel 3 y 4*/

bool viendoSonambuloN3(const stateN3 & st){

	bool viendo = false;
	switch (st.jugador.brujula){

		case norte:

			if(st.jugador.f == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 2 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f - 3 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else {
				viendo = false;
			}
		break;

		case sur:
			if(st.jugador.f == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 2 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if (st.jugador.f + 3 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else {
				viendo = false;
			}


		break;

		case oeste:

			if(st.jugador.f == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c - 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c - 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 3 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 3 == st.sonambulo.f and st.jugador.c - 3 == st.sonambulo.c){

				viendo = true;
			}
			else {

				viendo = false;
			}
		break;

		case este:

			if(st.jugador.f == st.sonambulo.f and st.jugador.c == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c + 1 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c + 2 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 3 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 2 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f - 1 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 1 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 2 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else if(st.jugador.f + 3 == st.sonambulo.f and st.jugador.c + 3 == st.sonambulo.c){

				viendo = true;
			}
			else {

				viendo = false;
			}
		break;
	}

	return viendo;

}

/*Nivel 2*/

int coste_accion(const Action a, const stateN2 & st, const vector<vector<unsigned char>> &mapa){

	int coste = 1;

	char tipo_casilla = mapa[st.jugador.f][st.jugador.c];

	switch (tipo_casilla){

		case 'A':

			if(st.bikini){

				if(a == actFORWARD){

					coste = 10;
				}

				if(a == actTURN_L or a == actTURN_R){

					coste = 5;
				}
			}
			else{

				if(a == actFORWARD){

					coste = 100;
				}

				if(a == actTURN_L or a == actTURN_R){

					coste = 25;
				}
			}

		break;

		case 'B':

			if(st.zapatillas){

				if(a == actFORWARD){

					coste = 15;
				}

				if(a == actTURN_L or a == actTURN_R){

					coste = 1;
				}
			}
			else{
				if(a == actFORWARD){

					coste = 50;
				}

				if(a == actTURN_L or a == actTURN_R){

					coste = 5;
				}
			}

		break;

		case 'T':

			coste = 2;
		break;

	}

	return coste;

}

/*Nivel 3 y 4*/

int coste_accionJ(const Action a, const stateN3 & st, const vector<vector<unsigned char>> &mapa){

	int coste = 1;

	char tipo_casilla = mapa[st.jugador.f][st.jugador.c];

	switch (tipo_casilla){

		case 'A':

			if(st.j_bikini){

				if(a == actFORWARD){

					coste = 10;
				}

				if(a == actTURN_L or a == actTURN_R){

					coste = 5;
				}
			}
			else{

				if(a == actFORWARD){

					coste = 100;
				}

				if(a == actTURN_L or a == actTURN_R){

					coste = 25;
				}
			}

		break;

		case 'B':
			if(st.j_zapatillas){

				if(a == actFORWARD){

					coste = 15;
				}

				if(a == actTURN_L or a == actTURN_R){

					coste = 1;
				}
			}
			else{
				if(a == actFORWARD){

					coste = 50;
				}

				if(a == actTURN_L or a == actTURN_R){

					coste = 5;
				}
			}

		break;

		case 'T':

			coste = 2;
		break;

	}

	return coste;

}


int coste_accionS(const Action a, const stateN3 & st, const vector<vector<unsigned char>> &mapa){

	int coste = 1;

	char tipo_casilla = mapa[st.sonambulo.f][st.sonambulo.c];

	switch (tipo_casilla){

		case 'A':
			if(st.s_bikini){

				if(a == actSON_FORWARD){

					coste = 10;
				}

				if(a == actSON_TURN_SL or a == actSON_TURN_SR){

					coste = 2;
				}
			}
			else{

				if(a == actSON_FORWARD){

					coste = 100;
				}

				if(a == actSON_TURN_SL or a == actSON_TURN_SR){

					coste = 7;
				}
			}

		break;

		case 'B':
			if(st.s_zapatillas){

				if(a == actSON_FORWARD){

					coste = 15;
				}

				if(a == actSON_TURN_SL or a == actSON_TURN_SR){

					coste = 1;
				}
			}
			else{
				if(a == actSON_FORWARD){

					coste = 50;
				}

				if(a == actSON_TURN_SL or a == actSON_TURN_SR){

					coste = 3;
				}
			}

		break;

		case 'T':
			if(a == actSON_FORWARD){

				coste = 2;
			}

			else if(a == actSON_TURN_SL or a == actSON_TURN_SR){

				coste = 1;
			}
		break;
	}

	return coste;

}

int heuristicaChebyshev(ubicacion x1, ubicacion x2){

	return max(abs(x1.f - x2.f), abs(x1.c - x2.c));
}

stateN0 apply(const Action &a, const stateN0 &st, const vector<vector<unsigned char>> &mapa){

    stateN0 st_result = st;
	ubicacion sig_ubicacion;

	switch (a){

        case actFORWARD:
			sig_ubicacion = NextCasilla(st.jugador);
			if (CasillaTransitable(sig_ubicacion, mapa) and
				!(sig_ubicacion.f == st.sonambulo.f and sig_ubicacion.c == st.sonambulo.c))
				st_result.jugador = sig_ubicacion;
		break;

		case actTURN_L:
			st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 6) % 8);
		break;

		case actTURN_R:
			st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 2) % 8);
		break;
	}
	return st_result;
}

stateN1 apply1(const Action &a, const stateN1 &st, const vector<vector<unsigned char>> &mapa){

	stateN1 st_result = st;
	ubicacion sig_ubi;

	switch (a) {

		case actFORWARD:

			sig_ubi = NextCasilla(st.jugador);

			if(CasillaTransitable(sig_ubi, mapa) and !(sig_ubi.f == st.sonambulo.f and sig_ubi.c == st.sonambulo.c)){

				st_result.jugador = sig_ubi;
			}
		break;

		case actTURN_L:

			st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 6) % 8);
		break;

		case actTURN_R:

			st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 2) % 8);
		break;

		case actSON_FORWARD:

			sig_ubi = NextCasilla(st.sonambulo);

			if(CasillaTransitable(sig_ubi, mapa) and !(sig_ubi.f == st.jugador.f and sig_ubi.c == st.jugador.c)){

				st_result.sonambulo = sig_ubi;
			}

		break;

		case actSON_TURN_SL:

			st_result.sonambulo.brujula = static_cast<Orientacion>((st_result.sonambulo.brujula + 7) % 8);

		break;

		case actSON_TURN_SR:

			st_result.sonambulo.brujula = static_cast<Orientacion>((st.sonambulo.brujula + 1) % 8);

		break;

	}

	return st_result;
}

stateN2 apply2 (const Action &a, const stateN2 &st, const vector<vector<unsigned char>> &mapa) {

	stateN2 st_result = st;
	ubicacion sig_ubi;

	switch(a){

		case actFORWARD:

			sig_ubi = NextCasilla(st.jugador);

			if(CasillaTransitable(sig_ubi, mapa) and !(sig_ubi.f == st.sonambulo.f and sig_ubi.c == st.sonambulo.c)){

				st_result.jugador = sig_ubi;
			}
		break;

		case actTURN_L:

			st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 6) % 8);
		break;

		case actTURN_R:

			st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 2) % 8);
		break;
	}

	return st_result;
}

stateN3 apply3(const Action &a, const stateN3 &st, const vector<vector<unsigned char>> &mapa){

	stateN3 st_result = st;
	ubicacion sig_ubi;

	switch (a) {

		case actFORWARD:

			sig_ubi = NextCasilla(st.jugador);

			if(CasillaTransitable(sig_ubi, mapa) and !(sig_ubi.f == st.sonambulo.f and sig_ubi.c == st.sonambulo.c)){

				st_result.jugador = sig_ubi;
			}
		break;

		case actTURN_L:

			st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 6) % 8);
		break;

		case actTURN_R:

			st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula + 2) % 8);
		break;

		case actSON_FORWARD:

			sig_ubi = NextCasilla(st.sonambulo);

			if(CasillaTransitable(sig_ubi, mapa) and !(sig_ubi.f == st.jugador.f and sig_ubi.c == st.jugador.c)){

				st_result.sonambulo = sig_ubi;
			}

		break;

		case actSON_TURN_SL:

			st_result.sonambulo.brujula = static_cast<Orientacion>((st_result.sonambulo.brujula + 7) % 8);

		break;

		case actSON_TURN_SR:

			st_result.sonambulo.brujula = static_cast<Orientacion>((st.sonambulo.brujula + 1) % 8);

		break;

	}

	return st_result;
}

/*Nivel 0*/

list<Action> AnchuraSoloJugador(const stateN0 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa){

    nodeN0 current_node;
	list<nodeN0> frontier;
	set<nodeN0> explored;
	list<Action> plan;
	current_node.st = inicio;
	frontier.push_back(current_node);
	bool SolutionFound = (current_node.st.jugador.f == final.f and current_node.st.jugador.c == final.c);

	while (!frontier.empty() and !SolutionFound){

        frontier.pop_front();
		explored.insert(current_node);

		//Generar hijo actFORWARD
		nodeN0 child_forward = current_node;
		child_forward.st = apply(actFORWARD, current_node.st, mapa);

		if (child_forward.st.jugador.f == final.f and child_forward.st.jugador.c == final.c){

            child_forward.secuencia.push_back(actFORWARD);
			current_node = child_forward;
			SolutionFound = true;
		}
		else if (explored.find(child_forward) == explored.end()){

            child_forward.secuencia.push_back(actFORWARD);
			frontier.push_back(child_forward);
		}


		if (!SolutionFound){
			//Generar hijo actTURN_L
			nodeN0 child_turnl = current_node;
			child_turnl.st = apply(actTURN_L, current_node.st, mapa);

			if (explored.find(child_turnl) == explored.end()){

                child_turnl.secuencia.push_back(actTURN_L);
				frontier.push_back(child_turnl);
			}


			//Generar hijo actTURN_R
			nodeN0 child_turnr = current_node;
			child_turnr.st = apply(actTURN_R, current_node.st, mapa);

			if (explored.find(child_turnr) == explored.end()){

                child_turnr.secuencia.push_back(actTURN_R);
				frontier.push_back(child_turnr);
			}

		}

		if (!SolutionFound and !frontier.empty()){

            current_node = frontier.front();
        }
        while(!frontier.empty() and explored.find(current_node) != explored.end()){

            frontier.pop_front();

            if(!frontier.empty()){

                current_node = frontier.front();
            }
      	}
	}

	if (SolutionFound){

        plan = current_node.secuencia;
    }

	return plan;
}

/*Nivel 1*/

list<Action> AnchuraSonambulo(const stateN1 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa){

	nodeN1 current_node; 	// estado nodo actual tanto jugador como sonámbulo
	list<nodeN1> frontier;	// lista de nodos abiertos, nodos pendientes
	set<nodeN1> explored;	// lista de nodos cerrados, ya explorados
	list<Action> plan;		// Secuencia de acciones para conseguir el objetivo
	bool visto;

	current_node.st = inicio;
	frontier.push_back(current_node);
	bool SolutionFound = (current_node.st.sonambulo.f == final.f and current_node.st.sonambulo.c == final.c);

	while (!frontier.empty() and !SolutionFound){

		frontier.pop_front();
		explored.insert(current_node);
		visto = viendoSonambulo(current_node.st);

		if(visto){

			//Generar hijo del sonámbulo actFORWARD
			nodeN1 childSON_forward = current_node;
			childSON_forward.st = apply1(actSON_FORWARD, current_node.st, mapa);

			if(childSON_forward.st.sonambulo.f == final.f and childSON_forward.st.sonambulo.c == final.c){

				childSON_forward.secuencia.push_back(actSON_FORWARD);
				current_node = childSON_forward;
				SolutionFound = true;
			}
			else if(explored.find(childSON_forward) == explored.end()){

				childSON_forward.secuencia.push_back(actSON_FORWARD);
				frontier.push_back(childSON_forward);

			}

			if(!SolutionFound){

				// Para el sonámbulo hijo turn_sl
				nodeN1 child_son_turn_sl = current_node;
				child_son_turn_sl.st = apply1(actSON_TURN_SL, current_node.st, mapa);

				if(explored.find(child_son_turn_sl) == explored.end()){

					child_son_turn_sl.secuencia.push_back(actSON_TURN_SL);
					frontier.push_back(child_son_turn_sl);
				}

				//Para el sonámbulo hijo Turn_sr
				nodeN1 child_son_turn_sr = current_node;
				child_son_turn_sr.st = apply1(actSON_TURN_SR, current_node.st, mapa);

				if(explored.find(child_son_turn_sr) == explored.end()){

					child_son_turn_sr.secuencia.push_back(actSON_TURN_SR);
					frontier.push_back(child_son_turn_sr);
				}
			}
		}

		// Para el jugador hijo Forward
			nodeN1 child_forward = current_node;
			child_forward.st = apply1(actFORWARD, current_node.st, mapa);

			if(explored.find(child_forward) == explored.end()){

				child_forward.secuencia.push_back(actFORWARD);
				frontier.push_back(child_forward);
			}

			// Para el jugador hijo Turn_l
			nodeN1 child_turnl = current_node;
			child_turnl.st = apply1(actTURN_L, current_node.st, mapa);

			if(explored.find(child_turnl) == explored.end()){

				child_turnl.secuencia.push_back(actTURN_L);
				frontier.push_back(child_turnl);
			}

			// Para el jugador hijo Turn_r
			nodeN1 child_turnr = current_node;
			child_turnr.st = apply1(actTURN_R, current_node.st, mapa);

			if(explored.find(child_turnr) == explored.end()){

				child_turnr.secuencia.push_back(actTURN_R);
				frontier.push_back(child_turnr);
			}

			if (!SolutionFound and !frontier.empty()){

				current_node = frontier.front();


				while(!frontier.empty() and explored.find(current_node) != explored.end()){

					frontier.pop_front();

					if(!frontier.empty()){

						current_node = frontier.front();
					}
				}
			}

	}

	if (SolutionFound){

        plan = current_node.secuencia;
    }

	return plan;
}


/*Nivel 2*/

list<Action> CosteUniformeJugador(const stateN2 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa){

	nodeN2 current_node; 	// estado nodo actual tanto jugador como sonámbulo
	priority_queue<nodeN2> frontier;	// lista de nodos abiertos, nodos pendientes en una cola con prioridad
	set<stateN2> explored;	// lista de nodos cerrados, ya explorados
	list<Action> plan;		// Secuencia de acciones para conseguir el objetivo

	current_node.st = inicio;
	frontier.push(current_node);

	bool SolutionFound = (current_node.st.jugador.f == final.f and current_node.st.jugador.c == final.c);

	while (!frontier.empty() and !SolutionFound){

		frontier.pop();
		explored.insert(current_node.st);

		if(mapa[current_node.st.jugador.f][current_node.st.jugador.c] == 'K'){

			current_node.st.bikini = true;

			if(current_node.st.zapatillas){

				current_node.st.zapatillas = false;
			}
		}

		if(mapa[current_node.st.jugador.f][current_node.st.jugador.c] == 'D'){

			current_node.st.zapatillas = true;

			if(current_node.st.bikini){

				current_node.st.bikini = false;
			}
		}

		//Generar hijo actFORWARD
		nodeN2 child_forward = current_node;
		child_forward.st = apply2(actFORWARD, current_node.st, mapa);
		child_forward.st.coste_acumulado += coste_accion(actFORWARD, current_node.st, mapa);

		if (explored.find(child_forward.st) == explored.end()){

            child_forward.secuencia.push_back(actFORWARD);
			frontier.push(child_forward);
		}

		//Generar hijo actTurnl
		nodeN2 child_turnl = current_node;
		child_turnl.st = apply2(actTURN_L, current_node.st, mapa);
		child_turnl.st.coste_acumulado += coste_accion(actTURN_L, current_node.st, mapa);

		if (explored.find(child_turnl.st) == explored.end()){

            child_turnl.secuencia.push_back(actTURN_L);
			frontier.push(child_turnl);
		}

		//Generar hijo actTurnr
		nodeN2 child_turnr = current_node;
		child_turnr.st = apply2(actTURN_R, current_node.st, mapa);
		child_turnr.st.coste_acumulado += coste_accion(actTURN_R, current_node.st, mapa);

		if(explored.find(child_turnr.st) == explored.end()){

			child_turnr.secuencia.push_back(actTURN_R);
			frontier.push(child_turnr);
		}

		if (!SolutionFound and !frontier.empty()){

            current_node = frontier.top();

			while(!frontier.empty() and explored.find(current_node.st) != explored.end()){

				frontier.pop();
				current_node = frontier.top();
			}
			if (current_node.st.jugador.f == final.f and current_node.st.jugador.c == final.c){

				SolutionFound = true;
			}

        }

	}
	if (SolutionFound){

        plan = current_node.secuencia;
    }

	return plan;
}


/*Nivel 3*/

list<Action> AEstrella(const stateN3 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa){

	nodeN3 current_node; 				// estado nodo actual tanto jugador como sonámbulo
	priority_queue<nodeN3> frontier;	// lista de nodos abiertos, nodos pendientes en una cola con prioridad
	set<stateN3> explored;				// lista de nodos cerrados, ya explorados
	list<Action> plan;					// Secuencia de acciones para conseguir el objetivo
	bool visto; 						// Indicará si el sonámbulo está o no en nuestra visión

	current_node.st = inicio;
	frontier.push(current_node);
	bool SolutionFound = (current_node.st.sonambulo.f == final.f and current_node.st.sonambulo.c == final.c);

	while (!frontier.empty() and !SolutionFound){

		frontier.pop();
		explored.insert(current_node.st);
		visto = viendoSonambuloN3(current_node.st);

		if(visto){

			if(mapa[current_node.st.sonambulo.f][current_node.st.sonambulo.c] == 'K'){

				current_node.st.s_bikini = true;

				if(current_node.st.s_zapatillas){

					current_node.st.s_zapatillas = false;
				}
			}

			if(mapa[current_node.st.sonambulo.f][current_node.st.sonambulo.c] == 'D'){

				current_node.st.s_zapatillas = true;

				if(current_node.st.s_bikini){

					current_node.st.s_bikini = false;
				}
			}

			//Generar hijo del sonámbulo actFORWARD
			nodeN3 childSON_forward = current_node;
			childSON_forward.st = apply3(actSON_FORWARD, current_node.st, mapa);
			childSON_forward.st.coste_acumulado += coste_accionS(actSON_FORWARD, current_node.st, mapa);
			childSON_forward.st.valor_heuristica = heuristicaChebyshev(childSON_forward.st.sonambulo, final);
			childSON_forward.st.v_total = childSON_forward.st.coste_acumulado + childSON_forward.st.valor_heuristica;

			if(explored.find(childSON_forward.st) == explored.end()){

				childSON_forward.secuencia.push_back(actSON_FORWARD);
				frontier.push(childSON_forward);

			}

			if(!SolutionFound){

				// Para el sonámbulo hijo turn_sl
				nodeN3 child_son_turn_sl = current_node;
				child_son_turn_sl.st = apply3(actSON_TURN_SL, current_node.st, mapa);
				child_son_turn_sl.st.coste_acumulado += coste_accionS(actSON_TURN_SL, current_node.st, mapa);
				child_son_turn_sl.st.valor_heuristica = heuristicaChebyshev(child_son_turn_sl.st.sonambulo, final);
				child_son_turn_sl.st.v_total = child_son_turn_sl.st.coste_acumulado + child_son_turn_sl.st.valor_heuristica;

				if(explored.find(child_son_turn_sl.st) == explored.end()){

					child_son_turn_sl.secuencia.push_back(actSON_TURN_SL);
					frontier.push(child_son_turn_sl);
				}

				//Para el sonámbulo hijo Turn_sr
				nodeN3 child_son_turn_sr = current_node;
				child_son_turn_sr.st = apply3(actSON_TURN_SR, current_node.st, mapa);
				child_son_turn_sr.st.coste_acumulado += coste_accionS(actSON_TURN_SR, current_node.st, mapa);
				child_son_turn_sr.st.valor_heuristica = heuristicaChebyshev(child_son_turn_sr.st.sonambulo, final);
				child_son_turn_sr.st.v_total = child_son_turn_sr.st.coste_acumulado + child_son_turn_sr.st.valor_heuristica;

				if(explored.find(child_son_turn_sr.st) == explored.end()){

					child_son_turn_sr.secuencia.push_back(actSON_TURN_SR);
					frontier.push(child_son_turn_sr);
				}
			}
		}

		if(mapa[current_node.st.jugador.f][current_node.st.jugador.c] == 'K'){

			current_node.st.j_bikini = true;

			if(current_node.st.j_zapatillas){

				current_node.st.j_zapatillas = false;
			}
		}

		if(mapa[current_node.st.jugador.f][current_node.st.jugador.c] == 'D'){

			current_node.st.j_zapatillas = true;

			if(current_node.st.j_bikini){

				current_node.st.j_bikini = false;
			}
		}

		if (current_node.st.sonambulo.f == final.f and current_node.st.sonambulo.c == final.c){

			SolutionFound = true;
		}

		// Para el jugador hijo Forward
		nodeN3 child_forward = current_node;
		child_forward.st = apply3(actFORWARD, current_node.st, mapa);
		child_forward.st.coste_acumulado += coste_accionJ(actFORWARD, current_node.st, mapa);
		child_forward.st.valor_heuristica = heuristicaChebyshev(child_forward.st.sonambulo, final);
		child_forward.st.v_total = child_forward.st.coste_acumulado + child_forward.st.valor_heuristica;

		if(explored.find(child_forward.st) == explored.end()){

			child_forward.secuencia.push_back(actFORWARD);
			frontier.push(child_forward);
		}

		// Para el jugador hijo Turn_l
		nodeN3 child_turnl = current_node;
		child_turnl.st = apply3(actTURN_L, current_node.st, mapa);
		child_turnl.st.coste_acumulado += coste_accionJ(actTURN_L, current_node.st, mapa);
		child_turnl.st.valor_heuristica = heuristicaChebyshev(child_turnl.st.sonambulo, final);
		child_turnl.st.v_total = child_turnl.st.coste_acumulado + child_turnl.st.valor_heuristica;

		if(explored.find(child_turnl.st) == explored.end()){

			child_turnl.secuencia.push_back(actTURN_L);
			frontier.push(child_turnl);
		}

		// Para el jugador hijo Turn_r
		nodeN3 child_turnr = current_node;
		child_turnr.st = apply3(actTURN_R, current_node.st, mapa);
		child_turnr.st.coste_acumulado += coste_accionJ(actTURN_R, current_node.st, mapa);
		child_turnr.st.valor_heuristica = heuristicaChebyshev(child_turnr.st.sonambulo, final);
		child_turnr.st.v_total = child_turnr.st.coste_acumulado + child_turnr.st.valor_heuristica;

		if(explored.find(child_turnr.st) == explored.end()){

			child_turnr.secuencia.push_back(actTURN_R);
			frontier.push(child_turnr);
		}

		if (!SolutionFound and !frontier.empty()){

			current_node = frontier.top();

			while(!frontier.empty() and explored.find(current_node.st) != explored.end()){

				frontier.pop();
				if(!frontier.empty()){

					current_node = frontier.top();
				}

				if (current_node.st.sonambulo.f == final.f and current_node.st.sonambulo.c == final.c){

					SolutionFound = true;
				}

			}

		}
	}
	if (SolutionFound){

        plan = current_node.secuencia;
    }

	return plan;

}


/*Nivel 4*/

list<Action> nivel4J(const stateN3 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa){

	nodeN3 current_node;
	priority_queue<nodeN3> frontier;	// lista de nodos abiertos, nodos pendientes en una cola con prioridad
	set<stateN3> explored;				// lista de nodos cerrados, ya explorados
	list<Action> plan;					// Secuencia de acciones para conseguir el objetivo
	bool visto; 						// Indicará si el sonámbulo está o no en nuestra visión

	
}


Action ComportamientoJugador::think(Sensores sensores){

    Action accion = actIDLE;

	if(sensores.nivel != 4){

    if (!hayPlan){

      cout << "Calculando un nuevo plan\n";

    	switch (sensores.nivel){
            case 0:
				c_state.jugador.f = sensores.posF;
      			c_state.jugador.c = sensores.posC;
      			c_state.jugador.brujula = sensores.sentido;
      			c_state.sonambulo.f = sensores.SONposF;
      			c_state.sonambulo.c = sensores.SONposC;
      			c_state.sonambulo.brujula = sensores.SONsentido;
      			goal.f = sensores.destinoF;
      			goal.c = sensores.destinoC;
            	plan = AnchuraSoloJugador(c_state, goal, mapaResultado);
            break;

            case 1:
				c_state1.jugador.f = sensores.posF;
      			c_state1.jugador.c = sensores.posC;
      			c_state1.jugador.brujula = sensores.sentido;
      			c_state1.sonambulo.f = sensores.SONposF;
      			c_state1.sonambulo.c = sensores.SONposC;
      			c_state1.sonambulo.brujula = sensores.SONsentido;
      			goal.f = sensores.destinoF;
      			goal.c = sensores.destinoC;
				plan = AnchuraSonambulo(c_state1, goal, mapaResultado);
            break;

            case 2:
				c_state2.jugador.f = sensores.posF;
      			c_state2.jugador.c = sensores.posC;
      			c_state2.jugador.brujula = sensores.sentido;
      			c_state2.sonambulo.f = sensores.SONposF;
      			c_state2.sonambulo.c = sensores.SONposC;
      			c_state2.sonambulo.brujula = sensores.SONsentido;
				c_state2.bikini = false;
				c_state2.zapatillas = false;
				c_state2.coste_acumulado = 0;
      			goal.f = sensores.destinoF;
      			goal.c = sensores.destinoC;
				plan = CosteUniformeJugador(c_state2, goal, mapaResultado);
            break;

            case 3:
				c_state3.jugador.f = sensores.posF;
      			c_state3.jugador.c = sensores.posC;
      			c_state3.jugador.brujula = sensores.sentido;
      			c_state3.sonambulo.f = sensores.SONposF;
      			c_state3.sonambulo.c = sensores.SONposC;
      			c_state3.sonambulo.brujula = sensores.SONsentido;
				c_state3.j_bikini = false;
				c_state3.j_zapatillas = false;
				c_state3.s_bikini = false;
				c_state3.s_zapatillas = false;
				c_state3.coste_acumulado = 0;
				c_state3.valor_heuristica = 0;
				c_state3.v_total = 0;
      			goal.f = sensores.destinoF;
      			goal.c = sensores.destinoC;
				plan = AEstrella(c_state3, goal, mapaResultado);
            break;
        }
        if(plan.size() > 0){

			if (sensores.nivel == 0){

				VisualizaPlan(c_state, plan);
			}
			if(sensores.nivel == 1){

				VisualizaPlan1(c_state1, plan);
			}
			if(sensores.nivel == 2){

				VisualizaPlan2(c_state2, plan);
			}
			if(sensores.nivel == 3){

				VisualizaPlan3(c_state3, plan);
			}
            hayPlan = true;
        }
    }
    if (hayPlan and plan.size()>0){

      cout << "Ejecutando la siguiente acción del plan\n";
      accion = plan.front();
      plan.pop_front();
    }

    if (plan.size()==0){

      cout << "Se completó el plan";
      hayPlan = false;
    }
  }
  else {

    cout << "Incluir el nivel 4";
  }


	return accion;
}
