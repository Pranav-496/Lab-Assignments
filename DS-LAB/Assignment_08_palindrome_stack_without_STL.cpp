#include <iostream>
using namespace std;

class Stack {
    char arr[200];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == 199;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char ch) {
        if (!isFull()) {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }
};

int main() {
    char str[200], clean[200], reversed[200];

    cout << "Enter string: ";
    cin.getline(str, 200);

    Stack st;

    int i = 0, j = 0;

    // Step 1: Clean string + push into stack
    while (str[i] != '\0') {
        char ch = str[i];

        if ((ch >= 'A' && ch <= 'Z') || 
            (ch >= 'a' && ch <= 'z') || 
            (ch >= '0' && ch <= '9')) {

            // convert to lowercase
            if (ch >= 'A' && ch <= 'Z')
                ch = ch + 32;

            clean[j++] = ch;
            st.push(ch);
        }
        i++;
    }
    clean[j] = '\0';

    // Step 2: Reverse using stack ADT
    int k = 0;
    while (!st.isEmpty()) {
        reversed[k++] = st.pop();
    }
    reversed[k] = '\0';

    // Step 3: Display
    cout << "Original (processed): " << clean << endl;
    cout << "Reversed string: " << reversed << endl;

    // Step 4: Palindrome check
    bool isPalindrome = true;

    for (int i = 0; clean[i] != '\0'; i++) {
        if (clean[i] != reversed[i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << "String is Palindrome\n";
    else
        cout << "String is NOT Palindrome\n";

    return 0;
}