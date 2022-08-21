#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<vector>

using namespace std;

//常用遍历算法
//for_each
void Print01(int val)
{
	cout << val << "  ";
}
class Print02
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};
void ForEach()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.emplace_back(i);
	//for_each普通函数
	for_each(begin(v), end(v), Print01);
	cout << endl;
	//for_each函数对象
	for_each(v.begin(), v.end(), Print02());
	cout << endl;
}

//    transform
//    transform(iterator beg1, iterator end1, iterator beg2, _func);
class Transform
{
public:
	int operator()(int val)
	{
		return val;
	}
};
void TransForm()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.emplace_back(i);
	vector<int>target;
	target.resize(v.size());
	transform(v.begin(), v.end(), target.begin(), Transform());
	for_each(target.begin(), target.end(), Print02());
}

//常用查找算法
//find
void test1()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.emplace_back(i + 1);
	//查找容器是否有5这个元素
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos == v.end())
		cout << "没有找到！" << endl;
	else
	{
		cout << "找到了！" << endl;
		cout << "pos = " << *pos << endl;
	}
}
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
	bool operator=(const Person& p)
	{
		if (this->m_name == p.m_name && this->m_age == p.m_age)
			return true;
		else
			return false;
	}
	bool operator==(const Person& p)
	{
		if (this->m_age == p.m_age)
			return true;
		else
			return false;
	}
};
void test2()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
	if (pos == v.end())
		cout << "没有找到！" << endl;
	else
	{
		cout << "找到了！" << endl;
		cout << "姓名 = " << pos->m_name << "年龄 = " << pos->m_age << endl;
	}
}

//find_if
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test3()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.emplace_back(i + 1);
	//查找容器大于5的元素
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
	if (pos == v.end())
		cout << "没有找到大于5的元素！" << endl;
	else
	{
		cout << "找到了大于5的元素！" << endl;
		cout << "pos = " << *pos << endl;
	}
}
class Greater20
{
public:
	bool operator()(Person& p)     
	{
		return p.m_age > 20;
	}
};
void test4()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator pos = find_if(v.begin(), v.end(), Greater20());
	if (pos == v.end())
		cout << "没有找到！" << endl;
	else
	{
		cout << "找到了！" << endl;
		cout << "姓名 = " << pos->m_name << "年龄 = " << pos->m_age << endl;
	}
}

//adjacent_find
//查找相邻重复元素,返回相邻元素的第一个位置的迭代器
void test5()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);
	//查找相邻重复的元素
	vector<int>::iterator pos = adjacent_find(begin(v), end(v));
	if (pos == v.end())
		cout << "没有找到！" << endl;
	else
		cout << "找到相邻重复的元素：" << *pos << endl;
}

//binary_search
//二分查找指定的元素，查到 返回true 否则false，仅在有序序列中使用
void test6()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	bool ret = binary_search(begin(v), end(v), 2);
	if (ret)
		cout << "找到了！" << endl;
	else
		cout << "没找到！" << endl;
}

//count
//统计元素个数
void test7()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	int num = count(begin(v), end(v), 4);
	cout << "4的个数有：" << num << endl;

	vector<Person>v2;
	Person p1("liu", 35);
	Person p2("guang", 35);
	Person p3("zhang", 35);
	Person p4("zhao", 30);
	Person p5("cao", 25);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	Person p("zhu", 35);
	int num2 = count(begin(v2), end(v2), p);
	cout << "num2 = " << num2 << endl;
}

//count_if
//按照条件统计元素出现的次数
class Greater4
{
public:
	bool operator()(int val)
	{
		return val > 4;
	}
};
class AgeLess35
{
public:
	bool operator()(const Person& p)
	{
		return p.m_age < 35;
	}
};
void test8()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	int num = count_if(v.begin(), v.end(), Greater4());
	cout << "大于4的元素有：" << num << " 个" << endl;

	vector<Person>v2;
	Person p1("liu", 35);
	Person p2("guang", 35);
	Person p3("zhang", 35);
	Person p4("zhao", 30);
	Person p5("cao", 25);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);

	int num2 = count_if(v2.begin(), v2.end(), AgeLess35());
	cout << "小于35岁的个数：" << num2 << endl;
}

//常用排序算法
//sort
void MyPrint(int val)
{
	cout << val << "  ";
}
void test9()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	//默认从小到大排序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
	//按照从大到小排序
	sort(begin(v), end(v), greater<int>());
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

