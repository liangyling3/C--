#include <vector>
#include <iostream>
using namespace std;

vector <string> v;  
 
int main ()  
 {    
    for(int i=0; i<1000000; i++)  
       v.push_back("abcdefghijklmn");  
    v.clear(); //��������ݣ�vectorռ���ڴ治�� 
    
    vector <string> tem;
    tem.swap(v);

    // vector<string>(v).swap(v); //������  
    return 0;  
 }  
