#pragma once

#include "../../CommandHandler.h"

struct CommandWarn : public CommandHandler, Client {
	CommandWarn() = default;

	bool Execute(std::shared_ptr<Client> executor, const std::vector<std::string>& args = std::initializer_list<std::string>()) override {
		try {
			auto client = this->_clients[args.at(0)];
			auto reason = (args.at(1) != "") ? args.at(1) : "No reason specified";
			if (client) {
				spdlog::info("Warning {} for Reason: {}", client->GetName(), reason);
				return true;
			}
		} catch (std::exception& e) {
			spdlog::warn("Not enough arguments. Error: {}", e.what());
			return false;
		}
	}

	~CommandWarn() = default;
};