/**
 * Universidad de La Laguna
 * Facultad: Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica . Autómatas Finitos No Deterministas
 * @author Marcos Padilla Herrera
 * Correo: alu0101045177@ull.edu.es
 * @since 23/11/2020
 * @details:      Contiene el desarrollo de la clase NFA, que representa un Autómata 
 *                Finito No Determinista (NFA). Contiene un alfabeto, un conjunto de 
 *                estados y un conjunto de transiciones, y comprueba si una determinada
 *                cadena de entrada es aceptada o no por el autómata.
                   
 * Referencias:   [1] Doxygen 
 *                http://www.doxygen.nl/index.html
                  [2] Diez consejos para mejorar tus comentarios decodigo fuente ´ 
                  https://www.genbeta.com/desarrollo/diez-consejos-para-mejorar-tus-comentarios-de-codigo-fuente
                  [3] Como identificar clases y objetos ´ 
                  http://www.comscigate.com/uml/DeitelUML/Deitel01/Deitel02/ch03.htm

 */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "alphabet.h"
#include "transition.h"
#include "state.h"

class NFA {
 public:
  NFA();
  NFA(std::string input);
  ~NFA();
  bool AnalyzeString(std::string word);
  void Write();
  bool RecognizeElement(std::string word);


 private:
  Alphabet alphabet_;
  std::vector<Transition> transitions_vector_;
  std::vector<State> state_vector_;
  std::string empty_string;

 private:
  State SearchInitialState();
  bool AutomatonRecognize(std::string word, State current_state);
  std::vector<Transition> SearchTransition(State current_state, std::string word);
  State SearchState(std::string state_id);

  
};
