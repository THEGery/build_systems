#include "inventory.hpp"


std::size_t count_resistors(const std::vector<Item>& items) {
    std::size_t resistor_count;
    char type[] = "resistor";

    for (std::size_t i = 0; i < items.size(); ++i) {
        if (items[i].component_type == type) {
            resistor_count += items[i].quantity;
        }
    }
    return resistor_count;
}


std::size_t count_capacitors(const std::vector<Item>& items) {
    std::size_t capacitor_count;
    char type[] = "capacitor";

    for (std::size_t i = 0; i < items.size(); ++i) {
        if (items[i].component_type == type) {
            capacitor_count += items[i].quantity;
        }
    }
    return capacitor_count;
}