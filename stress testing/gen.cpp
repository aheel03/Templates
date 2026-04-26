#include<bits/stdc++.h>
using namespace std;

int rand(int a,int b){
    return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]){
    srand(atoi(argv[1]));
    int n=rand(4,4);
    for(int i=1;i<=n;i++){
        int r=rand(0,2);
        if(r==0) cout<<":";
        else if(r==1) cout<<"(";
        else cout<<")";
    }
}