//random_shuffle
void test10()
{
	srand((unsigned int)time(nullptr));
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;

	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

//merge
//merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// [beg1,end1)和[beg2,end2)合并，并将结果放在dest目标容器开始迭代器
void test11()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	vector<int>target;
	target.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
	for_each(target.begin(), target.end(), MyPrint);
	cout << endl;
}

//reverse
//reverse(iterator beg,iterator end)  反转容器
void test12()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(30);

	cout << "反转前：" << endl;
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;

	reverse(v.begin(), v.end());

	cout << "反转后：" << endl;
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

//常用复制和替换
//copy
//copy(iterator beg, iterator end, iterator dest);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};
void test13()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i + 1);
	vector<int>v2;
	v2.resize(v.size());
	copy(v.begin(), v.end(), myPrint());
	cout << endl;
}

//replace
//replace(iterator beg, iterator end, oldvalue, newvalue);
// 将区间内旧元素oldvalue替换成新元素newvalue
void test14()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	v.push_back(20);
	v.push_back(20);

	cout << "替换前：" << endl;
	for_each(begin(v), end(v), myPrint());
	cout << endl;

	replace(begin(v), end(v), 20, 2000);
	cout << "替换后：" << endl;
	for_each(begin(v), end(v), myPrint());
	cout << endl;
}

//replace_if
//replace_if(iterator beg, iterator end, _pred, newvalue);
//按条件替换元素，满足条件的替换成指定元素
class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val > 30;
	}
};
void test15()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	cout << "替换前：" << endl;
	for_each(begin(v), end(v), myPrint());
	cout << endl;
	//将大于30的替换成3000
	replace_if(begin(v), end(v), ReplaceGreater30(), 3000);
	cout << "替换后：" << endl;
	for_each(begin(v), end(v), myPrint());
	cout << endl;
}

//swap
//swap(container c1, container c2);
//互换两个容器的元素
void test16()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
	}
	cout << "交换前：" << endl;
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;

	swap(v1, v2);

	cout << "交换后：" << endl;
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}


//常用算术生成算法
//accumulate
//accumulate(iterator beg, iterator end, value);
// 计算容器元素累计总和
void test17()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
		v.push_back(i);
	int total = accumulate(v.begin(), v.end(), 0);
	cout << "total = " << total << endl;
}

//fill
//fill(iterator beg,iterator end,int val)
void test18()
{
	vector<int>v;
	v.resize(10);

	fill(begin(v), end(v), 100);

	for_each(begin(v), end(v), myPrint());
	cout << endl;
}


//常用集合生成算法

//set_intersection
// set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的交集
// 两个集合必须是有序序列
void test19()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>target;
	//取两个里面较小的值给目标容器开辟空间
	target.resize(min(v1.size(), v2.size()));
	vector<int>::iterator pos = set_intersection(begin(v1), end(v1), begin(v2), end(v2), target.begin());

	for_each(target.begin(), end(target), myPrint());
	cout << endl;
}


//set_union
//set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的并集
// 注意:两个集合必须是有序序列
void test20()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>target;
	//取两个容器大小之和给目标容器开辟空间
	target.resize(v1.size() + v2.size());
	vector<int>::iterator pos = set_union(begin(v1), end(v1), begin(v2), end(v2), target.begin());

	for_each(target.begin(), end(target), myPrint());
	cout << endl;
}

//set_diffrence
//set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的差集
// 注意:两个集合必须是有序序列
void test21()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>target;
	//取两个里面较大的值给目标容器开辟空间
	target.resize(max(v1.size(), v2.size()));
	vector<int>::iterator pos = set_difference(begin(v1), end(v1), begin(v2), end(v2), target.begin());

	for_each(target.begin(), end(target), myPrint());
	cout << endl;
}

int main()
{
	//常用遍历算法
	void ForEach();    //for_each
	void TransForm();    //transform
	//常用查找算法
	void test1();       //find
	void test2();       //find自定义类型
	void test3();       //find_if
	void test4();       //find_if自定义类型
	void test5();       //adjacent_find
	void test6();        //binary_search
	void test7();       //count
	void test8();       //count_if
	//常用排序算法
	void test9();      //sort
	void test10();      //random_shuffle
	void test11();      //merge
	void test12();        // reverse
	//常用复制和替换
	void test13();       //copy
	void test14();       //replace
	void test15();      //replace_if
	void test16();      //swap
	//常用算术生成算法
	void test17();        //accumulate
	void test18();         //fill
	//常用集合生成算法
	void test19();        //set_intersection
	void test20();        //set_union
	void test21();          //set_diffrence

	return 0;
}