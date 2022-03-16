#pragma once

char inputBytes(unsigned short port) {
    char return_value;
    asm volatile("inb %1,%0" : "=a"(return_value):"d"(port));
    return return_value;
}

void outputBytes(unsigned short port,char content) {
    asm volatile("outb %0,%1":"=a"(content) : "d"(port));
} 

char getKeycode() {
    char character = 0;
    while(character = inputBytes(0x60) != 0 || null) {
        if (character > 0) {
            return character;
        }
    }
    return character;
}

void awaitIo(int tc) {
    // Execute 'nop' instruction to keep the cpu busy
    while(tc--) {
        asm volatile("nop");
        if (tc <= 0) {
            break;
        }
    }
}

// cpu sleep

void cpuSleep(int tc) {
    awaitIo(tc);
}

void setKeyInput() {
    char character = 0;
    char keycode = 0;
    do {
        keycode = getKeycode();
        cpuSleep(0x02FFFFFF);
    } while (character > 0);
}