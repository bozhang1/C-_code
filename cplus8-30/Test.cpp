#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
//����ṹ
class mystring
{
public:
	//ʵ�ֹ��캯��
	mystring()//��
		:_str(new char[1])
	{
		*_str = '\0';
		_size = _capacity = 1;
	}
	mystring(const char* s)
		:_size(strlen(s))   //��_size��Ч����
	{
		_str = new char[_size + 1];      //��_strһ��strlen(s)+1���ȵĿռ�
		strcpy(_str, s);               //�����ַ���
		_capacity = _size;           //��������
		_str[_size] = '\0';
	}
	//��������
	void Swap(mystring& a, mystring& b)
	{//����Ϊ�˴������ԺͿ��Ķ��ԣ�������һ��Swap��װһ��
		swap(a._str, b._str);
		swap(a._size, b._size);
		swap(a._capacity, b._capacity);
	}

	mystring(const mystring& t) :_str(nullptr)  
	{//��������һ�ÿղ���,��Ϊ_str��ʼ�Ǹ������,������tmp._str��,���ͷŻ����������
		mystring tmp(t._str);  //ֱ�����ù��캯��,��tmp���󿪱���һ��ռ�,����ֵ����ȥ.
		Swap(*this, tmp);
	}
	//��ֵ����
	mystring& operator=(mystring t)
	{
		Swap(*this, t);  //ע��Ŷ,�������õ���Swap,������swap.
		return *this;
	}
	//���������
	char& operator[](size_t pos)
	{//֧�ֶ�д
		return _str[pos];
	}
	const char& operator[](size_t pos) const
	{//֧��ֻ��
		return _str[pos];
	}
	//ʵ�ָı�����
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];//�ȿ�һ����������Ҫ�Ŀռ���Ҫ��1��\0
			strcpy(tmp,_str);//���ｫ_str�����ֵ�ȿ�������
            delete[]_str;//Ȼ��ԭ����_str�ռ��ͷŵ�
			_str = tmp;//�����ǿ��õĿռ丳ֵ��_str
			_str[n] = '\0';//���������tmp��ֵҲ�������ֵ
			_capacity = n;//�ı�����
		}
	}
	void resize(size_t n,char ch = '\0')
	{
		if (n > _capacity) reserve(n);
		for (size_t i = _size; i < n; i++) _str[i] = ch;
		_size = n;
		_str[_size] = '\0';

	}
	//�ַ���ƴ��
	//β��
	void push_back(char c)
	{//������沢û������������Ҫ���ݣ����з�ֹ�ղ���
		if (_size >= _capacity)
		{
			int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity);
		}
		_str[_size] = c;//��ֵβ��
		_size++;
		_str[_size] = '\0';
	}
	//ƴ��
	void append(const char* s)
	{
		int len = strlen(s);
		if (_size + len > _capacity)
		{
			
			reserve((_size + len) * 2);//2������
		}
		strcpy(_str + _size, s);//���ַ���������ȥ
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
	//���Ҵ�С
	size_t size()const
	{
		return _size;
	}
	size_t capacity()const
	{
		return _capacity;
	}
	//������
	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin() { return _str; }
	iterator end() { return _str + _size; }
	iterator begin() const { return _str; }
	iterator end() const { return _str + _size; }


	//��������
	~mystring()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}
	//�����ɾ�����
	void insert(size_t pos, const char c)
	{
		if (_size >= _capacity)
		{//���ݷ���
			int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			reserve(newcapacity);
		}
		for (int i = _size; i > pos; i--)
		{//��posλ�ú��������ƶ�һλ
			_str[i] = _str[i -1];
		}
		_str[pos] = c;//����
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