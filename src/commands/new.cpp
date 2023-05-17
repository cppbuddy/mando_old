#include "new.hpp"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "init.hpp"

namespace new_package {

namespace error {

void missing_path() {
  std::cout << "\033[0;31merror: \033[0m";
  std::cout << "the following required arguments were not provided:\n";
  std::cout << "\033[0;32m    <path> \033[0m\n\n";
  std::cout << "Usage: mando new <path>\n\n";
  std::cout << "For more information, try '--help'." << std::endl;
  exit(1);
}

void folder_exists(const std::string& path) {
  std::cout << "\033[0;31merror: \033[0m";
  std::cout << "destination ";
  std::cout << std::filesystem::canonical(path);
  std::cout << " already exists\n\n";
  std::cout << "Use `mando init` to initialize the directory." << std::endl;
  exit(1);
}
}  // namespace error

void run(const std::vector<std::string>& arguments) {
  if (arguments.size() < 2) {
    error::missing_path();
  }

  const auto& path = arguments.at(1);

  if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
    error::folder_exists(path);
  } else {
    std::filesystem::path folder_path = path;

    std::filesystem::create_directories(folder_path);
    init::package(folder_path);

    std::cout << "\033[1;32m    Created \033[0m";
    std::cout << "binary (application) `";
    std::cout << path;
    std::cout << "` package" << std::endl;
  }
}

}  // namespace new_package