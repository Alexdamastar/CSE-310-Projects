#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

Node::Node(std::string& key, std::string& data) : key(key), data(data), next(nullptr) {}

HashTable::HashTable(int size) : size(size) {
    table = new Node*[size];
    for (int i = 0; i < size; i++) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    delete[] table;
}

void HashTable::insert(std::string& key, std::string& data) {
    int index = hash_function(key) % size;
    Node* newNode = new Node(key, data);

    newNode->next = table[index];
    table[index] = newNode;
}

std::string HashTable::search(const std::string& key) {
    int index = hash_function(key) % size;
    Node* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current->data;
        }
        current = current->next;
    }

    return "";
}

int hash_function(std::string text) {
    // Implement your own hash function here

    int x = text.length();

    int a = x % 5;

    return 1;
}