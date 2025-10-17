#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int globalVar = 1;
int static staticGlobalVar = 2;
int const constGlobalVar = 3;

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    // fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    int localVar = 4;
    int static localStaticVar = 5;
    int const localConstVar = 6;
    int* heapVar = new int(3);

    /* INSERT YOUR CODE HERE */
    fmt::print("globalVar: {}, Adresse: {}\n", globalVar, fmt::ptr(&globalVar));
    fmt::print("staticVar: {}, Adresse: {}\n", staticGlobalVar, fmt::ptr(&staticGlobalVar));
    fmt::print("constVar: {}, Adresse: {}\n", constGlobalVar, fmt::ptr(&constGlobalVar));
    fmt::print("localVar: {}, Adresse: {}\n", localVar, fmt::ptr(&localVar));
    fmt::print("localStaticVar: {}, Adresse: {}\n", localStaticVar, fmt::ptr(&localStaticVar));
    fmt::print("localConstVar: {}, Adresse: {}\n", localConstVar, fmt::ptr(&localConstVar));
    fmt::print("heapVar: {}, Adresse: {}", fmt::ptr(&heapVar), fmt::ptr(heapVar));

    delete heapVar;

    return 0; /* exit gracefully*/
}
