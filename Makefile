nfa_simulation: nfa_simulation.cc alphabet.cc state.cc transition.cc nfa.cc
	g++ -std=c++14 -g -Wall -o nfa_simulation nfa_simulation.cc alphabet.cc state.cc transition.cc nfa.cc

alphabet.o: alphabet.cc
	g++ -std=c++14 -g -Wall -o alphabet alphabet.cc

state.o: state.cc
	g++ -std=c++14 -g -Wall -o state state.cc

transition.o: transition.cc
	g++ -std=c++14 -g -Wall -o transition transition.cc

nfa.o: dfa.cc
	g++ -std=c++14 -g -Wall -o nfa nfa.cc
	
clean: 
	rm -f nfa_simulation output.txt *.o