#include <iostream>

using namespace std;

int main () {

    printf("%lu%c", sizeof(0), '\n');
    printf("%lu%c", sizeof(INT8_MAX), '\n');
    printf("%lu%c", sizeof(INT16_MAX), '\n');

    printf("%d", INT16_MAX);

    return 0;
}