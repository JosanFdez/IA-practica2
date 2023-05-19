#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>

struct stateN0{

  ubicacion jugador;
  ubicacion sonambulo;

  bool operator == (const stateN0 &x) const {

    if(jugador == x.jugador and sonambulo.f == x.sonambulo.f and sonambulo.c == x.sonambulo.c){

      return true;
    }

    else {

      return false;
    }
  }
};

struct stateN1{

  ubicacion jugador;
  ubicacion sonambulo;

  bool operator == (const stateN1 &x) const {

    if(jugador == x.jugador and sonambulo.f == x.sonambulo.f and sonambulo.c == x.sonambulo.c){

      return true;
    }

    else {

      return false;
    }
  }

  bool operator < (const stateN1 &st) const {

    if (jugador.f < st.jugador.f){

      return true;
    }

    else if (jugador.f == st.jugador.f and jugador.c < st.jugador.c){

      return true;
    }

    else if (jugador.f == st.jugador.f and jugador.c == st.jugador.c and jugador.brujula < st.jugador.brujula){

      return true;
    }
    else if (jugador.f == st.jugador.f and jugador.c == st.jugador.c and jugador.brujula == st.jugador.brujula and sonambulo.f < st.sonambulo.f){

      return true;
    }
    else if (jugador.f == st.jugador.f and jugador.c == st.jugador.c and jugador.brujula == st.jugador.brujula and sonambulo.f == st.sonambulo.f and sonambulo.c < st.sonambulo.c){

      return true;
    }
    else if (jugador.f == st.jugador.f and jugador.c == st.jugador.c and jugador.brujula == st.jugador.brujula and sonambulo.f == st.sonambulo.f and
              sonambulo.c == st.sonambulo.c and sonambulo.brujula < st.sonambulo.brujula){

      return true;
    }
    else {

      return false;
    }
  }
};

struct stateN2{

  ubicacion jugador;
  ubicacion sonambulo;
  bool zapatillas;
  bool bikini;
  int coste_acumulado;

  bool operator == (const stateN2 &x) const {

    if(jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f == x.sonambulo.f and sonambulo.c == x.sonambulo.c
     and zapatillas == x.zapatillas and bikini == x.bikini and coste_acumulado == x.coste_acumulado){

      return true;
    }

    else {

      return false;
    }
  }

  bool operator < (const stateN2 &x) const{

    if (jugador.f < x.jugador.f){

      return true;
    }

    else if (jugador.f == x.jugador.f and jugador.c < x.jugador.c){

      return true;
    }

    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula < x.jugador.brujula){

      return true;
    }
    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f < x.sonambulo.f){

      return true;
    }
    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f == x.sonambulo.f and sonambulo.c < x.sonambulo.c){

      return true;
    }
    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f == x.sonambulo.f and
              sonambulo.c == x.sonambulo.c and sonambulo.brujula < x.sonambulo.brujula){

      return true;
    }
    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f == x.sonambulo.f and
              sonambulo.c == x.sonambulo.c and sonambulo.brujula == x.sonambulo.brujula and zapatillas < x.zapatillas){

      return true;
    }
    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f == x.sonambulo.f and
              sonambulo.c == x.sonambulo.c and sonambulo.brujula == x.sonambulo.brujula and zapatillas == x.zapatillas and bikini < x.bikini){

      return true;
    }
    else {

      return false;
    }
  }

};

struct stateN3{

  ubicacion jugador;
  ubicacion sonambulo;
  bool j_zapatillas;
  bool j_bikini;
  bool s_zapatillas;
  bool s_bikini;
  int coste_acumulado;
  int valor_heuristica;
  int v_total;

  bool operator == (const stateN3 &x) const {

    if(jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f == x.sonambulo.f and sonambulo.c == x.sonambulo.c
        and j_zapatillas == x.j_zapatillas and j_bikini == x.j_bikini and s_zapatillas == x.s_zapatillas and s_bikini == x.s_bikini and coste_acumulado == x.coste_acumulado
        and valor_heuristica == x.valor_heuristica and v_total == x.v_total){

      return true;
    }

    else {

      return false;
    }
  }

