template <typename T>
class Vector{
private: 
	... 

public:
	
	Iterator begin(){
		return Iterator(this, 0);
	}
	
	Iterator end(){
		return Iterator(this, this->size());
	}
	
	class Iterator {
		
	private:
		Vector * beingIterated;			//���ڱ����������� 
		int pos;						//���ڱ�����Ԫ�� 
		
	public:
		Iterator(Vector * beingIterated_, int pos_) {
			beingIterated = beingIterated_;
			pos - pos_;
		}	
		
		bool operator != (const Iterator & other) const {
			return beingIterated != other.beingIterated or pos != other.pos;
		}
	
		Iterator & operator ++ () {
			if(pos == vector->size()) throw ... ;			//���������� 
			++ pos;
			return * this;
		}
		
		T & operator * () {
			if ... throw ...;
			return (*vector)[pos];
		}
		
	};
};
