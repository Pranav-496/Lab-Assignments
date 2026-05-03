/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: Data Structures
Assignment-02-String Operations: Write a menu driven C++ program with a class for
String. Write functions
1. To determine the frequency of occurrence of a particular character
in the string.
2. Extract a new string from original string by accepting starting
position and length
3. To accept any character and return the string with by removing all
occurrences of a character accepted
4. To make an in-place replacement of a substring w of a string by the
string x. Note that w may not be of same size that of x
5. To check whether given string is palindrome or not
*/

#include <bits/stdc++.h>
using namespace std;

class String {
    char str[200];

    int length() {
        int i = 0;
        while (str[i] != '\0')
            i++;
        return i;
    }

public:
    void input() {
        cin.ignore();
        cin.getline(str, 200);
    }

    void display() {
        cout << str << endl;
    }

    // 1. Frequency of character
    void frequency() {
        char ch;
        int count = 0;
        cout << "Enter character: ";
        cin >> ch;

        for (int i = 0; str[i] != '\0'; i++)
            if (str[i] == ch)
                count++;

        cout << "Frequency: " << count << endl;
    }

    // 2. Extract substring
    void extract() {
        int pos, len;
        cout << "Enter position and length: ";
        cin >> pos >> len;

        char temp[200];
        int i = 0;

        for (int j = pos; j < pos + len && str[j] != '\0'; j++)
            temp[i++] = str[j];

        temp[i] = '\0';
        cout << "Extracted string: " << temp << endl;
    }

    // 3. Remove character
    void removeChar() {
        char ch;
        cout << "Enter character to remove: ";
        cin >> ch;

        char temp[200];
        int i = 0, j = 0;

        while (str[i] != '\0') {
            if (str[i] != ch)
                temp[j++] = str[i];
            i++;
        }

        temp[j] = '\0';

        for (i = 0; temp[i] != '\0'; i++)
            str[i] = temp[i];
        str[i] = '\0';

        cout << "After removal: ";
        display();
    }

    // 4. Replace word
    void replace() {
        char w[50], x[50];
        cout << "Enter word to replace: ";
        cin.ignore();
        cin.getline(w, 50);

        cout << "Enter new word: ";
        cin.getline(x, 50);

        char temp[200];
        int i = 0, j = 0, k, wl = 0, xl = 0;

        while (w[wl] != '\0') wl++;
        while (x[xl] != '\0') xl++;

        while (str[i] != '\0') {
            k = 0;
            while (k < wl && str[i + k] == w[k])
                k++;

            if (k == wl) {
                for (int m = 0; m < xl; m++)
                    temp[j++] = x[m];
                i += wl;
            } else {
                temp[j++] = str[i++];
            }
        }

        temp[j] = '\0';

        for (i = 0; temp[i] != '\0'; i++)
            str[i] = temp[i];
        str[i] = '\0';

        cout << "After replacement: ";
        display();
    }

    // 5. Palindrome check
    void palindrome() {
        int l = 0;
        int r = length() - 1;
        int flag = 1;

        while (l < r) {
            if (str[l] != str[r]) {
                flag = 0;
                break;
            }
            l++;
            r--;
        }

        if (flag)
            cout << "Palindrome" << endl;
        else
            cout << "Not Palindrome" << endl;
    }

    // 6. Reverse string
    void reverse() {
        int l = 0;
        int r = length() - 1;
        char temp;

        while (l < r) {
            temp = str[l];
            str[l] = str[r];
            str[r] = temp;
            l++;
            r--;
        }

        cout << "Reversed string: ";
        display();
    }

    // 7. Concatenate strings
    void concat() {
        char s2[200];
        cout << "Enter second string: ";
        cin.ignore();
        cin.getline(s2, 200);

        int i = length();
        int j = 0;

        while (s2[j] != '\0') {
            str[i++] = s2[j++];
        }
        str[i] = '\0';

        cout << "After concatenation: ";
        display();
    }
};

int main() {
    String s;
    int ch;

    cout << "Enter a string: ";
    s.input();

    do {
        cout << "\nMenu:\n";
        cout << "1. Frequency of character\n";
        cout << "2. Extract substring\n";
        cout << "3. Remove character\n";
        cout << "4. Replace word\n";
        cout << "5. Palindrome check\n";
        cout << "6. Reverse string\n";
        cout << "7. Concatenate string\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        cin >> ch;

        switch (ch) {
            case 1: s.frequency(); break;
            case 2: s.extract(); break;
            case 3: s.removeChar(); break;
            case 4: s.replace(); break;
            case 5: s.palindrome(); break;
            case 6: s.reverse(); break;
            case 7: s.concat(); break;
            case 0: break;
            default: cout << "Invalid choice!" << endl;
        }

    } while (ch != 0);

    return 0;
}