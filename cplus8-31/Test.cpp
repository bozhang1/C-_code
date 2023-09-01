#include<iostream>
#include<vector>
using namespace std;
//迭代器的使用
void Print(const vector<int>& v)
{
	vector<int>::const_iterator ite = v.begin();
	while (ite != v.end())
	{
		cout << *ite << " ";
		ite++;
	}
	cout << endl;
	////反向迭代器遍历vector
	//vector<int>::const_reverse_iterator rit = v.rbegin();
	//while (rit!=v.rend())
	//{
	//	cout << *rit << " ";
	//	++rit;
	//}
	//cout << endl;
	////范围for遍历
	//for (auto& e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	////[]操作符遍历
	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	cout << v[i] << " ";

	//}
	//cout << endl;
}
void Print(const vector<char>& v)
{
	vector<char>::const_iterator ite = v.begin();
	while (ite!=v.end())
	{
		cout << *ite << " ";
		++ite;
	}
	cout << endl;
}

void Print(const vector<double>& v)
{
	vector<double>::const_reverse_iterator rit = v.rbegin();
	while (rit!=v.rend())
	{
		cout << *rit << " ";
		++rit;

	}
	cout << endl;
}

//int main()
//{//1、vector的使用
//	vector<int>v5();
//	vector<double> v2(10,2.2);//定义了double类线性表，里面有10个2.2
//	vector<char>v3(10,'a');//定义了char类的线性表，里面有10个a字符
//	vector<int> v1(10,5);//定义了int类型的线性表，里面有10个5
//	/*v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);*/
//	/*v3.push_back('b');
//	v2.push_back(6.6);*/
//	//Print(v1);
//	//Print(v2);
//	//Print(v3);
//	//Print(v1);
//	vector<int>v4(v1);
//	Print(v4);
//}
//int main()
//{
//	vector<int>v1(10,9);//创建int类型的顺序表，里面有10个9
//	vector<int>v2(v1.begin(), v1.begin() + 6);//利用迭代器创建int类型的顺序表，里面有6个9
//	v1.push_back(11);
//	v1.push_back(13);
//	Print(v1);
	/*Print(v2);*/
    //vector<int>v3(v2);//同类型创建对象
	//Print(v3);
	//v1.insert(v1.begin(), 100);//头插一个元素100
	//Print(v1);
	//v1.insert(v1.begin(), 1, 400);
	//Print(v1);
	//v1.insert(v1.begin() + 2, v1.begin(), v1.begin() + 2);
	//Print(v1);
//	//erase和pop_back尾删删除数据
//	v1.pop_back();
//	Print(v1);
//
//	v1.erase(v1.begin());
//	Print(v1);
//
//	v1.erase(v1.begin()+1);
//	Print(v1);
//	//容量操作
//	cout <<"大小为："<< v1.size()<<endl;
//	cout << "空间为：" << v1.capacity() << endl;
//	v1.reserve(20);
//	cout << "扩容:" << endl;
//	cout << "大小为：" << v1.size() << endl;
//	cout << "空间为：" << v1.capacity() << endl;
//	v1.resize(3,0);
//	Print(v1);
//	v1.resize(9, 0);
//	Print(v1);
//	//判空
//	cout << v1.empty() << endl;
//	//清空
//	v1.clear();
//	cout << v1.empty() << endl;
//
//	return 0;
//}
int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.insert(v1.begin(), 100);//在第一个元素前插入
	//Print(v1);
	v1.insert(v1.begin(), 1, 400);//也是在第一个元素前面插入
	//Print(v1);
	v1.insert(v1.begin() + 1, v1.begin(), v1.begin() + 2);
	//在第一个元素后面插入，400   100  v1的前两个元素
	//Print(v1);

	v1.pop_back();
	//Print(v1);


	v1.erase(v1.begin());//删除第1个元素
	//Print(v1);
	v1.erase(v1.begin()+1);//删除第2个元素
	//Print(v1);

	// 使用find查找100所在位置的iterator
	Print(v1);
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 100);
	// 在pos位置之前插入30
	v1.insert(pos, 30);
	Print(v1);
	return 0;
}