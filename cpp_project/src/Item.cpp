#include "Item.h"

// Base class: Item
Item::Item(const std::string& name, double price) : name(name), price(price) {}
Item::~Item() {}

void Item::display() const {
    std::cout << "Name: " << name << ", Price: $" << price << std::endl;
}

void Item::persist_common(std::ostream& out) const {
    out << name << "\n" << price << "\n";
}

void Item::persistBinary_common(std::ofstream& out) const {
    out.write(name.c_str(), name.size() + 1);
    out.write(reinterpret_cast<const char*>(&price), sizeof(price));
}

void Item::restore_common(std::istream& in) {
    in >> name >> price;
}

void Item::restoreBinary_common(std::ifstream& in) {
    std::getline(in, name, '\0');
    in.read(reinterpret_cast<char*>(&price), sizeof(price));
}

// Non-member overloads for << and >>
std::ostream& operator<<(std::ostream& out, const Item& item) {
    item.persist(out);
    return out;
}

std::istream& operator>>(std::istream& in, Item*& item) {
    std::string type;
    in >> type;
    if (type == "Grocery") {
        item = Grocery::restore(in).release();
    } else if (type == "Electronics") {
        item = Electronics::restore(in).release();
    } else if (type == "Clothing") {
        item = Clothing::restore(in).release();
    }
    return in;
}



// Binary restore and persist for Item
std::unique_ptr<Item> Item::restoreBinary(std::ifstream& in) {
    std::string type;
    std::getline(in, type, '\0');
    if (type == "Grocery") {
        return Grocery::restoreBinary(in);
    } else if (type == "Electronics") {
        return Electronics::restoreBinary(in);
    } else if (type == "Clothing") {
        return Clothing::restoreBinary(in);
    }
    return nullptr;
}
