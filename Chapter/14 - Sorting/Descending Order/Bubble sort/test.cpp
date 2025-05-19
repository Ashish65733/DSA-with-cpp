#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int bubble(vector<int>& nums){
    int n = nums.size();

    for(int i=0; i<n; i++){
        bool isSwap = false;
        for(int j=0; j<n-i; j++){
            if(nums[j] < nums[j+1]){
                swap(nums[j],nums[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            return 0;
        }
    }
    return 0;
}
void printArr(vector<int> arr,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> nums = {3,6,2,1,8,7,4,5,3,1};
    int n = nums.size();;

    cout<<"Brfore sorting : ";
    printArr(nums,n);
    
    bubble(nums);

    cout<<endl<<"After sorting : ";
    printArr(nums,n);
    return 0;
}

// #include<iostream>
// #include<climits>
// #include<vector>
// using namespace std;

// int sort(vector<int>& nums){

// }
// void printArr(vector<int> arr,int n){
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// }

// int main(){
//     vector<int> nums = {3,6,2,1,8,7,4,5,3,1};
//     int n = nums.size();;

//     cout<<"Brfore sorting : ";
//     printArr(nums,n);
    
//     sort(nums);

//     cout<<endl<<"After sorting : ";
//     printArr(nums,n);
//     return 0;
// }