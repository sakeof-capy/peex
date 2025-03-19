#include <iostream>
#include <regex>
#include <string>
#include "utilities.hpp"




int main()
{
    // Validate
    {
        std::regex email_regex(R"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)");
        const std::string email = "user@example.com";
        const std::string invalid_email = "user@@example.com";

        const auto validate_email = [&email_regex](const std::string& email) {
            if (std::regex_match(email, email_regex))
            {
                std::cout << "Valid email address: " << email << "\n";
            }
            else
            {
                std::cout << "Invalid email address: " << email << "\n";
            }
        };

        validate_email(email);
        validate_email(invalid_email);
    }

    std::cout << "-------------------------------------------------------------------------------\n";

    const std::regex digit_regex(R"(\d+)");
    const std::string text = "My number is 12345. Other numbers are 21345 and 32451234";

    // Search
    {
        std::smatch match;

        // Search for first occurrence
        if (std::regex_search(text, match, digit_regex))
        {
            std::cout << "Found number: " << match.str() << '\n';
        }

        std::cout << "-------------------------------------------------------------------------------\n";

        // Iterate over all occurrence
        std::sregex_iterator begin(text.begin(), text.end(), digit_regex);
        const std::sregex_iterator end;

        for (; begin != end; ++begin)
        {
            std::cout << "Found: " << begin->str() << '\n';
        }
    }

    std::cout << "-------------------------------------------------------------------------------\n";

    // Replace
    {
        const std::string replaced_text = std::regex_replace(text, digit_regex, "<some_number>");
        std::cout << "Original text: " << text << "\n";
        std::cout << "Replaced text: " << replaced_text << "\n";
    }
        std::cout << "-------------------------------------------------------------------------------\n";
    {
        std::cout << "Replacing only second number if present:\n";

        std::string replaced_text = text;
        std::sregex_iterator begin(replaced_text.begin(), replaced_text.end(), digit_regex);
        const std::sregex_iterator end;

        for (int count = 0; begin != end; ++begin)
        {
            count++;

            if (count == 2)
            {
                replaced_text.replace(begin->position(), begin->length(), "<REPLACEMENT>");
                break;
            }
        }

        std::cout << "Original text: " << text << "\n";
        std::cout << "Replaced text: " << replaced_text << "\n";
    }

    exit_program(EXIT_SUCCESS);
}
