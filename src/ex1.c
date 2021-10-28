#include "ex1.h"

/**
 * Checks the current machine endianness
 *
 * @return 1 for big endian and 0 for little endian.
 */
int is_big_endian() {
    // define a number in which his LSB is 1 and the remaining bytes are 0.
    unsigned long num = 1;

    // take the LSB of our number
    char* firstByte = (char *) &num;

    // checks if the LSB is first in order in  the memory.
    return (*firstByte == 1) ? 0 : 1;
}

/**
 * Merges the first half bytes (from the LSB) from y and the remaining bytes from x.
 *
 * @param x first given word.
 * @param y second given word.
 * @return new merged word.
 */
unsigned long merge_bytes(unsigned long x, unsigned long int y) {
}
unsigned long put_byte(unsigned long x, unsigned char b, int i){

}

