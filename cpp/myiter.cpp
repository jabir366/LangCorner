#include <iostream>
using namespace std;
#include <set>
int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    struct sam
    {
        int num;
        struct val {
            bool n;
        }v;
        sam(int x){
            num=x;
         v.n=false;   
        }
    };
    
    typedef std::set<sam*> myset_t;
    myset_t myset;
    myset.insert(new sam(4));
    myset.insert(new sam(8));
    myset_t::iterator mit;

    mit=myset.begin();
    cout<<"Hi"<<(*mit)->num<<endl;
    cout<<"Hi2 "<<&(*mit)->num<<endl;
    sam n(8);
    cout<<"Hi3 "<<&n<<&n.v;

    std::set<sam*>::iterator it= myset.begin();
    cout<<*it<<endl;
    for(it=myset.begin();it!=myset.end();it++){
        cout<<(*it)->num;
    };
    
    return 0;
}
