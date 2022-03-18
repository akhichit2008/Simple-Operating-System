// Main Kernel File

#include "libs/io/io.c"

void kernel_entry() {
    INIT_VGA(WHITE,CYAN);
    testColorText();
}