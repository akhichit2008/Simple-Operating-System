#pragma once
#include "../../vars.h"
#include "../../vga.c"
#include "../../../../tests/basic_vga_tests/basic_vga_test.c"
#include "../string/string.h"
#include "../../drivers/keyboard/keyboard.c"

unsigned int VGA_INDEX;
static int next_line_index = 1;
char g_fore_color = WHITE, g_back_color = CYAN;
int digit_ascii_codes[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

// Basic Output Functions

void printc(char chracter) {
    VGA_BUFFER[VGA_INDEX] = VGA_ENTRY_POINT(chracter,g_fore_color,g_back_color);
    VGA_INDEX++;
}

void handleNewLine() {
    if (next_line_index >= 70) {
        next_line_index = 0;
        CLEAR_VGA_BUFFER(&VGA_BUFFER,g_fore_color,g_back_color);
    }
    VGA_INDEX = 80*next_line_index;
    next_line_index++;
}

void puts(char* string) {
    int i = 0;
    while(string[i]) {
        if (string[i] == '\n') {
            handleNewLine();
        }else  {
        printc(string[i]);
        }
        i++;
    }
}

// This is a simple in devlopment version of scanf() function. Currently it does have the usual scanf functionalities. But these features will be coming soon
void scank() {
    getKeycode();
}