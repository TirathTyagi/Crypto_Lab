#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
double encrypt(int m,pair<int,int> publicKey,int n){
    double cipher;
    cipher = fmod(pow(m,publicKey.first) , n);
    return cipher;
}
double decrypt(double c,pair<int,int> privateKey,int n){
    double m;
    m = fmod(pow(c,privateKey.first) , n);
    return m;
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
bool checkPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i = 2;i<sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int p,q;
    cout<<"SELECT FIRST RANDOM PRIME NUMBER: ";
    cin>>p;

    cout<<endl;
    cout<<"SELECT SECOND RANDOM PRIME NUMBER: ";
    cin>>q;
    if(!checkPrime(q) || !checkPrime(p)){
        cout<<"WRONG NUMBERS SELECTED";
        return 0;
    }
    int n = p*q;
    int phi = (p-1) * (q-1);
    int e;
    for(int i = 2;i<phi;i++){
        if(gcd(i,phi) ==1){
            e = i;
            break;
        }
    }
    int d;
    for(int i = 1;i<=phi;i++){
        if((e*i)%phi == 1){
            d = i;
            break;
        }
    }
    cout<<endl;
    pair<int,int> publicKey;
    publicKey.first = e;
    publicKey.second = n;
    pair<int,int> privateKey;
    privateKey.first = d;
    privateKey.second = n;
    cout<<"PLEASE ENTER THE MESSAGE IN INTEGER FORM: ";
    int m;
    cin>>m;
    cout<<endl;
    double cipher = encrypt(m,publicKey,n);
    cout<<"THE ENCRYPTED MESSAGE IS: "<<cipher;
    cout<<endl;
    cout<<"THE DECRYPTED MESSAGE IS: "<<decrypt(cipher,privateKey,n);
}
