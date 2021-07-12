#pragma once

#include "Moderation/Kick.h"
#include "Moderation/Ban.h"
#include "Moderation/Warn.h"

#include <filesystem>
#include <string>

void InitializeCommands(std::map<std::string, CommandHandler*>& commands) {
	spdlog::info("Initializing Commands");

	try {
		for (const auto& file : std::filesystem::directory_iterator("Source/Commands/Moderation")) {
			spdlog::info("Command File: {}", file.path().filename().string());
		}

		commands.insert(std::make_pair("kick", new CommandKick()));
		commands.insert(std::make_pair("ban", new CommandBan()));
		commands.insert(std::make_pair("warn", new CommandWarn()));
	} catch (std::exception& e) {
		spdlog::error("Failed creating command\nError: {}", e.what());
	}
}	