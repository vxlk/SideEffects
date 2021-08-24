#pragma once

#include "action.hpp"
#include "model.hpp"

#include <map>
#include <string>
#include <variant>
#include <vector>

struct State {
	using StateMap = std::map< std::string, _ModelType >;
	StateMap map;
};