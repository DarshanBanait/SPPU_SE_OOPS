#include<iostream>
#include<fstream>
using namespace std;
class Employee // declaring class employee
{
  string Name;
  int ID;
  double salary;
  public:
     void accept(){
     cout << "\nName : ";
     cin.ignore();
     getline(cin, Name);
     cout << "\nID : ";
     cin >> ID;
     cout << "\nsalary : ";
     cin >> salary;
     cout << "\n";
     }
  void display() {
      cout<<"\nName : "<<Name;
      cout<<"\nID : " << ID;
      cout<<"\nSalaray : "<< salary<<"\n";
  }
};

int main () {
    Employee o[5];
    fstream f;
    int i, n;
    f.open("demo.txt", ios::out);
    cout<<"\nEnter The Number of Employees You Want to Store : ";
    cin>>n;
    for (i =0; i < n; i++) {
        cout << "\n\nEnter Information of Employee " << i + 1 << "\n";
        o[i].accept();
        f.write((char * ) & o[i], sizeof o[i]);

    }
    f.close();

    f.open("demo.txt", ios:: in );

    cout << "\n";

    cout << "Information of Employees is as follows :";

    for (i =0; i<n; i++) {
        cout << "\nEmployee " << i + 1;
        f.write((char * ) & o[i], sizeof o[i]);
        o[i].display();
 
    }

    f.close();

    return 0;
}

