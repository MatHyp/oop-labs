#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <queue>

// Base class for all items
class Item {
protected:
    std::string name;
    double price;

public:
    Item(const std::string& name, double price);
    virtual ~Item();

    virtual void display() const;
    virtual void persist(std::ostream& out) const = 0;
    virtual void persistBinary(std::ofstream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Item& item);
    friend std::istream& operator>>(std::istream& in, Item*& item);

    static std::unique_ptr<Item> restore(std::istream& in);
    static std::unique_ptr<Item> restoreBinary(std::ifstream& in);

protected:
    void persist_common(std::ostream& out) const;
    void persistBinary_common(std::ofstream& out) const;
    void restore_common(std::istream& in);
    void restoreBinary_common(std::ifstream& in);
};

// Derived class: Grocery
class Grocery : public Item {
    double weight;

public:
    Grocery(const std::string& name, double price, double weight);
    void display() const override;
    void persist(std::ostream& out) const override;
    void persistBinary(std::ofstream& out) const override;

    friend std::ostream& operator<<(std::ostream& out, const Grocery& grocery);
    friend std::istream& operator>>(std::istream& in, Grocery& grocery);

    static std::unique_ptr<Grocery> restore(std::istream& in);
    static std::unique_ptr<Grocery> restoreBinary(std::ifstream& in);
};

// Derived class: Electronics
class Electronics : public Item {
    int warranty_years;

public:


    Electronics(const std::string& name, double price, int warranty_years);
    void display() const override;
    void persist(std::ostream& out) const override;
    void persistBinary(std::ofstream& out) const override;

    friend std::ostream& operator<<(std::ostream& out, const Electronics& electronics);
    friend std::istream& operator>>(std::istream& in, Electronics& electronics);

    static std::unique_ptr<Electronics> restore(std::istream& in);
    static std::unique_ptr<Electronics> restoreBinary(std::ifstream& in);
};

// Derived class: Clothing
class Clothing : public Item {
    std::string size;

public:
    Clothing(const std::string& name, double price, const std::string& size);
    void display() const override;
    void persist(std::ostream& out) const override;
    void persistBinary(std::ofstream& out) const override;

    friend std::ostream& operator<<(std::ostream& out, const Clothing& clothing);
    friend std::istream& operator>>(std::istream& in, Clothing& clothing);

    static std::unique_ptr<Clothing> restore(std::istream& in);
    static std::unique_ptr<Clothing> restoreBinary(std::ifstream& in);
};

// Comparator for priority queue (order items by price in descending order)
struct ItemComparator {
    bool operator()(const std::unique_ptr<Item>& lhs, const std::unique_ptr<Item>& rhs) const {
        return lhs->price < rhs->price;
    }
};

#endif // ITEM_H
