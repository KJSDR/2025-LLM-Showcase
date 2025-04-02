#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

// Function to convert string lowercase
std::string toLowerCase(const std::string& text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to remove punctuation from string
std::string removePunctuation(const std::string& text) {
    std::string result;
    std::remove_copy_if(text.begin(), text.end(), std::back_inserter(result), ::ispunct);
    return result;
}

// Function to tokenize string to words
std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::istringstream stream(text);
    std::string word;
    while (stream >> word) {
        tokens.push_back(word);
    }
    return tokens;
}

int main() {
    std::string inputText = "Hello, World! This is a sample text for LLM data preparation.";

    // convert to lowercase
    std::string lowerText = toLowerCase(inputText);

    // remove punctuation
    std::string cleanedText = removePunctuation(lowerText);

    // tokenize text
    std::vector<std::string> tokens = tokenize(cleanedText);

    // output tokens
    std::cout << "Tokens:" << std::endl;
    for (const auto& token : tokens) {
        std::cout << token << std::endl;
    }

    return 0;
}
