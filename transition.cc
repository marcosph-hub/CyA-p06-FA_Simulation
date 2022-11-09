/** 
 * Universidad de La Laguna
 * Facultad: Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7. Autómatas Finitos Deterministas
 * @author David Hernández Suárez
 * Correo: alu0101048239@ull.edu.es
 * @since 21/11/2020
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
                  21/11/2020 - Creación del código (primera versión)
                  24/11/2020 - Versión para evaluación
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
