#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Car{
public:
    int idx;
    int distSq;

    Car(int idx,int distSq){
        this->idx = idx;
        this->distSq = distSq;
    }

    bool operator < (const Car &obj) const {
        return this->distSq > obj.distSq;   // min Heap
    }
};

void nearbyCar(vector<pair<int, int>> pos, int k){  // O(k*log n + n)
    vector<Car> cars;

    for(int i=0; i<pos.size(); i++){    // O(n)
        int distSq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(Car(i,distSq));
    }

    priority_queue<Car> pq(cars.begin(), cars.end());   // O(n)

    // for(int i=0; i<cars.size(); i++){   // O(n*log n)
    //     pq.push(cars[i]);
    // }

    for(int i=0; i<k; i++){ // O(k*log n)
        cout << "Car " << pq.top().idx << endl;
        pq.pop();   // O(log n)
    }
}

int main(){
    vector<pair<int, int>> pos;
    pos.push_back({3,3});
    pos.push_back({5,-1});
    pos.push_back({-2,4});

    int k = 2;
    nearbyCar(pos, k);

    return 0;
}