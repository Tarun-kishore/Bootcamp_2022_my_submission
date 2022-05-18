#include<bits/stdc++.h>

using namespace std;

int main(){
    cout<< "Enter Number: ";
    int n;
    cin>>n;

    cout<< "Factors : \n";

    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<< i<< " ";
        }
    }
    cout<< "\n";
    return 0;
}
