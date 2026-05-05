/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: Data Structures
Assignment-12-A list of data representing various environmental parameters such as
temperature, humidity, pollution levels, etc is maintained using
appropriate data structure. Write a C++ program that uses data structures
to perform the following operations:
1. Find the maximum and minimum values of each parameter in the list.
2. Calculate the average value of each parameter in the list.
3. Sort the list in ascending order of any one parameter.
4. Find the highest and lowest values of any one parameter that are
considered safe for the environment.
5. Calculate the impact of the parameter values on the environment based
on certain pre-defined criteria.
6. Analyze the impact of the environmental parameters on the health and
safety of the society.
7. Ensure that the program follows ethical and professional practices,
such as ensuring the privacy and security of the data.
You should implement the program using appropriate data structures that
take into account the size and complexity of the data, and demonstrate an
understanding of the societal and environmental issues related to the data.
Your program should also demonstrate an understanding of the impact of
the parameter values on the environment, and the need for sustainable
development. Finally, your program should adhere to ethical principles
and professional practices, such as ensuring the confidentiality, privacy,
and security of the data
*/


#include <iostream>
using namespace std;

struct Data {
    float temperature;
    float humidity;
    float pollution;
};

Data records[100];
int n;

// input
void inputData() {
    for (int i = 0; i < n; i++) {
        cout << "Enter temp, humidity, pollution: ";
        cin >> records[i].temperature >> records[i].humidity >> records[i].pollution;
    }
}

// min max
void findMinMax() {
    float minT = records[0].temperature, maxT = records[0].temperature;
    float minH = records[0].humidity, maxH = records[0].humidity;
    float minP = records[0].pollution, maxP = records[0].pollution;

    for (int i = 0; i < n; i++) {
        if (records[i].temperature < minT) minT = records[i].temperature;
        if (records[i].temperature > maxT) maxT = records[i].temperature;

        if (records[i].humidity < minH) minH = records[i].humidity;
        if (records[i].humidity > maxH) maxH = records[i].humidity;

        if (records[i].pollution < minP) minP = records[i].pollution;
        if (records[i].pollution > maxP) maxP = records[i].pollution;
    }

    cout << "Temperature Min: " << minT << " Max: " << maxT << endl;
    cout << "Humidity Min: " << minH << " Max: " << maxH << endl;
    cout << "Pollution Min: " << minP << " Max: " << maxP << endl;
}

// average
void averageValues() {
    float sumT = 0, sumH = 0, sumP = 0;

    for (int i = 0; i < n; i++) {
        sumT += records[i].temperature;
        sumH += records[i].humidity;
        sumP += records[i].pollution;
    }

    cout << "Avg Temperature: " << sumT / n << endl;
    cout << "Avg Humidity: " << sumH / n << endl;
    cout << "Avg Pollution: " << sumP / n << endl;
}

// sort by pollution (bubble sort)
void sortByPollution() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (records[j].pollution > records[j + 1].pollution) {
                swap(records[j],records[j+1]);
            }
        }
    }

    cout << "Sorted by Pollution:\n";
    for (int i = 0; i < n; i++) {
        cout << records[i].temperature << " "
             << records[i].humidity << " "
             << records[i].pollution << endl;
    }
}

// safe range
void safeRangeCheck() {
    float safeMin = 0, safeMax = 50;

    float lowest = 999999, highest = -999999;

    for (int i = 0; i < n; i++) {
        float p = records[i].pollution;

        if (p >= safeMin && p <= safeMax) {
            if (p < lowest) lowest = p;
            if (p > highest) highest = p;
        }
    }

    if (lowest == 999999)
        cout << "No safe values found\n";
    else
        cout << "Safe Pollution Range: " << lowest << " to " << highest << endl;
}

// environmental impact
void environmentalImpact() {
    for (int i = 0; i < n; i++) {
        if (records[i].pollution > 100)
            cout << "High Risk\n";
        else if (records[i].pollution > 50)
            cout << "Moderate Risk\n";
        else
            cout << "Low Risk\n";
    }
}

// health impact
void healthImpact() {
    for (int i = 0; i < n; i++) {
        if (records[i].pollution > 100)
            cout << "Severe Hazard\n";
        else if (records[i].pollution > 70)
            cout << "Respiratory Issues\n";
        else
            cout << "Safe\n";
    }
}

int main() {
    int choice;

    cout << "Enter number of records: ";
    cin >> n;

    inputData();

    do {
        cout << "\n1.Min-Max\n2.Average\n3.Sort\n4.Safe Range\n5.Env Impact\n6.Health Impact\n7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: findMinMax(); break;
            case 2: averageValues(); break;
            case 3: sortByPollution(); break;
            case 4: safeRangeCheck(); break;
            case 5: environmentalImpact(); break;
            case 6: healthImpact(); break;
        }

    } while (choice != 7);

    return 0;
}