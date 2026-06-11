#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "inventory.hpp"

#include <vector>


// ask the user to enter a new item on the command-line;
// add the new item to the given list and return the count increased by one
// (since there is one more element in the inventory array)
void add_item(std::vector<Item>& items);

// print given item to stdout
void print_item(Item i);

// print all items, one per line
void print_items(const std::vector<Item>& items);

// command-line interface to create and manage an inventory
// start a loop that asks the user which action they want to perform
// `a` -> create a new item and add it to the inventory array
// `c` -> show the number of capacitors
// `e` -> exit the program
// `i n` -> show the n-th item (0-indexed) of the inventory array
// `h` -> show this help text
// `l` -> show the list of items
// `r` -> show the number of resistors
void cli();

#endif