#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int globalVar = 1;
int static staticVar = 2;
int const constVar = 3;

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

    /* INSERT YOUR CODE HERE */
    fmt::print("globalVar: {}, Adresse: {}\n", globalVar, fmt::ptr(&globalVar));
    fmt::print("staticVar: {}, Adresse: {}\n", staticVar, fmt::ptr(&staticVar));
    fmt::print("constVar: {}, Adresse: {}\n", constVar, fmt::ptr(&constVar));
    fmt::print("localVar: {}, Adresse: {}\n", localVar, fmt::ptr(&localVar));
    fmt::print("localStaticVar: {}, Adresse: {}\n", localStaticVar, fmt::ptr(&localStaticVar));
    fmt::print("localConstVar: {}, Adresse: {}\n", localConstVar, fmt::ptr(&localConstVar));

    return 0; /* exit gracefully*/
}
