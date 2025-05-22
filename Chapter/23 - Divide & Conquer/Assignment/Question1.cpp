#include<iostream>
#include<climits>
#include<vector>
#include<string>

using namespace std;
// Apply Merge sort to sort an array of String. (Assume that all the characters in all the Strings are in lowercase.)

void merge(vector<string> &arr,int si,int ei,int mid){
    int i = si;
    int j = mid+1;
    vector<string> temp;

    while(i <= mid && j <= ei){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        } 
    }
    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= ei){
        temp.push_back(arr[j++]);
    }

    for (int i = si,x = 0; i <= ei; i++){
        arr[i] = temp[x++];
    }
    
}

void sortString(vector<string> &arr,int si,int ei){
    if(si >= ei){
        return;
    }

    int mid = si + (ei-si)/2;
    sortString(arr,si,mid);
    sortString(arr,mid+1,ei);
    merge(arr,si,ei,mid);
}
void printVector(vector<string> arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    vector<string> vec = {"sun","earth","mars","mercury"};
    cout << "Before Sorting : ";
    printVector(vec);
    sortString(vec,0,vec.size()-1);
    cout << "After Sorting : ";
    printVector(vec);
    return 0;
}