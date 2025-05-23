#include <iostream>
#include <climits>
#include <vector>
using namespace std;

bool search(vector<int> &nums, int target){
    int si = 0, ei = nums.size() - 1;

    while (si <= ei){
        int mid = si + (ei - si) / 2;

        if (nums[mid] == target) return true;

        if (nums[si] == nums[mid] && nums[mid] == nums[ei]){
            si++;
            ei--;
        }else if (nums[si] <= nums[mid]){
            if (nums[si] <= target && target <= nums[mid]){
                ei = mid - 1;
            }
            else{
                si = mid + 1;
            }
        }else{
            if (nums[mid] <= target && target <= nums[ei]){
                si = mid + 1;
            }
            else{
                ei = mid - 1;
            }
        }
    }
    return false;
}
int main(){
    vector<int> arr = {4,5,6,7,0,1,2};

    if(search(arr,4)){
        cout << "Target found." << endl;
    }else{
        cout << "Target not found." << endl;
    }
    return 0;
}