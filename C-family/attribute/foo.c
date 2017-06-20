#include "foo.h"
/* https://stackoverflow.com/questions/2053029/how-exactly-does-attribute-constructor-work */

static  __attribute__((constructor)) void before()
{
    puts("Hacked!");
}

#define SECTION( S ) __attribute__ ((section ( S )))

void test1(void) {
       printf("Hello 1\n");
}

void test2(void) {
       printf("Hello 2\n");
}

void test3(void) {
       printf("Hello 3\n");
}

void (*funcptr1)(void) SECTION(".ctors") =test1;
void (*funcptr2)(void) SECTION(".ctors") =test2;
void (*funcptr3)(void) SECTION(".dtors") =test3;

void foo()
{
    puts("foo");
}

