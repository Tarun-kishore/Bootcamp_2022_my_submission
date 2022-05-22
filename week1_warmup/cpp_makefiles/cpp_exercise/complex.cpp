#include<bits/stdc++.h>

using namespace std;

class Complex{
    public :
        int real,imag;
};

Complex add(Complex c1, Complex c2){
    Complex res;
    res.real = c1.real + c2.real;
    res.imag = c1.imag + c2.imag;

    return res;
}

int main(){
    Complex a,b;

    cout<< "Enter first complex number : ";
    cin>>a.real>>a.imag;

    cout<< "Enter Second complex number : ";
    cin>>b.real>>b.imag;

    Complex result = add(a,b);

    cout<< "Result : "<< result.real<< " "<< result.imag<< "\n";
    return 0;
}
