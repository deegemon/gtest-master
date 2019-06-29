/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);
/*
 * Сохраняет текст в указанный файл
*/
void save(text txt, char *filename);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);
/**
 * Капитализация символов, которым предшествует пробел 
 */
void showupfirst(text txt);
/**
 * Меняет позицию курсора 
 */
void mwcrsr(text txt,int line,int position);
/**
 * Перемещение курсора в конец текущей строки
 */
void mle(text txt);
/**
 * Получение координат курсора 
 */
void getcrsr(text txt);
/**
 * Удаление первой непустой строки 
 */
void remove_first_no_entry_line(text txt);

#endif
