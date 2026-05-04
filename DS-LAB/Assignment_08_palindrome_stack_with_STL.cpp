/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: Data Structures
Assignment-08-String operations: A palindrome is a string of characters that's identical
when read in forward and backward direction. Typically, punctuation,
capitalization, and spaces are ignored. For example, “1.Poor Dan is in a
droop!!” is a palindrome, as can be seen by examining the characters
“poordanisinadroop” and observing that they are identical when read
forward and backward directions. One way to check for a palindrome is to
reverse the characters in the string and compare them with the original-in
a palindrome, the sequence will be identical.
Write C++ program with functions using Standard Template Library
(STL) stack-
1. To print original string followed by reversed string using stack
2. To check whether given string is palindrome or not
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
stack<char> st;
string str, str2, filter_str;

cout << "Enter string:" << endl;
getline(cin, str);

for (int i = 0; i < str.length(); i++) {
char ch = tolower(str[i]);
filter_str += ch;
st.push(ch);
}

while (!st.empty()) {
str2 += st.top();
st.pop();
}

cout << "Original string: " << filter_str << endl;
cout << "Reversed string: " << str2 << endl;

if (filter_str == str2) {
cout << "String is palindrome" << endl;
} else {
cout << "String is not palindrome" << endl;
}

return 0;
}
