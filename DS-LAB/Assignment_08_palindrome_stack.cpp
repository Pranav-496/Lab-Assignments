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
