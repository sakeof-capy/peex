#include <iostream>
#include <chrono>
#include <sstream>
#include "date/date.h"

int main()
{
    // Get the current system time and floor to days
    const auto now = std::chrono::system_clock::now();
    const date::sys_days today = date::floor<std::chrono::days>(now);  // Correct type conversion

    // Extract year, month, and day
    const date::year_month_day ymd{today};  // Convert sys_days -> year_month_day
    const date::weekday wd{today};  // Convert sys_days -> weekday

    // Print human-readable date format
    std::cout << "Today's date: " << ymd << " (" << wd << ")\n";

    // Date arithmetic: Get the first day of the current month
    const date::year_month_day first_day_of_month = ymd.year() / ymd.month() / date::day{1};
    std::cout << "First day of this month: " << first_day_of_month << "\n";

    // Get the last day of the month
    const date::year_month_day last_day_of_month = ymd.year() / ymd.month() / date::last;
    std::cout << "Last day of this month: " << last_day_of_month << "\n";

    // Leap year check
    const bool is_leap = date::year{ymd.year()}.is_leap();
    std::cout << "Is this year a leap year? " << (is_leap ? "Yes" : "No") << "\n";

    // Parsing a date string (std::chrono has no easy way to do this)
    std::istringstream ss("2025-07-04");
    date::year_month_day parsed_date{};
    ss >> date::parse("%F", parsed_date);
    std::cout << "Parsed date: " << parsed_date << "\n";

    return EXIT_SUCCESS;
}
