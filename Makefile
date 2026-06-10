CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++20

# $@ (target) and $^ (all prerequisites)
calculate_resistance: circuit.o circuit_cli.o ui.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Main so all hpp is needed
circuit_cli.o: circuit_cli.cpp circuit.hpp ui.hpp
	$(CXX) $(CXXFLAGS) -c circuit_cli.cpp -o $@

circuit.o: circuit.cpp circuit.hpp
	$(CXX) $(CXXFLAGS) -c circuit.cpp -o $@

ui.o: ui.cpp ui.hpp
	$(CXX) $(CXXFLAGS) -c ui.cpp -o $@

clean:
	rm -f *.o calculate_resistance

.PHONY: clean
