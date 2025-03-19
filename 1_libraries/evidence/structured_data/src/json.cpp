#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace json = nlohmann;
namespace fs = std::filesystem;

static const fs::path ROOT_PATH = SOURCE_ROOT_PATH;
static const fs::path DATA_DIR_PATH = ROOT_PATH / "data";
static const fs::path ADDRESS_FILE_PATH = DATA_DIR_PATH / "address.json";

struct Address
{
    std::string street;
    int house_number{};
    int postcode{};
};

void to_json(json::json& j, const Address& p) {
    j = json::json{
        {"street", p.street},
        {"house_number", p.house_number},
        {"postcode", p.postcode}
    };
}

void from_json(const json::json& j, Address& p) {
    j.at("street").get_to(p.street);
    j.at("house_number").get_to(p.house_number);
    j.at("postcode").get_to(p.postcode);
}

int main()
{
    if (!fs::exists(DATA_DIR_PATH))
    {
        fs::create_directory(DATA_DIR_PATH);
    }

    const Address address {
        .street = "SomeStreet",
        .house_number = 13,
        .postcode = 38800,
    };

    const json::json address_json = address;

    std::cout << "Address json before saving to file: " << address_json.dump(4) << '\n';
    std::ofstream out_file(ADDRESS_FILE_PATH.string());
    out_file << address_json.dump(4);
    out_file.close();

    std::cout << "Serialized Address put to a file: " << ADDRESS_FILE_PATH.string() << '\n';

    std::ifstream in_file(ADDRESS_FILE_PATH.string());
    nlohmann::json out_address_json;
    in_file >> out_address_json;
    in_file.close();

    std::cout << "Get address out of the file: " << out_address_json.dump(4) << '\n';

    // Convert JSON back to Address object
    Address address_deserialized = out_address_json.template get<Address>();

    std::cout << "Deserialized Address: " << std::endl;
    std::cout << "Street: " << address_deserialized.street << '\n';
    std::cout << "House Number: " << address_deserialized.house_number << '\n';
    std::cout << "Postcode: " << address_deserialized.postcode << '\n';

    // json::json json_data = {
    //     {"pi", 3.141},
    //     {"happy", true},
    //     {"name", "Niels"},
    //     {"nothing", nullptr},
    //     {"answer", {
    //     {"everything", 42}
    //     }},
    //     {"list", {1, 0, 2}},
    //     {"object", {
    //     {"currency", "USD"},
    //     {"value", json::json::array({
    //         {"currency", "USD"},
    //         {"value", "USD"} })}
    //     }}
    // };
    //
    // std::cout << "JSON Data: " << json_data.dump(2) << std::endl;

    return EXIT_SUCCESS;
}
