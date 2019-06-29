#ifndef MWCRSR_H
#define MWCRSR_H
#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}
TEST(mwcrsr,pr1){
    text txt = create_text();
    char fileName[] = "tests/input/test_save_input1.txt";

    load(txt,fileName);

    mwcrsr(txt,6,7);

    node *current = txt->begin;

    int index = 0;

    while(current){
        if(index == 5){
            if(txt->cursor->position == 6){
                SUCCEED();
            } else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    SUCCEED();
}

TEST(mwcrsr,pr2){
    text txt = create_text();
    char fileName[] = "tests/input/test_save_input1.txt";

    load(txt,fileName);

    mwcrsr(txt,2,1);

    node *current = txt->begin;

    int index = 0;

    while(current){
        if(index == 1){
            if(txt->cursor->position == 0){
                SUCCEED();
            } else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    SUCCEED();
}

TEST(mwcrsr,pr3){
    text txt = create_text();
    char fileName[] = "tests/input/test_save_input1.txt";

    load(txt,fileName);

    mwcrsr(txt,6,7);
    mwcrsr(txt,1,7);
    mwcrsr(txt,5,3);
    mwcrsr(txt,7,7);
    mwcrsr(txt,8,10);

    node *current = txt->begin;

    int index = 0;

    while(current){
        if(index == 7){
            if(txt->cursor->position == 9){
                SUCCEED();
            } else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    SUCCEED();
}
#endif // MWCRSR_H