  bool operator < (const stateN3 &x) const{

    if (jugador.f < x.jugador.f){

      return true;
    }

    else if (jugador.f == x.jugador.f and jugador.c < x.jugador.c){

      return true;
    }

    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula < x.jugador.brujula){

      return true;
    }
    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f < x.sonambulo.f){

      return true;
    }
    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f == x.sonambulo.f and sonambulo.c < x.sonambulo.c){

      return true;
    }
    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f == x.sonambulo.f and
              sonambulo.c == x.sonambulo.c and sonambulo.brujula < x.sonambulo.brujula){

      return true;
    }
    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f == x.sonambulo.f and
              sonambulo.c == x.sonambulo.c and sonambulo.brujula == x.sonambulo.brujula and j_zapatillas < x.j_zapatillas){

      return true;
    }
    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f == x.sonambulo.f and
              sonambulo.c == x.sonambulo.c and sonambulo.brujula == x.sonambulo.brujula and j_zapatillas == x.j_zapatillas and j_bikini < x.j_bikini){

      return true;
    }
    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f == x.sonambulo.f and
              sonambulo.c == x.sonambulo.c and sonambulo.brujula == x.sonambulo.brujula and j_zapatillas == x.j_zapatillas and j_bikini == x.j_bikini and
              s_zapatillas < x.s_zapatillas){

      return true;
    }
    else if (jugador.f == x.jugador.f and jugador.c == x.jugador.c and jugador.brujula == x.jugador.brujula and sonambulo.f == x.sonambulo.f and
              sonambulo.c == x.sonambulo.c and sonambulo.brujula == x.sonambulo.brujula and j_zapatillas == x.j_zapatillas and j_bikini == x.j_bikini and
              s_zapatillas == x.s_zapatillas and s_bikini < x.s_bikini){

      return true;
    }
    else{

      return false;
    }

  }
};

struct nodeN0{
  stateN0 st;
  list<Action> secuencia;

  bool operator == (const nodeN0 &n) const {

    return (st == n.st);
  }

  bool operator<(const nodeN0 &n) const {

    if (st.jugador.f < n.st.jugador.f)

      return true;

    else if (st.jugador.f == n.st.jugador.f and st.jugador.c < n.st.jugador.c)

      return true;

    else if (st.jugador.f == n.st.jugador.f and st.jugador.c == n.st.jugador.c and st.jugador.brujula < n.st.jugador.brujula)

      return true;

    else
      return false;
  }

};

struct nodeN1 {

  stateN1 st;
  list<Action> secuencia;

  bool operator == (const nodeN1 &n) const {

    return (st == n.st);
  }

  bool operator < (const nodeN1 &n) const {

    if (st.jugador.f < n.st.jugador.f){

      return true;
    }

    else if (st.jugador.f == n.st.jugador.f and st.jugador.c < n.st.jugador.c){

      return true;
    }

    else if (st.jugador.f == n.st.jugador.f and st.jugador.c == n.st.jugador.c and st.jugador.brujula < n.st.jugador.brujula){

      return true;
    }
    else if (st.jugador.f == n.st.jugador.f and st.jugador.c == n.st.jugador.c and st.jugador.brujula == n.st.jugador.brujula and st.sonambulo.f < n.st.sonambulo.f){

      return true;
    }
    else if (st.jugador.f == n.st.jugador.f and st.jugador.c == n.st.jugador.c and st.jugador.brujula == n.st.jugador.brujula and st.sonambulo.f == n.st.sonambulo.f and
              st.sonambulo.c < n.st.sonambulo.c){

      return true;
    }
    else if (st.jugador.f == n.st.jugador.f and st.jugador.c == n.st.jugador.c and st.jugador.brujula == n.st.jugador.brujula and st.sonambulo.f == n.st.sonambulo.f and
              st.sonambulo.c == n.st.sonambulo.c and st.sonambulo.brujula < n.st.sonambulo.brujula){

      return true;
    }

    else {
      return false;
    }

  }
};

struct nodeN2{

  stateN2 st;
  list<Action> secuencia;

  bool operator == (const nodeN2 &n) const {

    return (st == n.st);
  }


  bool operator < (const nodeN2 &n) const{

    if(st.coste_acumulado > n.st.coste_acumulado){

      return true;
    }
    else{

      return false;
    }
  }

};

struct nodeN3{

  stateN3 st;
  list<Action> secuencia;

  bool operator == (const nodeN3 &n) const{

    return (st == n.st);
  }

  bool operator < (const nodeN3 &n) const{

    if(st.v_total > n.st.v_total){

      return true;
    }
    else{

      return false;
    }
  }

};

class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado

    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      hayPlan = false;
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void VisualizaPlan(const stateN0 &st, const list<Action> &plan);
    void VisualizaPlan1(const stateN1 &st, const list<Action> &plan);
    void VisualizaPlan2(const stateN2 &st, const list<Action> &plan);
    void VisualizaPlan3(const stateN3 &st, const list<Action> &plan);

  private:
    // Declarar Variables de Estado
    list<Action> plan; // Almacena el plan en ejecución
    bool hayPlan;      // Si es verdad indica que se está siguiendo un plan
    stateN0 c_state;
    stateN1 c_state1;
    stateN2 c_state2;
    stateN3 c_state3;
    stateN3 c_state4;
    ubicacion goal;

};

#endif
