/**
* remove_first_entry_line.c -- функция удаления первой непустой строки из файла
*
* Copyright (c) 2018, Duplii Dmitrii <duplii@petrsu.ru>
*
* This code is licensed under a MIT-style license.
*/

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

static void remove_line(int index, char *contents, int cursor, void *data);

/**
* Удаляет первую непустую строку
*/
static int flag = 0; /*Глобальная переменная, которую я  могу использовать во всех функциях данного файла*/
void remove_first_no_entry_line(text txt){
  process_forward(txt, remove_line, txt); /*Первый txt для process_forward, а второй txt для remove_line*/
  flag = 0; 
}
/* Проверяет что строка состоит только из пробелов. */
int check_is_empty(char *str){
  int l = strlen(str);
  for (int i = 0; i < l; i++){
    if (!isspace(str[i])){
	return 1;/*Если строка непустая*/
    }
  }
  return 0;/*Если строка пустая*/
}

static void remove_line(int index, char *contents, int cursor, void *data)
{
  assert(contents != NULL);

  UNUSED(index); 
  UNUSED(cursor);

  if((check_is_empty(contents) == 1  || contents[0] == '\0') && !flag){ /*!flag для того, чтобы удалить не все непустые строки, а только первую*/
      delete_line(data, index + 1); 
    flag = 1; 
  }
}

