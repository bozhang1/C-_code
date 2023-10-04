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
	//������
	template <class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef __list_iterator<T, T&, T*> iterator;              //��ͨ������
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
		Ref operator*() //������ʹ��*����˼�� ��ȡ���ֵ,���Ծ�ֱ�ӽ�����_node,Ȼ�󷵻�
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
		//typedef __list_iterator<T, T&> iterator;              //��ͨ������
		//typedef __list_iterator<T, const T&> const_iterator;  //��������
		typedef __list_iterator<T, T&, T*> iterator;              //��ͨ������
		typedef __list_iterator<T, const T&, const T*> const_iterator;  //��������

		iterator begin() { return iterator(_head->_next); }
		iterator end() { return iterator(_head); }

		const_iterator begin() const { return iterator(_head->_next); }
		const_iterator end() const { return iterator(_head); }

		list()
		{//��ͷ˫��ѭ��
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		//���������캯��
		//template <class InputIterator, class OutputIterator>
		//list(InputIterator input, OutputIterator output)
		//{
		//	_head = new Node;  // ��ͷ��㿪��һ��ռ�.
		//	_head->_next = _head;
		//	_head->_prev = _head;
		//	while (input != output)
		//	{
		//		push_back(*input); //�������������ʵ��β�����ݵ�,������������н���
		//		input++;
		//	}
		//}
		//��������
		list(const list<T>& lt)
		{
			_head = new Node;    // ��������ȿ���ͷ���ռ�Ŷ,��Ϊ���ǿ�������,���Ǹ�ֵ
			_head->_next = _head;
			_head->_prev = _head;
			for (const auto& e : lt)
			{
				push_back(e);//������������ʵ��
			}
		}
		//��ֵ����
		list<T>& operator=(const list<T> lt)  
	//ע��Ŷ,����Ĳ�������û��ʹ�� ����.����lt����ͨ�����������ȡ��ֵ
		{
			swap(_head, lt._head);   //Ȼ�󽻻����������ͷ���
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
		//��������
		~list()
		{
			clear(); //һ��Ҫ���ͷ�ͷ�����������
			delete _head;
			_head = nullptr;
		}
		////β��
		//void push_back(const T& x)
		//{
		//	Node* tail = _head->_prev;
		//	Node* newnode = new Node(x);
		//	tail->_next = newnode;
		//	newnode->_prev = tail;
		//	newnode->_next = _head;
		//	_head->_prev = newnode;
		//}
		////βɾ
		//void pop_back()
		//{
		//	assert(_head != _head->_next);   //�������Ϊ��,����ɾ��

		//	Node * oldtail = _head->_prev;      //��ȡ��β�ͽ��
		//	Node * newtail = oldtail->_prev;    //�����β�ͽ���ǰһ�����
		//	delete oldtail;
		//	oldtail = nullptr;
		//	_head->_prev = newtail;
		//	newtail->_next = _head;
		//}
		////ͷ��
		//void push_front(const T& val)
		//{
		//	Node* tmp = new Node(val);     //���������½�һ�����
		//	Node* next = _head->_next;     //����ͷ�����һ�����
		//	_head->_next = tmp;
		//	tmp->_prev = _head;            //ͷ���������ݽ������
		//	tmp->_next = next;
		//	next->_prev = tmp;             //�½��ͱ���������
		//}
		////ͷɾ
		//void pop_front()
		//{
		//	assert(_head != _head->_next);//�������Ϊ��,����ɾ��
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
