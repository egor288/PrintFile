#include <iostream>
#include <fstream>
#include "string.cpp"     
 
int main(int a, char** arg) {
    int len = -1; //количество выводимых строк
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
            len = std::atoi(arg[i + 1]);
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
        else {
            std::cout << "Wrong arguments\nCheck -h or --help for help";
            return 0;
        }
    }

    if (!filename.compare("null")) {
        std::ifstream file(filename.getValue()); // окрываем файл для чтения
        if (file.is_open())
        {

            // while (std::getline(file, line))
            // {
            //     std::cout << line << std::endl;
            // }
        }
        file.close();
    }     // закрываем файл
    else {
        std::cout << "no filename find\nCheck -h or --help for help";
    }

    return 0;
}
