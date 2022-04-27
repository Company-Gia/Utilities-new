#ifndef utils
#define utils

int addNewBit(int newBit_pos, int SR_status) {
    int newBit = 1;
    newBit_pos--;                           /* decrements cuz newBis is already := ...0001 */
    for (int i = 0; i < newBit_pos; i++)
        newBit = newBit << 1;
    return SR_status | newBit;
}

#endif utils