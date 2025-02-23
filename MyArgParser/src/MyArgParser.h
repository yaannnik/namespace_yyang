#pragma once

#include <unordered_map>
#include <unordered_set>

namespace yyang {
class ArgParser
{
    private:
    std::unordered_map<std::string, std::string> args;
    std::unordered_set<std::string>              flags;

    public:
    ArgParser(int args, char** argv);
    std::string getStr(const std::string& key, const std::string& defaultStr = "");
    int         getInt(const std::string& key, int defaultInt = 0);
    bool        getFlag(const std::string& key);
};
}  // namespace yyang