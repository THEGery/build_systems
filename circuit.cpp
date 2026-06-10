#include "circuit.hpp"

double calc_circuit_resistance(const Circuit& c) {
    double total = 0.0;

    if (c.is_paralel) { // Parallel resistors
        for (double r : c.resistance) {
            total += 1.0 / r;
        }
        return 1.0 / total;
    }
    else { // Serial resistors
        for (double r : c.resistance) {
            total += r;
        }
    }
    return total;
}
