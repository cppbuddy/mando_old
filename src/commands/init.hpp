#ifndef COMMANDS_INIT_HPP_
#define COMMANDS_INIT_HPP_

#include <vector>
#include <string>
#include <filesystem>

namespace init {

void package(const std::filesystem::path& path);

void run(const std::vector<std::string>& arguments);

}

#endif  // COMMANDS_INIT_HPP_