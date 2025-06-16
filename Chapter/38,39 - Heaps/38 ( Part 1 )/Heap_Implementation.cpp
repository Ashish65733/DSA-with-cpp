#include<iostream>
#include<climits>
#include<vector>

using namespace std;

class Heap{
    vector<int> vec;    // Max Heap

    void heapify(int i){    // i = parI
        if(i >= vec.size()){
            return;
        }
        int l = 2*i + 1;
        int r = 2*i + 2;

        int maxI = i;
        if(l < vec.size() && vec[l] > vec[maxI]){// vec[l] > vec[maxI] --> use < in this condition to convert it into min heap
            maxI = l;
        }
        if(r < vec.size() && vec[r] > vec[maxI]){// vec[r] > vec[maxI] --> use < in this condition to convert it into min heap
            maxI = r;
        }

        swap(vec[i],vec[maxI]);
        if(maxI != i){  // swapping with child node, not with it self
            heapify(maxI);
        }
    }
public:

    void push(int val){ // O(log n)
        // Step 1:
        vec.push_back(val);

        // Step 2 : (Fix heap)
        int x = vec.size()-1;
        int parI = (x-1)/2;

        while(parI >= 0 && vec[x] > vec[parI]){ // vec[x] > vec[parI] --> use < in this condition to convert it into min heap
            swap(vec[x],vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }

    void pop(){
        // Step 1:
        swap(vec[0],vec[vec.size()-1]);

        // Step 2:
        vec.pop_back();

        // Step 3:
        heapify(0);
    }

    int top(){  // O(1)
        return vec[0];  // highest priority element
    }

    bool empty(){   // O(1)
        return vec.size() == 0;
    }
};

int main(){
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    while(!heap.empty()){
        cout << "Top = " << heap.top() << endl;
        heap.pop();
    }
    return 0;
}