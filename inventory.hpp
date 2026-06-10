#ifndef INVENTORY_HPP 
#define INVENTORY_HPP

#include <cstdint>
#include <string>


struct Item {
    std::string component_type;
    uint32_t quantity;
    double component_value;
    std::string unit;
};

#endif