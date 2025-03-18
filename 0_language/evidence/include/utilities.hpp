#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>
#include <iostream>

[[noreturn]] inline void exit_program(const int code, const std::string& message = "")
{
    if (code != EXIT_SUCCESS)
    {
        std::cerr << "Exiting with an error: " << message << '\n' << std::flush;
    }

    std::exit(code);
}

#endif //UTILITIES_HPP
