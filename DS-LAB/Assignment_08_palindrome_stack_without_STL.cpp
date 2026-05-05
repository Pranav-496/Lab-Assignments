#include <iostream>
#include <string>
using namespace std;

class Stack {
    char arr[200];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() { return top == 199; }
    bool isEmpty() { return top == -1; }

    void push(char ch) {
        if (!isFull()) arr[++top] = ch;
    }

    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0';
    }
};

int main() {
    string str, clean = "", reversed = "";

    cout << "Enter string: ";
    getline(cin, str);

    Stack st;

    for (char ch : str) {

        if (isalnum(ch)) {

            if (ch >= 'A' && ch <= 'Z')
                ch = ch + 32;

            clean += ch;
            st.push(ch);
        }
    }

    while (!st.isEmpty()) {
        reversed += st.pop();
    }

    cout << "Original (processed): " << clean << endl;
    cout << "Reversed string: " << reversed << endl;

    if (clean == reversed)
        cout << "String is Palindrome\n";
    else
        cout << "String is NOT Palindrome\n";

    return 0;
}