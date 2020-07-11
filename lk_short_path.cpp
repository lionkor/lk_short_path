#include <iostream>
#include <string>
#include <algorithm>
#include <filesystem>
#include <utility>
#include <cassert>
#include <vector>
#include <cassert>
#include <sstream>

static std::string shortened(std::string);

int main(int argc, char** argv) {
    std::string path = std::filesystem::current_path();

    std::cout << shortened(path) << std::endl;
}

static std::string shortened(std::string path) {
    if (path == "/") {
        return path;
    }

    // remove trailing slash
    if (path.rfind('/') == path.size() - 1) {
        path = path.substr(0, path.size() - 1);
    }

    std::string home = std::getenv("HOME");
    if (path.substr(0, home.size()) == home) {
        path = "~" + path.substr(home.size());
    }

    // exit early if it's root ("/") or home ("~")
    if (path == "/" || path == "~") {
        return path;
    }

    std::stringstream ss;

    bool last_was_slash = true;
    for (auto iter = path.begin(); iter != path.end(); ++iter) {
        char& c = *iter;
        if (c == '/') {
            // is this the end of the string?
            if (iter == path.end() - 1) {
                // we're done (ignore trailing '/')
                break;
            } else {
                // note that the last char was a slash
                // }
                last_was_slash = true;
            }
        } else if (last_was_slash) {
            // we're at a char after a slash
            // check if there's more slashes
            if (path.begin() + path.rfind('/') > iter) {
                // yes more slashes
                if (iter != path.begin()) {
                    ss << '/';
                }
                ss << c;
                last_was_slash = false;
            } else {
                // no more slashes, add everything and break
                ss << "/" << iter.base();
                break;
            }
        }
    }
    return ss.str();
}

