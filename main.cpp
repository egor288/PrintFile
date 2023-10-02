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
    delimetr.setValue("--delimiter="); // теперь это метод setValue
    lines.setValue("--lines="); // теперь это метод setValue

/*
создать буферный массив равный длине аргумента l и писать в него вайл построчно
для упрощения d
*/


    for(int i = 0; i < a; i++) {
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

    }
    std::cout << revers << " " << len << " " ;
    del.printValue();


    std::ifstream file(arg[a - 1]); // окрываем файл для чтения
    if (file.is_open())
    {

        // while (std::getline(file, line))
        // {
        //     std::cout << line << std::endl;
        // }
    }
    file.close();     // закрываем файл

    return 0;
}
