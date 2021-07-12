#pragma once

#include "Client.h"
#include <memory>
#include <vector>

struct CommandHandler {
	CommandHandler() = default;
	CommandHandler& operator=(const CommandHandler&) = delete;

	virtual bool Execute(std::shared_ptr<Client> executor, const std::vector<std::string>& args) = 0;

	virtual ~CommandHandler() = default;
};