#pragma once
template <typename T>
class list
{
	template <typename T>
	class Node
	{
	public:
		Node(){}
		Node(T Object, Node* PNext=nullptr)
		{
			this->Object = Object;
			this->PNext = PNext;
		}
		~Node(){}
		T Object;
		Node* PNext;
	};
	Node<T>* PHead;
	Node<T>* PCurrent;
	int size;
public:
	list();
	//list(T, Node* Pnext = nullptr);
	~list();
	void PushBack(T);
	void PopFront(const int);
	void Clear();
	int getsize();
};

template<typename T>
list<T>::getsize()
{
	this->PCurrent->
}

