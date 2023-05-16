#include <iostream>
#include <vector>

#include "commands/help.hpp"

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments;

  if (argc < 2) {
    help::run();
  }

  // Read command-line arguments into the vector
  for (int i = 1; i < argc; ++i) {
    arguments.push_back(argv[i]);
  }

  // Print the arguments
  for (const std::string& argument : arguments) {
    std::cout << argument << std::endl;
  }

  return 0;
}