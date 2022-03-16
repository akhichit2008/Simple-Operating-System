#ifdef IO_H_INCLUDED
#define IO_H_INCLUDED

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

unsigned int VGA_INDEX;
static int next_line_index = 1;
char g_fore_color = WHITE, g_back_color = BLUE;
int digit_ascii_codes[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

// Basic Output Functions

void printc(char character);
void handleNewLine();
void getStringLength();
void puts(char *string);

#endif