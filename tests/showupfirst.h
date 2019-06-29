#ifndef SHOWUPFIRST_H
#define SHOWUPFIRST_H
#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}
TEST(showupfirst,pr1){
    text txt = create_text();
    FILE *file;
    char buf[MAXLINE + 1];
    char loadFile[] = "tests/input/test_save_input1.txt";

    load(txt,loadFile);
    showupfirst(txt);
    node *current = txt->begin;

    if((file = fopen("tests/result/test_showupfirst.txt","r")) == NULL){
        FAIL();
    }

    while(fgets(buf,MAXLINE,file)){
        if(current){
            ASSERT_STREQ(buf,current->contents);

            current = current->next;
        }
    }
    SUCCEED();
}
#endif // SHOWUPFIRST_H
