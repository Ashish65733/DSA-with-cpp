#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int findMin(vector<int>& nums) {
        int si = 0, ei = nums.size()-1;
        
        while(si < ei){
            int mid = si + (ei - si)/2;

            if(nums[ei] < nums[mid]){// If rightmost element is less then mid, smallest element is in the right half
                si = mid+1;
            }else{ // smallest element is in the left half (Including mid)
                ei = mid;
            }
        }
        //After loop, si == ei -> pointing to the smallest element
        return nums[si];
    }
int main(){
    vector<int> arr = {4,5,6,7,0,1,2};

    cout << "Minimum element in the array is: " << findMin(arr) << endl;
    return 0;
}