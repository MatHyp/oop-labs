#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Base class for all items
class Item {
protected:
    std::string name;
    double price;

public:
    Item(const std::string& name, double price);
    virtual ~Item();

    // Virtual methods for displaying and persisting item information
    virtual void display() const;
    virtual void persist(std::ofstream& out) const = 0;

    // Static method to restore item from file
    static Item* restore(std::ifstream& in);

protected:
    void persist_common(std::ofstream& out) const;
    void restore_common(std::ifstream& in);
};

// Derived class: Grocery
class Grocery : public Item {
    double weight;

public:
    Grocery(const std::string& name, double price, double weight);
    void display() const override;
    void persist(std::ofstream& out) const override;
    static Grocery* restore(std::ifstream& in);
};

// Derived class: Electronics
class Electronics : public Item {
    int warranty_years;

public:
    Electronics(const std::string& name, double price, int warranty_years);
    void display() const override;
    void persist(std::ofstream& out) const override;
    static Electronics* restore(std::ifstream& in);
};

// Derived class: Clothing
class Clothing : public Item {
    std::string size;

public:
    Clothing(const std::string& name, double price, const std::string& size);
    void display() const override;
    void persist(std::ofstream& out) const override;
    static Clothing* restore(std::ifstream& in);
};

#endif // ITEM_H
