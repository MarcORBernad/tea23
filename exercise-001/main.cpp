#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int globalVar = 1;
int static staticGlobalVar = 2;
int const constGlobalVar = 3;

void foo() 
{ 
    fmt::print("Hello from foo!\\n"); 
}

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    // fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    /* INSERT YOUR CODE HERE */
    int localVar = 4;
    int static localStaticVar = 5;
    int const localConstVar = 6;
    int* heapVar = new int(3);

    fmt::print("globalVar: {}, Adresse: {}\n", globalVar, fmt::ptr(&globalVar));
    fmt::print("staticVar: {}, Adresse: {}\n", staticGlobalVar, fmt::ptr(&staticGlobalVar));
    fmt::print("constVar: {}, Adresse: {}\n", constGlobalVar, fmt::ptr(&constGlobalVar));
    fmt::print("localVar: {}, Adresse: {}\n", localVar, fmt::ptr(&localVar));
    fmt::print("localStaticVar: {}, Adresse: {}\n", localStaticVar, fmt::ptr(&localStaticVar));
    fmt::print("localConstVar: {}, Adresse: {}\n", localConstVar, fmt::ptr(&localConstVar));
    fmt::print("heapVar: {}, Adresse: {}\n", fmt::ptr(&heapVar), fmt::ptr(heapVar));
    fmt::print("Adresse von foo: {}\n", fmt::ptr(&foo));

    delete heapVar;

    /*
    Fazit
    Bereich Adresse                         Read/Write  Speicherart
    Stack   0x78fd915e1d9c                              RAM
    Heap    0x5dbd539f3340                              RAM
    .bss    0x5db29a8d06c   Daten Segment   R/W         RAM
    .data   0x5db29a8d058   Daten Segment   R/W         Flash->RAM
    .rodata 0x5db29a8b348   Daten Segment   R           "Flash"
    .Text   0x5db29a85980                               Flash
    */

    return 0; /* exit gracefully*/
}
