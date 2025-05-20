#include<iostream>
#include<climits>
#include<String>
using namespace std;
void removeDuplicates(string str, string ans, int i ,bool map[]){ 
    if(i == str.size()){ // Base case
        cout << "Ans = " << ans << endl;
        return;
    }

    char ch = str[i];
    int idx = (int)(ch - 'a');
    
    if (map[idx]){ // char already in ans
        removeDuplicates(str,ans,i+1,map);
    }else{
        map[idx] = true ;
        removeDuplicates(str,ans+str[i],i+1,map);
    } 
}
int main(){
    string str = "appnnacollege";
    string ans = "";
    bool map[26] = {false};

    removeDuplicates(str,ans,0,map);
    return 0;
}