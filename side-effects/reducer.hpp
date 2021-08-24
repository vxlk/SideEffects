#pragma once

#include "action.hpp"
#include "model.hpp"

#include <algorithm>

using ReducerFunction = std::tuple<Model, Action>;
/*
struct Reducer {
	void run(ReducerFunction reducer) {
		std::get<1>(reducer).func(std::get<0>(reducer));
	}
};
*/
