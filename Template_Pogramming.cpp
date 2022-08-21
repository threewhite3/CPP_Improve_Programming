#include<iostream>
#include<vector>

using namespace std;

//交换整型函数
void swapInt(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//交换浮点型函数
void swapDouble(double& a, double& b)
{
	double tmp = a;
	a = b;
	b = tmp;
}
//利用模板提供通用的交换函数
template<typename T>
void mySwap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
void test1()
{
	int a = 10;
	int b = 20;
	cout << "a = " << a << ", b = " << b << endl;
	swapInt(a, b);
	cout<< "a = " << a << ", b = " << b << endl;

	a = 10;
	b = 20;
	cout<<"a = " << a << ", b = " << b << endl;
	mySwap(a, b);
	cout<<"a = " << a << ", b = " << b << endl;
}

template<class T>
void mySwap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
void func()
{
	cout << "func调用" << endl;
}

void test2()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	mySwap(a, b);
	//mySwap(a, c);    //a和c类型不一致，报错

	//func();    //缺少T类型
	func<int>();   //指出T类型为int
	func<char>();  //指出T类型为char
}

template<class T>
void mySwap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int mmax = i;   //最大数的下标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[mmax] < arr[j])
				mmax = j;
		}
		if (mmax != i)
			mySwap(arr[mmax], arr[i]);
	}
}
template<class T>
void PrintArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void test3()
{
	//测试char数组
	char charArr[] = "bdcfeagh";
	int num1 = sizeof(charArr) / sizeof(char);
	mySort(charArr, num1);
	PrintArray(charArr, num1);

	//测试int数组
	int intArr[] = { 7,5,8,1,3,9,2,4,6 };
	int num2 = sizeof(intArr) / sizeof(int);
	mySort(intArr, num2);
	PrintArray(intArr, num2);
}

int myAdd01(int a, int b)
{
	return a + b;
}
template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}
void test4()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	cout << myAdd01(a, c) << endl;//c发生隐式类型转换
	//myAdd02(a, c);    //自动类型推导，不会发生隐式类型转换
	cout<<myAdd02<int>(a, c);  //char强制类型转换int
}

void myPrint(int a, int b)
{
	cout << "调用普通函数" << endl;
}
template<class T>
void myPrint(T a, T b)
{
	cout << "调用模板" << endl;
}
template<class T>
void myPrint(T a, T b, T c)
{
	cout << "调用重载的模板" << endl;
}
void test5()
{
	int a = 10;
	int b = 20;
	myPrint(a, b);

	myPrint<>(a, b);

	int c = 30;
	myPrint(a, b, c);

	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);
}

class Persona
{
public:
	string m_name;
	int m_age;
	Persona(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
};
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
		return true;
	else
		return false;
}
template<>bool myCompare(Persona& p1, Persona& p2)
{
	if (p1.m_name == p2.m_name && p1.m_age == p2.m_age)
		return true;
	else
		return false;
}
void test6()
{
	int a = 10;
	int b = 20;
	bool ans = myCompare(a, b);
	if (ans)
	{
		cout << "a = b" << endl;
	}
	else
		cout << "a != b" << endl;

	Persona p1("Tom", 10);
	Persona p2("Tom", 10);
	bool ans2 = myCompare(p1, p2);
	if (ans2)
		cout << "p1 = p2" << endl;
	else
		cout << "p1 != p2" << endl;
}

//类模板  Class Template
template<class NameType,class AgeType>
class Person
{
public:
	NameType mName;
	AgeType mage;

	Person(NameType name, AgeType age)
	{
		mName = name;
		mage = age;
	}
	void Show()
	{
		cout << "name: " << mName << "  age: " << mage << endl;
	}
};
void test7()
{
	Person<string, int>p("孙", 1000);
	p.Show();
}

class Person1
{
public:
	void Show1()
	{
		cout << "Person1 Show" << endl;
	}
};
class Person2
{
public:
	void Show2()
	{
		cout << "Person2 Show" << endl;
	}
};
template<class T>
class MyClass
{
public:
	T obj;
	void fun1() { obj.Show1(); }
	void fun2() { obj.Show2(); }
};
void test8()
{
	MyClass<Person1>m1;
	m1.fun1();
	//m1.fun2();    //编译报错,说明函数调用才会去创建成员函数

}

template<class NameType,class AgeType=int>
class Person
{
public:
	NameType mName;
	AgeType mAge;
	Person(NameType name, AgeType age)
	{
		mName = name;
		mAge = age;
	}
	void Show()
	{
		cout << "name: " << mName << "    age: " << mAge << endl;
	}
};
//指定传入的类型
void PrintPerson1(Person<string, int>& p)
{
	p.Show();
}
//参数模板化
template<class T1,class T2>
void PrintPerson2(Person<T1, T2>& p)
{
	p.Show();
	cout << "T1的类型是: " << typeid(T1).name() << endl;
	cout << "T2的类型是: " << typeid(T2).name() << endl;
}
//整个类模板化
template<class T>
void PrintPerson3(T& p)
{
	cout << "T的类型是: " << typeid(T).name() << endl;
	p.Show();
}
void test9()
{
	Person<string, int>p("sun", 1000);
	PrintPerson1(p);

	Person<string, int>p2("zhu", 900);
	PrintPerson2(p2);

	Person<string, int>p3("sha", 100);
	PrintPerson3(p3);
}


