/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: DCN
Assignment-10-Write a program for DNS lookup. Given an IP address as input, it should
return URL and vice-versa.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, string> ipToUrl;
    unordered_map<string, string> urlToIp;

    int n;
    cout << "Enter number of DNS entries: ";
    cin >> n;

    string ip, url;

    for (int i = 0; i < n; i++) {
        cout << "Enter IP and URL: ";
        cin >> ip >> url;
        ipToUrl[ip] = url;
        urlToIp[url] = ip;
    }

    int choice;
    do {
        cout << "\n--- DNS MENU ---\n";
        cout << "1. Find URL from IP\n";
        cout << "2. Find IP from URL\n";
        cout << "3. Display All Entries\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter IP: ";
            cin >> ip;
            if (ipToUrl.find(ip) != ipToUrl.end())
                cout << "URL: " << ipToUrl[ip] << endl;
            else
                cout << "Entry not found\n";
        }
        else if (choice == 2) {
            cout << "Enter URL: ";
            cin >> url;
            if (urlToIp.find(url) != urlToIp.end())
                cout << "IP: " << urlToIp[url] << endl;
            else
                cout << "Entry not found\n";
        }
        else if (choice == 3) {
            cout << "\nDNS Records:\n";
            for (auto &p : ipToUrl) {
                cout << p.first << " -> " << p.second << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}

/*
Testcase:
Enter number of DNS entries: 2
Enter IP and URL: 8.8.8.8 google.com
Enter IP and URL: 1.1.1.1 cloudflare.com

--- DNS MENU ---
1. Find URL from IP
2. Find IP from URL
3. Display All Entries
4. Exit
Enter your choice: 1
Enter IP: 8.8.8.8
URL: google.com

Enter your choice: 2
Enter URL: cloudflare.com
IP: 1.1.1.1

Enter your choice: 3
DNS Records:
8.8.8.8 -> google.com
1.1.1.1 -> cloudflare.com

Enter your choice: 4
Exiting...
*/