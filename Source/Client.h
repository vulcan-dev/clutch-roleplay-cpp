#pragma once

#include "./Vehicle.h"

class Client : Vehicle {
public:
	Client() { ++this->_id; };
	Client& operator=(const Client&) = delete;

	void Create(std::string_view name) {
		this->_name = name;
		this->_clients.insert(std::make_pair(name, this));
	}

	inline const std::map<std::string, Vehicle*> GetVehicles() const { return this->_vehicles; }
	inline const std::string& GetName() const { return this->_name; }
	inline const uint64_t GetID() const { return this->_id; }

	bool AddVehicle(Vehicle* vehicle);
	static inline std::map<std::string, Client*> _clients = {};

	~Client() { --this->_id; };


private:
	std::map<std::string, Vehicle*> _vehicles;
	std::string _name = "";
	uint64_t _id = 0;
};