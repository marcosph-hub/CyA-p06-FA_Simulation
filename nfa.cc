/**
 * @par Universidad de La Laguna 
 * Facultad: Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica . Autómatas Finitos No Deterministas
 * @author Marcos Padilla Herrera
 * Correo: alu0101045177@ull.edu.es
 * @since 09/11/2022
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

#include "nfa.h"

NFA::NFA() {}

NFA::~NFA() {}

NFA::NFA(std::string input) {
  empty_string = "~";
  std::ifstream file(input);
  if (!file.good()) {
    std::cout << "Error en la apertura de fichero" << std::endl;
    exit(1);
  }

  //Alphabet
  std::set<std::string> alphabet_set;
  std::string file_alphabet;
  getline(file, file_alphabet);

  for (unsigned int i = 0; i < file_alphabet.size(); i++) {
    char char_symbol = file_alphabet[i];
    std::string str_symbol(1,char_symbol);
    alphabet_set.insert(str_symbol);
    i++;
  }
  alphabet_.setAlphabet(alphabet_set);

  std::string data;
  //Total states amount
  getline(file, data);
  unsigned int number_of_states = std::stoi(data);

  //Analyzing the initial state
  State initial_state;
  getline(file, data);
  std::string id_initial_state = data;

  //Taking the information of the input file about each state description
  for (unsigned int iterator = 0; iterator < number_of_states; iterator++) {
    State current_state;
    getline(file, data);
    std::istringstream data_line(data);
    std::string input_word;
    data_line >> input_word;
    if (id_initial_state == input_word) {
      current_state.SetStartState();
    }
    current_state.SetIdentifier(input_word);
    data_line >> input_word;
    if (input_word == "1") {
      current_state.SetAcceptState();
    }
    state_vector_.push_back(current_state);
    data_line >> input_word;
    unsigned int transition_number = std::stoi(input_word);
    for (unsigned int iterator = 0; iterator < transition_number; iterator++) {
      std::string actual_symbol;
      std::string destiny_id_state;
      data_line >> actual_symbol;
      alphabet_.InsertSymbol(actual_symbol);
      data_line >> destiny_id_state;
      Transition current_transition(current_state.GetIdentifier(), destiny_id_state, actual_symbol);
      transitions_vector_.push_back(current_transition);
    }
  }
}

bool NFA::AnalyzeString(std::string word) {
  if (!RecognizeElement(word)) {
    return false;
  }
  State current_state;
  current_state = SearchInitialState();
  return AutomatonRecognize(word, current_state);
}

bool NFA::AutomatonRecognize(std::string word, State current_state) {
  bool result = false;
  std::vector<Transition> found_transition = SearchTransition(current_state, word);
  if (word.empty() && current_state.GetAcceptState()) {
    return true;
  }
  std::string word_copy = word;
  State state_copy;
  state_copy = current_state;
  for (unsigned int iterator = 0; iterator < found_transition.size(); iterator++) {
    Transition current_transition;
    current_transition = found_transition[iterator];
    current_state = SearchState(current_transition.GetNextState());
    if (current_transition.GetSymbol() != empty_string) {
      word.erase(0, 1);
    }
    result = AutomatonRecognize(word, current_state);
    if (result) {
      break;
    }
    word = word_copy;
    current_state = state_copy;
  }
  return result;
}
            
std::vector<Transition> NFA::SearchTransition(State current_state, std::string word) {
  std::string current_symbol = "";
  current_symbol += word[0];
  std::vector<Transition> container_transitions;
  for (unsigned int iterator = 0; iterator < transitions_vector_.size(); iterator++) {
    if (current_state.GetIdentifier() == transitions_vector_[iterator].GetIdOrigin() 
    && (current_symbol == transitions_vector_[iterator].GetSymbol() 
    || empty_string == transitions_vector_[iterator].GetSymbol())) {
      container_transitions.push_back(transitions_vector_[iterator]);
    }
  }
  return container_transitions;
}

bool NFA::RecognizeElement(std::string word) {
  for (unsigned int iterator = 0; iterator < word.length(); iterator++) {
    std::string current_symbol;
    current_symbol += word[iterator];
    if (!alphabet_.SearchElement(current_symbol)) {
      return false;
    }
  }
  return true;
}
State NFA::SearchInitialState() {
  unsigned int index = 0;
  for (unsigned int iterator = 0; iterator < state_vector_.size(); iterator++) {
    if(state_vector_[iterator].GetStartState()) {
      index = iterator;
    }
  }
  return state_vector_[index];
}

State NFA::SearchState(std::string state_id) {
  unsigned int index = 0;
  for (unsigned int iterator = 0; iterator < state_vector_.size(); iterator++) {
    if (state_vector_[iterator].GetIdentifier() == state_id) {
      index = iterator;
    }
  }
  return state_vector_[index];
}

void NFA::Write() {
  for (unsigned int iterator = 0; iterator < transitions_vector_.size(); iterator++) {
    std::cout << "id estado origen: " << transitions_vector_[iterator].GetIdOrigin() << " id estado final: " 
    << transitions_vector_[iterator].GetNextState()  << " symbolo de la transicion: " << transitions_vector_[iterator].GetSymbol()
    << std::endl;
  }

  for (unsigned int state_iterator = 0; state_iterator < state_vector_.size(); state_iterator++) {
    std::cout << "identificador: " << state_vector_[state_iterator].GetIdentifier() << "Estado inicial: " <<
    state_vector_[state_iterator].GetStartState() << " Estado final: " << state_vector_[state_iterator].GetAcceptState()
    << std::endl;
  }
    alphabet_.WriteAlphabet();
}


