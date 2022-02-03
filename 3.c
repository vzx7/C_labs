#include <stdio.h>
#include <string.h>
#include "l3.h"
/*
Массив из M строк по N символов каждая. Необходимо вывести только те строки, которые являются палиндромами,
 т.е. читаются одинаково слева направо и справа налево. При проверке строки необходимо определять ее длину с помощью функции strlen() (#include )
 */

int check_char(char *s) {
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        if (s[i] != s[0]) return 0;
    }
    return 1;
}

int is_pal(char *s) {
    int l = strlen(s);
    for (int i = 0; i < l/2; i++) {
        if (s[i] != s[l - i - 1])  return 0;
    }
    return 1;
}


int l3() {
    char str[100];
    printf("Enter world:\n");
    scanf("%79s", str);

    if (check_char(str)) printf("Недопустимое выражение, слово должно состоять из разных букв\n");
    else {
        if (!is_pal(str))  {
            printf("Вы ввели не палиндром!\n");
        } else {
            printf("Поздравляем - это палиндром!\n");
        }
    }
    return 0;

};
