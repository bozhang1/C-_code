#include<iostream>
using namespace std;
//class Person
//{
//public:
//	virtual void buy()
//	{
//		cout << "全价-全票" << endl;
//	}
//};
////派生类继承基类
//class Student:public Person
//{
//public:
//	virtual void buy()//对基类的虚函数进行重写
//	{
//		cout << "半价-全票" << endl;
//	}
//
//};
////用引用调用父类的虚函数
//void buyone(Person&p)
//{
//	p.buy();
//}
//int main()
//{
//	Person p;
//	Student s;
//	buyone(p);
//	buyone(s);
//}

//class A {};
//class B : public A {};
//class Person {
//public:
//	virtual A* f() { 
//		cout << "全价-全票" << endl;
//		return new A; }
//};
//class Student : public Person {
//public:
//	virtual B* f() { 
//		cout << "半价-全票" << endl;
//		return new B; }
//};
//void buyone(Person&p)
//{
//	p.f();
//}
//int main()
//{
//	Person p;
//	Student s;
//	buyone(p);
//	buyone(s);
//}
//class Person {
//public:
//	 virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	 ~Student() { cout << "~Student()" << endl; }
//};
//int main()
//{
//	//当不写virtual的，p2的析构函数和person的析构函数构成隐藏关系，这里调用的是~person
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}
//class Car
//{
//public:
//	virtual void Drive() {};
//	virtual void Drive2() {};
//	virtual void Drive3() {};
//
//protected:
//	int _i;
//	char _s;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive(){  }
//	virtual void Drive4() {  }
//	virtual void Drive5() {  }
//
//
//};
////void PrintVFT(void* vft[])
////{
////	printf("%p\n",vft);
////	for (size_t i = 0; vft[i] != nullptr; ++i)
////	{
////		printf("vtf[%d]:%p\n", i, vft[i]);
////
////	}
////	printf("\n");
////}
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vft[])
//{
//	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
//	cout << " 虚表地址>" << vft << endl;
//	for (size_t i = 0; vft[i] != nullptr; ++i)
//	{
//		printf(" vft[%d]:%p,->", i, vft[i]);
//		VFPTR f = vft[i];
//		f();
//	}
//	cout << endl;
//}
//int main()
//{
//	//Car* b1 = new Benz;
//	//b1->Drive();
//	Car c;
//	Benz b;
//	//cout << sizeof(c) << endl;
//	//PrintVFT((void**)(*((int*)& b)));
//	VFPTR* vft = (VFPTR*)(*(int*)& b);
//	PrintVTable((VFPTR*)(*(int*)& c));
//}
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//void Func(Person p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//}
class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%p,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Derive d;
	VFPTR* vTableb1 = (VFPTR*)(*(int*)& d);
	PrintVTable(vTableb1);
	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)& d + sizeof(Base1)));
	PrintVTable(vTableb2);
	return 0;
}