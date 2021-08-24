#pragma once

#include <concepts>
#include <memory>
#include <string>
#include <typeinfo>

// This concept tests whether 'T::value' is a valid expression which can be implicitly converted to bool
// 'std::convertible_to' is a concept defined in <concepts>
template<typename T>
concept has_key_value_member = requires { { T::key } -> std::convertible_to<std::string>; };

#define KEYTYPE static constexpr char key[]
#define KEYTYPEGET virtual const char* getKey() const { return key; } 

struct Model { 
	virtual ~Model() = default;
	KEYTYPE = "model.type";
	KEYTYPEGET
};

using _ModelType = std::unique_ptr<Model>;

