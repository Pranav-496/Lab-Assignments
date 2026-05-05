#include <iostream>
using namespace std;

struct Node {
    string name;
    int day, month;
    Node* next;
};

Node* head = NULL;

// insert
void insert() {
    Node* newNode = new Node;

    cout << "Enter name: ";
    cin >> newNode->name;

    cout << "Enter birthday (DD MM): ";
    cin >> newNode->day >> newNode->month;

    newNode->next = head;
    head = newNode;

    cout << "Student added\n";
}

// delete
void deleteStudent() {
    string name;
    cout << "Enter name to delete: ";
    cin >> name;

    Node* temp = head;
    Node* prev = NULL;

    while (temp) {
        if (temp->name == name) {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            cout << "Deleted\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Student not found\n";
}

// birthday check (manual date input)
void todayBirthday() {
    int todayDay, todayMonth;

    cout << "Enter today's date (DD MM): ";
    cin >> todayDay >> todayMonth;

    bool found = false;
    Node* temp = head;

    while (temp) {
        if (temp->day == todayDay && temp->month == todayMonth) {
            cout << "Happy Birthday " << temp->name << "!\n";
            found = true;
        }
        temp = temp->next;
    }

    if (!found)
        cout << "No birthdays today\n";
}

// display
void display() {
    Node* temp = head;

    if (!temp) {
        cout << "List is empty\n";
        return;
    }

    while (temp) {
        cout << temp->name << " - "
             << temp->day << "/" << temp->month << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        cout << "\n1.Insert\n2.Delete\n3.Today Birthday\n4.Display\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insert(); break;
            case 2: deleteStudent(); break;
            case 3: todayBirthday(); break;
            case 4: display(); break;
        }

    } while (choice != 5);

    return 0;
}