#include <iostream>
#include "lib/string.cpp"
#include "source/parser.cpp"
#include "source/printing.cpp"


int main(int a, char** arg) {
    // основные переменные для обработи аргументов
    long len;
    bool revers;
    char sep;
    Stroka del, filename;

    // вызываем функцию парсера, что бы обработать переданные аргументы
    pars(arg, a, len, revers, sep, del, filename);

    // используя аргументы из парсера выводим айл в консоль
    printFile(len, revers, sep, del, filename);
    
    return 0;
}
