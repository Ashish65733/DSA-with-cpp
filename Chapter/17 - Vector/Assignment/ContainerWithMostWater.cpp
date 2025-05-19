#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int st = 0, end = height.size()-1;
    int maxWater = INT_MIN ;
    // while (st < end)
    // {
    //     int h = min(height[st],height[end]);
    //     int l = end - st ;
    //     int currWater = h * l ;
    //     maxWater = max(currWater,maxWater);
        
    // }
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i; j < height.size(); j++)
        {
            int h = min(height[i],height[j]);
            int l = j - i ;
            int currWater = h * l ;
            maxWater = max(currWater,maxWater);
        }
        
    }
    return maxWater;
    
}

int main(){
    vector<int> arr = {1,8,6,2,5,4,8,3,7};

    cout << "Maximum Water : " << maxArea(arr) << endl;
    return 0;
}