# CMakeList.txt : CMake project for side-effects, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)

# Add source to this project's executable.
add_executable (side-effects 
"action.hpp"
"reducer.hpp"
"state.hpp"
"store.hpp"
"model.hpp"
"hooks.hpp"
"side-effects.hpp" # having this above any other files bugs out the cmake script???
"side-effects.cpp"
)

set_property(TARGET side-effects PROPERTY CXX_STANDARD 20)

# TODO: Add tests and install targets if needed.
