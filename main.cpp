#include <iostream>
#include <fstream>
#include "string.cpp"  
#include <string>   
 
int lenOf(char* str1) {
    int i = 1;
    while (str1[i] != '\0') i++;
    return i;
}

int main(int a, char** arg) {
    long len = -1; //количество выводимых строк
    bool revers = false; //с начала False, с конца True
    char sep = '\n'; //символ определения конца строки
    Stroka del;
    del.setValue(&sep);
    Stroka lines;
    Stroka delimetr;
    Stroka filename;
    filename.setValue("null");
    delimetr.setValue("--delimiter="); // теперь это метод setValue
    lines.setValue("--lines="); // теперь это метод setValue

/*
создать буферный массив равный длине аргумента l и писать в него вайл построчно
для упрощения d
*/


    for(int i = 1; i < a; i++) {
        Stroka ar;
        ar.setValue(arg[i]);
        if(ar.compare("-l")) {
            len = std::atol(arg[i + 1]);
        }
        else if (lines.compare(ar.substr(0, 9))) {
            len = std::atoi(ar.substr(ar.find('=') + 1));
        }
        else if ((ar.compare("-t")) || (ar.compare("--tail"))) {
            revers = true;
        }
        else if (ar.compare("-d")) {
            del.setValue(arg[i + 1]);
        }
        else if (delimetr.compare(ar.substr(0, 13))) {
            del.setValue(ar.substr(ar.find('=') + 1));
        }
        else if(ar.find('.') != -1) {
            filename.setValue(arg[i]);
        }
        else if((ar.compare("-h")) || (ar.compare("--help"))) {
            std::cout << "Usage:\n-l, --lines=n print n lines from begin(end) of the file [optional]\n-t, --tail print n last lines from the file [optional]\n-d, --delimiter=c the character by which the end of the line is determined [optional] [\\n by default]\nThe file name and options are passed through command line arguments in the following format:\nPrintFile.exe [OPTION] filename";
            return 0;
        }
        // else {
        //     std::cout << "Wrong arguments\nCheck -h or --help for help";
        //     return 0;
        // }
    }
    if (lenOf(del.getValue()) > 1) std::cout << "Wrong delimiter\nCheck -h or --help for help";
    char* line = new char [64];
    char* bufer;
    int j = 0;
    int ansLen;
    try{
        std::ifstream file(filename.getValue());
        if (!filename.compare("null")) {
            std::ifstream file(filename.getValue());
            int k = 0;
            int cursor = 0;
            char sym;
            int fileLen;
            int mult = 5;
            file.seekg (0, file.end);
            fileLen = file.tellg();
            file.seekg (0, file.beg);
            if (len == -1) {
                len = fileLen;
            }
            bufer = new char [len * mult];
            while (!file.eof()) {
                for (int i = 0; i < 64; i++) {
                    line[i] = '\0';
                }
                if (file.is_open()) {
                    file.seekg(64 * k * sizeof(char));
                    file.read(line, 64);
                    k++;
                }
                if (!revers) {
                    if (cursor < len) {
                        for (int i = 0; i < 64; i++) {
                            if (del.getValue()[0] != '\n') {
                                if (line[i] == '\n') {}
                                else if (line[i] != del.getValue()[0]) std::cout << line[i];
                                else if (line[i] == del.getValue()[0]) {
                                    std::cout << '\n';
                                    cursor++;
                                }
                                if (cursor == len) break;
                            }
                            else {
                                if (cursor >= len) break;
                                std::cout << line[i];
                                if (line[i] == '\n') {
                                    cursor++;
                                }
                            }
                        }
                    }
                    else break;
                }
                else {
                    for (int i = 0; i < 64; i++) {
                        if (del.getValue()[0] != '\n') {
                            if (line[i] == del.getValue()[0]) {
                                cursor++;
                            }
                        }
                        else {
                            if (line[i] == '\n') {
                                cursor++;
                            }
                        }
                    }
                    
                }
            }
            ansLen = cursor - len + 1;
            file.close();
        }
        else {
            std::cout << "no filename find\nCheck -h or --help for help";
        }
    }
    catch (...) {
        std::cout << "Wrong arguments or\nCheck -h or --help for help";
    }

    if (revers) {
        int cursor = 0;
        std::ifstream file(filename.getValue());
        int k = 0;
        while (!file.eof()) {
            for (int i = 0; i < 64; i++) {
                line[i] = '\0';
            }
            if (file.is_open()) {
                file.seekg(64 * k * sizeof(char));
                file.read(line, 64);
                k++;
            }
            for (int i = 0; i < 64; i++) {
                if (del.getValue()[0] != '\n') {
                    if (line[i] == '\n') {}
                    else if (line[i] != del.getValue()[0]) {
                        if (cursor >= ansLen) std::cout << line[i];
                    }
                    else if (line[i] == del.getValue()[0]) {
                        if (cursor >= ansLen) std::cout << '\n';
                        cursor++;
                        if (cursor >= ansLen + len) break;
                    }
                }
                else {
                    if (line[i] == '\n') cursor++;
                    if (cursor >= ansLen + len) break;
                    if (cursor >= ansLen) std::cout << line[i];
                }
                if (cursor >= ansLen + len) break;
            }
        }
        file.close();
    }
    
    
    return 0;
}
