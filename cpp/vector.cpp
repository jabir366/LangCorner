#include <vector>
#include <iostream>

using namespace std;
int main(){
    vector<int> myvec(5);
    vector < vector<char> > my2dvec(5,vector<char> (5));

    cout<<myvec[3]<<endl;
    
    my2dvec [2][2]=65;
    cout<<"The 2d array ";
    for (auto  row: my2dvec)
        for (auto elem : row)
            cout<<elem<<endl;

    cout<<"Pair"<<endl;
    pair<char,int> myP;
    myP={'a',65};
    cout<<myP.first<<endl;
    cout<<myP.second<<endl;
    vector < vector< pair<char,int>>> pvec;
    pvec.push_back({ {'a',1}});
    pvec.push_back({ {'b',2}});
    pvec[1].push_back({'b',3});

    //this will cause in segfault because there is no index 3 is created for pvec
    pvec[3].push_back({'b',3});

    //push_back accepts an object. not an object to pointer

    pvec[0].push_back(*(new pair<char,int> ('c',3)));
    pair <char, int>* elem = new pair<char, int>('c',5);
    pvec[0].push_back(*elem);

    return 0 ;
}
