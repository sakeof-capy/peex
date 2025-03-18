#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <filesystem.hpp>
#include <ctime>
#include <chrono>

namespace fs = std::filesystem;

inline std::time_t to_time_t(const fs::file_time_type& ftime)
{
    auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
            ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now()
        );
    std::time_t cftime = std::chrono::system_clock::to_time_t(sctp);
    return cftime;
}

#endif //FILESYSTEM_HPP
