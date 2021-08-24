#pragma once

#include "state.hpp"
#include "action.hpp"
#include "reducer.hpp"

#include <functional>
#include <assert.h>

struct Store {
	// dispatch an action type
	template<typename Action>
	void dispatch(Action a) {
		auto model = std::move(state.map[a.type]);
		assert(model);
		auto base_model = *model;
		static_assert(has_key_value_member<decltype(base_model)>);
		a.reducer(model.get());

		// find effects and run them
		auto effectList = std::find_if(a.effects.map.begin(), 
									   a.effects.map.end(), 
			[&](auto&& index) { 
				auto key = decltype(base_model)::key;
				return index.first == model->getKey(); 
			});
		
		if (effectList != a.effects.map.end())
			for (auto&& reaction : effectList->second)
				reaction();
	}

	// Link actions and reducers to a model in the state system
	template <typename Model>
	void link(_Type type, Model m) {
		state.map.insert({ type , std::make_unique<Model>() });
	}
private:
	State state;
};

static Store store;
