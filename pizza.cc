#include <iostream>
using namespace std;

class Pizza
{
  string queue[50];
  int size, front, rear;

public:
  Pizza(int M)
  {
    size = M;
    front = -1;
    rear = -1;
  }

  bool isEmpty() { return front == -1; }
  bool isFull() { return front == (rear + 1) % size; }

  void placeOrder(string order)
  {
    if (isFull())
    {
      cout << "The order limit is full !!" << endl;
    }
    if (isEmpty())
    {
      front = rear = 0;
    }
    else
    {
      rear = (rear + 1) % size;
    }
    queue[rear] = order;
    cout << "Order placed : " << order << endl;
  }

  void serveOrder()
  {
    if (isEmpty())
    {
      cout << "No pending orders !" << endl;
    }
    cout << "Order served: " << queue[front] << endl;
    if (front == rear)
    {
      front = rear = -1;
    }
    else
    {
      front = (front + 1) % size;
    }
  }
  void display()
  {
    if (isEmpty())
    {
      cout << "No pending orders.\n";
      return;
    }

    cout << "Pending Orders:\n";

    int i = front;
    while (true)
    {
      cout << queue[i] << endl;
      if (i == rear)
        break;
      i = (i + 1) % size;
    }
  }
};


int main() {
    int M;
    cout << "Enter maximum number of orders: ";
    cin >> M;

    Pizza p(M);

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
                p.display();
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