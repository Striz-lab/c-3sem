#include <iostream>
#include <vector>

void LG_sort(std::vector<std::string>& words) {
    for (int i = 0; i < words.size() - 1; ++i) {
        for (int j = 0; j < words.size() - i - 1; ) {
            if (words[j] < words[j + 1]) {
                std::swap(words[j], words[j + 1]);
                ++j;
            } else if (words[j] == words[j + 1]) {
                words.erase(words.begin() + j);
            } else {
                ++j;
            }
        }
    }
}

void to_lower(std::string& str) {
    for (auto& i : str) {
        i = tolower(i);
    }
}

int main() {
    int size;
    std::cin >> size;
    std::vector<std::string> words;
    words.reserve(size);
    
    for (int i = 0; i < size; ++i) {
        std::string inp;
        std::cin >> inp;
        to_lower(inp);
        words.push_back(inp);
    }
    
    LG_sort(words);
    
    for (auto& word : words) {
        std::cout << word << ' ';
    }
    std::cout << std::endl;
}
