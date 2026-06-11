#include "interface.hpp"
#include "inventory.hpp"
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
    std::cout << "Last added item:\n";
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
        std::cout << "Unit: " << items[i].unit << "\n";
    }
    std::cout << std::endl;
}


void cli() {
    std::vector<Item> items;

    while (true) {
        char mode;

        std::cin >> mode;

        switch (mode) {
            case 'a':
                add_item(items);
                break;
            case 'c':
                count_capacitors(items);
                break;
            case 'e':
                break;
            case 'i':
                item_index(items);
                break;
            case 'h':
                help();
                break;
            case 'l':
                print_items(items);
                break;
            case 'r':
                count_resistors(items);
                break;
            default:
                std::cout << "Invalid option. Type \"h\" for help.";
        }
        // while (std::cin.get() != '\n');
        break;
    }
}

// Helper functions
void help() {
    std::cout << "\n====== Help menu ======";
    std::cout << "a -> create a new item and add it to the inventory array\n";
    std::cout << "c -> show the number of capacitors\n";
    std::cout << "e -> exit the program\n";
    std::cout << "i n -> show the n-th item (0-indexed) of the inventory array\n";
    std::cout << "h -> show this help text\n";
    std::cout << "l -> show the list of items\n";
    std::cout << "r -> show the number of resistors\n\n";
}


void item_index(const std::vector<Item>& items) {
    std::size_t index;
    std::cout << "Type a number to show that item in the list:\n";
    std::cin >> index;

    for (std::size_t i = 0; i < items.size(); ++i) {
        if (i == index) {
            print_item(items[i]);
        }
    }
    std::cout << std::endl;
}
