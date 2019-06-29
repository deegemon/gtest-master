TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    editor.c \
    end_cursor.c \
    load.c \
    mwcrsr.c \
    remove_first_no_entry_line.c \
    save.c \
    show.c \
    showupfirst.c \
    text/append_line.c \
    text/change_cursor_position.c \
    text/create_text.c \
    text/delete_line.c \
    text/process_forward.c \
    text/remove_all.c

HEADERS += \
    common.h \
    text/_text.h \
    text/text.h


QMAKE_CFLAGS += -Wall -Wextra -Wsign-compare
# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0 -std=c99
LIBS += -lgcov

SUBDIRS += \
    app.pro
