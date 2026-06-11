cmake_minimum_required(VERSION 3.18)
project(build_systems LANGUAGES CXX)

# IMS program
add_executable(ims
    inventory.cpp
    interface.cpp
    inventory_cli.cpp
)

target_compile_features(ims PRIVATE cxx_std_20)
target_compile_options(ims PRIVATE -Wall -Wextra)

# calculate_resistance
add_executable(calculate_resistance
circuit.cpp
ui.cpp
circuit_cli.cpp
)

target_compile_features(calculate_resistance PRIVATE cxx_std_20)
target_compile_options(calculate_resistance PRIVATE -Wall -Wextra)
