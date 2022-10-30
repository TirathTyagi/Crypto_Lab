#include<iostream>
#include<bitset>
#include<math.h>
using namespace std;
int ls1[10];
int ip[8] = {1,5,2,0,3,7,4,6};
int ipin[8] = {3,0,2,4,6,1,7,5};
int ep[8] = {3,0,1,2,1,2,3,0};
int p4[4] = {1,3,2,0};
string s0[4][4]={
        "01","00","11","10",
        "11","10","01","00",
        "00","10","01","11",
        "11","01","11","10"
};
string s1[4][4] = { "00","01","10","11",
                    "10","00","01","11",
                    "11","00","01","00",
                    "10","01","00","11"};
int *keyGeneration2(){
    int p10[10] = {2,4,1,6,3,9,0,8,7,5};
    int p8[8] = {5,2,6,3,7,4,9,8};
    int ls2[10];
    int left2[5];
    int right2[5];
    for(int i = 0 ;i<5;i++){
        left2[i] = ls1[i];
    }
    for(int i = 5;i<10;i++){
        right2[i-5] = ls1[i];
    }
    cout<<endl;
    for(int i = 0;i<10;i++){
        if(i<5){
            if(i == 3){
                ls2[i] = left2[0];
            }
            else if(i==4){
                ls2[i] = left2[1];
            }
            else{
                ls2[i] = left2[i+2];
            }
        }
        else{
            if(i == 8){
                ls2[i] = right2[0];
            }
            else if(i == 9){
                ls2[i] = right2[1];
            }
            else{
                ls2[i] = right2[(i+2) - 5];
            }
        }
    }
    int *key2 = new int[8];
    for(int i = 0; i<8;i++){
        key2[i] = ls2[p8[i]];
    }
    return key2;
}
int *keyGeneration1(int *keyMain){
    int p10[10] = {2,4,1,6,3,9,0,8,7,5};
    int p8[8] = {5,2,6,3,7,4,9,8};
    int left[5];
    int right[5];
    pair<int*,int*> keys;
    for(int i = 0;i<5;i++){
        left[i] = keyMain[p10[i]];
    }
    for(int i = 0;i<5;i++){
        right[i] = keyMain[p10[5+i]];
    }
    for(int i = 0;i<10;i++){
        if(i<5){
            if(i == 4){
                ls1[i] = left[0];
            }
            else{
                ls1[i] = left[i+1];
            }
        }
        else{
            if(i == 9){
                ls1[i] = right[0];
            }
            else{
                ls1[i] = right[(i+1) - 5];
            }
        }
    }
    int *key1 = new int[8];
    for(int i = 0;i<8;i++){
        key1[i] = ls1[p8[i]];
    }
    return key1;
}
int* round1(int *pt,int *key1){
    int left[4],right[4];
    for(int i = 0;i<4;i++){
        left[i] = pt[ip[i]];
    }
    for(int i = 4;i<8;i++){
        right[i-4] =pt[ip[i]];
    }
    int getEP[8];
    for(int i = 0;i<8;i++){
        getEP[i] = right[ep[i]];
    }
   for(int i = 0;i<8;i++){
       getEP[i] = getEP[i]^key1[i];
   }
    for(int i = 0;i<4;i++){
        left[i] = getEP[i];
    }
    for(int i = 4;i<8;i++){
        right[i-4] = getEP[i];
    }
    int rowleft[2] = {left[0],left[3]};
    int colleft[2] = {left[1],left[2]};
    int row=0,col=0;
    for(int i = 0;i<2;i++){
        if(rowleft[i] == 0){
            continue;
        }
        else{
            row+= pow(2,1-i);
        }
    }
    for(int i = 0;i<2;i++){
        if(colleft[i] == 0){
            continue;
        }
        else{
            col+= pow(2,1-i);
        }
    }
    string a = s0[row][col];
    int op[2];
    for(int i = 0;i<a.length();i++){
        op[i] = (int)a[i] - '0';
    }
    int rowright[2] = {right[0],right[3]};
    int colright[2] = {right[1],right[2]};
    int rrow=0,rcol=0;
    for(int i = 0;i<2;i++){
        if(rowright[i] == 0){
            continue;
        }
        else{
            rrow+=pow(2,1-i);
        }
    }
    for(int i = 0 ;i<2;i++){
        if(colright[i] == 0){
            continue;
        }
        else{
            rcol+= pow(2,1-i);
        }
    }
    string b = s1[rrow][rcol];
    int op2[2];
    for(int i = 0;i<b.length();i++){
        op2[i] = (int)b[i] - '0';
    }
    int fop[4];
    for(int i = 0;i<4;i++){
        if(i<2){
            fop[i] = op[i];
        }
        else{
            fop[i] = op2[i-2];
        }
    }
    int newfop[4];
    for(int i = 0;i<4;i++){
        newfop[i] = fop[p4[i]];
    }
    for(int i = 0;i<4;i++){
        left[i] = pt[ip[i]];
    }
    int oxor[4];
    for(int i = 0;i<4;i++){
        oxor[i] = newfop[i] ^ left[i];
    }
    int *finalOp = new int[8];
    for(int i = 4;i<8;i++){
        right[i-4] =pt[ip[i]];
    }
    for(int i = 0;i<8;i++){
        if(i<4){
            finalOp[i] = right[i];
        }
        else{
            finalOp[i] = oxor[i-4];
        }
    }
    return finalOp;
}
int *round2(int *r1,int *key2){
    int getEP[8];
    int left[4] = {r1[0],r1[1],r1[2],r1[3]};
    int right[4] = {r1[4],r1[5],r1[6],r1[7]};
    for(int i = 0;i<8;i++){
        getEP[i] = right[ep[i]];
    }
    int getXor[8];
    for(int i = 0;i<8;i++){
        getXor[i] = getEP[i] ^ key2[i];
    }
    int rowleft[2] = {getXor[0],getXor[3]};
    int colleft[2] = {getXor[1],getXor[2]};
    int row=0,col=0;
    for(int i = 0;i<2;i++){
        if(rowleft[i] == 0){
            continue;
        }
        else{
            row+= pow(2,1-i);
        }
    }
    for(int i = 0;i<2;i++){
        if(colleft[i] == 0){
            continue;
        }
        else{
            col+= pow(2,1-i);
        }
    }
    string a = s0[row][col];
    int op[2];
    cout<<endl;
    for(int i = 0;i<a.length();i++){
        op[i] = (int)a[i] - '0';
    }
    int rowright[2] = {getXor[4],getXor[7]};
    int colright[2] = {getXor[5],getXor[6]};
    int rrow=0,rcol=0;
    for(int i = 0;i<2;i++){
        if(rowright[i] == 0){
            continue;
        }
        else{
            rrow+=pow(2,1-i);
        }
    }
    for(int i = 0 ;i<2;i++){
        if(colright[i] == 0){
            continue;
        }
        else{
            rcol+= pow(2,1-i);
        }
    }
    string b = s1[rrow][rcol];
    int op2[2];
    for(int i = 0;i<b.length();i++){
        op2[i] = (int)b[i] - '0';
    }
    int fop[4] = {op[0],op[1],op2[0],op2[1]};
    int p4op[4];
    for(int i = 0; i<4;i++){
        p4op[i] = fop[p4[i]];
    }
    int *finalOp = new int[8];
    for(int i = 0;i<8;i++){
        if(i<4){
            finalOp[i] = left[i] ^ p4op[i];
        }
        else{
            finalOp[i] = right[i-4];
        }
    }
    return finalOp;
}
int main(){
    int keyMain[10];
    int pt[8];
    cout<<"PLEASE ENTER THE KEY: "<<endl;
    for(int i = 0;i<10;i++){
        cin>>keyMain[i];
    }
    cout<<"PLEASE ENTER THE PLAIN TEXT: ";
    cout<<endl;
    for(int i = 0;i<8;i++){
        cin>>pt[i];
    }
    int* key1 = keyGeneration1(keyMain);
    int* key2 = keyGeneration2();
    int *r1 = round1(pt,key1);
    int *r2 = round2(r1,key2);
    int cipher[8];
    for(int i = 0;i<8;i++){
        cipher[i] = r2[ipin[i]];
    }
    cout<<"THE ENCRYPTED CIPHER TEXT IS: ";
    for(int i:cipher){
        cout<<i;
    }
}