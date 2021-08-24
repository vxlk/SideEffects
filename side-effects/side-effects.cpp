// side-effects.cpp : Defines the entry point for the application.
//

#include "side-effects.hpp"

#include <iostream>
#include <functional>

struct increment_action : Action {};
struct counter : Model { // eventually won't have inheritance :)
	KEYTYPE = "type.model.counter";
	KEYTYPEGET
	int i = 0;
};

int main()
{		
	//Model m;
	auto counter_model = counter();
	increment_action inc_action;
	inc_action.type = "Increment Action";
	inc_action.reducer = [](Model* m) {
		// this should not modify
		auto p = dynamic_cast<counter*>(m);
		p->i += 1;
		std::cout << "in my callback function :)";
	};
	inc_action.effects.add_effect<counter>([]() {
		int i = 0;
	});
	// assumes c++17
	store.link(inc_action.type, counter_model);
	store.dispatch(inc_action);
	return 0;
}
