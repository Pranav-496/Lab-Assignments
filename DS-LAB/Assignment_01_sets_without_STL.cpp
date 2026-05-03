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

string coding[50], project[50], paper[50], mastermind[50];
int nc, np, npp, nm;

bool exists(string arr[], int n, string key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return true;
    return false;
}

void input(string arr[], int &n) {
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void display(string arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

    cout << "Coding:\n"; input(coding, nc);
    cout << "Project:\n"; input(project, np);
    cout << "Paper:\n"; input(paper, npp);
    cout << "MasterMind:\n"; input(mastermind, nm);

    int choice;
    do {
        cout << "\n1. Coding AND Project\n";
        cout << "2. Coding OR Project OR MasterMind\n";
        cout << "3. Coding but NOT MasterMind\n";
        cout << "4. All events\n";
        cout << "5. Exit\n";
        cin >> choice;

        string result[100];
        int k = 0;

        switch (choice) {
            case 1:
                for (int i = 0; i < nc; i++)
                    if (exists(project, np, coding[i]))
                        result[k++] = coding[i];
                display(result, k);
                break;

            case 2:
                for (int i = 0; i < nc; i++)
                    if (!exists(result, k, coding[i]))
                        result[k++] = coding[i];

                for (int i = 0; i < np; i++)
                    if (!exists(result, k, project[i]))
                        result[k++] = project[i];

                for (int i = 0; i < nm; i++)
                    if (!exists(result, k, mastermind[i]))
                        result[k++] = mastermind[i];

                display(result, k);
                break;

            case 3:
                for (int i = 0; i < nc; i++)
                    if (!exists(mastermind, nm, coding[i]))
                        result[k++] = coding[i];
                display(result, k);
                break;

            case 4:
                for (int i = 0; i < nc; i++)
                    if (exists(project, np, coding[i]) &&
                        exists(paper, npp, coding[i]) &&
                        exists(mastermind, nm, coding[i]))
                        result[k++] = coding[i];
                display(result, k);
                break;
        }

    } while (choice != 5);

    return 0;
}