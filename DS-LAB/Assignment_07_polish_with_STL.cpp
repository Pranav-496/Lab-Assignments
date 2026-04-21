#include <bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

bool isOperator(char c) {
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

void reverseStr(string &s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++) {
        char t = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = t;
    }
}

void swapBracket(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i]=='(') s[i]=')';
        else if (s[i]==')') s[i]='(';
    }
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) postfix += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    reverseStr(infix);
    swapBracket(infix);
    string post = infixToPostfix(infix);
    reverseStr(post);
    return post;
}

string postfixToInfix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(string(1,c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = "(" + op2 + c + op1 + ")";
            st.push(temp);
        }
    }

    return st.top();
}

string prefixToInfix(string prefix) {
    stack<string> st;

    for (int i = prefix.length()-1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            st.push(string(1,c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = "(" + op1 + c + op2 + ")";
            st.push(temp);
        }
    }

    return st.top();
}

string postfixToPrefix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(string(1,c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = c + op2 + op1;
            st.push(temp);
        }
    }

    return st.top();
}

string prefixToPostfix(string prefix) {
    stack<string> st;

    for (int i = prefix.length()-1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            st.push(string(1,c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = op1 + op2 + c;
            st.push(temp);
        }
    }

    return st.top();
}

int main() {
    int choice;
    string exp;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Postfix to Infix\n";
        cout << "4. Prefix to Infix\n";
        cout << "5. Postfix to Prefix\n";
        cout << "6. Prefix to Postfix\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cin >> exp;
                cout << infixToPostfix(exp);
                break;
            case 2:
                cin >> exp;
                cout << infixToPrefix(exp);
                break;
            case 3:
                cin >> exp;
                cout << postfixToInfix(exp);
                break;
            case 4:
                cin >> exp;
                cout << prefixToInfix(exp);
                break;
            case 5:
                cin >> exp;
                cout << postfixToPrefix(exp);
                break;
            case 6:
                cin >> exp;
                cout << prefixToPostfix(exp);
                break;
        }

        cout << endl;

    } while(choice != 7);

    return 0;
}