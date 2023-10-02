#include <iostream>
#include <fstream>

void printFile(long &len, bool &revers, char &sep, Stroka &del, Stroka &filename) {
    char* line = new char [64];
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
}