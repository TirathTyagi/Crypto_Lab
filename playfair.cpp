#include<iostream>
#include<string>
#include<vector>
using namespace std;
string encrypt(vector<string> keyMap,string arr[5][5]){
    for(int i = 0;i<keyMap.size();i++){
        string x = keyMap.at(i);
        char a = x[0];
        char b = x[1];
        int coorda;
        int coorda1;
        int coordb;
        int coordb1;
        for(int j = 0;j<5;j++){
            for(int k = 0;k<5;k++){
                if(arr[j][k].find(a)!=-1){
                    coorda = j;
                    coorda1 = k;
                }
                if(arr[j][k].find(b)!=-1){
                    coordb = j;
                    coordb1 = k;
                }
            }
        }
        if(coorda == coordb){
            string s="";
            if(coorda1+1 >4){
                s+= arr[coorda][0];
            }
            else {
                s += arr[coorda][coorda1 + 1];
            }
            if(coordb1+1>4){
                s += arr[coordb][0];
            }
            else {
                s += arr[coordb][coordb1 + 1];
            }
            keyMap[i] = s;
        }
        else if(coorda1 == coordb1){
            string s = "";
            if(coorda+1>4){
                s += arr[0][coorda1];
            }
            else{
                s += arr[coorda+1][coorda1];
            }
            if(coordb+1>4){
                s += arr[0][coordb1];
            }
            else{
                s += arr[coordb+1][coordb1];
            }
            keyMap[i] = s;
        }
        else{
            string s ="";
            s += arr[coorda][coordb1];
            s += arr[coordb][coorda1];
            keyMap[i] = s;
        }
    }
    string enc = "";
    for(int i = 0;i<keyMap.size();i++){
        enc += keyMap[i];
    }
    return enc;
}
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
    vector<string> arrProcess;
    int s = 0;
    while(s<sent.length()){
        string x = "";
        if(sent[s] == sent[s+1]){
            x += sent[s];
            x+= 'x';
            s++;
            arrProcess.push_back(x);
            continue;
        }
        else if((s+1) == sent.length()){
            x += sent[s];
            x+= 'x';
            arrProcess.push_back(x);
            break;
        }
        x += sent[s];
        x += sent[s+1];
        arrProcess.push_back(x);
        s +=2;
    }
    sent = encrypt(arrProcess,keyArr);
    cout<<"ENCRYPTED TEXT: "<<endl;
    cout<<sent;
}