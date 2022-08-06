#include<iostream>
#include<string>
#include<vector>
using namespace std;
void getKey(string arr[5][5],string a){
    string add;
    add = "";
    int s = 0;
    int t = 0;
    for(int i = 0;i<a.length();i++){
        if(add.find(a[i])== -1) {
            if(t>4){
                t = 0;
                s++;
            }
            arr[s][t] = a[i];
            add += a[i];
            t++;
        }
    }
    cout<<arr[1][0]<<endl;
    int m = 97;
    while(m!=123) {
        char c = m;
        if (add.find(c) == -1) {
            if (t > 4) {
                t = 0;
                s++;
            }
            if(c == 'i'){
                arr[s][t] = "ij";
                m+=2;
            }
            else {
                arr[s][t] = c;
                m++;
            }
            t++;
        }
        else{
            m++;
        }
    }
}
int main(){
    string key;
    cout<<"Enter key: "<<endl;
    getline(cin,key);
    string sent;
    cout<<"Enter sentence: "<<endl;
    getline(cin,sent);
    string keyArr[5][5];
    getKey(keyArr,key);
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            cout<<keyArr[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<string> multArr;
    for(int i = 0;i<sent.length();i++){
        string one;
        cout<<i;
        cout<<sent[i]<<" "<<sent[i+1]<<endl;
        if(sent[i] == sent[i+1]){
            one = sent[i];
            one +="x";
            multArr.push_back(one);
            i++;
        }
        else if(i == sent.length()-1){
            one = sent[i];
            one += "x";
            multArr.push_back(one);
        }
        else{
            one = sent[i];
            one += sent[i+1];
            multArr.push_back(one);
            i+=2;
        }
    }
    for(int i = 0;i<multArr.size();i++){
        cout<<multArr.at(i)<<endl;
    }
}