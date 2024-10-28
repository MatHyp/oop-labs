#include "Item.h"

// Base class: Item
Item::Item(const std::string& name, double price) : name(name), price(price) {}
Item::~Item() {}

void Item::display() const {
    std::cout << "Name: " << name << ", Price: $" << price << std::endl;
}

void Item::persist_common(std::ofstream& out) const {
    out << name << "\n" << price << "\n";
}

void Item::restore_common(std::ifstream& in) {
    in >> name >> price;
}

Item* Item::restore(std::ifstream& in) {
    std::string type;
    in >> type;
    if (type == "Grocery") {
        return Grocery::restore(in);
    } else if (type == "Electronics") {
        return Electronics::restore(in);
    } else if (type == "Clothing") {
        return Clothing::restore(in);
    }
    // Additional types can be handled similarly
    return nullptr;
}

// Derived class: Grocery
Grocery::Grocery(const std::string& name, double price, double weight)
    : Item(name, price), weight(weight) {}

void Grocery::display() const {
    Item::display();
    std::cout << "Weight: " << weight << " kg" << std::endl;
}

void Grocery::persist(std::ofstream& out) const {
    out << "Grocery\n";
    persist_common(out);
    out << weight << "\n";
}

Grocery* Grocery::restore(std::ifstream& in) {
    std::string name;
    double price, weight;
    in >> name >> price >> weight;
    return new Grocery(name, price, weight);
}

// Derived class: Electronics
Electronics::Electronics(const std::string& name, double price, int warranty_years)
    : Item(name, price), warranty_years(warranty_years) {}

void Electronics::display() const {
    Item::display();
    std::cout << "Warranty: " << warranty_years << " years" << std::endl;
}

void Electronics::persist(std::ofstream& out) const {
    out << "Electronics\n";
    persist_common(out);
    out << warranty_years << "\n";
}

Electronics* Electronics::restore(std::ifstream& in) {
    std::string name;
    double price;
    int warranty_years;
    in >> name >> price >> warranty_years;
    return new Electronics(name, price, warranty_years);
}

// Derived class: Clothing
Clothing::Clothing(const std::string& name, double price, const std::string& size)
    : Item(name, price), size(size) {}

void Clothing::display() const {
    Item::display();
    std::cout << "Size: " << size << std::endl;
}

void Clothing::persist(std::ofstream& out) const {
    out << "Clothing\n";
    persist_common(out);
    out << size << "\n";
}

Clothing* Clothing::restore(std::ifstream& in) {
    std::string name, size;
    double price;
    in >> name >> price >> size;
    return new Clothing(name, price, size);
}
