// 311432082 Edward Gutman

#include "ex1.h"

/**
 * checks if the machine operates on small/big endian
 *
 * first we assign the value of 1 to a unsigned long named num,
 * which means his LSByte is 1, and all the other bytes are 0.
 * then we check the first byte of memory of num:
 * if it equals 1 then we know the lowest memory is the LSByte, therefore its little endian.
 * if it equals 0 then we know the lowest memory is not the LSByte, therefore its big endian.
 *
 * @return 1 for big endian and 0 for little endian.
 */

int is_big_endian() {
    // a long to check the byte order.
    unsigned long num = 1;
    // pointer to the first byte of num.
    unsigned char *byte = (unsigned char *) &num;
    // we check if the LSB of num is in the first memory location.
    return (*byte == 1) ? 0 : 1;
}

/**
 * merges 'x' and 'y' to a new number by taking half of the bytes from on 'y' (from the LSByte),
 * and the remaining half from 'x'.
 *
 * first we check the machine's endian, and depending on it we assign the copy order.
 * if its big endian the MSByte is first in memory, therefore 'x' needs to be first.
 * if its little endian the LSByte is first in memory, therefore 'y' needs to be first.
 * after that we iterate on the memory of 'merged' and copy the desired byte from 'x' and 'y',
 * respectively to the order we calculated.
 *
 * @param x the first number.
 * @param y the second number.
 * @return a merged number of 'x' and 'y'.
 */

unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    unsigned long merged;
    unsigned char *mp = (unsigned char *) &merged, *xp = (unsigned char *) &x,
            *yp = (unsigned char *) &y;
    unsigned char *first, *second;

    // depending on the machine's endian we assign the copying order.
    if (is_big_endian()) {
        first = xp;
        second = yp;
    } else {
        first = yp;
        second = xp;
    }

    // copy the desired bytes (from memory) from x and y to merged.
    for (int i = 0; i < sizeof(merged); i++) {
        if (i < sizeof(merged) / 2) {
            *(mp + i) = *(first + i);
        } else {
            *(mp + i) = *(second + i);
        }
    }
    return merged;
}

/**
 * replace the 'i' byte (from the MSByte) of 'x' with given byte 'b'.
 *
 * first we check the machine's endian:
 * if its big endian then MSByte is first in memory, so 'position' to change remains 'i'.
 * if its little endian then LSByte is first in memory, so we need to count backward and
 * change 'position' to the number of bytes of 'x' minus 'i'.
 *
 * @param x an unsigned long
 * @param b byte to switch
 * @param i position to replace
 * @return
 */

unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    unsigned int position;
    unsigned char *p = (unsigned char *) &x;

    // determine the position depending on the machine's endian
    position = (is_big_endian()) ? i : (sizeof(x) - i - 1);

    // replace the correct byte of 'x' with 'b'
    *(p + position) = b;
    return x;
}


