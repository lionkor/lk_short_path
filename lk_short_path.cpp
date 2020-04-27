#include <iostream>
#include <string>
#include <algorithm>
#include <filesystem>
#include <utility>
#include <cassert>
#include <vector>

static std::string replace(const std::string& str,
    const std::string& to_replace, const std::string& with);

static std::vector<std::string> split(const std::string& str, char c);

int main() {
    std::string path = std::filesystem::current_path();

    if (path == "/") {
        std::cout << path;
        return 0;
    }

    std::string home = std::getenv("HOME");
    path             = replace(path, home, "~");

    auto        splits = split(path, '/');
    std::string short_path {};
    for (auto& str : splits) {
        if (str.size() == 0) {
            short_path += "/";
        } else if (str == splits.at(splits.size() - 1)) {
            short_path += str;
        } else {
            short_path += str[0];
            short_path += "/";
        }
    }
    std::cout << short_path;
}

static std::string replace(const std::string& str,
    const std::string& to_replace, const std::string& with) {
    std::string new_str;
    for (std::size_t i = 0; i < str.size(); ++i) {
        if (str.substr(i, to_replace.size()) == to_replace) {
            new_str += with;
            i += to_replace.size() - 1;
        } else {
            new_str += str[i];
        }
    }
    return new_str;
}

static std::vector<std::string> split(const std::string& str, char c) {
    std::vector<std::string> parts;
    std::string              current_part;
    for (std::size_t i = 0; i < str.size(); ++i) {
        if (str[i] == c) {
            parts.push_back(current_part);
            current_part.clear();
        } else {
            current_part += str[i];
        }
    }
    parts.push_back(current_part);
    return parts;
}
