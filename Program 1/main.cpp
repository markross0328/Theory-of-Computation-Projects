#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cctype>

bool is_operator(char c)
{
    return c == '+' || c == '-';
}

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

bool is_valid_literal(const std::string &literal)
{
    bool has_digit = false;
    bool has_decimal = false;

    for (int i = 0; i < literal.length(); i++)
    {
        char c = literal[i];
        if (is_digit(c))
        {
            has_digit = true;
            continue;
        }
        else if (c == '.')
        {
            if (has_decimal)
            {
                return false;
            }
            has_decimal = true;
            continue;
        }
        else if (i == 0 && is_operator(c))
        {
            continue;
        }
        else if (c == 'e' || c == 'E')
        {
            if (i == 0 || i == literal.length() - 1)
            {
                return false;
            }
            continue;
        }
        else if (literal[i - 1] == 'e' || literal[i - 1] == 'E' && is_operator(c))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return has_digit; // return true if the literal has at least one digit
}

// void trim(std::string &s)
// {
//     s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isspace(c); }));
//     s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !std::isspace(c); }).base(), s.end());
// }

/*
void trim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), 
        [](int c) -> bool { return !std::isspace(c); }));
    s.erase(std::find_if(s.rbegin(), s.rend(), 
        [](int c) -> bool { return !std::isspace(c); }).base(), s.end());
}
*/

void trim(std::string &s)
{
    s.erase(s.begin(),
            std::find_if(s.begin(), s.end(),
                [](unsigned char c) { return !std::isspace(c); }));

    s.erase(std::find_if(s.rbegin(), s.rend(),
                [](unsigned char c) { return !std::isspace(c); }).base(),
            s.end());
}

/*
void trim(std::string &s)
{
    // Find the position of the first non-whitespace character
    std::size_t start = s.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos)
    {
        // The string is all whitespace or empty
        s.clear();
        return;
    }

    // Find the position of the last non-whitespace character
    std::size_t end = s.find_last_not_of(" \t\n\r\f\v");

    // Rebuild the string to just contain the trimmed portion
    s = s.substr(start, end - start + 1);
}
*/

int main(int argc, char *argv[])
{

    char ch;
    if (argc < 2)
    {
        std::cout << "Usage: PR <filename>\n";
        return 1;
    }

    std::string filename = argv[1];
    size_t pos = filename.find_last_of(".");
    std::string output_filename = filename.substr(0, pos) + "_output.txt";
    std::ofstream out(output_filename, std::ios::app);
    std::ifstream in(filename);
    if (!in)
    {
        std::cout << "Error: Cannot open file.";
        return 1;
        // process error
    }
    std::cout << "Validating numeric literals...\n";
    do
    {
        std::string literal;
        if (std::getline(in, literal))
        {

            trim(literal);
            bool valid_literal = is_valid_literal(literal);

            int width_literal = 52;
            int width_message = 35;

            std::cout << std::left << std::setw(width_literal) << std::setfill(' ') << literal
                      << std::setw(width_message) << std::setfill(' ')
                      << (valid_literal ? "is a valid numeric literal" : "is NOT a valid numeric literal") << '\n';

            out << std::left << std::setw(width_literal) << std::setfill(' ') << literal
                << std::setw(width_message) << std::setfill(' ')
                << (valid_literal ? "is a valid numeric literal" : "is NOT a valid numeric literal") << '\n';
        }
    } while (!in.eof());

    out.close();
    in.close();
}
