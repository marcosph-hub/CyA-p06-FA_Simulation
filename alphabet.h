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
 * @details:      Contiene el desarrollo de la clase Alphabet, que representa el alfabeto
 *                de un autómata finito determinista (DFA). La clase incluye métodos para
 *                insertar y buscar elementos en el alfabeto.
                   
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
#include <set>
#include <string>

class Alphabet {
 
 public:
  Alphabet();
  ~Alphabet();
  bool SearchElement(std::string element);
  void setAlphabet(std::set<std::string> external_alphabet);
  void WriteAlphabet();
  void InsertSymbol(std::string symbol);
  Alphabet operator=(const Alphabet parametre_alphabet); 

  private:
    std::set<std::string> alphabet_container;
};