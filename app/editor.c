/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main(){
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "exit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }
        if (strcmp(cmd, "save") == 0) { 
	    if ((arg = strtok(NULL, " \n")) == NULL) { 
		fprintf(stderr, "Usage: save filename\n"); 
	    } else { 
		save(txt, arg); 
	    } 
	    continue; 
	}
        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }
	/*Проводим капитализацию символов, которым предшествует пробел */
        if (strcmp(cmd, "showupfirst")==0){
	    showupfirst(txt);
	    continue;
	}
        /*Перемещение позиции курсора в конец текущей строки*/
	if (strcmp(cmd, "mle") == 0) {
	   mle(txt);
	    continue;
        }
    /*Перемещение курсора в заданные координаты(строка\позиция)*/
	if (strcmp(cmd, "mwcrsr") == 0) { 
	    char *line = strtok(NULL, " \n");
	    char *position = strtok(NULL, " \n"); 
	if (line && position) 
	    mwcrsr(txt, atoi(line), atoi(position));
	else
	    printf("Usage: mwcrsr line position");
	    continue; 
	    }
	/*Удаляем первую непустую строку*/
	 if (strcmp(cmd, "r1ne") == 0) {
	    remove_first_no_entry_line(txt);
	    continue;
	    }
        /* Если команда не известна */
         fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
