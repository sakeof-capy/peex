#include <stdexcept>
#include <string_view>
#include <iostream>

class CustomError : public std::exception
{
public:
    constexpr explicit CustomError(const std::string_view message)
        : message_ { message }
    {}

    ~CustomError() override = default;

    const char* what() const noexcept override
    {
        return message_.data();
    }

private:
    const std::string_view message_;
};

class BadRegistration : public CustomError {
public:
    constexpr explicit BadRegistration(const std::string_view message)
        : CustomError(message)
    {}
};

enum class UserQueryErrorType
{
    USER_NOT_FOUND,
    USER_CONSTRAINTS_VIOLATED,
};

template<UserQueryErrorType>
class UserQueryError : public CustomError {
public:
    constexpr explicit UserQueryError(const std::string_view message)
        : CustomError(message)
    {}
};

static constexpr std::string_view USER_QUERY_ERROR_FMT_MESSAGE[] = {
    [static_cast<std::size_t>(UserQueryErrorType::USER_NOT_FOUND)]              = "User not found: {}",
    [static_cast<std::size_t>(UserQueryErrorType::USER_CONSTRAINTS_VIOLATED)]   = "Constraints violated",
};

constexpr std::string_view error_type_to_string(const UserQueryErrorType error_type)
{
    return USER_QUERY_ERROR_FMT_MESSAGE[static_cast<std::size_t>(error_type)];
}

template<UserQueryErrorType ErrorType>
class AutoUserQueryError : public CustomError {
public:
    template<typename... FmtArgs>
    constexpr explicit AutoUserQueryError(FmtArgs&&... fmt_args)
        : CustomError(std::format(error_type_to_string(ErrorType), std::forward<FmtArgs>(fmt_args)...))
    {}
};

int main()
{
    try
    {
        throw BadRegistration("Bad Registration: invalid username...");
    }
    catch(const BadRegistration& err)
    {
        std::cout << err.what() << std::endl;
    }

    try
    {
        throw UserQueryError<UserQueryErrorType::USER_NOT_FOUND> {
            "Requested user has not been found"
        };
    }
    catch(const UserQueryError<UserQueryErrorType::USER_NOT_FOUND>& err)
    {
        std::cout << err.what() << std::endl;
    }

    try
    {
        throw AutoUserQueryError<UserQueryErrorType::USER_NOT_FOUND>{ "usr_id=2" };
    }
    catch(const AutoUserQueryError<UserQueryErrorType::USER_NOT_FOUND>& err)
    {
        std::cout << err.what() << std::endl;
    }

    return EXIT_SUCCESS;
}