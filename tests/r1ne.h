#ifndef R1NE_H
#define R1NE_H
#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}

TEST(r1ne,pr1){
    text txt = create_text();
    FILE *file;
    char buf[MAXLINE + 1];
    char loadFile[] = "tests/input/test_save_input1.txt";
    int index = 0;
    int count = 0;

    load(txt,loadFile);
    remove_first_no_entry_line(txt);
    node *current = txt->begin;


    if((file = fopen("tests/result/test_save_result1.txt","r")) == NULL){
        FAIL();
    }

    while (fgets(buf,MAXLINE,file)) {
        if(current && index  > 0){
            ASSERT_STREQ(buf, current->contents);

            count++;

            current = current->next;
        }
        index++;
    }

    EXPECT_EQ(count,7);

    fclose(file);

    SUCCEED();
}

TEST(r1ne,pr2){
    text txt = create_text();
    FILE *file;
    char buf[MAXLINE + 1];
    char loadFile[] = "tests/input/test_save_input2.txt";
    int index = 0;
    int count = 0;

    load(txt,loadFile);
    remove_first_no_entry_line(txt);
    node *current = txt->begin;
    current = current->next;
    current = current->next;

    if((file = fopen("tests/result/test_r1ne.txt","r")) == NULL){
        FAIL();
    }

    while (fgets(buf,MAXLINE,file)) {
        if(current && index  > 0){
            ASSERT_STREQ(buf, current->contents);

            count++;

            current = current->next;
        }
        index++;
    }

    EXPECT_EQ(count,7);

    fclose(file);

    SUCCEED();
}
#endif // R1NE_H
