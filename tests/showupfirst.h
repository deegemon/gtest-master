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
    char loadFile[] = "test_save_input3.txt";
    load(txt,loadFile);
    showupfirst(txt);
    node *current = txt->begin;

    if((file = fopen("test_suf.txt","r")) == NULL){
        FAIL();
    }
    while(fgets(buf,MAXLINE,file)){
        if(current){
            EXPECT_STREQ(buf,current->contents);

            current = current->next;
        }
    }

    fclose(file);
    SUCCEED();
}
#endif // SHOWUPFIRST_H
