// Main Kernel File

#include "libs/io.c"

#define VGA_START_ADDRESS 0xB8000
#define BUFFER_SIZE 2800
#define null 0

unsigned short* VGA_BUFFER;

enum Colors {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE
};

unsigned short VGA_ENTRY_POINT(unsigned char character,unsigned char fc,unsigned char bc) {
    unsigned short ax = 0;
    unsigned char ah = bc;
    unsigned char al = 0;
    ah <<= 4;
    ah |= fc;
    ax = ah;
    ax <<= 8;
    al = character;
    ax |= al;
    return ax;
}

void CLEAR_VGA_BUFFER(unsigned short **buff,unsigned char fc,unsigned char bc) {
    for (int i = 0; i < BUFFER_SIZE;i++) {
        (*buff) [i] = VGA_ENTRY_POINT(null,fc,bc);
    }
}

void INIT_VGA(unsigned char fc,unsigned char bc) {
    VGA_BUFFER = (unsigned short*)VGA_START_ADDRESS;
    CLEAR_VGA_BUFFER(&VGA_BUFFER,fc,bc);
}

void getDemoText() {
    // work in progress implementing a proper way to print strings and int
    VGA_BUFFER[0] = VGA_ENTRY_POINT('A', WHITE, CYAN);
    VGA_BUFFER[1] = VGA_ENTRY_POINT('K', WHITE, CYAN);
    VGA_BUFFER[2] = VGA_ENTRY_POINT('H', WHITE, CYAN);
    VGA_BUFFER[3] = VGA_ENTRY_POINT('I', WHITE, CYAN);
    VGA_BUFFER[5] = VGA_ENTRY_POINT(' ', WHITE, CYAN);
    VGA_BUFFER[6] = VGA_ENTRY_POINT('O', WHITE, CYAN);
    VGA_BUFFER[7] = VGA_ENTRY_POINT('S', WHITE, CYAN);
}

void kernel_entry() {
    INIT_VGA(WHITE,CYAN);
    getDemoText();
}