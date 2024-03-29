/**
 * showupfirst.c -- капитализация всех символов, которым предществует пробел
 *
 * Copyright (c) 2018, Dmitrii Duplii <duplii@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

void toup(char *s){
    int len = strlen(s);
    int i;
    for (i = 0; i < len - 1; i++){
        if(isspace(s[i])) {
            s[i+1]=toupper(s[i+1]);
        }
    }
}
static FILE *file;
static void showupfirst_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит текст в верхнем регистре
 */
void showupfirst(text txt)
{
    /* Применяем функцию showupper_line к каждой строке текста */
    file = fopen("tests/input/test_save_input3.txt","w");
    process_forward(txt, showupfirst_line, NULL);
    fclose(file);
    printf("\n");
}

static void showupfirst_line(int index, char *contents, int cursor, void *data)
{
    assert(contents != NULL);

    UNUSED(index);
    UNUSED(data);

    /* Капитализация символов */
    char line[MAXLINE];
    char output_line[MAXLINE];
    strncpy(line, contents, sizeof(line));

    if (cursor >= 0){
        strncpy(output_line, line, cursor);
        output_line[cursor] = '|';
        strncpy(output_line+cursor+1, line+cursor, sizeof(output_line+cursor+1));
        toup(output_line);
        printf("%s", output_line);
        fprintf(file,"%s",output_line);
    } else {
        toup(line);
        printf("%s", line);
        fprintf(file,"%s", line);
    }
}
