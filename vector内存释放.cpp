#include <vector>
#include <iostream>
using namespace std;

vector <string> v;  
 
int main ()  
 {    
    for(int i=0; i<1000000; i++)  
       v.push_back("abcdefghijklmn");  
    v.clear(); //仅清除数据，vector占用内存不变 
    
    vector <string> tem;
    tem.swap(v);

    // vector<string>(v).swap(v); //？？？  
    return 0;  
 }  
