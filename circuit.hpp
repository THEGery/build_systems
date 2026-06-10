#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

#include <vector>


struct Circuit {
    std::vector<double> resistance;
    bool is_parallel;
};

// return the total resistance of the circuit
double calc_circuit_resistance(const Circuit& c);

#endif