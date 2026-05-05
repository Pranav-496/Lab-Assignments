/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: Data Structures
Assignment-11-A Dictionary using Hash table: A Dictionary stores key and value pairs
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
comparable, Keys must be unique.
Standard Operations: Insert(key, value), Find(key), Delete(key)
Write a menu driven C++ program to provide above standard operations
on dictionaries
Write a menu driven C++ program to provide all the functions of a
dictionary (ADT) using hashing and handle collisions using chaining.
*/

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 20;

struct Node {
    int key;
    string value;
    Node* next;
};

Node* table[SIZE];

// hash function
int hashFunc(int key) {
    return key % SIZE;
}

// insert
void insert(int key, string value) {
    int index = hashFunc(key);

    Node* temp = table[index];

    while (temp) {
        if (temp->key == key) {
            cout << "Key already exists\n";
            return;
        }
        temp = temp->next;
    }

    Node* newNode = new Node{key, value, table[index]};
    table[index] = newNode;

    cout << "Inserted\n";
}

// search
void findKey(int key) {
    int index = hashFunc(key);
    Node* temp = table[index];

    while (temp) {
        if (temp->key == key) {
            cout << "Value: " << temp->value << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Key not found\n";
}

// delete
void deleteKey(int key) {
    int index = hashFunc(key);
    Node* temp = table[index];
    Node* prev = NULL;

    while (temp) {
        if (temp->key == key) {
            if (prev == NULL)
                table[index] = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            cout << "Deleted\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Key not found\n";
}

// display
void display() {
    bool empty = true;

    for (int i = 0; i < SIZE; i++) {
        if (table[i] != NULL) {
            empty = false;

            cout << "Index " << i << ": ";
            Node* temp = table[i];

            while (temp) {
                cout << "(" << temp->key << "," << temp->value << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    if (empty)
        cout << "Dictionary is empty\n";
}

int main() {
    int choice, key;
    string value;

    // initialize table
    for (int i = 0; i < SIZE; i++)
        table[i] = NULL;

    do {
        cout << "\n1.Insert\n2.Find\n3.Delete\n4.Display\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value: ";
                cin >> key >> value;
                insert(key, value);
                break;

            case 2:
                cout << "Enter key: ";
                cin >> key;
                findKey(key);
                break;

            case 3:
                cout << "Enter key: ";
                cin >> key;
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}