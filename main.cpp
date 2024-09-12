#include <iostream>
#include "funcs.h"
#include "dialog.h"
#include "logic.h"

int main(){
    int option{};
    do{
        try{
            option = dialog::choosing_implementation();
            if (option < 0 || option > 2) { // проверка на корректность ввода
                std::cerr << "Неверный выбор. Пожалуйста, выберите от 0 до 2." << std::endl;
                continue; 
            }
            if (option == 0){
                return 1;
            }
            
            dialog::input_data(option);
        }
        catch(const std::bad_alloc& ba){
            std::cerr << "Ошибка выделения памяти" << std::endl;
            return 1;
        }
        catch (const std::runtime_error& e){
            std::cerr << "Проверьте корректность вводимых данных!" << std::endl;
            return 1;
        }
        catch(const std::exception& e){
            std::cerr << "Ошибка: " << e.what() << std::endl;
            return 1;
        }
    }while(option != 0);
    std::cout << "Завершение программы." << std::endl;
    return 0;
}