/*
    Ляпин Иван Алексеевич
    М8О-104Б-22
    Вариант №27
*/

#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define FALSE 0
#define TRUE 1

int main(int argc, const char * argv[])
{
    FILE *file; // "создаем" файл
    file = fopen("input.txt", "r"); // открываем его   c разрешением на чтение

    if (file == NULL) { // проверка на возможность открытия файла
        printf("Не удалось открыть файл!");
    }
    
    int count_words = 0; // вводим счетчик
    bool word_search = 0; // вводим переменную, отвечающую за нахождение слова в комментарии
    bool is_comment = FALSE; // вводим переменную, отвечающую за открытия комментария
    char c; // вводим переменную, что будет являться символом из файл
    
    while (!feof(file)) { // создаем цикл, выполняющийся пока файл не будет пустыm
        while ((c = fgetc(file))!= EOF) {
            if (c != '"') { // проверяем, находится ли конструкция внутри строки
                if (c == '{') { // встретили начало комментария
                    is_comment = TRUE; // bool переменная равна 1, так как открылся комментарий
                    
                    while (is_comment) { // цикл пока не закроется комментарий

                        c = fgetc(file);
                        if (isalpha(c) && word_search == 0) { // если встретили букву, то поднимаем флаг, чтобы считать только первую букву слова
                            count_words += 1; // увеличиваем счетчик слов
                            word_search = 1; // поднимаем флаг
                        } else if (c == '}') { // условие закрытия комментария, опускаем флаг
                            is_comment = 0;
                            word_search = 0;
                        } else if (!isalpha(c)) { // если встречаем все кроме букв, то не учитываем
                            word_search = 0; // опускаем флаг(конец слова)
                        }
                        if (c == EOF) { // если забыли закрыть комментарий
                            is_comment = 0;
                            word_search = 0;
                        }
                    }

                } else if (c == '(') { // встретили первый элемент конструкции "(*"
                    c = fgetc(file); // считываем следующий элемент
                    if (c == '*') { // если он равен "*" , то конструкция найдена
                        
                        is_comment = TRUE; // открыт комментарий!
                        
                        while (is_comment) { // цикл пока он не закроется
                            c = fgetc(file);
                            
                            if (isalpha(c) && word_search == 0) {
                                count_words += 1;
                                word_search = 1;
                            } else if (c == '*') { // если встретили "*", проверяем на часть конструкции закрытия комментария
                                
                                c = fgetc(file);
                                
                                if (c == ')') { // конец комментария
                                    is_comment = FALSE;
                                    word_search = 0;
                                }
                            } else if (!isalpha(c)) {
                                word_search = 0;
                            }
                            if (c == EOF) { // если забыли закрыть комментарий
                                is_comment = FALSE;
                                word_search = 0;
                            }
                            
                        }
                        
                    }
                    
                }
                
            } else { // если конструкция внутри строки, то она уже не является комментарием, потому считать её мы не будем
                c = fgetc(file);
                while (c != '"') {
                    c = fgetc(file);

                }
            }
        }
    }
    printf("%d\n", count_words); // выводим значение счетчика
    fclose(file); // закрываем файл, в котором работали
    return 0;

}
        


