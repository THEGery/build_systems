#ifndef INVENTORY_HPP 
#define INVENTORY_HPP

#include <cstdint>
#include <string>
#include <vector>

struct Item;

struct Item {
    std::string component_type;
    uint32_t quantity;
    double component_value;
    std::string unit;
};

// Return the total number of resistors in the inventory.
// Eg. there are 100 resistors with 330 ohm, 50 with 5600 ohm and 10 with
// 2 megaohm, the total number is 160.
std::size_t count_resistors(const std::vector<Item>& items);

// Return the total number of capacitors in the inventory.
std::size_t count_capacitors(const std::vector<Item>& items);

#endif