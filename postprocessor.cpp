#include <iostream>
#include <algorithm>
#include <cctype>
#include <unordered_map>

// correct grammatical errors
std::string correctGrammar(const std::string& text) {
    std::unordered_map<std::string, std::string> corrections = {
        {"its", "it's"},
        {"your", "you're"},
        {"there", "their"},
        {"alot", "a lot"}
    };

    std::string result = text;
    for (const auto& correction : corrections) {
        size_t pos = 0;
        while ((pos = result.find(correction.first, pos)) != std::string::npos) {
            result.replace(pos, correction.first.length(), correction.second);
            pos += correction.second.length();
        }
    }
    return result;
}

// ensure consistency in the text
std::string ensureConsistency(const std::string& text) {
    std::string result = text;
    // ensure uniform capitalization of specific words
    std::unordered_map<std::string, std::string> consistency = {
        {"llm", "LLM"},
        {"ai", "AI"}
    };

    for (const auto& rule : consistency) {
        size_t pos = 0;
        while ((pos = result.find(rule.first, pos)) != std::string::npos) {
            result.replace(pos, rule.first.length(), rule.second);
            pos += rule.second.length();
        }
    }
    return result;
}

int main() {
    std::string inputText = "The LLM generated text with some common errors. Its important to correct them. Your model should ensure consistency and alot of accuracy.";

    // correct grammar
    std::string correctedText = correctGrammar(inputText);

    // ensure consistency
    std::string consistentText = ensureConsistency(correctedText);

    // output the refined text
    std::cout << "Refined Text:" << std::endl;
    std::cout << consistentText << std::endl;

    return 0;
}
