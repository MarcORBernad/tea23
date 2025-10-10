#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int main(int argc, char **argv) {
    //fmt::print("Hello, {} in version {}!\n", tea::PROJECT_NAME, tea::PROJECT_VER);
    // Part 0
    fmt::print("Anzahl Argumente (argc): {}\n", argc);

    for (size_t i = 0; i < argc; i++)
    {
        fmt::print("argv[{}]: {} (Adresse: {})\n", i, argv[i], fmt::ptr(&argv[i]));
    }

    // Part 1
    int x = 10;
    int *p = &x;
    *p = 42;

    fmt::print("x: {}, Adresse: {}\n", x, fmt::ptr(&x));
    fmt::print("p: {}, Adresse: {}\n", *p, fmt::ptr(p));

    return 0; /* exit gracefully*/
}
