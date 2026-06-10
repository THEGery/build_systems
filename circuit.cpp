#include "circuit.hpp"

double calc_circuit_resistance(const Circuit& c) {
    double total = 0.0;

    if (c.is_parallel) { // Parallel resistors
        for (double r : c.resistance) {
            total += 1.0 / r;
        }
        return 1.0 / total;
    }
    else { // Series resistors
        for (double r : c.resistance) {
            total += r;
        }
    }
    return total;
}
