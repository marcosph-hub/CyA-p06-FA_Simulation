/** 
 * Universidad de La Laguna
 * Facultad: Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 7. Autómatas Finitos Deterministas
 * @author Marcos Padilla Herrera
 * Correo: alu0101045177@ull.edu.es
 * @since 21/11/2020
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
                  21/11/2020 - Creación del código (primera versión)
                  24/11/2020 - Versión para evaluación
 */

#pragma once

#include <iostream>
#include <vector>

/**
 * @class State 
 * @details La clase State incluye los métodos y atributos necesarios para 
 *          representar un estado de un DFA.
 */
class State {
 public:
  State(std::string identifier_);
  ~State();
  State();
  std::string GetIdentifier();
  bool GetStartState(void);
  bool GetAcceptState(void);
  void SetIdentifier(std::string identifier_);
  void SetStartState(void);
  void SetAcceptState(void);
  friend std::istream& operator>>(std::istream &input, State &state);
  bool operator==(const State &state) const;
  State& operator=(const State &state);

 private:
  std::string identifier;
  bool accept_state;
  bool start_state;
};