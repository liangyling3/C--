#include <iostream> 
#include <vector> 
using namespace std;

class String{
	private:
		vector<char> letters;
		
	public:
		String(){
		}
		
		int size() {
			for(int i = 0; ; ++ i) 
				if(this->letters[i] == 0) return i;
		}
		
		String operator += (const vector<char> & s2) {
			// attention!!!: 不要把this->size()作为循环条件，
			//因为循环中改变了this，导致this->size()也随着改变 
			int len = this->size();
			for (int i = len; s2.size() != 0; ++ i) {
				this->letters.push_back(s2.size()) ;
			}
			return *this;
		} 
		
		String replace(const vector<char> s1, const vector<char> s2) {
			int count, position;
			int len = this->size();
			for (int i = 0; i < len; ++ i) { // Find s1
				count = 0;
				for (int j = 0; j < s1.size(); ++ j) {
					if (this->letters[i+j] != s1[j]) break;
					else count ++;
				}
				if (count == s1.size()) {
					position = i;
					break;
				}
			}
		
			this->letters.erase(position, position + s2.size());
			this->letters.insert(position, s2);
			
			return *this;
		}
		
		String trim() {
			const int len = this->size();
			int positions[len];
			for (int i = 0; i < len; ++ i) {
				positions[i] = -1;
			}
			for (int i = 0; i < len; ++ i) {
				if (this->letters[i] < 'a' || this->letters[i] > 'Z') 
					positions[i] = i;
			}
			
			for (int i = 0; i < len; ++ i) {
				if (positions[i] == -1) continue;
				this->letters.erase(positions[i]);
			}
			return *this;
		}
};

#include <iostream> 
#include <vector> 
using namespace std; 
 
int main() { 
    String text = "Hello, "; 
    text[text.size()] = 'I'; 
     
    text += " am Mike."; 
    cout << text << endl; // Hello, I am Mike. 
 
    text.replace("Hello", "Hi"); 
    cout << text << endl; // Hi, I am Mike. 
 
    text.replace("Mike", "Steven"); 
    cout << text << endl; // Hi, I am Steven. 
     
    String text2 = "  ABCD   "; 
    cout << "[" << text2.trim() << "]\n"; // [ABCD] 
     
    vector<String> words = text.split(','); 
    for (int i = 0; i < words.size(); ++ i) { 
        cout << words[i].trim() << endl; 
    } 
    // Hi 
    // I am Steven. 
} 
