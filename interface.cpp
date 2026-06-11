#include "interface.hpp"
#include "inventory.hpp"
#include <iostream>


void add_item(std::vector<Item>& items) {
    Item new_item;

    std::cout << "Add a new item to the items list.\n";
    std::cout << "=================================\n";
    std::cout << "Component type:\n";
    std::cin >> new_item.component_type;
    std::cout << "Quantity:\n";
    std::cin >> new_item.quantity;
    std::cout << "Component value:\n";
    std::cin >> new_item.component_value;
    std::cout << "Unit:\n";
    std::cin >> new_item.unit;

    std::cout << std::endl;

    bool matching = false;
    // if type, value, unit match add new item quantity to nth item's quantity
    for (std::size_t i = 0; i < items.size(); ++i) {
        if (items[i].component_type == new_item.component_type && 
            items[i].component_value == new_item.component_value && 
            items[i].unit == new_item.unit) {
                items[i].quantity += new_item.quantity;
                matching = true;
        }
    }
    // if there's no match add new item to the items vector
    if (matching == false) {
        items.push_back(new_item);
    }
}


void print_item(Item i) {
    std::cout << "Selected item:\n";
    std::cout << "==============\n";
    std::cout << "Component type: " << i.component_type << "\n";
    std::cout << "Quantity: " << i.quantity << "\n";
    std::cout << "Component value: " << i.component_value << "\n";
    std::cout << "Unit: " << i.unit << "\n\n";
}


void print_items(const std::vector<Item>& items) {
    for (std::size_t i = 0; i < items.size(); ++i) {
        std::cout << "Component type: " << items[i].component_type << "\n";
        std::cout << "Quantity: " << items[i].quantity << "\n";
        std::cout << "Component value: " << items[i].component_value << "\n";
        std::cout << "Unit: " << items[i].unit << "\n\n";
    }
    std::cout << std::endl;
}


void cli() {
    std::vector<Item> items;
    bool run = true;
    while (run) {
        char mode;

        std::cout << "Choos what you would like to do. (Type \"h\" for help): \n";
        std::cout << "========================================================\n";

        std::cin >> mode;

        switch (mode) {
            case 'a':
                add_item(items); // done
                break;
            case 'c':
                print_count(count_capacitors(items), 'r'); // done
                break;
            case 'e':
                run = false; // done
                break;
            case 'i':
                item_index(items);
                break;
            case 'h':
                help(); // done
                break;
            case 'l':
                print_items(items); // done
                break;
            case 'r':
                print_count(count_resistors(items), 'r'); // done
                break;
            default:
                std::cout << "###    Invalid option. Type \"h\" for help.    ###\n";
                std::cout << "==================================================\n";
        }

        // while (std::cin.get() != '\n');
    }
}

// Helper functions
void help() {
    std::cout << "============================ Help menu ============================\n\n";
    std::cout << "    a  ->  create a new item and add it to the inventory array\n";
    std::cout << "    c  ->  show the number of capacitors\n";
    std::cout << "    e  ->  exit the program\n";
    std::cout << "    i  ->  show the n-th item (0-indexed) of the inventory array\n";
    std::cout << "    h  ->  show this help text\n";
    std::cout << "    l  ->  show the list of items\n";
    std::cout << "    r  ->  show the number of resistors\n\n";
}


void item_index(const std::vector<Item>& items) {
    std::size_t index;
    std::cout << "Type a number to show item at that index: \n";
    std::cout << "The list has: " << items.size() << "elements (0 indexed)\n";
    std::cout << "==========================================\n";
    std::cin >> index;

    for (std::size_t i = 0; i < items.size(); ++i) {
        if (i == index) {
            print_item(items[i]);
        }
    }
    std::cout << std::endl;
}

void print_count(std::size_t count, char type) {
    if (type == 'r'){
        std::cout << "Number of resistors: " << count << std::endl;
    }
    else if (type == 'c') {
        std::cout << "Number of capacitors: " << count << std::endl;
    }
}