template<class T>
class Base
{
	T m;
};
class Son :public Base<int>
{

};
template<class T1,class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};
void test10()
{
	Son c;
	Son2<int, char>child1;
}

template<class T1,class T2>
class Person
{
public:
	T1 m_name;
	T2 m_age;
	Person(T1 name, T2 age);
	void Show();
};
template<class T1,class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	m_name = name;
	m_age = age;
}
template<class T1,class T2>
void Person<T1, T2>::Show()
{
	cout << "name: " << m_name << "    age: " << m_age << endl;
}
void test11()
{
	Person<string,int>p("Tom", 100);
	p.Show();

}


template<class T1, class T2>class Personb;
template<class T1,class T2>
void PrintPerson2(Personb<T1, T2>& p)
{
	cout << "类外实现-----姓名: " << p.m_name << "   年龄: " << p.m_age << endl;
}
template<class T1,class T2>
class Personb
{
private:
	T1 m_name;
	T2 m_age;
	friend void PrintPerson(Personb<T1, T2>& p)
	{
		cout << "姓名: " << p.m_name << "   年龄: " << p.m_age << endl;
	}
	friend void PrintPerson2<>(Personb<T1, T2>& p);
public:
	Personb(T1 name, T2 age)
	{
		m_name = name;
		m_age = age;
	}
};
//template<class T1, class T2>
//void PrintPerson2(Person<T1, T2>& p)
//{
//	cout << "类外实现-----姓名: " << p.m_name << "   年龄: " << p.m_age << endl;
//}
void test12()
{
	Personb<string, int>p("Tom", 100);
	PrintPerson(p);

	Personb<string, int>p2("Jerry", 10);
	PrintPerson2(p2);

}


template<class T>
class MyArray
{
private:
	T* pAddress;    //T 类型的数组
	int m_Capacity;   //最大容量
	int m_size;     //当前数组大小
public:
	MyArray(int capacity)          //构造函数
	{
		this->m_Capacity = capacity;
		this->m_size = 0;
		pAddress = new T[m_Capacity];
	}
	MyArray(const MyArray& arr)     //复制构造函数
	{
		m_Capacity = arr.m_Capacity;
		m_size = arr.m_size;
		pAddress = new T[m_Capacity];
		for (int i = 0; i < m_size; i++)
			pAddress[i] = arr[i];
	}
	MyArray& operator=(const MyArray& myarray)   //复制赋值运算符
	{
		if (pAddress != nullptr)
		{
			delete[]pAddress;
			m_Capacity = 0;
			m_size = 0;
		}
		m_Capacity = myarray.m_Capacity;
		m_size = myarray.m_size;
		pAddress = new T[m_Capacity];
		for (int i = 0; i < m_size; i++)
			pAddress[i] = myarray[i];
		return *this;
	}
	T& operator[](int index)   //重载[]运算符
	{
		return pAddress[index];
	}
	void pushback(const T& val)       //尾插法
	{
		if (m_Capacity == m_size)  //达到容量上限
			return;
		pAddress[m_size] = val;
		m_size++;
	}
	void popback()    //尾删法
	{
		if (m_size == 0)
			return;
		m_size--;
	}
	int getCapacity()   //获取容量
	{
		return m_Capacity;
	}
	int getSize()   //获取数组大小
	{
		return m_size;
	}
	~MyArray()     //析构函数
	{
		if (pAddress != nullptr)
		{
			delete[]pAddress;
			pAddress = nullptr;
			m_Capacity = 0;
			m_size = 0;
		}
	}
};
void PrintIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl;
}
void test13()
{
	MyArray<int>arr1(10);
	for (int i = 0; i < 10; i++)
		arr1.pushback(i);
	cout << "arr1输出: " << endl;
	PrintIntArray(arr1);
	cout << "arr1的容量: " << arr1.getCapacity() << endl;
	cout << "arr1的大小: " << arr1.getSize() << endl;

	cout << "--------------------------------------" << endl;

	MyArray<int>arr2(arr1);
	arr2.popback();
	cout << "arr2输出: " << endl;
	PrintIntArray(arr2);
	cout << "arr2的容量: " << arr2.getCapacity() << endl;
	cout << "arr2的大小: " << arr2.getSize() << endl;
}
class Personc
{
public:
	string m_name;
	int m_age;
	Personc() {}
	Personc(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
};
void PrintPersonArray(MyArray<Personc>& p)
{
	for (int i = 0; i < p.getSize(); i++)
		cout << "姓名: " << p[i].m_name << "   年龄: " << p[i].m_age << endl;
}
void test14()
{
	MyArray<Personc>pArray(10);
	Personc p1("sun", 30);
	Personc p2("chen", 20);
	Personc p3("bi", 40);
	Personc p4("xia", 60);
	Personc p5("zhao", 70);

	pArray.pushback(p1);
	pArray.pushback(p2);
	pArray.pushback(p3);
	pArray.pushback(p4);
	pArray.pushback(p5);

	PrintPersonArray(pArray);

	cout << "pArray的大小: " << pArray.getSize() << endl;
	cout << "pArray的容量: " << pArray.getCapacity() << endl;
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();
	test12();
	test13();
	test14();

	return 0;
}