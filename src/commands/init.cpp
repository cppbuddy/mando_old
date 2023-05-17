#include "init.hpp"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace init {

namespace error {}  // namespace error

void package(const std::filesystem::path& path) {
  std::ofstream file(path / "Mando.toml");

  if (file.is_open()) {
    file << "[package]\n";
    file << "name = \"";
    file << path.filename();
    file << "\"\n";
    file << "version = \"0.1.0\"\n";
    file << "edition = \"2023\"\n\n";
    file << "# See more keys and their definitions at TBD\n\n";
    file << "[dependencies]" << std::endl;

    file.close();
  }

  file = std::ofstream(path / ".clang-tidy");
  file = std::ofstream(path / ".clang-format");
  // file = std::ofstream(path / ".bazelrc");

  auto folder_Path = path / "src";

  std::filesystem::create_directories(folder_Path);

  file = std::ofstream(folder_Path / "BUILD");

  if (file.is_open()) {
    file << "load(\"@rules_cc//cc:defs.bzl\", \"cc_binary\")\n\n";
    file << "cc_binary(\n";
    file << "    name = ";
    file << path.filename();
    file << ",\n";
    file << "    srcs = glob([\"**/*.cpp\", \"**/*.cc\", \"**/*.hpp\", "
            "\"**/*.h\"]),\n";
    file << ")";

    file.close();
  }

  file = std::ofstream(folder_Path / "main.cpp");

  if (file.is_open()) {
    file << "#include <iostream>\n\n";
    file << "int main() {\n";
    file << "    std::cout << \"Hello World!\";\n";
    file << "    return 0;\n";
    file << "}";

    file.close();
  }
}

void run(const std::vector<std::string>& arguments) {}

}  // namespace init