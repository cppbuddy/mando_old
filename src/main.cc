#include <iostream>
#include <vector>

#include "commands/help.hpp"
#include "commands/new.hpp"

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments;

  if (argc < 2) {
    help::run();
    return 1;
  }

  // Read command-line arguments into the vector
  for (int i = 1; i < argc; ++i) {
    arguments.push_back(argv[i]);
  }

  if (arguments.at(0) == "new") {
    new_package::run(arguments);
  }

  return 0;
}