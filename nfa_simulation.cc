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
 * @details:      Contiene el desarrollo del programa nfa_simulation, que a partir de un
 *                fichero .nfa de entrada construye la simulación de un NFA. Asimismo, 
 *                el programa comprueba que una serie de cadenas sean reconocidas por el
 *                autómata, escribiendo el resultado (Sí o No) en un fichero de salida.
                   
 * Referencias:   [1] Doxygen 
 *                http://www.doxygen.nl/index.html
                  [2] Diez consejos para mejorar tus comentarios decodigo fuente ´ 
                  https://www.genbeta.com/desarrollo/diez-consejos-para-mejorar-tus-comentarios-de-codigo-fuente
                  [3] Como identificar clases y objetos ´ 
                  http://www.comscigate.com/uml/DeitelUML/Deitel01/Deitel02/ch03.htm
 */


#include "nfa.h"

void InputStrings(std::string nfa_input, std::string input, std::string output) {
  std::ifstream input_file(input);
  std::string line;
  std::ofstream output_file(output);
  while(!input_file.eof()) {
    NFA nfa(nfa_input);
    getline(input_file, line);
    bool accepted = nfa.AnalyzeString(line);
    if (accepted) {
      output_file << line <<  " -- Accepted\n";
    } else {
      output_file << line << " -- Rejected\n";
    }
  }
}

int main(int argc, char* argv[]) {
if (argc - 1 != 3) {
  if (argc - 1 == 1) {
    std::string help = argv[1];
    if (help == "--help") {
      std::cout << "Este programa construye una simulación de un NFA y comprueba ";
      std::cout << "que una serie de cadenas sean reconocidas por el mismo\n";
      std::cout << "Debes introducir tres parámetros:" << std::endl;
      std::cout << "./dfa_simulation input.dfa input.txt output.txt\n";
      std::cout << "Parámetro 1: un fichero .dfa de entrada con la ";
      std::cout << "especificación del NFA\n";
      std::cout << "Parámetro 2: un fichero .txt con las cadenas de prueba\n";
      std::cout << "Parámetro 3: un fichero .txt de salida con los resultados\n";
      return 1;
    } 
  }
  std::cout << "Modo de empleo: ./nfa_simulation input.nfa input.txt output.txt\n";
  std::cout << "Pruebe ’nfa_simulation --help’ para más información.\n";
  return 1;
}
InputStrings(argv[1], argv[2], argv[3]);
return 0;
}