/** 
 * Universidad de La Laguna
 * Facultad: Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7. Autómatas Finitos Deterministas
 * @author Marcos Padilla Herrera
 * Correo: alu0101045177@ull.edu.es
 * @since 09/11/2022
 * @details:      Contiene el desarrollo de la clase Transition, que representa una 
 *                transición en un Autómata Finito Determinista (DFA). La transición
 *                viene determinada por el estado actual, el estado siguiente y el 
 *                símbolo de entrada.
                   
 * Referencias:   Doxygen:
                  https://www.doxygen.nl/index.html 
                  Identificar clases y objetos:
                  http://www.comscigate.com/uml/DeitelUML/Deitel01/Deitel02/ch03.htm
                  Autómata Finito Determinista (DFA):
                  https://en.wikipedia.org/wiki/Deterministic_finite_automaton

 *  Historial de revisiones:
                  09/11/2022 - Creación del código (primera versión)
                  09/11/2022 - Versión para evaluación
 */

#pragma once

#include <iostream>
#include <string>
#include "state.h"

class Transition {
 public:
  Transition();
  Transition(std::string origin, std::string final, std::string letter);
  ~Transition();
  std::string GetIdOrigin(); 
  std::string GetNextState();
  std::string GetSymbol();

  private:
    std::string state_origin;
    std::string next_state;
    std::string symbol;  

};

