#include <regex>
#include <iostream>
#include <string>
#include <algorithm>


std::string trim(const std::string& s);
int main(int argc, char *argv[])
{
    // std::string s = "b*a*";

    // std::regex r("a*b*");

    // if (std::regex_match(s, r))
    // {
    // std::cout << "true" << std::endl;
    // }
    // else
    // {
    // std::cout << "false" << std::endl;
    // }

    std::string s = "             d     testing lambda function              d ";
    std::string d = "            d       testing trim function              d              ";

    // Remove leading spaces
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char c)
                                    { return !std::isspace(c); }));

    // Remove trailing spaces
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char c)
                         { return !std::isspace(c); })
                .base(),
            s.end());

    std::cout << s << std::endl;
    std::cout << trim(d) << std::endl;
    return 0;
}

bool is_valid_literal_regex(const std::string &literal)
{
    // std::regex pattern("[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?");
    // return std::regex_match(literal, pattern);
}

std::string trim(const std::string& s) {
    // Find the position of the first non-space character
    size_t start = s.find_first_not_of(" \t\n\r");

    // Find the position of the last non-space character
    size_t end = s.find_last_not_of(" \t\n\r");

    // If the string is all spaces, return an empty string
    if (start == std::string::npos) {
        return "";
    }

    // Return the trimmed string
    return s.substr(start, end - start + 1);
}