#include "ui.hpp"
#include "circuit.hpp"

#include <iostream>


Circuit read_circuit() {
    Circuit new_circuit;

    std::cout << "Type resistance values after each other,";
    std::cout << "separated by a space (hit 'q' and enter to finish):\n";

    while (true) {
        double resistance_val;

        if (std::cin >> resistance_val) {
            // add resistance_val to struct
            new_circuit.resistance.push_back(resistance_val);
            // Sanity check, in case the user types invalid value,
            // to see what values are already accepted and saved.
            std::cout << "Added value: " << resistance_val << "Ω.\n";
        }
        else {
            // Clear error if non num character tiped, to continue loop
            std::cin.clear();
            
            // Check if 'q' was hit to end the input
            if (std::cin.get() == 'q') {
                break;
            }

            // get rid of non numeric(double) and non 'q' characters until '\n'
            while (std::cin.get() != '\n');
            std::cout << "Invalid input was ignored. (Enter a number or 'q' to finish):\n";
        }
    }
    
    std::cout << "Is the connection parallel or series? ";
    std::cout << "(Enter \"s\" for series, \"p\" for parallel.):\n";

    while (true) {
        char connection_type;

        std::cin >> connection_type;

        if (connection_type == 'p' || connection_type == 'P') {
            new_circuit.is_parallel = true;
            break;
        }
        else if (connection_type == 's' || connection_type == 'S') {
            new_circuit.is_parallel = false;
            break;
        }
        while (std::cin.get() != '\n');
        std::cout << "Invalid option. Please type \"s\"(series, or \"p\"(parallesl).\n";
    }

    return new_circuit;
}


void draw_circuit(const Circuit& c) {
    if (c.is_parallel) {
        //  ┌[220Ω]┐
        // ─┼[330Ω]┼─
        //  └[220Ω]┘
        std::cout << "Parallel connection:\n";
        for (size_t i = 0; i < c.resistance.size(); ++i) {
            if (i == 0) {
                std::cout << " ┌[" << c.resistance[i] << "Ω]┐\n";
            }
            else if (i == c.resistance.size() - 1) {
                std::cout << " └[" << c.resistance[i] << "Ω]┘\n";
            }
            else {
                std::cout << "─┼[" << c.resistance[i] << "Ω]┼─\n";
            }
        }
    }
    else {
        // -[220Ω]-[330Ω]-[220Ω]-
        std::cout << "Series connection:\n";
        std::cout << "-";
        for (size_t i = 0; i < c.resistance.size(); ++i) {
            std::cout << "[" << c.resistance[i] << "Ω]-";
        }
        std::cout << std::endl;
    }
}


void print_circuit(const Circuit& c) {
    if (c.is_parallel) {
        std::cout << "Parallel connection:\n";
    }
    else {
        std::cout << "Series connection:\n";
    }
    for (double r : c.resistance) {
        std::cout << r << "Ω\n";
    }

    double total = calc_circuit_resistance(c);
    std::cout << "Total resistance: " << total << "Ω" << std::endl;
}