#include "./src/Item.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <queue>

int main() {
    std::vector<std::unique_ptr<Item>> shopping_list;

    // Create items using make_unique and move them to the vector
    shopping_list.push_back(std::make_unique<Grocery>("Apple", 1.99, 1.5));
    shopping_list.push_back(std::make_unique<Electronics>("Laptop", 999.99, 2));
    shopping_list.push_back(std::make_unique<Clothing>("T-shirt", 19.99, "L"));

    // Save to text file
    std::ofstream text_out("shopping_list.txt");
    for (const auto& item : shopping_list) {
        text_out << *item << std::endl;
    }
    text_out.close();

    // Restore items from text file
    std::ifstream text_in("shopping_list.txt");
    std::vector<std::unique_ptr<Item>> restored_text_items;
    while (text_in) {
        Item* item = nullptr;
        text_in >> item;
        if (item) {
            restored_text_items.push_back(std::unique_ptr<Item>(item));
        }
    }
    text_in.close();

    // Display restored items
    std::cout << "Restored items from text file:" << std::endl;
    for (const auto& item : restored_text_items) {
        item->display();
        std::cout << std::endl;
    }

    // Save to binary file
    std::ofstream binary_out("shopping_list.bin", std::ios::binary);
    for (const auto& item : shopping_list) {
        item->persistBinary(binary_out);
    }
    binary_out.close();

    // Restore items from binary file
    std::ifstream binary_in("shopping_list.bin", std::ios::binary);
    std::vector<std::unique_ptr<Item>> restored_binary_items;
    while (binary_in) {
        auto item = Item::restoreBinary(binary_in);
        if (item) {
            restored_binary_items.push_back(std::move(item));
        }
    }
    binary_in.close();

    // Display restored binary items
    std::cout << "Restored items from binary file:" << std::endl;
    for (const auto& item : restored_binary_items) {
        item->display();
        std::cout << std::endl;
    }

    // Priority queue
    std::priority_queue<std::unique_ptr<Item>, std::vector<std::unique_ptr<Item>>, ItemComparator> pq;
    for (auto& item : shopping_list) {
        pq.push(std::move(item));
    }
    std::cout << "Priority queue (highest price first):" << std::endl;
    while (!pq.empty()) {
        pq.top()->display();
        pq.pop();
    }

    return 0;
}
