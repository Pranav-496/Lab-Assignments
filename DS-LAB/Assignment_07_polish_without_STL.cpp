#include <bits/stdc++.h>
using namespace std;

#define MAX 100

char stackArr[MAX];
int top = -1;

void push(char c) {
    stackArr[++top] = c;
}

char pop() {
    return stackArr[top--];
}

char peek() {
    return stackArr[top];
}

bool isEmpty() {
    return top == -1;
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

bool isOp(char c) {
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

void reverse(char exp[]) {
    int n = strlen(exp);
    for (int i = 0; i < n/2; i++) {
        char t = exp[i];
        exp[i] = exp[n-i-1];
        exp[n-i-1] = t;
    }
}

void swapBracket(char exp[]) {
    for (int i = 0; exp[i]; i++) {
        if (exp[i]=='(') exp[i]=')';
        else if (exp[i]==')') exp[i]='(';
    }
}

void infTopost(char inf[], char post[]) {
    int k = 0;
    top = -1;

    for (int i = 0; inf[i]; i++) {
        char c = inf[i];

        if (isalnum(c)) post[k++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (!isEmpty() && peek()!='(')
                post[k++] = pop();
            pop();
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(c))
                post[k++] = pop();
            push(c);
        }
    }

    while (!isEmpty())
        post[k++] = pop();

    post[k] = '\0';
}

void infTopre(char inf[], char pre[]) {
    char temp[MAX], post[MAX];

    strcpy(temp, inf);
    reverse(temp);
    swapBracket(temp);

    infTopost(temp, post);
    reverse(post);

    strcpy(pre, post);
}

void postToinf(char post[], char inf[]) {
    char stack[MAX][MAX];
    int topStr = -1;

    for (int i = 0; post[i]; i++) {
        char c = post[i];

        if (isalnum(c)) {
            stack[++topStr][0] = c;
            stack[topStr][1] = '\0';
        } else {
            char op1[MAX], op2[MAX], temp[MAX];

            strcpy(op1, stack[topStr--]);
            strcpy(op2, stack[topStr--]);

            temp[0]='(';
            temp[1]='\0';

            strcat(temp, op2);
            strncat(temp, &c, 1);
            strcat(temp, op1);
            strcat(temp, ")");

            strcpy(stack[++topStr], temp);
        }
    }

    strcpy(inf, stack[topStr]);
}

void preToinf(char pre[], char inf[]) {
    char stack[MAX][MAX];
    int topStr = -1;

    for (int i = strlen(pre)-1; i >= 0; i--) {
        char c = pre[i];

        if (isalnum(c)) {
            stack[++topStr][0] = c;
            stack[topStr][1] = '\0';
        } else {
            char op1[MAX], op2[MAX], temp[MAX];

            strcpy(op1, stack[topStr--]);
            strcpy(op2, stack[topStr--]);

            temp[0]='(';
            temp[1]='\0';

            strcat(temp, op1);
            strncat(temp, &c, 1);
            strcat(temp, op2);
            strcat(temp, ")");

            strcpy(stack[++topStr], temp);
        }
    }

    strcpy(inf, stack[topStr]);
}

void postTopre(char post[], char pre[]) {
    char stack[MAX][MAX];
    int topStr = -1;

    for (int i = 0; post[i]; i++) {
        char c = post[i];

        if (isalnum(c)) {
            stack[++topStr][0] = c;
            stack[topStr][1] = '\0';
        } else {
            char op1[MAX], op2[MAX], temp[MAX];

            strcpy(op1, stack[topStr--]);
            strcpy(op2, stack[topStr--]);

            temp[0] = c;
            temp[1] = '\0';

            strcat(temp, op2);
            strcat(temp, op1);

            strcpy(stack[++topStr], temp);
        }
    }

    strcpy(pre, stack[topStr]);
}

void preTopost(char pre[], char post[]) {
    char stack[MAX][MAX];
    int topStr = -1;

    for (int i = strlen(pre)-1; i >= 0; i--) {
        char c = pre[i];

        if (isalnum(c)) {
            stack[++topStr][0] = c;
            stack[topStr][1] = '\0';
        } else {
            char op1[MAX], op2[MAX], temp[MAX];

            strcpy(op1, stack[topStr--]);
            strcpy(op2, stack[topStr--]);

            temp[0] = '\0';

            strcat(temp, op1);
            strcat(temp, op2);
            strncat(temp, &c, 1);

            strcpy(stack[++topStr], temp);
        }
    }

    strcpy(post, stack[topStr]);
}

int main() {
    int choice;
    char exp[MAX], result[MAX];

    do {
        cout << "===== MENU ====="<<endl;
        cout << "1. inf to post"<<endl;
        cout << "2. inf to pre"<<endl;
        cout << "3. post to inf"<<endl;
        cout << "4. pre to inf"<<endl;
        cout << "5. post to pre"<<endl;
        cout << "6. pre to post"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cin >> exp;
                infTopost(exp, result);
                cout << result;
                break;
            case 2:
                cin >> exp;
                infTopre(exp, result);
                cout << result;
                break;
            case 3:
                cin >> exp;
                postToinf(exp, result);
                cout << result;
                break;
            case 4:
                cin >> exp;
                preToinf(exp, result);
                cout << result;
                break;
            case 5:
                cin >> exp;
                postTopre(exp, result);
                cout << result;
                break;
            case 6:
                cin >> exp;
                preTopost(exp, result);
                cout << result;
                break;
        }

        cout << endl;

    } while(choice != 7);

    return 0;
}