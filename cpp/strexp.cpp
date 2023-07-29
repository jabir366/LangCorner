
#include <iostream>  
#include <cstring>  
#include <map>
#include <vector>
using namespace std;  
  
void mapexample(){
    char  str[]  = "newnumber";    
    for (int i=0; str[i] !='\0'; i++){
        cout<<static_cast<void*>(&str[i])<<endl;
    }
    /* cout<<static_cast<void*>(str+strlen(str)-1)<<endl; */
    cout<<strlen(str)<<endl;
    cout<<*(str+3);
    *(str+3) = '\0';
    cout<<*(str+3);
    /* str[3] = '\0'; */
    cout<<strlen(str)<<endl;
    /* char str[256]  = {'n','e','w','\0'}; */
    std::map<std::string,std::string> qparams_mandatory ;
    qparams_mandatory[string(str)] = "extra";
    cout<<qparams_mandatory["new"]<<endl;
    for (auto const& [key, value] : qparams_mandatory) {
        std::cout << key << ": " << value << std::endl;
    }
    cout<<qparams_mandatory.find("new")->second<<endl;
    /* cout<<qparams_mandatory.find("old")->second<<endl; */
    string val;
    //get a value to char *
    const char *val2 = qparams_mandatory.at(str).c_str();
    cout<<"Val2:"<<val2<<endl;
    
    //get a value to string
    val = qparams_mandatory[str];
    val = qparams_mandatory.at(str);
    cout<<"Val:"<<val<<endl;
    
    //check a char is present in a string
     char str2[] = "Hello, World!";
     if (strchr(str2,'l')) {
            cout<<"Item found:";
     }
     char* pos1 = strchr(str2,'o');
     char* pos2  = strchr(str2,'z');
     cout<<"first:"<<pos1<<endl<<"second"<<pos2;

    /* val =qparams_mandatory.find("ee")->second; */
    if(qparams_mandatory.end() == qparams_mandatory.find("ee")){
        cout<<"End found";
    }
}  


void vectorexample(){
    vector<string> strlist;
    strlist.push_back("this");
    strlist.push_back("is ");
    strlist.push_back("list");
    strlist[1][1]='x';
    const char *newstr = strlist[1].data();
    /* newstr[1] = 's'; */
    /* const char *newstr2 = strlist[1].c_str(); */
    string str2 = strlist[2];
    str2[1] ='y';
    cout<<"New is:"<<strlist[0]<<endl;
    cout<<"New is:"<<newstr<<endl;
    cout<<"New is:"<<str2<<endl;
}

int main(){
    vectorexample();
    // Buffer overflow using strcpy
	char myc[5];
    char cc[] = "tttttttttt444";
	strncpy(myc,cc,sizeof(myc)-1);
	cout<<"Copied str:"<<myc<<endl;
	cout<<"size of myc:"<<sizeof(myc);
	cout<<"length of myc:"<<strlen(myc);
    return 0;
}

