#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class SigmaStar {
private:
    vector<char> alphabet;

public:
    // Constructor that takes a string representing the alphabet
    SigmaStar(const string& alpha) {
        for (char c : alpha) {
            if (find(alphabet.begin(), alphabet.end(), c) == alphabet.end()) {
                alphabet.push_back(c);
            }
        }
    }

    // Returns the alphabet
    vector<char> getAlphabet() const {
        return alphabet;
    }

    // Generate all strings up to a given length
    vector<string> generateStrings(int maxLength) const {
        vector<string> result;
        
        // Add the empty string
        result.push_back("");
        
        // For each length from 1 to maxLength
        for (int length = 1; length <= maxLength; length++) {
            vector<string> stringsOfLength = generateStringsOfLength(length);
            result.insert(result.end(), stringsOfLength.begin(), stringsOfLength.end());
        }
        
        return result;
    }

    // Generate all strings of a specific length
    vector<string> generateStringsOfLength(int length) const {
        vector<string> result;
        generateStringsHelper("", length, result);
        return result;
    }

    // Check if a string belongs to the language (sigma*)
    bool belongsToLanguage(const string& str) const {
        for (char c : str) {
            if (find(alphabet.begin(), alphabet.end(), c) == alphabet.end()) {
                return false;
            }
        }
        return true;
    }

    // Concatenate two languages (all possible combinations)
    static vector<string> concatenate(const vector<string>& language1, const vector<string>& language2) {
        set<string> resultSet;  // Using set to avoid duplicates
        
        for (const string& str1 : language1) {
            for (const string& str2 : language2) {
                resultSet.insert(str1 + str2);
            }
        }
        
        vector<string> result(resultSet.begin(), resultSet.end());
        return result;
    }

    // Apply Kleene star operation to a language (up to a certain length)
    static vector<string> kleeneStar(const vector<string>& language, int maxLength) {
        set<string> resultSet;
        
        // Empty string is always in Kleene star
        resultSet.insert("");
        
        // Start with the original language
        vector<string> current = language;
        
        // Add the original language
        for (const string& str : language) {
            if (str.length() <= maxLength) {
                resultSet.insert(str);
            }
        }
        
        // Compute L², L³, ..., until we reach maxLength
        for (int i = 2; i <= maxLength; i++) {
            vector<string> newStrings = concatenate(current, language);
            current = newStrings;
            
            for (const string& str : newStrings) {
                if (str.length() <= maxLength) {
                    resultSet.insert(str);
                }
            }
        }
        
        vector<string> result(resultSet.begin(), resultSet.end());
        return result;
    }

private:
    // Helper function for generating strings recursively
    void generateStringsHelper(const string& prefix, int remaining, vector<string>& result) const {
        if (remaining == 0) {
            result.push_back(prefix);
            return;
        }
        
        for (char c : alphabet) {
            generateStringsHelper(prefix + c, remaining - 1, result);
        }
    }
};

int main() {
    string alphabetStr;
    cout << "Enter the alphabet (e.g., 'ab' for {a,b}): ";
    cin >> alphabetStr;
    
    SigmaStar language(alphabetStr);
    
    int maxLength;
    cout << "Enter the maximum length of strings to generate: ";
    cin >> maxLength;
    
    vector<string> strings = language.generateStrings(maxLength);
    
    cout << "\nStrings in Sigma* up to length " << maxLength << ":" << endl;
    for (const string& str : strings) {
        int count = 0;
        if (str.empty()) {
            cout << "e -> " << count << endl;
        } else {
            count++;
            cout << str << " -> " << count << endl;
        }
    }
    
    cout << "\nTotal number of strings: " << strings.size() << endl;
    
    // Demonstrate string validation
    string testStr;
    cout << "\nEnter a string to check if it belongs to the language: ";
    cin >> testStr;
    
    if (language.belongsToLanguage(testStr)) {
        cout << "'" << testStr << "' belongs to the language." << endl;
    } else {
        cout << "'" << testStr << "' does not belong to the language." << endl;
    }
    
    // Demonstrate concatenation
    cout << "\nDemonstrating concatenation of {a,b} and {c,d}:" << endl;
    vector<string> lang1 = {"a", "b"};
    vector<string> lang2 = {"c", "d"};
    vector<string> concatenated = SigmaStar::concatenate(lang1, lang2);
    
    cout << "Result: {";
    for (size_t i = 0; i < concatenated.size(); i++) {
        cout << concatenated[i];
        if (i < concatenated.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    
    // Demonstrate Kleene star
    cout << "\nDemonstrating Kleene star of {a,b} with max length 2:" << endl;
    vector<string> kleeneResult = SigmaStar::kleeneStar(lang1, 2);
    
    cout << "Result: {";
    for (size_t i = 0; i < kleeneResult.size(); i++) {
        if (kleeneResult[i].empty()) {
            cout << "ε";
        } else {
            cout << kleeneResult[i];
        }
        if (i < kleeneResult.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    
    return 0;
} 