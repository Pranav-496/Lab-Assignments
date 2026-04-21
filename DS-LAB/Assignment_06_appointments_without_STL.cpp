#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int start, end;
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
  Node *t = head;
  while (t)
  {
    if (!t->booked)
      cout << t->start << "-" << t->end << endl;
    t = t->next;
  }
}

void book(int s, int e)
{
  Node *t = head;
  while (t)
  {
    if (t->start == s && t->end == e)
    {
      if (!t->booked)
      {
        t->booked = true;
        cout << "Booked\n";
        return;
      }
      else
      {
        cout << "Already booked\n";
        return;
      }
    }
    t = t->next;
  }
  cout << "Invalid slot\n";
}

void cancel(int s, int e)
{
  Node *t = head;
  while (t)
  {
    if (t->start == s && t->end == e)
    {
      if (t->booked)
      {
        t->booked = false;
        cout << "Cancelled\n";
        return;
      }
      else
      {
        cout << "Not booked\n";
        return;
      }
    }
    t = t->next;
  }
  cout << "Invalid slot\n";
}

// Bubble sort using pointer manipulation
void sortList()
{
  if (!head)
    return;

  bool swapped;
  Node *ptr1;
  Node *lptr = NULL;

  do
  {
    swapped = false;
    ptr1 = head;

    while (ptr1->next != lptr)
    {
      if (ptr1->start > ptr1->next->start)
      {
        swap(ptr1->start, ptr1->next->start);
        swap(ptr1->end, ptr1->next->end);
        swap(ptr1->booked, ptr1->next->booked);
        swapped = true;
      }
      ptr1 = ptr1->next;
    }
    lptr = ptr1;
  } while (swapped);
}

// TRUE pointer manipulation (no data swap)
Node *sortByPointer(Node *head)
{
  if (!head || !head->next)
    return head;

  Node *sorted = NULL;

  while (head)
  {
    Node *curr = head;
    head = head->next;

    if (!sorted || curr->start < sorted->start)
    {
      curr->next = sorted;
      sorted = curr;
    }
    else
    {
      Node *temp = sorted;
      while (temp->next && temp->next->start < curr->start)
        temp = temp->next;

      curr->next = temp->next;
      temp->next = curr;
    }
  }
  return sorted;
}

void displayAll()
{
  Node *t = head;
  while (t)
  {
    cout << t->start << "-" << t->end << " ";
    if (t->booked)
      cout << "Booked\n";
    else
      cout << "Free\n";
    t = t->next;
  }
}

int main()
{
  int n, s, e, ch;
  cout << "Enter number of slots: ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> s >> e;
    insert(s, e);
  }

  do
  {
    cout << "\n1.Free\n2.Book\n3.Cancel\n4.Sort(Data Swap)\n5.Sort(Pointer)\n6.Display\n7.Exit\n";
    cin >> ch;

    switch (ch)
    {
    case 1:
      displayFree();
      break;
    case 2:
      cin >> s >> e;
      book(s, e);
      break;
    case 3:
      cin >> s >> e;
      cancel(s, e);
      break;
    case 4:
      sortList();
      break;
    case 5:
      head = sortByPointer(head);
      break;
    case 6:
      displayAll();
      break;
    }
  } while (ch != 7);

  return 0;
}