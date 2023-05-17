#include "help.hpp"

#include <iostream>

namespace help {

void run() {
  std::cout << "C++'s package manager\n\n";
  std::cout << "Usage: mando [+toolchain] [OPTIONS] [COMMAND]\n\n";
  std::cout
      << "Some common mando commands are (see all commands with --list):\n\n";
  std::cout << "    new         Create a new mando package\n\n";
  std::cout << "See 'mando help <command>' for more information on a specific "
               "command."
            << std::endl;
}

}  // namespace help