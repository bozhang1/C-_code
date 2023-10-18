//#include<iostream>
//#include<vector>
//using namespace std;
//template<class T>
//
//	class stack
//	{
//	public:
//		stack() {}
//		void push(const T& x) { _c.push_back(x); }
//		void pop() { _c.pop_back(); }
//		T& top() { return _c.back(); }
//		const T& top()const { return _c.back(); }
//		size_t size()const { return _c.size(); }
//		bool empty()const { return _c.empty(); }
//	private:
//		vector<T> _c;
//	};
//int main()
//{
//    stack<int>l1;
//	l1.push(1);
//	l1.push(2);
//	l1.push(3);
//	l1.push(4);
//	
//	return 0;
//}
//#include<deque>
//#include<iostream>
//using namespace std;
//namespace zq
//{
//template<class T, class Con = deque<T>>
////template<class T, class Con = vector<T>>
////template<class T, class Con = list<T>>
//class stack
//{
//public:
//	stack() {}
//	void push(const T& x) { _c.push_back(x); }
//	void pop() { _c.pop_back(); }
//	T& top() { return _c.back(); }
//	const T& top()const { return _c.back(); }
//	size_t size()const { return _c.size(); }
//	bool empty()const { return _c.empty(); }
//private:
//	Con _c;
//};
//}

//#include<deque>
//#include <list>
//namespace zq
//{
//	template<class T, class Con = deque<T>>
//	//template<class T, class Con = list<T>>
//	class queue
//	{
//	public:
//		queue() {}
//		void push(const T& x) { _c.push_back(x); }
//		void pop() { _c.pop_front(); }
//		T& back() { return _c.back(); }
//		const T& back()const { return _c.back(); }
//		T& front() { return _c.front(); }
//		const T& front()const { return _c.front(); }
//		size_t size()const { return _c.size(); }
//		bool empty()const { return _c.empty(); }
//	private:
//		Con _c;
//	};
//}
//#include<iostream>
//using namespace std;
//
//template<class T>
//struct less
//{
//	bool operator()(const T& x, const T& y)
//	{
//		return x < y;
//	}
//};
//int main()
//{
//	int x = 2;
//	int y = 10;
//	std::less<int>l;
//	if (l(y, x))cout << "yes!" << endl;
//	else cout << "no!";
//}
#include<iostream>
#include<queue>
using namespace std;
namespace zq
{
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		//向上调整法
		void adjustup(size_t child)
		{
			less<T> L;
			while (L(_con[(child - 1) / 2], _con[child]))
			{
				swap(_con[(child - 1) / 2], _con[child]);
				child = (child - 1) / 2;
			}
		}
		//插入数据
		void push(const T& x)
		{
			_con.push_back(x);
			adjustup(_con.size() - 1);  //传入插入数据的位置索引,方便调整数据
		}
		//向下调整法
		void adjustdown(size_t parent)
		{
			int child = parent * 2 + 1;
			less<T> L;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && L(_con[child], _con[child + 1])) child++;
				if (L(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else break;
			}
		}
		//删除数据
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjustdown(0);
		}
		//获取堆顶
		const T& top() const
		{
			return _con[0];
		}
		//获取大小
		size_t size()
		{
			return _con.size();
		}
		//判空
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}
int main()
{
	return 0;
}