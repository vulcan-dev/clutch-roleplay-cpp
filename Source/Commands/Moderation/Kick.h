#pragma once

#include "../../CommandHandler.h"

struct CommandKick : public CommandHandler, Client {
	CommandKick() = default;

	bool Execute(std::shared_ptr<Client> executor, const std::vector<std::string>& args = std::initializer_list<std::string>()) override {
		try {
			auto client = this->_clients[args.at(0)];
			if (client) {
				spdlog::info("Kicking {}", client->GetName());
				return true;
			}
		} catch (std::exception&) {
			spdlog::warn("Not enough arguments");
			return false;
		}
	}

	~CommandKick() = default;
};