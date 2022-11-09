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
                  19/11/2020 - Creación del código (primera versión)
                  21/11/2020 - Versión para evaluación
 */

#include "alphabet.h"

Alphabet::Alphabet() {}

Alphabet::~Alphabet() {}
 
 /** @brief método SearchElemento que se encarga de buscar un determinado elemento en el
  * alfabeto si lo encuentra devuelve un booleano a true en caso contrario devuelve false
  * @param element variable de tipo char que que recive un symbolo por parámetro que será
  * comparado con todos los elementos del alfabeto para ver si se encuentra o no.
  */
bool Alphabet::SearchElement(std::string element) {
  for ( std::set<std::string>::iterator it = alphabet_container.begin(); it != alphabet_container.end(); it++) { //cambie del  auto it
    if (element == *it) {
      return true;
    }
  }
  return false;
}

  /** @brief método WriteAlphabet encargado de visualizar el alfabeto
   */
void Alphabet::WriteAlphabet() {
  for (std::set<std::string>::iterator alphabet_iterator = alphabet_container.begin();
       alphabet_iterator != alphabet_container.end(); alphabet_iterator++) {
       std::cout << "{" << *alphabet_iterator << "} ";
  }
  std::cout << std::endl;
}

void Alphabet::InsertSymbol(std::string symbol) {
  alphabet_container.insert(symbol);
}

Alphabet Alphabet::operator=(const Alphabet parametre_alphabet) {
  this->alphabet_container = parametre_alphabet.alphabet_container; 
  return *this;
}