#include<iostream>
#include<climits>
#include<string>

using namespace std;

void binString(int n,int lastPlace,string ans){
    if(n == 0){
        cout << ans << endl;
        return;
    }

    if(!lastPlace){
        binString(n-1,0,ans+'0');
        binString(n-1,1,ans+'1');
    }else{
        binString(n-1,0,ans+'0');
    }
}
void binString(int n,string ans){
    if(n == 0){
        cout << ans << endl;
        return;
    }

    if(ans[ans.size()-1] != '1'){
        binString(n-1,ans+'0');
        binString(n-1,ans+'1');
    }else{
        binString(n-1,ans+'0');
    }
}
int main(){
    string ans = "";

    binString(3,ans);
    return 0;
}