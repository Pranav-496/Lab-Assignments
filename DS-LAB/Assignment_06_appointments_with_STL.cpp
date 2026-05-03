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

struct Appointment {
    int start, end;
    bool booked;
};

list<Appointment> slots;

void displayFreeSlots() {
    cout << "\nFree Slots:\n";
    for (auto &a : slots) {
        if (!a.booked)
            cout << a.start << " - " << a.end << endl;
    }
}

void bookAppointment(int s, int e) {
    for (auto &a : slots) {
        if (a.start == s && a.end == e) {
            if (!a.booked) {
                a.booked = true;
                cout << "Appointment Booked\n";
            } else {
                cout << "Slot already booked\n";
            }
            return;
        }
    }
    cout << "Invalid slot\n";
}

void cancelAppointment(int s, int e) {
    for (auto &a : slots) {
        if (a.start == s && a.end == e) {
            if (a.booked) {
                a.booked = false;
                cout << "Appointment Cancelled\n";
            } else {
                cout << "Slot was not booked\n";
            }
            return;
        }
    }
    cout << "Invalid slot\n";
}

void sortSlots() {
    slots.sort([](Appointment a, Appointment b) {
        return a.start < b.start;
    });
    cout << "Slots sorted by time\n";
}

void displayAll() {
    cout << "\nAll Slots:\n";
    for (auto &a : slots) {
        cout << a.start << "-" << a.end << " : ";
        if (a.booked) cout << "Booked\n";
        else cout << "Free\n";
    }
}

int main() {
    int n, s, e, choice;

    cout << "Enter number of appointment slots: ";
    cin >> n;

    cout << "Enter start and end time for each slot:\n";
    for (int i = 0; i < n; i++) {
        cout << "Slot " << i + 1 << " (start end): ";
        cin >> s >> e;
        slots.push_back({s, e, false});
    }

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Display Free Slots\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Sort Slots\n";
        cout << "5. Display All Slots\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayFreeSlots();
                break;

            case 2:
                cout << "Enter start and end time to BOOK: ";
                cin >> s >> e;
                bookAppointment(s, e);
                break;

            case 3:
                cout << "Enter start and end time to CANCEL: ";
                cin >> s >> e;
                cancelAppointment(s, e);
                break;

            case 4:
                sortSlots();
                break;

            case 5:
                displayAll();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}