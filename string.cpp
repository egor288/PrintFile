#include <iostream>

int len(char* str1) {
    int i = 1;
    while (str1[i] != '\0') i++;
    return i;
}

class Stroka {
    public:

        void setValue(char* str) {
            value = new char[len(str)];
            for (int i = 0; i < len(str); i++) {
                value[i] = str[i];
            }
        }

        char* substr(int begin = 0, int end = 0) {
            if (end == 0) end = len(value) + 1;
            char* ans = new char [end - begin - 1];
            for (int i = 0; i < (end - begin - 1); i++) {
                ans[i] = value[i + begin];
            }
            return ans;
        }
        int find(char sim) {
            for (int i = 0; i < len(value); i++) {
                if (value[i] == sim ) return i;
            }
            return -1;
        }

        bool compare(char* str1) {
            if (len(str1) != len(value)){
                return false;
            }
            else {
                for (int i = 0; i < len(str1); i++){
                    if (str1[i] != value[i]) return false; 
                }
            }
            return true;
        }

        char* getValue() {
            return value;
        }
    private:
        char* value;

};
