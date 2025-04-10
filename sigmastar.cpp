#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

// Forward declaration of the recursive helper function
void generate_strings(const std::vector<char>& alphabet_set, int length, std::string current, int& num_strings);

/**
 * Prints all strings in Σ* of a given length from the given alphabet set
 * @param alphabet_set The set of characters in the alphabet
 * @param length The length of strings to generate
 * @param num_strings Reference to running counter of strings generated
 * @return Empty string (for compatibility with original function)
 */
std::string print_sigmastar(const std::vector<char> alphabet_set, int length, int& num_strings) {
    // Print the header information
    std::cout << "Length = " << length << " | " << "Number of strings = " << pow(alphabet_set.size(), length) << std::endl;

    if (length == 0) {
        // The empty string case (epsilon)
        std::cout << "e -> " + std::to_string(num_strings) << std::endl;
    } else {
        // Call recursive helper to generate all strings of given length
        generate_strings(alphabet_set, length, "", num_strings);
    }
    
    return "";
}

/**
 * Recursive helper function to generate all strings of a given length
 * @param alphabet_set The set of characters in the alphabet
 * @param length The remaining length to generate
 * @param current The current string built so far
 * @param num_strings Reference to running counter of strings generated
 */
void generate_strings(const std::vector<char>& alphabet_set, int length, std::string current, int& num_strings) {
    // Base case: if we've built a string of the desired length
    if (length == 0) {
        num_strings++;
        std::cout << current << " -> " + std::to_string(num_strings) << std::endl;
        return;
    }
    
    // Recursive case: add each character in the alphabet and continue building
    for (int i = 0; i < alphabet_set.size(); i++) {
        generate_strings(alphabet_set, length - 1, current + alphabet_set[i], num_strings);
    }
}
