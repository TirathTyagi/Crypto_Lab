#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
char decrypt(unordered_map<char,char> map,char a){
    auto iterate = map.begin();
    char c = '/';
    while(iterate!=map.end()){
        if(iterate->second == a){
            c = iterate->first;
        }
        iterate++;
    }
    return c;
}
int main(){
    unordered_map<char,char> mapKey;
    string a = "attack postponed to tomorrow and do not use our secret paper until further information";
    string assigned;
    string assignedkey;
    string key = "the quick brown fox jumps over the lazy dog";
    int index = 0;
    cout<<"ENTERED MESSAGE: "<<a<<endl;
    cout<<"ENTERED KEY: "<<key<<endl;
    cout<<endl;
    cout<<"-----------KEY TO STRING MAP----------"<<endl;
    for(int i =0;i<a.length();i++){
        if(a[i] == ' '){
            continue;
        }
        if(assigned.find(a[i])!=-1){
            continue;
        }
        else{
            assigned+=a[i];
            if(key[index] == ' '||assignedkey.find(key[index])!=-1){
                index++;
            }
            mapKey[a[i]] = key[index];
            assignedkey+= key[index];
            index++;
        }
    }
    for(int i = 0 ;i<assigned.length();i++){
        cout<<assigned[i]<<" "<<mapKey[assigned[i]]<<endl;
    }
    cout<<endl;
    cout<<"----ENCRYPTED TEXT----"<<endl;
    cout<<endl;
    for(int i = 0;i<a.length();i++){
        if(a[i] == ' '){
            continue;
        }
        a[i] = mapKey[a[i]];
    }
    cout<<a<<endl;
    for(int i = 0;i<a.length();i++){
        if(a[i] == ' '){
            continue;
        }
        char c = decrypt(mapKey,a[i]);
        a[i] = c;
    }
    cout<<endl;
    cout<<"----DECRYPTED TEXT----"<<endl;
    cout<<endl;
    cout<<a;
}