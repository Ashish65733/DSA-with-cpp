#include<iostream>
#include<climits>
#include<list>
#include<iterator>

using namespace std;

void printList(list<int> ll){
    list<int>::iterator itr;

    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout << *itr << " -> " ;
    }
    cout << "NULL" <<  endl;
}

int main(){
    list<int> ll;

    ll.push_front(2);
    ll.push_front(1);   // 1 -> 2
    ll.push_back(3);
    ll.push_back(4);    // 1 -> 2 -> 3 -> 4 

    printList(ll);
    
    cout << "Size = " << ll.size() << endl;
    
    cout << "Head = " << ll.front() << endl;
    cout << "Tail = " << ll.back() << endl;
    
    ll.pop_front();
    ll.pop_back();
    printList(ll);
    
    list<int>::iterator itr = ll.begin();
    
    // insert a single element
    ll.insert(itr,1);
    printList(ll);
    
    // insert multiple copies of an element
    ll.insert(itr,3,99); 
    printList(ll);
    
    // insert a range of element
    list<int> ll2 = {4,5,6};
    ll.insert(itr,ll2.begin(),ll2.end());
    printList(ll);

    return 0;
}