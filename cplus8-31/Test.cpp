#include<iostream>
#include<vector>
using namespace std;
//��������ʹ��
void Print(const vector<int>& v)
{
	vector<int>::const_iterator ite = v.begin();
	while (ite != v.end())
	{
		cout << *ite << " ";
		ite++;
	}
	cout << endl;
	////�������������vector
	//vector<int>::const_reverse_iterator rit = v.rbegin();
	//while (rit!=v.rend())
	//{
	//	cout << *rit << " ";
	//	++rit;
	//}
	//cout << endl;
	////��Χfor����
	//for (auto& e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	////[]����������
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
//{//1��vector��ʹ��
//	vector<int>v5();
//	vector<double> v2(10,2.2);//������double�����Ա�������10��2.2
//	vector<char>v3(10,'a');//������char������Ա�������10��a�ַ�
//	vector<int> v1(10,5);//������int���͵����Ա�������10��5
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
//	vector<int>v1(10,9);//����int���͵�˳���������10��9
//	vector<int>v2(v1.begin(), v1.begin() + 6);//���õ���������int���͵�˳���������6��9
//	v1.push_back(11);
//	v1.push_back(13);
//	Print(v1);
	/*Print(v2);*/
    //vector<int>v3(v2);//ͬ���ʹ�������
	//Print(v3);
	//v1.insert(v1.begin(), 100);//ͷ��һ��Ԫ��100
	//Print(v1);
	//v1.insert(v1.begin(), 1, 400);
	//Print(v1);
	//v1.insert(v1.begin() + 2, v1.begin(), v1.begin() + 2);
	//Print(v1);
//	//erase��pop_backβɾɾ������
//	v1.pop_back();
//	Print(v1);
//
//	v1.erase(v1.begin());
//	Print(v1);
//
//	v1.erase(v1.begin()+1);
//	Print(v1);
//	//��������
//	cout <<"��СΪ��"<< v1.size()<<endl;
//	cout << "�ռ�Ϊ��" << v1.capacity() << endl;
//	v1.reserve(20);
//	cout << "����:" << endl;
//	cout << "��СΪ��" << v1.size() << endl;
//	cout << "�ռ�Ϊ��" << v1.capacity() << endl;
//	v1.resize(3,0);
//	Print(v1);
//	v1.resize(9, 0);
//	Print(v1);
//	//�п�
//	cout << v1.empty() << endl;
//	//���
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
	v1.insert(v1.begin(), 100);//�ڵ�һ��Ԫ��ǰ����
	//Print(v1);
	v1.insert(v1.begin(), 1, 400);//Ҳ���ڵ�һ��Ԫ��ǰ�����
	//Print(v1);
	v1.insert(v1.begin() + 1, v1.begin(), v1.begin() + 2);
	//�ڵ�һ��Ԫ�غ�����룬400   100  v1��ǰ����Ԫ��
	//Print(v1);

	v1.pop_back();
	//Print(v1);


	v1.erase(v1.begin());//ɾ����1��Ԫ��
	//Print(v1);
	v1.erase(v1.begin()+1);//ɾ����2��Ԫ��
	//Print(v1);

	// ʹ��find����100����λ�õ�iterator
	Print(v1);
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 100);
	// ��posλ��֮ǰ����30
	v1.insert(pos, 30);
	Print(v1);
	return 0;
}