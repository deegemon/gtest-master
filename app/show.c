/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

#include <string.h>

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
    
    /* Выводим строку на экран */
      char line[MAXLINE];
      char output_line[MAXLINE];
      strncpy(line, contents, sizeof(line) - 1);

  if (cursor >= 0) { 
    strncpy(output_line, line, cursor); 
    output_line[cursor] = '|';
    strncpy(output_line + cursor + 1, line + cursor, sizeof(output_line + cursor + 1) - 1);
    printf("%s", output_line);
  } else {
    printf("%s", line);
  }
}

