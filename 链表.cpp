template <typename E>
class LinkedList {

private:
	struct Node {
		E date;				//存放数据	
		Node * next; 		//存放下一个数据的地址 
		int size;
	};
	
	int size;
	Node * firstNode;
	
public:
	LinkedList () 
	{
		firstNode = 0;
		size = 0;
	} 
	
	LinkedList (const LinkedList & list) 
	{
		size = list.size;
		firstNode = copyList(list, firstNode);
	}
	
	~LindkedList () 
	{
	}
	
	void push_front (const E & e) 
	{
		Node * newFirstNode = new Node();
		newFirstNode->data = e;
		newFirstNode->next = this->firstNode;
		this->firstNode = newFirstNode;
	}
	
	
private:
	class Iterator 
	{
	private:
		Node * pos;
		Iterator (Node * pos_) : pos(pos_) {}	
	};
	
	Node * copyList(Node * node) 
	{
		Node * copy = new Node();
		copy->data = node->data;
		if (node->next != 0) 
			copy->next = copyList(node->next); 
		else 
			copy->next = 0;
			
		return copy;
	}
	
public:
	Iterator begin() 
	{
		return Iterator(firstNode);
	}
	
	Iterator end() 
	{
		return Iterator(0);
	}
	
	bool operator != (const Iterator & other) {
		return pos != other.pos;
	}
	
	Iterator & operator ++ () {
		pos ++ ;
		return * this;
	}
	
	E & operator * () {
		return (*vector)pos;
	}
};
