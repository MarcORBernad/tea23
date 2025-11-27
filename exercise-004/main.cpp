#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

#include "image.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>


auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    /* INSERT YOUR CODE HERE */
    fmt::print("width: {}\nheight: {}\n", image_width, image_height);
    
    std::vector <uchar> v(image, image + (image_width * image_height));
    cv::Mat img = cv::imdecode(v, cv::IMREAD_COLOR);
    fmt::print("{}", img.channels());
    
    std::string output_filename = fmt::format("{}/{}", "assets", "image_edited.jpg");
    cv::imwrite(output_filename, img);
    
    return 0; /* exit gracefully*/
}
