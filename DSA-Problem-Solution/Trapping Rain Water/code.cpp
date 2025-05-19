#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height,int n){
    int maxLeft[7], maxRight[7];
    maxLeft[0] = height[0];
    for(int i=1; i<n; i++){
        maxLeft[i] = max(maxLeft[i-1], height[i-1]);  
    }

    maxRight[n-1] = height[n-1];
    for(int i=n-2; i>=0; i--){
        maxRight[i] = max(maxRight[i+1], height[i+1]);
    }

    int water = 0;
    for(int i=0; i<n; i++){
        int waterLevel = min(maxLeft[i], maxRight[i]);
        if(waterLevel > height[i]){
            water += waterLevel - height[i];
        }
    }

    return water;

}
int main(){
    vector<int> height = {4,2,0,6,3,2,5};
    int n = height.size();

    cout << "Water Traped = "<< trap(height,n) << endl;
    
    return 0;
}