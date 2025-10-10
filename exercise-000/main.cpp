#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

void changeValueByParameter(int value)
{
    value = 99;
    fmt::print("value: {}\n", value);
}

void changeValueByPointer(int* ptr)
{
    *ptr = 99;
    fmt::print("ptr: {}\n", *ptr);
}

int main(int argc, char **argv)
{
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

    // Part 2
    double* d = new double(3.1415);
    fmt::println("Wert: {}\n", *d);
    delete d;

    // Part 3
    int y = 5;

    fmt::print("y: {} (vor para)\n", y);
    changeValueByParameter(y);
    fmt::print("y: {} (nach para)\n", y);

    fmt::print("y: {} (vor pointer)\n", y);
    changeValueByPointer(&y);
    fmt::print("y: {} (nach pointer)\n", y);

    return 0; /* exit gracefully*/
}
