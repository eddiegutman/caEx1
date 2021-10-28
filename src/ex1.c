#include "ex1.h"

/**
 * Checks the current machine endianness.
 *
 * We assign the value '1' to num, which means the LSB of num equals to '1' and all the other bytes
 * are '0'.
 * Then we check the first byte in memory of num: if its '1' then our LSB is first in memory therefore
 * its little endian machine, and if its '0' then its a big endian machine.
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
 * first check for the machine endian, and based on it decide the copying order.
 * if its a big endian the MSB is first in the memory therefore 'x' need to be copied first.
 * if its a little endian the LSB is first in the memory therefore 'y' need to be copied first.
 * after that we iterate on the memory of 'merged' and copy the desired byte from 'x' and 'y',
 * respectively to the order we decided.
 *
 * @param x first given word.
 * @param y second given word.
 * @return new merged word.
 */
unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    unsigned long merged;
    int length = sizeof(long);

    // define byte size pointer for each word.
    char* byte = (char *) &merged;
    char* first;
    char* second;

    // decide the copy order based on the machine endian.
    if (is_big_endian()) {
        first = (char *) &x;
        second = (char *) &y;
    } else {
        first = (char *) &y;
        second = (char *) &x;
    }

    // copy the desired bytes from 'x' and 'y' to merged.
    for (int i = 0; i < length; i++) {
        if (i < length/2)
            *(byte + i) = *(first + i);
        else
            *(byte + i) = *(second + i);
    }

    return merged;
}
unsigned long put_byte(unsigned long x, unsigned char b, int i){

}

