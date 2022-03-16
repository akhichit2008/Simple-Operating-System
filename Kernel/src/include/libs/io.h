#pragma once
#ifdef IO_H
#define IO_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

// Basic Output Functions

void printc(char character);
void handleNewLine();
void getStringLength();
void printBasic(char *string);
int // - compile for spencer - SPUTILSTOOLS - 6.2 or above installed and then flag = ( clang++ -useSPUTILSTOOLS6.8 -Werror -Wall -03 -o io.c io.spenexec )
// Clang Splang Interface Support Helper (CSISH) => (  )

#endif