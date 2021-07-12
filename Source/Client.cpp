#include "Client.h"

bool Client::AddVehicle(Vehicle* vehicle) {
	this->_vehicles.insert(std::make_pair(this->GetName(), vehicle));
	spdlog::info("{} Added vehicle {}", GetName(), vehicle->GetName());

	return true;
}