/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s): Alexander Lumala, William Burdon
Your team alias: Hash Masters
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
using namespace std;

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now

    HashTable table(k);

    for (int i = 0; i < n; i++) {
        string data = "data";
        table.insert(texts[i], data);
    }

    Node** table_Array = table.getTable();
    int* table_lengths = new int[k];

    cout << "==== Printing the contents of the first 5 slots ====" << endl;

    for(int i = 0; i < 5; i++){
        cout << "Slot " << i << ": ";
        Node* current = table_Array[i];

        while(current != nullptr){
            cout << current->key << " ";
            current = current->next;
        }

        cout << endl;
    }


    cout << "==== Printing the slot lengths ====" << endl;

    for (int i = 0; i < k; i++) {
        int count = 0;
        Node* current = table_Array[i];

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        table_lengths[i] = count;

        cout << "Slot " << i << ": " << count << endl;
    }

    cout << "==== Printing the standard deviation =====" << endl;

    float sum = 0.0;

    for(int i = 0; i < k; i++){
        sum += table_lengths[i];
    }

    float mean = sum / k;

    float standard_deviation = 0.0;

    for(int i = 0; i < k; i++){
        standard_deviation += (table_lengths[i] - mean) * (table_lengths[i] - mean);
    }

    standard_deviation = sqrt(standard_deviation / k);

    cout << standard_deviation << endl;

    return 0;
}