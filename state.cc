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
 * @details:      Contiene el desarrollo de la clase State, que representa un estado de
 *                un autómata finito determinista (DFA). El estado viene determinado por 
 *                un identificador, y puede tratarse de un estado inicial o de un estado 
 *                de aceptación.
                   
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

#include "state.h"

/**
 * @brief Constructor. Inicializa los atributos del estado.
 * @param identifier_ - Identificador del estado.
 */
State::State(std::string identifier_) {
  identifier = identifier_;
  start_state = false;
  accept_state = false;
}

/**
 * @brief Destructor.
 */
State::~State() {}

/**
 * @brief Constructor por defecto.
 */
State::State() {
  accept_state = false;
  start_state = false;
}

/**
 * @brief Indica que el estado es el inicial.
 */
void State::SetStartState(void) {
  start_state = true;
}

/**
 * @brief Indica que el estado es de aceptación.
 */
void State::SetAcceptState(void) {
  accept_state = true;
}

/**
 * @brief Establece el identificador del estado.
 * @param identifier_ - Identificador del estado.
 */
void State::SetIdentifier(std::string identifier_) {
  identifier = identifier_;
}

/**
 * @brief Devuelve el identificador del estado.
 * @return Identificador del estado.
 */
std::string State::GetIdentifier(void) {
  return identifier;
}

/**
 * @brief Indica si el estado es el inicial.
 * @return Devuelve true si el estado es el inicial.
 */
bool State::GetStartState(void) {
  return start_state;
}

/**
 * @brief Indica si el estado es de aceptación.
 * @return Devuelve true si el estado es de aceptación.
 */
bool State::GetAcceptState(void) {
  return accept_state;
}

/**
 * @brief Sobrecarga del operador de inserción.
 * @param input - Objeto de istream.
 * @param state - Objeto de la clase State.
 * @return Devuelve el objeto de istream.
 */
std::istream& operator>>(std::istream &input, State &state) {
  std::string state_id;
  input >> state_id;
  state.identifier = state_id;
  return input;
}

/**
 * @brief Sobrecarga del operador de comparación.
 * @param state - Objeto de la clase State.
 * @return Devuelve true si los estados son iguales.
 */
bool State::operator==(const State &state) const {
  if (this -> identifier == state.identifier &&
    this -> start_state == state.start_state &&
    this -> accept_state == state.accept_state) {
    return true;
  }
  return false;
}

/**
 * @brief Sobrecarga del operador de asignación.
 * @param estado - Objeto de la clase State.
 * @return Devuelve el objeto State.
 */
State& State::operator=(const State &state) {
  this -> identifier = state.identifier;
  this -> start_state = state.start_state;
  this -> accept_state = state.accept_state;
  return *this;
}