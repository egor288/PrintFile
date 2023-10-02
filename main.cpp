#include <iostream>
#include "source/string.cpp"
#include "source/parser.cpp"
#include "source/printing.cpp"


int main(int a, char** arg) {
    long len;
    bool revers;
    char sep;
    Stroka del, filename;

    pars(arg, a, len, revers, sep, del, filename);

    printFile(len, revers, sep, del, filename);
    
    return 0;
}
