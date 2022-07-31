#include<iostream>
#include<string.h>
using namespace std;
/* CEASAR CIPHER ALGORITHM */
string encrypt(int shift,string to_enc){
    cout<<"ENCRYPTING..."<<endl;
    for(int i = 0;i<to_enc.length();i++){
        if(islower(to_enc[i])){
            to_enc[i] +=shift;
            if(to_enc[i]>='z') {
                to_enc[i] = to_enc[i] - 'z' + 'a' - 1;
            }
        }
        else if(isupper(to_enc[i])){
            to_enc[i] += shift;
            if(to_enc[i] > 'Z'){
                to_enc[i] = to_enc[i] - 'Z' + 'A' - 1;
            }
        }
    }
    return to_enc;
}
int main(){
    string a;
    cout<<"Enter the text to encrypt: ";
    getline(cin,a);
    int shift;
    cout<<"Enter Shift Key: ";
    cin>>shift;
    string enc = encrypt(shift,a);
    cout<<"Encrypted Text: ";
    cout<<enc;
}