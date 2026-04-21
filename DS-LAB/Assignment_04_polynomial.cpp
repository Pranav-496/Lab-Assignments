#include <bits/stdc++.h>
using namespace std;
const int MaxSize = 100;
typedef struct{
    float Coef;
    int Exp;
}polynomial_term;

class Polynomial {
    private:
    polynomial_term Poly [MaxSize];
    int Total_Terms;
    public:
    Polynomial() { 
        Total_Terms = 0; 
    }
    void Read_Poly();
    void Display_Poly();
    Polynomial Addition (Polynomial B);
};

void Polynomial :: Read_Poly(){
    int i ;
    cout <<"Enter total number of terms in polynomial: ";
    cin>>Total_Terms;
    for(i=0; i<Total_Terms ; i++){
        cout<<"Enter coefficient of "<<i+1<<" Term: ";
        cin>>Poly[i].Coef;
        cout<<"Enter exponent of "<<i+1<<" Term: ";
        cin>>Poly[i].Exp;
    }
}

void Polynomial :: Display_Poly(){
    int i ;
    for (int i = 0; i < Total_Terms; i++) {
    if (i == 0)
        cout << Poly[i].Coef << "x^" << Poly[i].Exp;
    else
        cout << " + " << Poly[i].Coef << "x^" << Poly[i].Exp;
    }
cout << endl;
}


Polynomial Polynomial::Addition(Polynomial B) {
    int i = 0, j = 0, k = 0;
    Polynomial C;

    while (i < Total_Terms && j < B.Total_Terms) {
        if (Poly[i].Exp == B.Poly[j].Exp) {
            C.Poly[k].Coef = Poly[i].Coef + B.Poly[j].Coef;
            C.Poly[k].Exp = Poly[i].Exp;
            i++; j++; k++;
        }
        else if (Poly[i].Exp > B.Poly[j].Exp) {
            C.Poly[k].Coef = Poly[i].Coef;
            C.Poly[k].Exp = Poly[i].Exp;
            i++; k++;
        }
        else {
            C.Poly[k].Coef = B.Poly[j].Coef;
            C.Poly[k].Exp = B.Poly[j].Exp;
            j++; k++;
        }
    }

    while (i < Total_Terms) {
        C.Poly[k].Coef = Poly[i].Coef;
        C.Poly[k].Exp = Poly[i].Exp;
        i++; k++;
    }

    while (j < B.Total_Terms) {
        C.Poly[k].Coef = B.Poly[j].Coef;
        C.Poly[k].Exp = B.Poly[j].Exp;
        j++; k++;
    }

    C.Total_Terms = k;
    return C;
}

int main() {
    Polynomial A, B, C;
    A.Read_Poly();
    A.Display_Poly();

    B.Read_Poly();
    B.Display_Poly();

    C = A.Addition(B);
    cout << "The addition of two polynomials is: ";
    C.Display_Poly();

    return 0;
}



