#include <bits/stdc++.h>
using namespace std;

class Set {
    string S[10];
    int n;
public:
    void read();
    void display();
    Set intSec(Set B);
    Set Union(Set B);
    Set setDiff(Set B);
};

void Set::read() {
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cout << "Participant" << i + 1 << " : ";
        cin >> S[i];
    }
}

void Set::display() {
    cout << "{";
    for(int i = 0 ; i < n ; i++) {
        if(i != n - 1) {
            cout << S[i] << " , ";
        } else {
            cout << S[i];
        }
    }
    cout << "}";
}

Set Set::intSec(Set B) {
    Set c;
    int k = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ;  j < B.n ; j++) {
            if(S[i] == B.S[j]) {
                c.S[k++] = B.S[j];
                break;
            }
        }
    }
    c.n = k;
    return c;
}

Set Set::Union(Set B) {
    Set d;
    int k = 0;

    for(int i = 0 ; i < n ; i++) {
        d.S[k++] = S[i];
    }

    for(int i = 0 ; i < B.n ; i++) {
        int flag = 0;
        for(int j = 0 ; j < n ; j++) {  
            if(B.S[i] == S[j]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            d.S[k++] = B.S[i];
        }
    }
    d.n = k;
    return d;
}

Set Set::setDiff(Set B) {
    Set e;
    int k = 0;
    for(int i = 0 ; i < n ; i++) {
        int flag = 0;
        for(int j = 0 ; j < B.n ; j++) {
            if(S[i] == B.S[j]) { 
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            e.S[k++] = S[i];
        }
    }

    e.n = k;
    return e;
}

int main() {
    Set A , B , I , N , U , C , D;
    int choice;

    cout << "Enter the participants for the Set" << endl;
    cout << "Enter the number of participants in Coding contest : ";
    A.read();
    cout << "Enter the number of participants in Project Competition : ";
    B.read();
    cout << "Enter the number of participants in Paper Presentation : ";
    C.read();
    cout << "Enter the number of participants in Mastermind : "; 
    D.read();

    cout << endl;

    do {
        cout << "-------------Menu-------------------\n";
        cout << "1.Participants - Coding and Project both \n";
        cout << "2.Participants - Coding or Project Competition or both or Mastermind \n";
        cout << "3.Participants - Coding but not in Master mind \n";
        cout << "4.Participants - all events\n";
        cout << "5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                I = A.intSec(B);
                cout << "\nStudents who have participated in coding and project : ";
                I.display();
                break;
            case 2:
                U = A.Union(B);
                U = U.Union(C);
                U = U.Union(D);
                cout << "Participants who have participated in Coding or Project Competition or both or Mastermind : ";
                U.display();
                break;
            case 3:
                N = A.setDiff(D);
                cout << "Participants who have participated in Coding but not in Master mind : ";
                N.display();
                break;
            case 4:
                I = A.intSec(B);
                I = I.intSec(C);
                I = I.intSec(D);
                cout << "Participants who have participated in all events : ";
                I.display();
                break;
            case 5:
                cout << "Exiting.....";
                break;
            default:
                cout << "Invalid Input" << endl;
        }

    } while(choice != 5);

    return 0;
}