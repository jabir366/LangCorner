#include <iostream>  
#include <cstring>  
using namespace std;  
  
int main()  
{  
    char str[100]; // declare the size of string      
    /* string str; */
    cout << " Enter a string: " <<endl;  
    cin.getline(str, 100); // use getline() function to read a string from input stream  
    /* getline(cin,str); */
      
    string delim = "&";
    size_t idx = string(str).find(string("&"));
    if (idx == string::npos)
        cout<<"No delim";
    string token = string(str).substr(0,idx);
    string t2 = string(str).substr(idx+1,strlen(str));
    /* string t2 = getline(str, */
    cout<<token<<endl<<"IDX:"<<idx<<"token2:"<<t2;

     const char *c_str = "apple,banana,cherry";
    char *tok = strtok(const_cast<char *>(c_str), ",");
    while (tok != nullptr) {
        std::cout << tok << std::endl;
        tok = strtok(nullptr, ",");
    }
    /* const char *c_str = "apple,banana,cherry"; */
    /* char *c_str_copy = (char *)malloc(strlen(c_str) + 1); */
    /* strcpy(c_str_copy, c_str); */
    /* char *tok = strtok(c_str_copy, ","); */
    /* std::cout << tok << std::endl; */
    /* return 0; */  
    return 0;  
}  
