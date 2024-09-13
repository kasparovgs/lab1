# Substring Search Program

## Описание

Этот проект представляет собой программу для поиска подстроки в содержимом файла. Программа позволяет искать заданное слово в файле и выводит результат поиска в формате `номер строки: сама строка`, где встречается слово.

## Быстрый старт

Чтобы запустить проект, выполните следующие шаги:

1. Создайте директорию для сборки:
    ```bash
    mkdir build
    ```

2. Перейдите в директорию сборки:
    ```bash
    cd build
    ```

3. Запустите CMake для генерации файлов сборки:
    ```bash
    cmake ..
    ```

4. Составьте проект с помощью Make:
    ```bash
    make
    ```

5. После успешной сборки вы сможете запустить программу из директории `build`.

## Использование

1. Запустите программу:
    ```bash
    ./main
    ```

2. Следуйте инструкциям на экране для выбора файла и слова для поиска.

## Примеры

Для примера, если файл `example.txt` содержит следующий текст:
```
I AM SAM. I AM SAM. SAM I AM.
THAT SAM-I-AM! THAT SAM-I-AM! I DO NOT LIKE THAT SAM-I-AM!
DO WOULD YOU LIKE GREEN EGGS AND HAM?
I DO NOT LIKE THEM,SAM-I-AM.
I DO NOT LIKE GREEN EGGS AND HAM.
```
И вы ищете слово `SaM`, программа выведет:
```
1: I AM SAM. I AM SAM. SAM I AM.
2: THAT SAM-I-AM! THAT SAM-I-AM! I DO NOT LIKE THAT SAM-I-AM!
4: I DO NOT LIKE THEM,SAM-I-AM.
```

## Тестирование

Для запуска тестов и проверки покрытия кода выполните следующие шаги:

1. Перейдите в директорию с тестами:
    ```bash
    cd tests
    ```

2. Сгенерируйте файлы для тестирования в режиме отладки:
    ```bash
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
    ```

3. Соберите тесты:
    ```bash
    cmake --build build
    ```

4. Запустите тесты:
    ```bash
    ./build/runTests
    ```

## Проверка покрытия кода

1. Соберите информацию о покрытии:
    ```bash
    lcov --directory . --capture --output-file coverage.info
    ```

2. Сгенерируйте HTML-отчёт:
    ```bash
    genhtml coverage.info --output-directory out
    ```

3. Отчёт о покрытии будет доступен в директории `out`.