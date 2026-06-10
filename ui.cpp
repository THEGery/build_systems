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
            std::cout << "Added value: " << resistance_val << " ohm.\n";
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

    while (true) {
        double connection_type;

        std::cout << "Is the connection parallel or series?";
        std::cout << "(Enter \"s\" for series, \"p\" for parallel.):\n";

        std::cin >> connection_type;

        if (connection_type == 'p' || 'P') {
            new_circuit.is_paralel = true;
            break;
        }
        else if (connection_type == 's' || 'S') {
            new_circuit.is_paralel = false;
            break;
        }
        while (std::cin.get() != '\n');
        std::cout << "Invalid option. Please type \"s\"(series, or \"p\"(parallesl).\n";
    }

    return new_circuit;
}