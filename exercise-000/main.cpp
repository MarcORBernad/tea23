#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    //fmt::print("Hello, {}!\n", tea::PROJECT_NAME);
    fmt::print("Anzahl Argumente (argc): {}\n", argc);

    for (size_t i = 0; i < argc; i++)
    {
        fmt::print("argv[{}]: {} (Adresse: {})\n", i, argv[i], fmt::ptr(&argv[i]));
    }
    

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
