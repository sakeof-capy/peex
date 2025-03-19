#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>
#include <iostream>

template<typename... Functors>
struct overload : Functors...
{
    using Functors::operator()...;
};

template<typename... Functors>
overload(Functors...) -> overload<Functors...>;

[[noreturn]] inline void exit_program(const int code, const std::string& message = "")
{
    if (code != EXIT_SUCCESS)
    {
        std::cerr << "Exiting with an error: " << message << '\n';
    }

    std::cout << std::flush;
    std::cerr << std::flush;
    std::exit(code);
}

#endif //UTILITIES_HPP
