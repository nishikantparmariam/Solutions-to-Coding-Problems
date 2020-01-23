#include <iostream>
#include <map>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

bool comp_func(int x, int y){
    return x>y;
};

bool comp_func2(pair<string, pair<int, int>> x, pair<string, pair<int, int>> y ){
    return x.second.second > y.second.second;
}

int main(){

    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    vector<int> A;
    for(int i = 0; i<10; i++){
        A.push_back(i%5);
        
    }

    A.push_back(2);
    A.push_back(2);

    

    sort(A.begin(), A.end());
    for(auto it = A.begin(); it!=A.end(); ++it){

        cout << *it << "\t";
    }
    cout << endl << endl;

    for(int &x : A) {
        x++;
        cout << x << "\t";
    } 
    

    cout << endl << endl;

    bool pres = binary_search(A.begin(), A.end(), 45);
    if(pres) {
        cout << "Present" << endl;
    }   else cout << "Not present" << endl;

    vector<int>::iterator it = lower_bound(A.begin(), A.end(), 2);
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 2);

    cout << *it << "\t" << *it2 << " Count 2 = " << it2 - it << endl;

    sort(A.begin(), A.end(), comp_func);

    cout << endl << endl;

    vector<pair<string, pair<int, int>>> B;
    for(int i = 0; i<10; i++) B.push_back(make_pair("h", make_pair(i, (i*i)%10)));

    sort(B.begin(), B.end(), comp_func2);
    for(auto it = B.begin(); it!=B.end(); it++){
        string s = (*it).first;
        int v1 = (*it).second.first;    
        int v2 = (*it).second.second;
        cout << s << "  " << v1 << "--" << v2 << endl; 
    }








    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    set<int> mySet;
    mySet.insert(1);
    mySet.insert(-5);
    mySet.insert(-56);
    mySet.insert(4);
    mySet.insert(455);
    mySet.insert(858);


    auto _iterator = mySet.find(554);
    mySet.erase(1);
    if(_iterator!=mySet.end()) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    for(int x:mySet){
        cout << x << "\t" ;
    }

    _iterator = mySet.lower_bound(4);
    auto _iterator2 = mySet.upper_bound(4);
    cout << endl << endl;
    cout << *_iterator << " " << *_iterator2 << endl;



    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    unordered_map<int, string> dictionary;
    dictionary.insert(make_pair(10, "Hello World!"));
    dictionary.insert(make_pair(11, "Hello World!"));
    dictionary.insert(make_pair(-1, "Hello World!"));
    dictionary.insert(make_pair(15, "Hello World!"));
    dictionary.insert(make_pair(10, "Hello World!"));
    dictionary.insert(make_pair(14, "Hello World!"));
    dictionary.insert(make_pair(1, "Hello World!"));

    for(pair<int, string> x : dictionary){
        cout << x.first << "\t";
    }
    cout << endl;
    
    //dictionary.erase(10);
    auto _find1 = dictionary.find(10);
    auto _find2 = dictionary.find(100);

    

    if(_find1==dictionary.end()) cout << "Not found" << endl;
    else cout << "Found : " << _find1->first << endl;

    if(_find2==dictionary.end()) cout << "Not found" << endl;
    else cout << "Found : " << _find2->first << endl;


    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    map<char, int> count;
    
    string s = "Nishikant Parmar";

    for(char x : s){
        count[x]++;
    }

    int ans = 0;
    for(auto itr = count.begin(); itr!=count.end(); itr++){
        ans+=itr->second;
        cout << " count['"<< itr->first <<"']=" << itr->second << endl;
    }

    cout << ans;

    return 0;
}