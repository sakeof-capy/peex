#include <pugixml.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

static const fs::path ROOT_PATH = SOURCE_ROOT_PATH;
static const fs::path DATA_DIR_PATH = ROOT_PATH / "data";
static const fs::path ADDRESS_FILE_PATH = DATA_DIR_PATH / "address.xml";

struct Address
{
    std::string street;
    int house_number{};
    int postcode{};
};

void to_xml(pugi::xml_document& doc, pugi::xml_node& node, const Address& p) {
    node = doc.append_child("Address");

    node.append_child("Street").text() = p.street.c_str();
    node.append_child("HouseNumber").text() = p.house_number;
    node.append_child("Postcode").text() = p.postcode;
}

void from_xml(const pugi::xml_node& node, Address& p) {
    p.street = node.child("Street").text().as_string();
    p.house_number = node.child("HouseNumber").text().as_int();
    p.postcode = node.child("Postcode").text().as_int();
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

    pugi::xml_document doc;
    pugi::xml_node address_node;
    to_xml(doc, address_node, address);

    std::cout << "Address XML before saving to file: " << std::endl;
    doc.save(std::cout, "  ");  // Optionally print the XML to console

    std::ofstream file_out(ADDRESS_FILE_PATH);

    if (!file_out)
    {
        std::cerr << "Failed to open file for writing: " << ADDRESS_FILE_PATH << std::endl;
        return 1;
    }

    doc.save(file_out, "  ");
    file_out.close();

    std::cout << "Serialized Address put to a file: " << ADDRESS_FILE_PATH.string() << '\n';

    pugi::xml_document read_doc;
    if (!read_doc.load_file(ADDRESS_FILE_PATH.string().c_str()))
    {
        std::cerr << "Failed to load XML file!" << std::endl;
        return 1;
    }

    pugi::xml_node read_address_node = read_doc.child("Address");
    Address address_deserialized;
    from_xml(read_address_node, address_deserialized);

    std::cout << "Deserialized Address: " << std::endl;
    std::cout << "Street: " << address_deserialized.street << '\n';
    std::cout << "House Number: " << address_deserialized.house_number << '\n';
    std::cout << "Postcode: " << address_deserialized.postcode << '\n';

    return 0;
}
