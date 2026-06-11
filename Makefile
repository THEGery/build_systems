CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++20

all: calculate_resistance ims
# $@ (target) and $^ (all prerequisites)
# Executable
calculate_resistance: circuit.o circuit_cli.o ui.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Main
circuit_cli.o: circuit_cli.cpp circuit.hpp ui.hpp
	$(CXX) $(CXXFLAGS) -c circuit_cli.cpp -o $@

# Modules
circuit.o: circuit.cpp circuit.hpp
	$(CXX) $(CXXFLAGS) -c circuit.cpp -o $@

ui.o: ui.cpp ui.hpp
	$(CXX) $(CXXFLAGS) -c ui.cpp -o $@

# ================= IMS =======================
# Executable
ims: inventory_cli.o interface.o inventory.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Main
inventory_cli.o: inventory_cli.cpp interface.hpp inventory.hpp
	$(CXX) $(CXXFLAGS) -c inventory_cli.cpp -o $@

# Modules
interface.o: interface.cpp interface.hpp
	$(CXX) $(CXXFLAGS) -c interface.cpp -o $@

inventory.o: inventory.cpp inventory.hpp
	$(CXX) $(CXXFLAGS) -c inventory.cpp -o $@

# =============== Clean =======================
clean:
	rm -f *.o calculate_resistance ims

.PHONY: clean
.PHONY: all
