#include "interface.hpp"
#include <iostream>


void add_item(std::vector<Item>& items) {
    Item new_item;

    std::cout << "Add a new item to the items list.\nComponent type:\n";

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
    for (int i = 0; i < items.size(); ++i) {
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
    std::cout << "Last added item:\n";
    std::cout << "Component type: " << i.component_type << "\n";
    std::cout << "Quantity: " << i.quantity << "\n";
    std::cout << "Component value: " << i.component_value << "\n";
    std::cout << "Unit: " << i.unit << "\n\n";
}


void print_items(const std::vector<Item>& items) {
    for (int i = 0; i < items.size(); ++i) {
        std::cout << "Component type: " << items[i].component_type << "\n";
        std::cout << "Quantity: " << items[i].quantity << "\n";
        std::cout << "Component value: " << items[i].component_value << "\n";
        std::cout << "Unit: " << items[i].unit << "\n";
    }
    std::cout << std::endl;
}


void cli() {
    while (true) {
        // TODO: switch case for options.
    }
}