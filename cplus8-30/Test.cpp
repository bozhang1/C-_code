#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
//定义结构
class mystring
{
public:
	//实现构造函数
	mystring()//空
		:_str(new char[1])
	{
		*_str = '\0';
		_size = _capacity = 1;
	}
	mystring(const char* s)
		:_size(strlen(s))   //给_size有效长度
	{
		_str = new char[_size + 1];      //给_str一个strlen(s)+1长度的空间
		strcpy(_str, s);               //拷贝字符串
		_capacity = _size;           //更新容量
		_str[_size] = '\0';
	}
	//拷贝构造
	void Swap(mystring& a, mystring& b)
	{//这里为了代码简洁性和可阅读性，定义了一个Swap封装一下
		swap(a._str, b._str);
		swap(a._size, b._size);
		swap(a._capacity, b._capacity);
	}

	mystring(const mystring& t) :_str(nullptr)  
	{//必须有这一置空操作,因为_str开始是个随机数,交换给tmp._str后,被释放会引起大问题
		mystring tmp(t._str);  //直接利用构造函数,给tmp对象开辟了一块空间,并把值传进去.
		Swap(*this, tmp);
	}
	//赋值重载
	mystring& operator=(mystring t)
	{
		Swap(*this, t);  //注意哦,博主调用的是Swap,而不是swap.
		return *this;
	}
	//运算符重载
	char& operator[](size_t pos)
	{//支持读写
		return _str[pos];
	}
	const char& operator[](size_t pos) const
	{//支持只读
		return _str[pos];
	}
	//实现改变容量
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];//先开一个块我们需要的空间需要加1放\0
			strcpy(tmp,_str);//这里将_str里面的值先拷贝进来
            delete[]_str;//然后将原来的_str空间释放掉
			_str = tmp;//将我们开好的空间赋值给_str
			_str[n] = '\0';//这里可以先tmp赋值也可以最后赋值
			_capacity = n;//改变容量
		}
	}
	void resize(size_t n,char ch = '\0')
	{
		if (n > _capacity) reserve(n);
		for (size_t i = _size; i < n; i++) _str[i] = ch;
		_size = n;
		_str[_size] = '\0';

	}
	//字符串拼接
	//尾插
	void push_back(char c)
	{//如果里面并没有容量我们需要增容，还有防止空插入
		if (_size >= _capacity)
		{
			int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity);
		}
		_str[_size] = c;//将值尾插
		_size++;
		_str[_size] = '\0';
	}
	//拼接
	void append(const char* s)
	{
		int len = strlen(s);
		if (_size + len > _capacity)
		{
			
			reserve((_size + len) * 2);//2倍增容
		}
		strcpy(_str + _size, s);//将字符串拷贝进去
		_size += len;
		_str[_size] = '\0';
	}
	mystring& operator+=(char c)
	{
		push_back(c);
		return*this;
	}
	mystring& operator+=(const char* s)
	{
		append(s);
		return*this;
	}
	//查找大小
	size_t size()const
	{
		return _size;
	}
	size_t capacity()const
	{
		return _capacity;
	}
	//迭代器
	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin() { return _str; }
	iterator end() { return _str + _size; }
	iterator begin() const { return _str; }
	iterator end() const { return _str + _size; }


	//析构函数
	~mystring()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}
	//插入和删除板块
	void insert(size_t pos, const char c)
	{
		if (_size >= _capacity)
		{//增容防空
			int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity);
		}
		for (int i = _size; i > pos; i--)
		{//将pos位置后面数据移动一位
			_str[i] = _str[i -1];
		}
		_str[pos] = c;//插入
		_size++;
		_str[_size] = '\0';
	}
	void insert(size_t pos, const char* s)
	{
		size_t len = strlen(s);
		if (_size+len > _capacity)
		{
			reserve(len+_size);
		}
		for (int i = _size + len - 1; i > pos+len-1; i--)
		{
			_str[i] = _str[i - len];
		}
		for (int i = pos + len - 1, j = len - 1; j >= 0; i--, j--)
		{
			_str[i] = s[j];
		}
		_size += len;
		_str[_size] = '\0';
	}
	//clear()
	void clear()
	{
		_str[0] = '\0';
		_size = 0;
	}
private:
	char* _str;
	int _size;
	int _capacity;
};

int main()
{
	/*mystring s1;*/
	mystring s2("zqqqz");

	s2.insert(2, 'b');
	printf("%s\n", s2);
	s2.insert(2, "666");
	printf("%s\n", s2);
	s2.clear();
	printf("%s\n", s2);


	/*s2 += 'b';
	s2 += "666";
	cout << s2.capacity() << endl;

	mystring s("123456");
	mystring::iterator itb = s2.begin();
	mystring::iterator ite = s2.end();
	while (itb != ite)
	{
		cout << *itb << endl;
		++itb;
	}*/

	//mystring s3(s2);
	//mystring s4 = s3;
	//s2[0] = 'b';
	return 0;
}