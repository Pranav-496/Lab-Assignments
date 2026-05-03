#include <bits/stdc++.h>
using namespace std;

class String
{
  string str;

public:
  void input()
  {
    cin.ignore();
    getline(cin, str);
  }

  void display()
  {
    cout << str << endl;
  }

  // 1. Frequency
  void frequency()
  {
    char ch;
    cout << "Enter character: ";
    cin >> ch;

    int count = 0;
    for (char c : str)
      if (c == ch)
        count++;

    cout << "Frequency: " << count << endl;
  }

  // 2. Extract substring
  void extract()
  {
    int pos, len;
    cout << "Enter position and length: ";
    cin >> pos >> len;

    cout << "Extracted: " << str.substr(pos, len) << endl;
  }

  // 3. Remove character
  void removeChar()
  {
    char ch;
    cout << "Enter character to remove: ";
    cin >> ch;

    string temp = "";
    for (char c : str)
      if (c != ch)
        temp += c;

    str = temp;

    cout << "After removal: " << str << endl;
  }

  // 4. Replace substring
  void replaceWord()
  {
    string w, x;
    cout << "Enter word to replace: ";
    cin >> w;
    cout << "Enter new word: ";
    cin >> x;

    size_t pos = str.find(w);

    while (pos != string::npos)
    {
      str.replace(pos, w.length(), x);
      pos = str.find(w);
    }

    cout << "After replacement: " << str << endl;
  }

  // 5. Palindrome
  void palindrome()
  {
    string temp = str;
    reverse(temp.begin(), temp.end());

    if (temp == str)
      cout << "Palindrome\n";
    else
      cout << "Not Palindrome\n";
  }

  // 6. Reverse
  void reverseStr()
  {
    reverse(str.begin(), str.end());
    cout << "Reversed: " << str << endl;
  }

  // 7. Concatenate
  void concat()
  {
    string s2;
    cout << "Enter second string: ";
    cin.ignore();
    getline(cin, s2);

    str += s2;

    cout << "After concatenation: " << str << endl;
  }
};

int main()
{
  String s;
  int ch;

  cout << "Enter string: ";
  s.input();

  do
  {
    cout << "\n1.Frequency\n2.Extract\n3.Remove\n4.Replace\n5.Palindrome\n6.Reverse\n7.Concat\n0.Exit\n";
    cout << "Enter choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
      s.frequency();
      break;
    case 2:
      s.extract();
      break;
    case 3:
      s.removeChar();
      break;
    case 4:
      s.replaceWord();
      break;
    case 5:
      s.palindrome();
      break;
    case 6:
      s.reverseStr();
      break;
    case 7:
      s.concat();
      break;
    }

  } while (ch != 0);

  return 0;
}