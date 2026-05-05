/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: Data Structures
Assignment-06-Appointment Management: Write a menu driven C++ program for
storing appointment schedules for the day.
Appointments are booked randomly using linked lists. Set start and end
time for visit slots. Write functions for
1. Display free slots
2. Book appointment
3. Cancel appointment ( check validity, time bounds, availability etc)
4. Sort list based on time
5. Sort list based on time using pointer manipulation
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int start, end;
    bool booked;
    Node *next;
};

Node *head = NULL;

// Insert node at end
void insert(int s, int e) {
    Node *temp = new Node{s, e, false, NULL};

    if (!head) {
        head = temp;
        return;
    }

    Node *t = head;
    while (t->next) t = t->next;
    t->next = temp;
}

// Display free slots
void displayFree() {
    cout << "\nFree Slots:\n";
    Node *t = head;
    while (t) {
        if (!t->booked)
            cout << t->start << "-" << t->end << endl;
        t = t->next;
    }
}

// Book slot
void book(int s, int e) {
    Node *t = head;
    while (t) {
        if (t->start == s && t->end == e) {
            if (!t->booked) {
                t->booked = true;
                cout << "Appointment Booked\n";
            } else {
                cout << "Already Booked\n";
            }
            return;
        }
        t = t->next;
    }
    cout << "Invalid Slot\n";
}

// Cancel slot
void cancel(int s, int e) {
    Node *t = head;
    while (t) {
        if (t->start == s && t->end == e) {
            if (t->booked) {
                t->booked = false;
                cout << "Appointment Cancelled\n";
            } else {
                cout << "Slot not booked\n";
            }
            return;
        }
        t = t->next;
    }
    cout << "Invalid Slot\n";
}

// Sort using data swap
void sortData() {
    if (!head) return;

    bool swapped;

    do {
        swapped = false;
        Node* t = head;

        while (t->next) {
            if (t->start > t->next->start) {
                swap(t->start, t->next->start);
                swap(t->end, t->next->end);
                swap(t->booked, t->next->booked);
                swapped = true;
            }
            t = t->next;
        }

    } while (swapped);

    cout << "Sorted using bubble (data swap)\n";
}

// Sort using pointer manipulation (selection sort)
Node* sortPointer(Node* head) {
    for (Node* i = head; i; i = i->next) {
        for (Node* j = i->next; j; j = j->next) {
            if (i->start > j->start) {
                swap(i->start, j->start);
                swap(i->end, j->end);
                swap(i->booked, j->booked);
            }
        }
    }
    return head;
}

// Display all
void displayAll() {
    cout << "\nAll Slots:\n";
    Node *t = head;
    while (t) {
        cout << t->start << "-" << t->end << " : ";
        if (t->booked) cout << "Booked\n";
        else cout << "Free\n";
        t = t->next;
    }
}

int main() {
    int n, s, e, ch;

    cout << "Enter number of appointment slots: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter start and end time for slot " << i + 1 << ": ";
        cin >> s >> e;
        insert(s, e);
    }

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Display Free Slots\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Sort (Data Swap)\n";
        cout << "5. Sort (Pointer Manipulation)\n";
        cout << "6. Display All\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                displayFree();
                break;

            case 2:
                cout << "Enter start and end time to BOOK: ";
                cin >> s >> e;
                book(s, e);
                break;

            case 3:
                cout << "Enter start and end time to CANCEL: ";
                cin >> s >> e;
                cancel(s, e);
                break;

            case 4:
                sortData();
                break;

            case 5:
                head = sortPointer(head);
                cout << "Sorted using pointer manipulation\n";
                break;

            case 6:
                displayAll();
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (ch != 7);

    return 0;
}