/*Please write a class Table, such that the main function outputs as follows. 

OUTPUT
{
	headers: ['AA','BB',],
	rows: [
		['123','456',],
		['234','567',],
	],
}

*/ 

#include <iostream> 
#include <string> 
#include <vector> 
using namespace std; 

class Table {
	
private:
	vector <string> headers;
	vector < vector<string> > rows;
	
public:
	Table() {	
	}
	
	~Table() {
	}
	
	vector <string> & operator [] (int index) { 
		//return a reference to assign a value to return value
		vector <string> temp;
		this->rows.push_back(temp);
		if (index < this->headers.size())
			return this->rows[index];
	}
	
	void addCol(string str) {
		headers.push_back(str);
	}
	
	
	vector <string> json() const {
		vector <string> json;
		json.push_back("{\n\theaders: [");
		
		for (int i = 0; i < this->headers.size(); ++ i) {
			json.push_back("'");
			json.push_back(this->headers[i]);
			json.push_back("',");
		} 
		
		json.push_back("],\n\trows: [\n" );
		
		for (int i = 0; i < this->rows.size(); ++ i) {
			
			json.push_back("\t\t['" );
			for (int j = 0; j < rows[i].size(); ++ j) {
				json.push_back("'");
				json.push_back(this->rows[i][j]);
				json.push_back("',");
			} 
			json.push_back("],\n" );
		}
		
		json.push_back("\t],\n}" );
		
		return json;
	}
	
};


ostream & operator << (ostream & out, const vector <string> & strs) { 
    for (int i = 0; i < strs.size(); ++ i) {
    	for (int j = 0; j < strs[i].size(); ++ j) 
    		out << strs[i][j]; 
	} 
	cout << strs[0][1];
    return out; 
} 

#include <iostream> 
#include <string> 
#include <vector> 
using namespace std; 

ostream & operator << (ostream & out, const Table & table) { 
    out << table.json() << endl; 
    return out; 
} 
 
int main() { 
    Table t1; 
    t1.addCol("AA"); 
    t1.addCol("BB"); 
    vector<string> vec; 
    vec.push_back("123"); 
    vec.push_back("456"); 
    t1[0] = vec; 
    vec[0] = "234"; 
    vec[1] = "567"; 
    t1[1] = vec; 
    cout << t1 << endl;
} 
