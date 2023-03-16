#include<iostream>
using namespace std;
class complex {
public:
    float real, img;

    complex()
    {
        real = 0;
        img = 0;
    }

    complex operator + (complex);
    complex operator * (complex);
    friend ostream& operator << (ostream&, complex&);
    friend istream& operator << (istream&, complex&);

};
istream& operator >> (istream& is, complex& obj) {
    is >> obj.real;
    is >> obj.img;
    return is;

}

ostream& operator << (ostream& outt, complex& obj) {
    outt << "" << obj.real;
    outt << "+" << obj.img << "i";
    return outt;
}
complex complex::operator + (complex obj) {
    complex temp;
    temp.real = real + obj.real;
    temp.img = img + obj.img;
    return (temp);

}
complex complex::operator * (complex obj) {
    complex temp;
    temp.real = real * obj.real - img * obj.img;
    temp.img = real * obj.img + img * obj.real;
    return (temp);

}

int main() {
    complex a, b, c, d;
    cout << "1st Complex Number - Enter Real and Imaginary\n";
    cin >> a;
    cout << "2nd Complex Number - Enter Real and Imaginary Number\n";
    cin >> b;
    cout << "\n Arithmetic Operations: ";
    c = a + b;
    cout << "\n Addition = " << c;
    d = a * b;
    cout << "\n Multiplication = " << d;
    return 0;


}
