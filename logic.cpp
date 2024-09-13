#include "logic.h"
#include "funcs.h"
#include <iostream>
#include <string>

namespace logic{
    void log_find_word(std::string word, std::string filename, int option){
        char* cline = nullptr, *cword = nullptr, *cresult;

        std::ifstream file;
        file.open(filename);
        if (!file){
            throw std::runtime_error("Проверьте корректность файла!");
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string line = buffer.str();

        try{
            switch(option){
                case 1:
                    cword = new char[(int)word.size() + 1];
                    cword[(int)word.size()] = '\0';

                    cline = new char[(int)line.size() + 1];
                    cline[(int)line.size()] = '\0';

                    std::copy(word.begin(), word.end(), cword);
                    std::copy(line.begin(), line.end(), cline);

                    cresult = lab1::find_word(cword, cline);
                    std::cout << cresult << std::endl;
        
                    delete[] cword;
                    delete[] cline;
                    delete[] cresult;
                    break;
                case 2:
                    std::cout << lab1::find_word(word, line) << std::endl;
                    break;
            }
        }
        catch(const std::bad_alloc& e){
            delete[] cword;
            delete[] cline;
            throw;
        }
    }
}
