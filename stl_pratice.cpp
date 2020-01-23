#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <unordered_map>
#include <queue>
#include <string>
#include <stack>

void print_array(vector<int> &mylist){

  for(auto itr = mylist.begin(); itr!=mylist.end(); itr++){
       cout << *itr <<"\t"; 
    }

  cout << endl;

  //mylist[0] = 1000;

}

void insertIntoHeap(priority_queue<pair<int, pair<int,int>>> &pq, int w, int v1, int v2){
    pq.push(make_pair(-w,make_pair(v1,v2)));
}

int main() {

    cout << "Queue :" << endl;

    queue<int> Q;
    Q.push(11);
    Q.push(12);
    Q.push(13);   

    while(!Q.empty()){
        int ele = Q.front();
        cout << ele << "\t";
        Q.pop();
    } 

    cout << "\n\n"; 

    cout << "Stack :" << endl;

    stack<int> S;
    S.push(11);
    S.push(12);
    S.push(13);   

    while(!S.empty()){
        int ele = S.top();
        cout << ele << "\t";
        S.pop();
    } 

    cout << "\n\n"; 

    

    cout << "List :" << endl;
    list<int> dll;
    dll.push_back(12);
    dll.push_back(10);
    dll.push_back(9);
    dll.push_back(15);
    dll.push_back(-88);

    dll.pop_back();
    dll.pop_front();
    dll.push_front(1);

    cout << dll.front() << endl;

    for(auto it = dll.begin(); it!=dll.end(); it++){
      cout << *it << "\t";
    }



    cout << "\n\n"; 

    vector<int> mylist;    
    mylist.push_back(10);
    mylist.push_back(200);
    mylist.push_back(310);
    mylist.push_back(40);
    mylist.push_back(540);
    mylist.push_back(650);
    

    cout << "Vector : " << endl;
    print_array(mylist);
    sort(mylist.begin(), mylist.end());
    print_array(mylist);


    int mylist2[] = {5,54,45,5};

    sort(mylist2, mylist2+4);

    for(int i = 0; i<4; i++){
      cout << mylist2[i] << " ";
    }    


    cout << "Map : " << endl;

    map<int, int> myMap;

    pair<int, int> p = make_pair(10, 20);
    
    cout << p.first << " " << p.second << endl;

    cout << endl << endl;

    

    myMap.insert(make_pair(0, 100));
    myMap.insert(make_pair(1, 10));
    myMap.insert(make_pair(45, 10));
    myMap.insert(make_pair(450, 105));
    myMap.insert(make_pair(445, 410));
    myMap[1] = 15;
    myMap[5] = 1554;
    auto f = myMap.lower_bound(6);
    auto g = myMap.upper_bound(6);
    cout << f->first << "<-->" << f->second << endl;
    cout << g->first << "<-->" << g->second << endl;

    string tp = (myMap.find(450) != myMap.end()) ? ("450 is present") : ("450 is absent");

    cout << tp << endl;
    

    int e1 = myMap.erase(450);
    int e2 = myMap.erase(45660);
    cout << e1 << "\t" << e2 << endl;

    for(auto it = myMap.begin();it!=myMap.end(); it++) {
      cout << it->first << "--->" << it->second << endl;
    } 

 
    cout << "Multi Map : " << endl;
     
    multimap<int, int> mmap;

    mmap.insert(make_pair(4, 5));
    mmap.insert(make_pair(40, 15));
    mmap.insert(make_pair(40, 152));
    mmap.insert(make_pair(10, 15));

    for(auto it = mmap.begin(); it!=mmap.end(); it++){
        cout << it->first << "-------->" << it->second << endl;
    }

    //sort(mylist)
    

    cout << "Unordered Map : " << endl;

    unordered_map<int, int> unomap;

    unomap.insert(make_pair(10, 45));
    unomap.insert(make_pair(1, 45));
    unomap.insert(make_pair(100, 4555));
    unomap.insert(make_pair(5, 45));

    auto itr = unomap.find(1);
    if(itr==unomap.end()) cout << "Not found **\n" << endl;
    else cout << "Found **->" << itr->second << endl;

    for(auto it = unomap.begin(); it!=unomap.end(); it++){
        cout << it->first << "-->" << it->second << endl;
    }

    //cout <<  << endl;
    

    cout << "Priority Queue : " << endl;

    priority_queue<int> pq;
    pq.push(10);
    pq.push(-10);
    pq.push(5);
    pq.push(1);
    pq.push(20);
    pq.push(100);

    while(!pq.empty()){
        int ele = pq.top();
        cout << ele << "\t";
        pq.pop();
    }
    


    priority_queue<pair<int, pair<int,int>>> unexplored_set;

    insertIntoHeap(unexplored_set, 4, 0, 1);
    insertIntoHeap(unexplored_set, 100, 1, 1);
    insertIntoHeap(unexplored_set, 15, 0, 1);
    insertIntoHeap(unexplored_set, 99, 10, 8);
    insertIntoHeap(unexplored_set, 55, 59, 12);
    insertIntoHeap(unexplored_set, 89, 10, -1);
    insertIntoHeap(unexplored_set, 14, -10, -10);


    cout << endl << endl;

    while(!unexplored_set.empty()){
        pair <int, pair <int,int>> a = unexplored_set.top();
        unexplored_set.pop();
        cout << -a.first << " : (" << a.second.first << "," << a.second.second << ")" << endl;

    }



    


    return 0;
}