#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
void hello(T t) 
{
  cout << "data= " << t;
}

template <class T>
class Array {
  T data;

  public:
    void setData(T t) {
      data = t;
    }
    void printData() {
      cout << "\nData= " << data;
    }
};

int main()
{ 
    Array<int> a0;
    a0.setData(500);
    a0.printData();

    Array<double> a1;
    a1.setData(500.32);
    a1.printData();

    cout << endl;
    char ch;
    fstream fin, fout;
    fin.open("sample.txt", ios::in);
    fout.open("sample-out.txt", ios::out);
    while (!fin.eof()) {
      fin.get(ch);
      cout << ch;
      fout.put(ch);
    }

    fout.close();
    fout.open("sample-out.txt", ios::in);

    while (!fout.eof()) {
      fout >> noskipws >> ch;
      cout << ch;
    }
    fin.close();
    fout.close();

    cout << endl;
    hello(12);
    hello(12.23);

    cout << endl;
    return 0;
}

