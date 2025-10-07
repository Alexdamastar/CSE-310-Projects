#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

#ifndef HASH_H
#define HASH_H

struct Node {
    std::string key;
    std::string data;
    Node* next;

    Node(std::string& key, std::string& data);
};

class HashTable {
    public:
        HashTable(int size);
        ~HashTable();

        void insert(std::string& key, std::string& data);
        std::string search(const std::string& key);

        Node** getTable();

    private:
        Node** table;
        int size;
};


int hash_function(string text);

#endif