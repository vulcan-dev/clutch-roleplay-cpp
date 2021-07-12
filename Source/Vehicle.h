#pragma once

#include <spdlog/spdlog.h>

#include <string>
#include <random>
#include <map>

class Vehicle {
public:
	Vehicle() = default;
	Vehicle(std::string_view name) : _name(name) {
		std::random_device randomDevice;
		std::default_random_engine engine(randomDevice());
		std::uniform_int_distribution<uint64_t> uniform(1, 200000);

		this->_id = uniform(engine);
	}

	Vehicle& operator=(Vehicle&) = delete;

	const std::string& GetName() const { return this->_name; }
	const uint64_t& GetID() const { return this->_id; }

	~Vehicle() = default;

protected:
	std::string _name = "";
	uint64_t _id = 0;
};