/*
    Ляпин Иван 104Б
    Вариант: 9
 */
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

int main(int argc, const char * argv[])
{
    FILE *file; //создаем файл для работы
    file = fopen("input.txt", "r");
    char c; // считываемый символ файла
    bool word_end = false; // переменная, отвечающая за конец слова
    bool word1_start_scan = false, word2_start_scan = false; //просканировали 1-ое, 2-ое слово
    uint32_t set_word1 = 0; //создаем множество под первое слово
    uint32_t set_word2 = 0; //создаем множество под второе соседнее слово
    while (!feof(file)) { // цикл пока файл не закончится
        if ((c = tolower(fgetc(file)))) { // считываем символ с нижнем регистром
            if (isalpha(c)) { // встретили букву
                if (word_end) { // сканируем следующее слово
                    set_word2 = set_word2 | (1u << (c - 'a'));
                    word2_start_scan = true; // отсканировали второе слово
                } else {
                    set_word1 = set_word1 | (1u << (c - 'a'));
                    word1_start_scan = true; // отсканировали первое слово
                }
            }
            if (isspace(c) && word1_start_scan) { // встретили пробел, после конца первого слова
                word_end = true;
            }
            if ((isspace(c) || c == EOF) && word2_start_scan) { // если встретили пробел после сканирования второго слова либо EOF
                if (set_word1 == set_word2) { // если множества равны, то такая пара слов существует
                    printf("Да\n");
                    return 0; // завершаем программу
                } else { // иначе
                    set_word1 = set_word2; // инициализируем второго множество как первое
                    set_word2 = 0; // обнуляем второе множество
                    word2_start_scan = false; // присваиваем false, для последующих сравнений
                    word1_start_scan = true; // больше не будем считывать первое множество, теперь оно всегда будет перенимать значения второго
                    
                }
            }
            if (c == EOF) { // встретили EOF - завершаем работу
                break;
            }
            
        }
    }
    printf("Нет\n"); // если, пройдя весь файл, мы так и не нашли нужной пары, то такой пары не существует, выводим соответствующее уведомление
    
    return 0;
}

