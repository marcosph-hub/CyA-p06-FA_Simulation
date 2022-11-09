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
                  21/11/2020 - Creación del código (primera versión)
                  24/11/2020 - Versión para evaluación
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
  void WriteAlphabet();
  void InsertSymbol(std::string symbol);
  Alphabet operator=(const Alphabet parametre_alphabet); 

  private:
    std::set<std::string> alphabet_container;
};