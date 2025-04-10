// /**
// You are given a (potentially large) list of words. 
// Some of these are compound words, where all parts are also in the list. 
// Identify all combinations of words in the list which form a compound word which is also in the list. 
// Return the set of unique combinations.

// Example Input:
// ["rockstar", "rock", "star", "rocks", "tar", "rockstars", "super", "superhighway", "highway", "high", "way", "superhighway"]

// Example Compound: "highway" = ("high" + "way")

// Output Format: {'rockstar': [['rock', 'star'], ['rocks', 'tar']], 'rockstars': [['rock', 'stars']], 'superhighway': [['super', 'highway'], ['super', 'high', 'way']], 'highway': [['high', 'way']]}



// wayhighway = way + high  + way == valid
// **/

// #include <iostream>
// #include <unordered_map>
// #include <unordered_set>
// #include <string>
// #include <vector>

// using std::vector; 
// using std::string; 
// using std::unordered_map;
// using std::unordered_set;

// class Compound {
//     public:
//     unordered_set<string> st;
//     public:
//         unordered_map<string, vector<vector<string>>> valid_compound_words(vector<string>& words);
//     private:
//         vector<vector<string>> compoundable(const string& word, unordered_map<string, vector<vector<string>>>& mp);
// };





// vector<vector<string>> Compound::compoundable(const string& word, unordered_map<string, vector<vector<string>>>& mp) {
//     vector<vector<string>> result;

//     for(int i = 1; i < word.length(); i++) {
//         string prefix = word.substr(0, i);
//         string suffix = word.substr(i);

//         if(st.count(prefix) && (st.count(suffix) )) {
//             result.push_back({prefix, suffix});
//         }
//         vector<vector<string>> recursive = compoundable(suffix, mp);
//         if(recursive.size() > 0) {
//             for(const auto& elem : recursive) {
//                 result.push_back(elem);
//             }
//         }
//     }

//     return result;
// }

// unordered_map<string, vector<vector<string>>> Compound::valid_compound_words(vector<string>& words) {
//     unordered_map<string, vector<vector<string>>> sol;
//     for(const auto& w : words) {
//         st.insert(w);
//     }

//     for(const auto& w : words) {
//         vector<vector<string>> results = compoundable(w, sol);
//         if(results.size() > 0) {
//             sol[w] = results;     
//         }
//     }
//     return sol;
// }

// int main() {
//     Compound C;
//     unordered_map<string, vector<vector<string>>> mp;
//     vector<string> words = {"rockstar", "rock", "star", "rocks", "tar", "rockstars", "super", "superhighway", "highway", "high", "way", "superhighway"};


//     mp = C.valid_compound_words(words);
//     std::cout << "{";
//     for(const auto& pair : mp) {
//         std::cout << "\'" << pair.first <<"\': ";
//         for(int i = 0; i < pair.second.size(); i++) {
//             std::cout << "[";
//             for(int j = 0; j < pair.second[0].size(); j++) {
//                 if(j == 0) {
//                     std::cout << "[\'" << pair.second[0][j] << "\', ";
//                 } else if(j + 1 < pair.second[0].size()) {
//                     std::cout << "\'" << pair.second[0][j] << "\', ";
//                 } else {
//                     std::cout << "\'" << pair.second[0][j] << "\']";
//                 }
//             }             
//             std::cout << "]";
//         }
//         if(mp.size())
//         std::cout << ", ";
//     }
//     std::cout <<"}\n";
//     return 0;
// }
// // Output format
// // {'rockstar': [['rock', 'star'], ['rocks', 'tar']], 'rockstars': [['rock', 'stars']], 'superhighway': [['super', 'highway'], ['super', 'high', 'way']], 'highway': [['high', 'way']]}



#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;

class Compound {
public:
    unordered_set<string> wordSet;
    
    unordered_map<string, vector<vector<string>>> valid_compound_words(vector<string>& words);
    
private:
    bool canForm(const string& word, vector<string>& current, vector<vector<string>>& result);
    vector<vector<string>> findCompounds(const string& word);
};

bool Compound::canForm(const string& word, vector<string>& current, vector<vector<string>>& result) {
    if (word.empty()) {
        // We've consumed the entire word successfully
        if (current.size() > 1) { // Ensure it's actually a compound (more than 1 part)
            result.push_back(current);
        }
        return current.size() > 1;
    }
    
    bool canFormCompound = false;
    
    // Try all possible prefixes
    for (int i = 1; i <= word.length(); i++) {
        string prefix = word.substr(0, i);
        
        // If this prefix is a valid word
        if (wordSet.count(prefix)) {
            current.push_back(prefix);
            
            // Recursively check if the remainder can form a compound
            string suffix = word.substr(i);
            canFormCompound |= canForm(suffix, current, result);
            
            // Backtrack
            current.pop_back();
        }
    }
    
    return canFormCompound;
}

vector<vector<string>> Compound::findCompounds(const string& word) {
    vector<vector<string>> result;
    vector<string> current;
    
    canForm(word, current, result);
    return result;
}

unordered_map<string, vector<vector<string>>> Compound::valid_compound_words(vector<string>& words) {
    unordered_map<string, vector<vector<string>>> sol;
    
    // First, add all words to the set
    for (const auto& w : words) {
        wordSet.insert(w);
    }
    
    // Then, for each word, check if it can be formed as a compound
    for (const auto& word : words) {
        vector<vector<string>> compounds = findCompounds(word);
        if (!compounds.empty()) {
            sol[word] = compounds;
        }
    }
    
    return sol;
}

// Helper function to print the result in the expected format
void printResult(const unordered_map<string, vector<vector<string>>>& result) {
    std::cout << "{";
    bool firstWord = true;
    
    for (const auto& [word, combinations] : result) {
        if (!firstWord) {
            std::cout << ", ";
        }
        firstWord = false;
        
        std::cout << "'" << word << "': [";
        
        for (size_t i = 0; i < combinations.size(); i++) {
            if (i > 0) {
                std::cout << ", ";
            }
            
            std::cout << "[";
            for (size_t j = 0; j < combinations[i].size(); j++) {
                if (j > 0) {
                    std::cout << ", ";
                }
                std::cout << "'" << combinations[i][j] << "'";
            }
            std::cout << "]";
        }
        
        std::cout << "]";
    }
    
    std::cout << "}" << std::endl;
}

int main() {
    Compound C;
    vector<string> words = {"rockstar", "rock", "star", "rocks", "tar", "rockstars", "super", "superhighway", "highway", "high", "way", "superhighway"};
    
    auto result = C.valid_compound_words(words);
    printResult(result);
    
    return 0;
}