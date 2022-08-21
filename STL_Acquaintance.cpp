#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myprint(int val)
{
	cout << val << endl;
}
void test1()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();

	while (pBegin != pEnd)
	{
		cout << *pBegin << endl;
		pBegin++;
	}

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << endl;

	for_each(v.begin(), v.end(), myprint);
}


//自定义容器类型
class Person
{
public:
	string m_name;
	int m_age;
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
};
void test2()
{
	vector<Person>v1;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);

	for (vector<Person>::iterator iter = v1.begin(); iter != v1.end(); iter++)
	{
		cout << "name: " << (*iter).m_name << "    age: " << (*iter).m_age << endl;
	}


	vector<Person*>v2;
	v2.push_back(&p1);
	v2.push_back(&p2);
	v2.push_back(&p3);
	v2.push_back(&p4);
	v2.push_back(&p5);

	for (vector<Person*>::iterator iter = v2.begin(); iter != v2.end(); iter++)
	{
		cout << "name: " << (*iter)->m_name << "    age: " << (*iter)->m_age << endl;
	}
}

//嵌套容器
void test3()
{
	vector<vector<int>>v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;

	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it++)
			cout << *it << "  ";
		cout << endl;
	}
}

int main()
{
	void test1();
	void test2();
	void test3();

	return 0;
}