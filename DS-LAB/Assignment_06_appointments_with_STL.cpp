#include <bits/stdc++.h>
using namespace std;

struct Appointment
{
  int start, end;
  bool booked;
};

list<Appointment> slots;

void displayFreeSlots()
{
  for (auto &a : slots)
  {
    if (!a.booked)
      cout << a.start << " - " << a.end << endl;
  }
}

void bookAppointment(int s, int e)
{
  for (auto &a : slots)
  {
    if (a.start == s && a.end == e)
    {
      if (!a.booked)
      {
        a.booked = true;
        cout << "Booked\n";
        return;
      }
      else
      {
        cout << "Already booked\n";
        return;
      }
    }
  }
  cout << "Invalid slot\n";
}

void cancelAppointment(int s, int e)
{
  for (auto &a : slots)
  {
    if (a.start == s && a.end == e)
    {
      if (a.booked)
      {
        a.booked = false;
        cout << "Cancelled\n";
        return;
      }
      else
      {
        cout << "Not booked\n";
        return;
      }
    }
  }
  cout << "Invalid slot\n";
}

void sortByTime()
{
  slots.sort([](Appointment a, Appointment b)
             { return a.start < b.start; });
}

void displayAll()
{
  for (auto &a : slots)
  {
    cout << a.start << "-" << a.end << " ";
    if (a.booked)
      cout << "Booked\n";
    else
      cout << "Free\n";
  }
}

int main()
{
  int n, s, e, choice;
  cout << "Enter number of slots: ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> s >> e;
    slots.push_back({s, e, false});
  }

  do
  {
    cout << "\n1.Display Free\n2.Book\n3.Cancel\n4.Sort\n5.Display All\n6.Exit\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
      displayFreeSlots();
      break;
    case 2:
      cin >> s >> e;
      bookAppointment(s, e);
      break;
    case 3:
      cin >> s >> e;
      cancelAppointment(s, e);
      break;
    case 4:
      sortByTime();
      break;
    case 5:
      displayAll();
      break;
    }
  } while (choice != 6);

  return 0;
}