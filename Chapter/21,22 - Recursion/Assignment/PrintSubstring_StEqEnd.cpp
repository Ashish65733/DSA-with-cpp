#include<iostream>
#include<climits>
#include<string>
#include<vector>
using namespace std;
/*
 We are given a string S, we need to find the count of all contiguous
substring starting and ending with the same character.[Leetcode Premium Qs]

Sample input: S = "abcab"
Sample Output: 7

There are 15 substrings of "abcab" : a,ab,abc,abca,abcab,b,bc,bca,bcab,c,ca,cab,a,ab,b
Out of the above substrings, there are 7 substring : a,abca,b,bcab,c,a and b. So, only
7 contiguous substrings start and end with the same character.

Sample input: S = "aba"
Sample Output: 4
The sunstrings are : a,b,a and aba
*/

int numOfSubstring(string s, int i, int ans, vector<int> map){
    if(i == s.size()){
        return ans;
    }
    char ch = s[i];
    int mapIdx = (int)(ch - 'a');

    if (!map[mapIdx]){
        map[mapIdx]++;
        ans++;
    }else{
        ans += (map[mapIdx]+1);
        map[mapIdx]++;
    }
    return numOfSubstring(s,i+1,ans,map);
}
int main(){
    string S = "abaca";
    vector<int> map(26,0);

    cout << "No. of Substrings : " << numOfSubstring(S,0,0,map) << endl;

    return 0;
}