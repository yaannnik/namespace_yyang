#include <MyArgParser.h>

namespace yyang {
ArgParser::ArgParser(int argc, char** argv)
{
    for (size_t i = 0; i < argc; i++) {
        std::string arg = argv[i];  // "--help" style
        if (arg.rfind("--", 0) == 0) {
            std::string key = arg;
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                args[key] = argv[i + 1];
                i++;
            } else {
                flags.emplace(key);
            }
        }
    }
}

std::string ArgParser::getStr(const std::string& key, const std::string& defaultStr) {
    auto it = args.find(key);
    if (it != args.end()) {
        return it->second;
    }
    return defaultStr;
}

int ArgParser::getInt(const std::string& key, int defaultInt) {
    auto it = args.find(key);
    if (it != args.end()) {
        return std::atoi(it->second.c_str());
    }
    return defaultInt;
}

bool ArgParser::getFlag(const std::string& key) {
    return flags.count(key);
}
}  // namespace yyang