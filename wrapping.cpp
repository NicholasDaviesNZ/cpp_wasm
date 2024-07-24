#include <stdio.h>
#include <emscripten.h>


extern "C" {
EMSCRIPTEN_KEEPALIVE
int addNums(int a, int b)
{
    return a + b;
}
}
extern "C" {
EMSCRIPTEN_KEEPALIVE
int subtractNums(int a, int b)
{
    return a - b;
}
}

EMSCRIPTEN_KEEPALIVE
int main()
{
    printf("Hello, world, %d\n", addNums(3, 5));

    return 0;
}