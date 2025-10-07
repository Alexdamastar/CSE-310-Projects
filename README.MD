# CSE 310 Hash Function DIY Contest

## Team Information
**Team Members:** Alexander Lumala, William Burdon  
**Team Alias:** Hash Masters

## Program Description

This program implements a custom hash table data structure for the CSE 310 Hash Function DIY Contest. The program reads input consisting of a specified number of hash table slots (k) followed by a sequence of text tokens (n), and inserts these tokens into the hash table using a custom-designed hash function. 

The hash table uses separate chaining with linked lists to handle collisions, where each slot can store multiple key-value pairs. The program is designed to evaluate the effectiveness of the custom hash function by printing the contents of the first 5 slots, displaying the length of each slot (collision chain length), and calculating the standard deviation of slot lengths to measure the distribution quality of the hash function. 

The implementation includes a HashTable class with insert and search operations, a Node structure for linked list elements, and a customizable hash_function that maps string keys to integer indices within the table size.

## Key Features
- **Custom Hash Function**: Implements a user-defined hash function to distribute keys across slots
- **Collision Handling**: Uses separate chaining with linked lists to manage collisions
- **Performance Metrics**: Calculates and displays standard deviation to measure hash distribution quality
- **Flexible Input**: Accepts variable number of slots and tokens via standard input

## Building and Running
```bash
make
./encoder < inputs/sample_input.txt
```
