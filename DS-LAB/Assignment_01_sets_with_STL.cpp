/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: Data Structures
Assignment-01-Set operations: Write a menu driven C++ program to store sets for
students' names participating in different events in Equinox such as
Coding contest, Project competition, Paper Presentation, MasterMind etc.
1. Find out participants who have participated in Coding and Project
both
2. Find out participants who have participated in Coding or Project
competition or both or Mastermind
3. Find out participants who have participated in Coding but not in
Master mind
Find out participants who have participated in all events
*/

#include <bits/stdc++.h>
using namespace std;

void inputSet(set<string> &s) {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> name;
        s.insert(name);
    }
}

void display(set<string> s) {
    for (auto x : s) cout << x << " ";
    cout << endl;
}

set<string> intersection(set<string> a, set<string> b) {
    set<string> result;
    for (auto x : a)
        if (b.count(x)) result.insert(x);
    return result;
}

set<string> unionSet(set<string> a, set<string> b) {
    set<string> result = a;
    result.insert(b.begin(), b.end());
    return result;
}

set<string> difference(set<string> a, set<string> b) {
    set<string> result;
    for (auto x : a)
        if (!b.count(x)) result.insert(x);
    return result;
}

int main() {
    set<string> coding, project, paper, mastermind;

    cout << "Coding:\n"; inputSet(coding);
    cout << "Project:\n"; inputSet(project);
    cout << "Paper:\n"; inputSet(paper);
    cout << "MasterMind:\n"; inputSet(mastermind);

    int choice;
    do {
        cout << "\n1. Coding AND Project\n";
        cout << "2. Coding OR Project OR MasterMind\n";
        cout << "3. Coding but NOT MasterMind\n";
        cout << "4. All events\n";
        cout << "5. Exit\n";
        cin >> choice;

        set<string> result;

        switch (choice) {
            case 1:
                result = intersection(coding, project);
                display(result);
                break;

            case 2:
                result = unionSet(coding, project);
                result = unionSet(result, mastermind);
                display(result);
                break;

            case 3:
                result = difference(coding, mastermind);
                display(result);
                break;

            case 4:
                result = intersection(coding, project);
                result = intersection(result, paper);
                result = intersection(result, mastermind);
                display(result);
                break;
        }
    } while (choice != 5);

    return 0;
}