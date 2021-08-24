#pragma once

#include "model.hpp"

#include <functional>
#include <map>

using _Type = std::string;

struct EffectGroup {
	using EffectMap = std::map<std::string, std::vector<std::function<void()>>>;
	EffectMap map;
	template <typename T>
	void add_effect(std::function<void()> effect) {
		static_assert(has_key_value_member<T>);
		this->map[T::key].push_back(effect);
	}
};

struct Action {
	std::function<void(Model*)> reducer = [](Model*) {};
	EffectGroup effects;
	_Type type;
};
