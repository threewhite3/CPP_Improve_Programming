#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<functional>
#include<stack>
#include<queue>
#include<list>
#include<map>
#include<set>

using namespace std;

//1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
void test1()
{
	MyAdd myadd;
	cout << myadd(10, 10) << endl;
}

//2、函数对象可以有自己的状态
class MyPrint
{
public:
	int count;    //统计使用次数
	MyPrint() { count = 0; }
	void operator()(string s)
	{
		cout << s << endl;
		count++;
	}
};
void test2()
{
	MyPrint myprint;
	myprint("hello world");
	myprint("hello world");
	myprint("hello world");
	cout << "myprint调用次数：" << myprint.count << endl;
}

//3、函数对象可以作为参数传递
void doPrint(MyPrint& mp, string s)
{
	mp(s);
}
void test3()
{
	MyPrint myprint;
	doPrint(myprint, "Hello C++");
}

//谓词
//一元谓词
struct GreaterFive
{
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test4()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	vector<int>::iterator iter = find_if(begin(v), end(v), GreaterFive());
	if (iter != v.end())
		cout << "没找到：" << endl;
	else
		cout << "找到： " << *iter << endl;
}

//二元谓词
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};
void test5()
{
	vector<int>v;
	v.emplace_back(10);
	v.emplace_back(20);
	v.emplace_back(30);
	v.emplace_back(40);
	v.emplace_back(50);
	//默认从小到大
	sort(begin(v), end(v));
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << "   ";
	cout << endl;
	cout << "---------------------------------------------------" << endl;
	//使用函数对象改变算法策略，排序从大到小
	sort(begin(v), end(v), MyCompare());
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << "   ";
	cout << endl;
}

//算术仿函数
//template<class T> T plus<T> //加法仿函数
//template<class T> T minus<T> //减法仿函数
//template<class T> T multiplies<T> //乘法仿函数
//template<class T> T divides<T> //除法仿函数
//template<class T> T modulus<T> //取模仿函数
//template<class T> T negate<T> //取反仿函数
void testNegate()
{
	negate<int>n;            //template<class T>  T negate<T>      取反函数    一元运算
	cout << n(50) << endl;
}
void testPlus()
{
	plus<int>p;               //template<class T>  T plus<T>      加法    二元运算
	cout << p(10, 20) << endl;
}

//关系仿函数
//template<class T> bool equal_to<T> //等于
//template<class T> bool not_equal_to<T> //不等于
//template<class T> bool greater<T> //大于
//template<class T> bool greater_equal<T> //大于等于
//template<class T> bool less<T> //小于
//template<class T> bool less_equal<T> //小于等于
class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void testGreater()
{
	vector<int>v;
	v.emplace_back(10);
	v.emplace_back(30);
	v.emplace_back(20);
	v.emplace_back(50);
	v.emplace_back(40);

	sort(begin(v), end(v), MyCompare());
	//sort(begin(v), end(v), greater<int>());
	for (vector<int>::iterator iter = v.begin(); iter < v.end(); iter++)
		cout << *iter << "  ";
	cout << endl;
}

//逻辑仿函数
//template<class T> bool logical_and<T> //逻辑与
//template<class T> bool logical_or<T> //逻辑或
//template<class T> bool logical_not<T> //逻辑非
void testLogical()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << "    ";
	cout << endl;

	//逻辑非 
	vector<bool>v2;
	v2.resize(v.size());
	transform(begin(v), end(v), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator iter = v2.begin(); iter != v2.end(); iter++)
		cout << *iter << "    ";
	cout << endl;
}

int main()
{
	//函数对象
	void test1();
	void test2();
	void test3();
	//一元谓词
	void test4();
	//二元谓词
	void test5();
	//算术仿函数
	void testNegate();
	void testPlus();
	//关系仿函数
	void testGreater();
	//逻辑仿函数
	void testLogical();

	return 0;
}