/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: Data Structures
Assignment-09-Simulation of pizza parlor: Pizza parlor accepting maximum M orders.
Orders are served on a first come first served basis. Order once placed
cannot be canceled.
Write C++ program to simulate the system using simple queue or circular
queue
*/

#include <iostream>
using namespace std;

class PizzaParlor {
    string queue[50];
    int front, rear, size;

public:
    PizzaParlor(int M) {
        size = M;
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == (rear + 1) % size);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void placeOrder(string order) {
        if (isFull()) {
            cout << "Order rejected! Queue is full.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        queue[rear] = order;
        cout << "Order placed: " << order << endl;
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }

        cout << "Order served: " << queue[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending Orders:\n";

        int i = front;
        while (true) {
            cout << queue[i] << endl;
            if (i == rear) break;
            i = (i + 1) % size;
        }
    }
};

int main() {
    int M;
    cout << "Enter maximum number of orders: ";
    cin >> M;

    PizzaParlor p(M);

    int choice;
    string order;

    do {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter pizza order: ";
                cin >> order;
                p.placeOrder(order);
                break;

            case 2:
                p.serveOrder();
                break;

            case 3:
                p.displayOrders();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}