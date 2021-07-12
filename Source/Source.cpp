#include <iostream>
#include <spdlog/spdlog.h>

#include "Commands/Commands.h"
#include "CommandHandler.h"
#include "Client.h"

std::vector<std::string> SplitToArgs(std::string_view str) {
	std::vector<std::string> args = std::initializer_list<std::string>();
	std::string temp = "";

	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			args.push_back(temp);
			temp = "";
		} else temp.push_back(str[i]);
	}

	args.push_back(temp);
	return args;
}

bool RunCommand(std::shared_ptr<Client> executor = nullptr, CommandHandler* command = nullptr, std::vector<std::string> args = std::initializer_list<std::string>()) {
	args.erase(args.begin());
	if (command) {
		if (!command->Execute(executor, args)) return false;
		return true;
	}

	return false;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv) {
	spdlog::set_level(spdlog::level::debug);

	std::map<std::string, CommandHandler*> commands;
	InitializeCommands(commands);

	auto cExecutor = std::make_shared<Client>();
	auto cClient = std::make_shared<Client>();

	cExecutor->Create("Executor");
	cClient->Create("Dan");

	/* Run Command */
	std::string message = "";
	std::vector<std::string> args = std::initializer_list<std::string>();

	while (message != "quit") {
		std::getline(std::cin, message, '\n');
		args = SplitToArgs(message.c_str());

		if (args[0].at(0) == '/') {
			spdlog::debug("Message: {}", message);
			args[0] = args[0].substr(1, args.at(0).length());
			if (RunCommand(cExecutor, commands[args[0]], args)) {
				for (std::size_t i = 0; i < args.size(); ++i) {
					spdlog::debug("Argument {}: {}", i, args[i]);
				}
			} else spdlog::error("Command failed");
		}
	}

	/* Clear up Memory */
	for (auto& it : commands) {
		delete it.second;
	}

	std::cin.get();
	return 0;
}