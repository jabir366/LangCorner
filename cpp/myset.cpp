#include <iostream>
using namespace std;
#include <set>
int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    struct sam
    {
        int num;
        /* struct val { */
        /*     bool n; */
        /* }v; */
        sam(int x){
            num=x;
         /* v.n=false; */   
        }
    };
   
    struct samcmp{
        bool operator()(struct sam *a,struct sam *b){
            if (a->num > b->num){
                return true;
            }
            else{
                return false;
            }
        }
    };
    typedef std::set<sam*,samcmp> myset_t;
    myset_t myset;
    sam s2(4),s3(8);
    myset.insert(&s2);
    myset.insert(&s3);
    /* myset_t::iterator mit; */
    sam s(8);
    auto mit = myset.find(&s);
    if(mit == myset.end()){
        cout<<"Element not found";
    }
    else{
        cout<<"Element Found";
    }

    /* mit=myset.begin(); */
    /* cout<<"Hi"<<(*mit)->num<<endl; */
    /* cout<<"Hi2 "<<&(*mit)->num<<endl; */
    /* sam n(8); */
    /* cout<<"Hi3 "<<&n<<&n.v; */

    /* std::set<sam*>::iterator it= myset.begin(); */
    /* cout<<*it<<endl; */
    /* for(it=myset.begin();it!=myset.end();it++){ */
    /*     cout<<(*it)->num; */
    /* }; */
    
    return 0;
}
