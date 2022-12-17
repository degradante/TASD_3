#ifndef _INC_MENU_H
#define _INC_MENU_H

enum {
    BTN_END, 
    BTN_LIST_ADD,
    BTN_LIST_POP,
    BTN_LIST_PRINT,
    BTN_LIST_MEMORY,
    BTN_ARRAY_ADD,
    BTN_ARRAY_POP,
    BTN_ARRAY_PRINT,
    BTN_ARRAY_MEMORY,
    BTN_BRACKETS_CHECK,
    BTN_DELETED_ADRESSES,
    BTN_MEMORY_PROFILE,
    BTN_TIME_PROFILE
};

void main_loop();

void print_menu();

#endif