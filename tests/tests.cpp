#include <gtest/gtest.h>
#include "../dialog.h"
#include "../logic.h"
#include "../funcs.h"

// тесты для модуля dialog
TEST(DialogTest, ChoosingImplementationFirst) {
    std::istringstream input("1\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(dialog::choosing_implementation());
}


TEST(DialogTest, ChoosingImplementationSecond) {
    std::istringstream input("2\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(dialog::choosing_implementation());
}

TEST(DialogTest, ChoosingImplementationEOF) {
    std::istringstream input(""); // ввод EOF
    std::cin.rdbuf(input.rdbuf());
    EXPECT_THROW(dialog::choosing_implementation(), std::runtime_error);
}

TEST(DialogTest, ChoosingImplementationIncorrect) {
    std::istringstream input("asd\n1\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(dialog::choosing_implementation());
}


TEST(DialogTest, InputDataGood) {
    std::istringstream input("");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(dialog::input_data(1));
}

TEST(DialogTest, InputDataBad) {
    std::istringstream input("example.txt\nsam\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_NO_THROW(dialog::input_data(1));
}


TEST(DialogTest, GetInputCinBad) {
    std::istringstream input("test\n");
    std::cin.rdbuf(input.rdbuf());

    std::cin.clear();
    std::cin.setstate(std::ios::badbit);

    EXPECT_THROW(dialog::get_input<std::string>(), std::runtime_error);
}


// тесты для модуля logic
TEST(LogicTest, FindWordTestGood) {
    std::string word = "saM";
    std::string filename = "example.txt";
    
    EXPECT_NO_THROW(logic::log_find_word(word, filename, 2));
}


TEST(LogicTest, FileNotFoundTest) {
    std::string word = "example";
    std::string filename = "non_existing_file.txt"; // Несуществующий файл
    
    EXPECT_THROW(logic::log_find_word(word, filename, 1), std::runtime_error);
}


// тесты для модуля funcs
TEST(FuncsTest, FindWordTestString) {
    std::string word = "there_is_no_such_word";
    
    std::string result = lab1::find_word(word, "An example\n of a\n string that\n does not\n contain \na word");
    std::string expected = "Совпадений не найдено.\n";

    EXPECT_EQ(result, expected);
}


TEST(FuncsTest, FindWordTestChar) {
    const char* word = "there_is_no_such_word";
    const char* line = "An example\n of a\n string that\n does not\n contain \na word";

    char* result = lab1::find_word(word, line);
    std::string result_str(result);
    std::string expected = "Совпадений не найдено.\n";

    EXPECT_EQ(result_str, expected);

    delete[] result;
}