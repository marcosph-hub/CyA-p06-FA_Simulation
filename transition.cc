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

#include "transition.h"

Transition::Transition () {}

Transition::Transition(std::string origin, std::string end, std::string letter) {
  state_origin = origin;
  next_state = end;
  symbol = letter;
}

Transition::~Transition() {}

std::string Transition::GetIdOrigin() { 
  return state_origin;
}

std::string Transition::GetNextState() { 
  return next_state;
}

std::string Transition::GetSymbol() { 
  return symbol;
}
