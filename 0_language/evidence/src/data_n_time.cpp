#include <iostream>
#include <chrono>
#include <format>
#include "utilities.hpp"

namespace ts = std::chrono;

template<typename Clock>
void print_clock_info()
{
    std::cout << std::boolalpha;
    std::cout << "-----------------------------------------------\n";
    std::cout << "Using clock: ";

    if constexpr (std::is_same_v<Clock, ts::system_clock>) {
        std::cout << "system_clock";
    } else if constexpr (std::is_same_v<Clock, ts::steady_clock>) {
        std::cout << "steady_clock";
    } else if constexpr (std::is_same_v<Clock, ts::high_resolution_clock>) {
        std::cout << "high_resolution_clock";
    } else if constexpr (std::is_same_v<Clock, ts::utc_clock>) {
        std::cout << "utc_clock";
    } else if constexpr (std::is_same_v<Clock, ts::tai_clock>) {
        std::cout << "tai_clock";
    } else if constexpr (std::is_same_v<Clock, ts::gps_clock>) {
        std::cout << "gps_clock";
    } else if constexpr (std::is_same_v<Clock, ts::file_clock>) {
        std::cout << "file_clock";
    }
    std::cout << '\n';
    std::cout << "Clock is steady: " << Clock::is_steady << std::endl;
}

template <typename Clock>
void display_time(const ts::time_point<Clock>& now)
{
    // zoned_time is supported only for system_clock
    if constexpr (std::is_same_v<Clock, std::chrono::system_clock>)
    {
        std::cout << std::format("Time in Tokyo: {:%T}", ts::zoned_time("Asia/Tokyo", now)) << '\n';
    }
    else
    {
        std::cout << "Zoned time is not supported by the clock\n";
    }
}

int main()
{
    using namespace std::literals;
    using Clock = ts::system_clock;
    // using Clock = ts::steady_clock;
    // using Clock = ts::high_resolution_clock;
    // using Clock = ts::utc_clock;
    // using Clock = ts::tai_clock;
    // using Clock = ts::gps_clock;
    // using Clock = ts::file_clock;

    print_clock_info<Clock>();

    // steady clock does not support formatting, it's for durations only
    if constexpr (!std::is_same_v<Clock, ts::steady_clock>) {
        const ts::time_point<Clock> now = Clock::now();
        std::cout << std::format("{:%F}", now) << '\n';
        std::cout << std::format("{:%H:%M:%S}", now) << '\n';

        const ts::time_point<Clock, ts::minutes> minutes = ts::time_point_cast<ts::minutes>(now);
        std::cout << "minutes: " << std::format("{:%F:%T}", minutes) << '\n';

        const ts::time_point<Clock, ts::hours> hours = ts::time_point_cast<ts::hours>(now);
        std::cout << "hours: " << std::format("{:%F:%T}", hours) << '\n';

        const ts::time_point<Clock, ts::days> days = ts::time_point_cast<ts::days>(now);
        std::cout << "days: " << std::format("{:%F:%T}", days) << '\n';

        display_time(now);
    }

    std::cout << '\n' << "Calculating durations:" << '\n';

    {
        const ts::time_point<Clock> now = Clock::now();
        const ts::time_point<Clock> then = now + 2h;
        const auto duration = then - now;
        const auto seconds = ts::duration_cast<ts::seconds>(duration);
        const auto minutes = ts::duration_cast<ts::minutes>(duration);
        const auto hours = ts::duration_cast<ts::hours>(duration);
        const auto days = ts::duration_cast<ts::days>(duration);

        std::cout << "Duration in:\n"
            << "\t- seconds: " << seconds.count() << '\n'
            << "\t- minutes: " << minutes.count() << '\n'
            << "\t- hours: " << hours.count() << '\n'
            << "\t- days: " << days.count() << '\n';
    }

    exit_program(EXIT_SUCCESS);
}
