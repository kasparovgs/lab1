#include <iostream>
#include "funcs.h"

namespace lab1{
    std::string find_word(const std::string& word, const std::string& full_line){
        std::string word_for_find = word;
        std::string line;
        std::string result;
        int line_num = 1;
        to_lower(word_for_find);

        std::istringstream stream(full_line);

        while (std::getline(stream, line)){
            std::string lower_line = line;
            to_lower(lower_line);
            if (lower_line.find(word_for_find) != std::string::npos){ // если найдено слово
                result = result + std::to_string(line_num) + ": " + line + "\n";
            }
            line_num++;
        }
        if (result.empty()){
            result.append("Совпадений не найдено.\n");
        }
        return result;
    }


    void to_lower(std::string& str){
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){
            return std::tolower(c);
        });
    }

    
    char* find_word(const char* cword, const char* cfull_line){
        std::string result = find_word(std::string(cword), std::string(cfull_line));
        char* cresult = new char[(int)result.size() + 1];
        cresult[(int)result.size()] = '\0';
        std::copy(result.begin(), result.end(), cresult);
        return cresult;
    }
}
