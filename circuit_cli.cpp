#include "circuit.hpp"
#include "ui.hpp"

#include <iostream>

// create at least two different circuits (one parallel and one serial)
// and use both draw_circuit(.) and print_circuit(.) on each of them
int main() {
    // Mode select
    bool interactive;

    std::cout << "Type \"i\" for interactive mode, or \"t\" to show template.\n";

    while (true) {
        char mode;
        std::cin >> mode;

        if (mode == 'i' || mode == 'I') {
            interactive = true;
            break;
        } 
        else if (mode == 't' || mode == 'T') {
            interactive = false;
            break;
        }
        while (std::cin.get() != '\n');
        std::cout << "Invalid option. Please type \"i\" for interactive mode";
        std::cout << " or \"t\" for template.\n";
    }


    // Interactive mode
    if (interactive) {
        Circuit circuit = read_circuit();

        draw_circuit(circuit);
        std::cout << std::endl;
        print_circuit(circuit);
    }
    else { // Template mode
        // Series circuit
        Circuit serial_circuit;
        serial_circuit.resistance = {220, 330, 220};
        serial_circuit.is_parallel = false;

        std::cout << "====== Series circuit ======\n";
        draw_circuit(serial_circuit);
        std::cout << std::endl;
        print_circuit(serial_circuit);
        std::cout << "============================\n";
        std::cout << std::endl;

        // Parallel circuit
        Circuit parallel_circuit;
        parallel_circuit.resistance = {220, 330, 220};
        parallel_circuit.is_parallel = true;
        
        std::cout << "===== Parallel circuit =====\n";
        draw_circuit(parallel_circuit);
        std::cout << std::endl;
        print_circuit(parallel_circuit);
        std::cout << "============================\n";
    }
    return 0;
}