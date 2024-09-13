#include <iostream>
#include "funcs.h"
#include "dialog.h"
#include "logic.h"

namespace dialog{
    int choosing_implementation(){
        std::cout << "1. Через char*\n2. Через std::string\n0. Завершение программы" <<std::endl;
        std::cout << "Какую реализацию использовать? ";
        return get_input<int>();
    }

    void input_data(int option){
        try{
            std::string filename, word;
            std::cout << "Введите имя файла (c форматом): ";
            filename = dialog::get_input<std::string>();

            // вводим само слово, которое будем искать
            std::cout << "Введите слово: ";
            word = dialog::get_input<std::string>();

            logic::log_find_word(word, filename, option);
        }
        catch(const std::runtime_error& e){
            std::cout << "Проверьте корректность файла!" << std::endl;
        }
    }
}