#include <iostream>
#include <filesystem>
#include <format>
#include <fstream>

#include "filesystem.hpp"
#include "utilities.hpp"

static const fs::path ROOT_PATH = SOURCE_ROOT_PATH;
static const fs::path DATA_DIR_PATH = ROOT_PATH / "data";
static const fs::path DATA_FILE_PATH1 = DATA_DIR_PATH / "data1.txt";
static const fs::path DATA_FILE_PATH2 = DATA_DIR_PATH / "data2.txt";
static const fs::path DATA_FILE_PATH3 = DATA_DIR_PATH / "data3.txt";

void create_data_file(const fs::path& file_path)
{
    std::ofstream file(file_path);

    if (file)
    {
        file
            << "This is a test file.\n"
            << "Some lines\n"
            << "Some lines\n"
            << "Some lines\n"
            << "Some lines\n"
            << "Some lines\n"
            << "Some lines\n"
            << "Some lines\n";
    }
    else
    {
        exit_program(EXIT_FAILURE, "Cannot create data file");
    }
}

int main()
{
    if (!fs::exists(DATA_DIR_PATH))
    {
        fs::create_directory(DATA_DIR_PATH);
    }

    if (!fs::exists(DATA_FILE_PATH1))
    {
        create_data_file(DATA_FILE_PATH1);
    }

    if (!fs::exists(DATA_FILE_PATH2))
    {
        create_data_file(DATA_FILE_PATH2);
    }

    if (!fs::exists(DATA_FILE_PATH3))
    {
        create_data_file(DATA_FILE_PATH3);
    }

    std::cout << std::boolalpha;
    std::cout << "Data dir: " << fs::absolute(DATA_DIR_PATH) << '\n';
    std::cout << "Data dir is directory: " << fs::is_directory(DATA_DIR_PATH) << '\n';
    std::cout << "Data dir is regular file: " << fs::is_regular_file(DATA_DIR_PATH) << '\n';

    const time_t dir_last_write_time = to_time_t(fs::last_write_time(DATA_DIR_PATH));
    std::cout << "Data dir last write time: " << std::ctime(&dir_last_write_time) << '\n';

    std::cout << "Data file: " << fs::absolute(DATA_FILE_PATH1) << '\n';
    std::cout << "Data file is directory: " << fs::is_directory(DATA_FILE_PATH1) << '\n';
    std::cout << "Data file is regular file: " << fs::is_regular_file(DATA_FILE_PATH1) << '\n';
    std::cout << "Data file size: " << fs::file_size(DATA_FILE_PATH1) << '\n';

    const time_t file_last_write_time = to_time_t(fs::last_write_time(DATA_FILE_PATH1));
    std::cout << "Data file last write time: " << std::ctime(&file_last_write_time) << '\n';

    fs::space_info space_info = fs::space(DATA_FILE_PATH1);
    std::cout
        << "Space available on C:/ | { available = " << space_info.available
        << ", capacity = " << space_info.capacity
        << ", free = " << space_info.free
        << " }\n";

    // fs::rename(DATA_FILE_PATH1, "renamed_data1.txt");
    // fs::copy(DATA_FILE_PATH1, "copied_data1.txt");
    // fs::remove_all(DATA_DIR_PATH);

    exit_program(EXIT_SUCCESS);
}
