#pragma once
#include<assert.h>
namespace zb
{
	template<class T>
	struct __list_node
	{
		__list_node<T>* _next;
		__list_node<T>* _prev;
		T _data;

		__list_node(const T&x=T())
			:_next(nullptr)
			,_prev(nullptr)
			,_data(x)
		{}
	};
	//迭代器
	template <class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef __list_iterator<T, T&, T*> iterator;              //普通迭代器
		//typedef __list_iterator<T> iterator;
		typedef __list_node<T> Node;
		Node* _node;
		__list_iterator(Node* node)
			
			:_node(node)
		{}
		//*it
		/*T& operator*()
		{
			return _node->_data;
		}*/
		//
		Ref operator*() //迭代器使用*的意思是 获取结点值,所以就直接解引用_node,然后返回
		{
			return _node->_data;
		}
		//
		Ptr operator->()
		{
			return &(_node->_data);
		}
		//++it
		iterator& operator ++()
		{
			_node = _node->_next;
			return *this;
		}
		//--it
		iterator& operator --()
		{
			_node = _node->_prev;
			return *this;
		}
		//!=
		bool operator!=(const iterator& it) const
		{
			return _node != it._node;
		}
		//==
		bool operator==(const iterator& it) const
		{
			return _node == it._node;
		}
	};
	struct Date
	{
		int _year;
		int _month;
	};
	template<class T>
	class list
	{
		typedef __list_node<T> Node;
	public:
		//typedef __list_iterator<T> iterator;
		//typedef __list_iterator<T, T&> iterator;              //普通迭代器
		//typedef __list_iterator<T, const T&> const_iterator;  //常迭代器
		typedef __list_iterator<T, T&, T*> iterator;              //普通迭代器
		typedef __list_iterator<T, const T&, const T*> const_iterator;  //常迭代器

		iterator begin() { return iterator(_head->_next); }
		iterator end() { return iterator(_head); }

		const_iterator begin() const { return iterator(_head->_next); }
		const_iterator end() const { return iterator(_head); }

		list()
		{//带头双向循环
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		//迭代器构造函数
		//template <class InputIterator, class OutputIterator>
		//list(InputIterator input, OutputIterator output)
		//{
		//	_head = new Node;  // 给头结点开辟一块空间.
		//	_head->_next = _head;
		//	_head->_prev = _head;
		//	while (input != output)
		//	{
		//		push_back(*input); //这个函数是用来实现尾插数据的,博主在下面进行讲解
		//		input++;
		//	}
		//}
		//拷贝构造
		list(const list<T>& lt)
		{
			_head = new Node;    // 这里必须先开个头结点空间哦,因为这是拷贝构造,不是赋值
			_head->_next = _head;
			_head->_prev = _head;
			for (const auto& e : lt)
			{
				push_back(e);//这个函数后面会实现
			}
		}
		//赋值重载
		list<T>& operator=(const list<T> lt)  
	//注意哦,这里的参数故意没有使用 引用.这样lt就是通过拷贝构造获取了值
		{
			swap(_head, lt._head);   //然后交换两个链表的头结点
			return *this;
		}
		//clear()
			void clear()
			{
				iterator it = begin();
				while (it != end())
				{
					it = erase(it);
				}
			}	
		//erase()
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node * cur = pos._node;
			Node * prev = cur->_prev;
			Node * next = cur->_next;
			delete cur;
			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}
		//insert()
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}
		//析构函数
		~list()
		{
			clear(); //一定要先释放头结点后面的数据
			delete _head;
			_head = nullptr;
		}
		////尾插
		//void push_back(const T& x)
		//{
		//	Node* tail = _head->_prev;
		//	Node* newnode = new Node(x);
		//	tail->_next = newnode;
		//	newnode->_prev = tail;
		//	newnode->_next = _head;
		//	_head->_prev = newnode;
		//}
		////尾删
		//void pop_back()
		//{
		//	assert(_head != _head->_next);   //如果数据为空,不可删除

		//	Node * oldtail = _head->_prev;      //提取旧尾巴结点
		//	Node * newtail = oldtail->_prev;    //保存旧尾巴结点的前一个结点
		//	delete oldtail;
		//	oldtail = nullptr;
		//	_head->_prev = newtail;
		//	newtail->_next = _head;
		//}
		////头插
		//void push_front(const T& val)
		//{
		//	Node* tmp = new Node(val);     //给新数据新建一个结点
		//	Node* next = _head->_next;     //保存头结点下一个结点
		//	_head->_next = tmp;
		//	tmp->_prev = _head;            //头结点和新数据结点连接
		//	tmp->_next = next;
		//	next->_prev = tmp;             //新结点和保存结点连接
		//}
		////头删
		//void pop_front()
		//{
		//	assert(_head != _head->_next);//如果数据为空,不可删除
		//	Node * dnext = _head->_next->_next;
		//	delete _head->_next;
		//	_head->_next = dnext;
		//	dnext->_prev = _head;
		//}
		void push_back(const T& x) { insert(end(), x); }
		void push_front(const T& x) { insert(begin(), x); }
		void pop_back() { erase(--end()); }
		void pop_front() { erase(begin()); }
	private:
		Node* _head;
	};

	void test1()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);

		l1.push_back(3);
		l1.push_back(4);
		l1.pop_back();
		l1.push_front(5);
		l1.pop_front();


		/*list<int>l2(l1.begin(), l1.end());*/

		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			//*it *= 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
//void test2()
//{
//	Date date[10];
//	zb::list<Date> li(date, date + 10);
//
//}
}
