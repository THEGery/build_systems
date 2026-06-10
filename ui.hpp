#ifndef UI_HPP
#define UI_HPP

#include "circuit.hpp"

// read the resistances from stdin
// also ask the user whether a parallel or series connection is used
// return a new `Circuit` containing the above data
Circuit read_circuit();

// print a visual representation of the struct; this can be something like
// -[220Ω]-[330Ω]-[220Ω]- or
//
//  ┌[220Ω]┐
// ─┼[330Ω]┼─
//  └[220Ω]┘
void draw_circuit(const Circuit& c);

// print the values of the resistors, whether a parallel or series connection
// is used and the total resistance
void print_circuit(const Circuit& c);

#endif