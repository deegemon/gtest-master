#ifndef SAVE_H
#define SAVE_H

#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}

TEST(save1,pr1){
    text txt = create_text();
    FILE *file = nullptr;
    char buf[MAXLINE + 1];
    char loadFile[] = "test_save_input1.txt";
    char saveFile[] = "test_save_result1.txt";

    /*Загружаем файл*/
    load(txt,loadFile);

    /*Вызов тестируемой функции*/
    save(txt,saveFile);
    file = fopen("test_save_result1.txt","")
    /*Если сохранённый файл не открывается, то ошибка*/
    if((file == NULL)){
        FAIL();
    }

    node *current = txt->begin;

    while(fgets(buf, MAXLINE, file)){
        if(current){
            ASSERT_STREQ(buf, current->contents);

            current = current->next;
        }
    }

    SUCCEED();
}
#endif // SAVE_H
