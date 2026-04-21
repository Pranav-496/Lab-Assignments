#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class SparseMatrix
{
public:
  int S[MAX][3];

  void read();
  void display();
  SparseMatrix simpleTranspose();
  SparseMatrix fastTranspose();
  SparseMatrix add(SparseMatrix B);
};

void SparseMatrix::read()
{
  int i;
  cout << "Enter rows, columns and number of non-zero elements: ";
  cin >> S[0][0] >> S[0][1] >> S[0][2];

  for (i = 1; i <= S[0][2]; i++)
  {
    cout << "Enter row, column and value: ";
    cin >> S[i][0] >> S[i][1] >> S[i][2];
  }
}

void SparseMatrix::display()
{
  int i;
  cout << "\nRow  Col  Val\n";
  for (i = 0; i <= S[0][2]; i++)
  {
    cout << S[i][0] << "    "
         << S[i][1] << "    "
         << S[i][2] << endl;
  }
}

SparseMatrix SparseMatrix::simpleTranspose()
{
  SparseMatrix B;
  int i, j, k = 1;

  B.S[0][0] = S[0][1];
  B.S[0][1] = S[0][0];
  B.S[0][2] = S[0][2];

  for (j = 0; j < S[0][1]; j++)
  {
    for (i = 1; i <= S[0][2]; i++)
    {
      if (S[i][1] == j)
      {
        B.S[k][0] = S[i][1];
        B.S[k][1] = S[i][0];
        B.S[k][2] = S[i][2];
        k++;
      }
    }
  }
  return B;
}

SparseMatrix SparseMatrix::fastTranspose()
{
  SparseMatrix B;
  int Freq[MAX], Index[MAX];
  int i, j;

  int cols = S[0][1];
  int terms = S[0][2];

  B.S[0][0] = cols;
  B.S[0][1] = S[0][0];
  B.S[0][2] = terms;

  if (terms == 0)
    return B;

  for (i = 0; i < cols; i++)
  {
    Freq[i] = 0;
  }

  for (i = 1; i <= terms; i++)
  {
    Freq[S[i][1]]++;
  }

  Index[0] = 1;
  for (i = 1; i < cols; i++)
  {
    Index[i] = Index[i - 1] + Freq[i - 1];
  }
  for (i = 1; i <= terms; i++)
  {
    j = Index[S[i][1]]++;
    B.S[j][0] = S[i][1];
    B.S[j][1] = S[i][0];
    B.S[j][2] = S[i][2];
  }

  return B;
}

SparseMatrix SparseMatrix::add(SparseMatrix B)
{
  SparseMatrix C;
  int i = 1, j = 1, k = 1;

  if (S[0][0] != B.S[0][0] || S[0][1] != B.S[0][1])
  {
    cout << "Addition not possible (dimension mismatch)\n";
    C.S[0][2] = 0;
    return C;
  }

  C.S[0][0] = S[0][0];
  C.S[0][1] = S[0][1];

  while (i <= S[0][2] && j <= B.S[0][2])
  {
    if (S[i][0] == B.S[j][0] && S[i][1] == B.S[j][1])
    {
      int sum = S[i][2] + B.S[j][2];
      if (sum != 0)
      {
        C.S[k][0] = S[i][0];
        C.S[k][1] = S[i][1];
        C.S[k][2] = sum;
        k++;
      }
      i++;
      j++;
    }
    else if (S[i][0] < B.S[j][0] ||
             (S[i][0] == B.S[j][0] && S[i][1] < B.S[j][1]))
    {
      C.S[k][0] = S[i][0];
      C.S[k][1] = S[i][1];
      C.S[k][2] = S[i][2];
      i++;
      k++;
    }
    else
    {
      C.S[k][0] = B.S[j][0];
      C.S[k][1] = B.S[j][1];
      C.S[k][2] = B.S[j][2];
      j++;
      k++;
    }
  }

  while (i <= S[0][2])
  {
    C.S[k][0] = S[i][0];
    C.S[k][1] = S[i][1];
    C.S[k][2] = S[i][2];
    i++;
    k++;
  }

  while (j <= B.S[0][2])
  {
    C.S[k][0] = B.S[j][0];
    C.S[k][1] = B.S[j][1];
    C.S[k][2] = B.S[j][2];
    j++;
    k++;
  }

  C.S[0][2] = k - 1;
  return C;
}

int main()
{
  SparseMatrix A, B, C;
  int choice;

  do
  {
    cout << "\n--- Sparse Matrix Menu ---\n";
    cout << "1. Input Matrix A\n";
    cout << "2. Display Matrix A\n";
    cout << "3. Simple Transpose\n";
    cout << "4. Fast Transpose\n";
    cout << "5. Add Matrix A and B\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      A.read();
      break;
    case 2:
      A.display();
      break;
    case 3:
      C = A.simpleTranspose();
      C.display();
      break;
    case 4:
      C = A.fastTranspose();
      C.display();
      break;
    case 5:
      cout << "Enter Matrix B:\n";
      B.read();
      C = A.add(B);
      C.display();
      break;
    }
  } while (choice != 0);

  return 0;
}
