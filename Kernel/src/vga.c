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