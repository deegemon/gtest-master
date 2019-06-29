/**
* end_cursor.c -- функция перевода курсора в начало текущей строки
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

static void end_cursor(int index, char *contents, int cursor, void *data); /*Заголовок функции,которая используется только в этом файле*/

/**
* Переводит курсор в конец текущей строки
*/
void mle(text txt)
{
  /* Применяем функцию mlе к каждой строке текста */
    process_forward(txt, end_cursor, txt);
}

static void end_cursor(int index, char *contents, int cursor, void *data)
{
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(cursor);
  UNUSED(data);
  /*Проверка что курсор нахолдится в данной строке и курсор не в конце строки*/
  if (cursor !=-1 && cursor != strlen(contents)){ 
      mwcrsr(data, index+1, strlen(contents)); /*Перевод курсора в конец строки*/
      contents[strlen(contents)+1]='\n'; /*После курсора перевод строки */
  }
}
