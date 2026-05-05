#include <iostream>
using namespace std;

struct Node
{
  int st, end;
  bool booked;
  Node *next;
};

Node *head = NULL;

void insert(int s, int e)
{
  Node *temp = new Node{s, e, false, NULL};
  if (!head)
  {
    head = temp;
    return;
  }

  Node *t = head;
  while (t->next)
    t = t->next;
  t->next = temp;
}

void displayFree()
{
  cout << "\n Free slots : \n";
  Node *t = head;

  while (t)
  {
    if (!t->booked)
    {
      cout << t->st << " - " << t->end << endl;
      t = t->next;
    }
  }
}

void book(int s, int e)
{
  Node *t = head;
  while (t)
  {
    if (t->st == s && t->end == e)
    {
      if (!t->booked)
      {
        t->booked = true;
        cout << "Appointment booked !" << endl;
      }
      else
      {
        cout << "Time slot is occupied" << endl;
      }
      return;
    }
    t = t->next;
  }
  cout << "Invalid time slot" << endl;
}

void cancel(int s, int e)
{
  Node *t = head;
  while (t)
  {
    if (t->st == s && t->end == e)
    {
      if (t->booked)
      {
        t->booked = false;
        cout << "Appointment Cancelled !" << endl;
      }
      else
      {
        cout << "Time slot is vacant" << endl;
      }
      return;
    }
    t = t->next;
  }
  cout << "Invalid time slot" << endl;
}

void sortData()
{
  if (!head)
    return;

  bool swp;

  do
  {
    swp = false;
    Node *t = head;

    while (t->next)
    {
      if (t->st > t->next->st)
      {
        swap(t->st, t->next->st);
        swap(t->end, t->next->end);
        swap(t->booked, t->next->booked);
        swp = true;
      }
      t = t->next;
    }
  } while (swp);

  cout << "Data sorted" << endl;
}

Node *sortPointer(Node *head)
{
  for (Node *i = head; i; i = i->next)
  {
    for (Node *j = i->next; j; j = j->next)
    {
      if (i->st > j->st)
      {
        swap(i->st, j->st);
        swap(i->end, j->end);
        swap(i->booked, j->booked);
      }
    }
  }
  return head;
}

void displayAll()
{
  cout << "\nAll Slots:\n";
  Node *t = head;
  while (t)
  {
    cout << t->st << "-" << t->end << " : ";
    if (t->booked)
      cout << "Booked\n";
    else
      cout << "Free\n";
    t = t->next;
  }
}

int main()
{
  int s, e, n, ch;

  cout << "Enter the number of appointment slots :" << endl;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cout << "Enter start and end time for slot " << i + 1 << ": ";
    cin >> s >> e;
    insert(s, e);
  }

  do
  {
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

    switch (ch)
    {
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