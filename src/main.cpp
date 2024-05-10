#include "utils/toml.hpp"
#include <iostream>

toml::table loadConfig(std::string config) {
  toml::table tbl;
  try {
    tbl = toml::parse_file(config);
    std::cout << "Config Loaded." << "\n";
  } catch (const toml::parse_error &err) {
    std::cerr << "Parsing failed:\n" << err << "\n";
  }

  return tbl;
}

int main(int argc, char **argv) {
  toml::table config = loadConfig("config.toml");
  std::cout << config["settings"]["name"] << " is live!\n";
  return 0;
}
