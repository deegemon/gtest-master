include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Wsign-compare
QMAKE_CFLAGS += -Wall -Wextra -Wsign-compare

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0 -std=c99
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage -O0 -std=c99
LIBS += -lgcov


HEADERS += \
    ../app/common.h \
    ../app/text/_text.h \
    ../app/text/text.h \
    save.h

SOURCES +=     main.cpp \
    ../app/end_cursor.c \
    ../app/load.c \
    ../app/mwcrsr.c \
    ../app/remove_first_no_entry_line.c \
    ../app/save.c \
    ../app/show.c \
    ../app/showupfirst.c \
    ../app/text/append_line.c \
    ../app/text/change_cursor_position.c \
    ../app/text/create_text.c \
    ../app/text/delete_line.c \
    ../app/text/process_forward.c \
    ../app/text/remove_all.c

INCLUDEPATH += ../app
