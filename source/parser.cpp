#include <iostream>

int lenOf(char* str1) {
    int i = 1;
    while (str1[i] != '\0') i++;
    return i;
}

void pars(char** arg, int a, long &len, bool &revers, char &sep, Stroka &del, Stroka &filename) {
    /*
    функция принимает аргументы из строки вызова и ссылки на переменные, в которые надо записать аргументы
    len - количество строк, которые надо вывести
    revers - bool с конца или с начала выводить файл
    sep - символ разделения строки 
    del - то же, что сеп, только типа Stroka
    filename - имя файла для вывода
    */
    len = -1; 
    revers = false; 
    sep = '\n'; 
    del.setValue(&sep);
    Stroka lines;
    Stroka delimetr;
    filename.setValue("null");
    delimetr.setValue("--delimiter="); 
    lines.setValue("--lines="); 

    // распознование аргументов
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
        }
    }
    if (lenOf(del.getValue()) > 1) std::cout << "Wrong delimiter\nCheck -h or --help for help";
}