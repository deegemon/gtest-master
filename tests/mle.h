#ifndef MLE_H
#define MLE_H
#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}

TEST(mle,pr1){
    text txt = create_text();
    char fileName[] = "tests/input/test_save_input1.txt";
    int index = 0;
    load(txt,fileName);
    mwcrsr(txt,1,1);
    mle(txt);

    node *current = txt->begin;

    while(current){
        if(index == 0){
            if(txt->cursor->position == 32){
                SUCCEED();
            }
            else {
                FAIL();
            }
            break;
        }
        index++;
        current = current->next;
    }
    SUCCEED();
}
TEST(mle,pr2){
    text txt = create_text();
    char fileName[] = "tests/input/test_save_input1.txt";
    int index = 0;
    load(txt,fileName);
    mwcrsr(txt,1,34);
    mle(txt);

    node *current = txt->begin;

    while(current){
        if(index == 0){
            if(txt->cursor->position == 33){
                SUCCEED();
            }
            else {
                FAIL();
            }
            break;
        }
        index++;
        current = current->next;
    }
    SUCCEED();
}
#endif // MLE_H
