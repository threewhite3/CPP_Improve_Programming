#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>
#include<map>
#include<set>

using namespace std;


//string类
void String_Container()
{
	//string构造函数
	cout << "string 构造函数：" << endl;
	string s1;           //string()
	cout << "str1 = " << s1 << endl;

	const char* str = "hello world";
	string s2(str);  //把c_string转换成string,string(const char*s)
	cout << "str2 = " << s2 << endl;

	string s3(s2);        //string(const string&s)
	cout << "str3 = " << s3 << endl;

	string s4(10, 'a');      //string(int n,char c)
	cout << "str4 = " << s4 << endl;
//=====================================================================
	//string赋值操作
	cout << "\nstring复制操作：" << endl;
	string str1;
	str1 = "hello world";     //stirng& operator=(const char*c)
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;             //stirng& operator=(const string&s)
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';       //stirng& operator=(char c)
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("Hello CPP");   //stirng& assign(const char*c)
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("Hello CPP", 5);          //stirng& assign(const char*c,int n)
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str5);         //stirng& assign(const string&s)
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(5, 'x');          //stirng& assign(const string&s,int n)
	cout << "str7 = " << str7 << endl;
//====================================================================
	//string字符串拼接
	cout << "\nstring字符串拼接：" << endl;
	string ss1 = "我";
	ss1 += "爱玩游戏";     //string& operator += (const char*s)
	cout << "ss1 = " << ss1 << endl;
	ss1 += ':';           //string& operator += (const char c)
	cout << "ss1 = " << ss1 << endl;
	string ss2 = "LOL DNF";
	ss1 += ss2;         //string& operator += (const string& s)
	cout << "ss1 = " << ss1 << endl;
	string ss3 = "I";
	ss3.append(" love ");      //string& append(const char* s)
	ss3.append("game abcde", 4);     //string& append(const char* s,int n)
	//ss3.append(ss2);               //stirng& append(const string& s)
	ss3.append(ss2, 4, 3);       //string& append(const string* s,int pos,int n)
	cout << "ss3 = " << ss3 << endl;
//=======================================================================
	//string查找与替换
/*  int find(const string & str, int pos = 0)const;
	int find(const char* s, int pos = 0)const;
	int find(const char* s, int pos, int n)const;
	int find(const char c, int pos = 0)const;
	int rfind(const string & str, int pos = npos)const;
	int rfind(const char* s, int pos = npos)const;
	int rfind(const char* s, int pos, int n)const;
	int rfind(const char c, int pos = 0)const;
	string& replace(int pos, int n, const string & str);
	string& replace(int pos, int n, const char* s);        */
	cout << "\nstring查找与替换:" << endl;
	cout << "查找：" << endl;
	string str11 = "abcdefgde";
	int pos = str11.find("de");
	if (pos == -1)
		cout << "未找到" << endl;
	else
		cout << "pos = " << pos << endl;
	pos = str11.rfind("de");
	cout << "pos = " << pos << endl;
	cout << "替换： " << endl;
	cout << "原 str11 = " << str11 << endl;
	str11.replace(1, 3, "1111");
	cout << "替换后 str11 = " << str11 << endl;
//=========================================================================
	//string字符串比较
	//int compare(const string & s)const;
	//int compare(const char* s)const;
	cout << "\n字符串比较：" << endl;
	string sa = "hello";
	string sb = "aello";
	int ret = sa.compare(sb);
	cout << "sa:   " << sa << "      sb:   " << sb << endl;
	if (ret == 0)
		cout << " sa 等于 sb" << endl;
	else if (ret > 0)
		cout << "sa 大于 sb" << endl;
	else
		cout << "sa 小于 sb" << endl;
//=========================================================================
	//string字符获取
	cout << "\nstring字符获取：" << endl;
	string tmp = "hello world";
	cout << "tmp: " << tmp << endl;
	cout << "operator []" << endl;
	for (int i = 0; i < tmp.size(); i++)
		cout << tmp[i] << endl;                 //char& operator[](int n)
	cout << "at()" << endl;
	for (int i = 0; i < tmp.size(); i++)
		cout << tmp.at(i) << endl;                 //char& at(int n)
	cout << "字符修改：" << endl;
	cout << "将第一个元素改为x:" << endl;
	cout << "operator []" << endl;
	tmp[0] = 'x';
	cout << tmp << endl;
	tmp[0] = 'h';
	cout << "at()" << endl;
	tmp.at(0) = 'x';
	cout << tmp << endl;
//==========================================================
	//string插入和删除
	cout << "\nstirng 插入和删除：" << endl;
	string aa = "hello";
	cout << "aa = " << aa << endl;
	cout << "在第一个位置后面插入111：" << endl;
	aa.insert(1, "111");         //string& insert(int pos,const char*s)       
	                             //string& insert(int pos,const string&s)
	                             //string& insert(int pos,int n,char c)
	cout << aa << endl;
	cout << "删除从第一个位置开始的3个字符：" << endl;
	aa.erase(1, 3);             //string& erase(int pos,int n=npos)
	cout << "aa = " << aa << endl;
//======================================================================
	//string 子串
	cout << "\nstring 子串：" << endl;
	string bb = "abcdefg";
	string sub = bb.substr(1, 3);      //string substr(int pos=0,int n=npos)const;
	cout << "父串： " << bb << "\n他的子串：" << endl;
	cout << " sub = " << sub << endl;
	string email = "hello@sina.com";
	int poss = email.find("@");
	cout << "email:" << email << "\n找到@然后生成子串：\n";
	string username = email.substr(0, poss);
	cout << "username = " << username << endl;
}

//vector类
void Vector_Container()
{
	//vector构造函数
	cout << "vector构造函数： " << endl;
	vector<int>v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	PrintVector(v1);
	vector<int>v2;
	v2 = v1;           //vector& operator = (const vector&vec)
	PrintVector(v2);
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());     //void assign(beg,end);
	PrintVector(v3);
	vector<int>v4;
	v4.assign(10, 100);          //void assign(int n,int elem)
	PrintVector(v4);
//=======================================================
	//vector容量和大小
	cout << "vector容量和大小：" << endl;
	vector<int>a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	PrintVector(a);
	if (a.empty())       //void empty()
		cout << "a为空" << endl;
	else
	{
		cout << "a不为空" << endl;
		cout << "a的容量 = " << a.capacity() << endl;     //void capacity()
		cout << "a的大小 = " << a.size() << endl;        //void size()
	}
	a.resize(15,10);               //void resize(int num,int elem)
	PrintVector(a);

	a.resize(5);                    //void resize(int num)
	PrintVector(a);
//===================================================================
	cout << "vector插入和删除：" << endl;
	vector<int>bb;
	//尾插
	cout << "尾插元素:\n";
	bb.push_back(10);              //void push_back(int val)
	bb.push_back(20);
	bb.push_back(30);
	bb.push_back(40);
	bb.push_back(50);
	PrintVector(bb);
	//尾删
	cout << "尾删一个元素：\n";
	bb.pop_back();                    //void pop_back()
	PrintVector(bb);
	//插入
	cout << "插入：\n";
	bb.insert(bb.begin(), 100);       //void insert(const_iterator pos,int ele)
	PrintVector(bb);
	bb.insert(bb.begin(), 2, 1000);   //void insert(const_iterator pos,int count,int ele)
	PrintVector(bb);
	//删除
	cout << "删除元素：\n";
	bb.erase(bb.begin());             //void erase(const_iterator pos)
	PrintVector(bb);
	//清空
	cout << "清空：\n";
	bb.erase(bb.begin(), bb.end());  //void erase(const_iterator start,const_iterator end)
	bb.clear();                      //void clear()
	PrintVector(bb);
//======================================================================
	//vector数据存取
	cout << "vector数据存取:\n";
	vector<int>cc;
	for (int i = 0; i < 10; i++)
		cc.push_back(i);
	for (int i = 0; i < cc.size(); i++)
		cout << cc[i] << " ";               //int operator[](int i)
	cout << endl;
	for (int i = 0; i < cc.size(); i++)
		cout << cc.at(i) << endl;           //int at(int i)
	cout << endl;
	cout << "cc的第一个元素： " << cc.front() << endl;        //int front()
	cout << "cc的最后一个元素： " << cc.back() << endl;       //int back()
//========================================================================
	//vector互换容器
	vector<int>dd;
	for (int i = 0; i < 10; i++)
		dd.push_back(i);
	PrintVector(dd);
	vector<int>ee;
	for (int i = 10; i > 0; i--)
		ee.push_back(i);
	PrintVector(ee);
	cout << "互换后： " << endl;
	dd.swap(ee);                              //vector& swap(vector<int>&v)
	PrintVector(dd);
	PrintVector(ee);

	vector<int>ff;
	for (int i = 0; i < 100000; i++)
		ff.push_back(i);
	cout << "ff的容量为：" << ff.capacity() << endl;
	cout << "ff的大小为：" << ff.size() << endl;
	ff.resize(3);
	cout << "ff的容量为：" << ff.capacity() << endl;
	cout << "ff的大小为： " << ff.size() << endl;
	//收缩内存
	vector<int>(ff).swap(ff);
	cout << "ff的容量为：" << ff.capacity() << endl;
	cout << "ff的大小为： " << ff.size() << endl;
//===============================================================
	//vector预留空间
	vector<int>gg;
	gg.reserve(10000);         //void reserve(int n)
	int num = 0;
	int* p = nullptr;
	for (int i = 0; i < 10000; i++)
	{
		gg.push_back(i);
		if (p != &gg[0])
		{
			p = &gg[0];
			num++;
		}
	}
	cout << "num: " << num << endl;
}
void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << "  ";
	cout << endl;
}

//deque类
void Deque_Container()
{
	//deque构造函数
	cout << "deque构造函数：" << endl;
	deque<int>d1;                   //deque<T> deqT
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	PrintDeque(d1);
	deque<int>d2(d1.begin(), d1.end());     //deque(beg,end)
	PrintDeque(d2);

	deque<int>d3(10, 100);                //deque(int n,int ele)
	PrintDeque(d3);

	deque<int>d4 = d3;               //deque(const deque&d)
	PrintDeque(d4);
//=============================================================
	//deque大小操作
	cout << "deque大小操作：" << endl;
	deque<int>d5;
	for (int i = 0; i < 10; i++)
		d5.push_back(i);
	PrintDeque(d5);
	if (d5.empty())               //void empty()
		cout << "容器d5为空" << endl;
	else
	{
		cout << "容器d5不为空" << endl;
		cout << "容器d5大小： " << d5.size() << endl;    //void size()
	}
	cout << "重新指定大小：" << endl;
	d5.resize(15, 1);        //void resize(int num,int ele)
	PrintDeque(d5);
	d5.resize(5);            //void resize(int num)
	PrintDeque(d5);
//=============================================================
	//deque删除和插入
	cout << "deque删除和插入： " << endl;
	deque<int>d6;
	//尾插
	d6.push_back(10);         //void push_back()
	d6.push_back(20);
	//头插
	d6.push_front(100);        //void push_front()
	d6.push_front(200);
	PrintDeque(d6);
	//尾删
	d6.pop_back();         //void pop_back()
	//头删
	d6.pop_front();        //void pop_front()
	PrintDeque(d6);
	//插入
	cout << "插入：" << endl;
	deque<int>d7;
	d7.push_back(10);
	d7.push_back(20);
	d7.push_front(100);
	d7.push_front(200);
	PrintDeque(d7);
	d7.insert(d7.begin(), 1000);       //void insert(const_iterator iter,int elem)
	PrintDeque(d7);
	d7.insert(d7.begin(), 2, 10000);    //void insert(const_iterator iter,int n,int elem)
	PrintDeque(d7);
	deque<int>d8;
	d8.push_back(1);
	d8.push_back(2);
	d8.push_back(3);
	d7.insert(d7.begin(), d8.begin(), d8.end());
	PrintDeque(d7);
	//删除
	cout << "删除：" << endl;
	deque<int>d9;
	d9.push_back(10);
	d9.push_back(20);
	d9.push_front(100);
	d9.push_front(200);
	PrintDeque(d9);
	d9.erase(d9.begin());            //void erase(const_iterator iter)
	PrintDeque(d9);
	d9.erase(d9.begin(), d9.end());    //void erase(const_iterator beg,const_iterator end)
	d9.clear();                       //void clear()
	PrintDeque(d9);
//==================================================
	//deque数据存取
	cout << "deque数据存取：" << endl;
	deque<int>d10;
	d10.push_back(10);
	d10.push_back(20);
	d10.push_front(100);
	d10.push_front(200);
	for (int i = 0; i < d10.size(); i++)
	{
		cout << d10[i] << " ";         //operator[](int index)
	}
	cout << endl;
	for (int i = 0; i < d10.size(); i++)
		cout << d10.at(i) << " ";            //int at(int index)
	cout << endl;
	cout << "front: " << d10.front() << endl;     //int front()
	cout << "back: " << d10.back() << endl;        //int back()
//======================================================
	//deque排序
	cout << "deque排序： " << endl;
	deque<int>d11;
	d11.push_back(10);
	d11.push_back(20);
	d11.push_front(100);
	d11.push_front(200);
	PrintDeque(d11);
	sort(begin(d11), end(d11));        //void sort(const_iterator beg,const_iterator end)
	PrintDeque(d11);
}
void PrintDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator iter = d.begin(); iter != d.end(); iter++)
		cout << *iter << "  ";
	cout << endl;
}

//////////////////////////////综合示例//////////////////////////////////
class Person
{
public:
	string m_name;
	int m_score;
	Person(string name, int score)
	{
		m_name = name;
		m_score = score;
	}
};
void CreatePerson(vector<Person>& v)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameseed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}
void SetScore(vector<Person>& v)
{
	for (vector<Person>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;   //60-100
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
			sum += *it;
		int avg = sum / d.size();
		iter->m_score = avg;
	}
}
void ShowScore(vector<Person>& v)
{
	for (vector<Person>::iterator iter = v.begin(); iter != v.end(); iter++)
		cout << "姓名： " << iter->m_name << "  平均分： " << iter->m_score << endl;
}
void ExampleStringVectorDeque()
{
	//随机种子
	srand((unsigned int)time(nullptr));
	//创建类数组
	vector<Person>v;
	CreatePerson(v);
	//打分
	SetScore(v);
	//显示
	ShowScore(v);
}
//////////////////////////////////////////////////////////////////////////////////

//stack类
void Stack_Container()
{
	//stack常用接口
	cout << "stack常用接口：" << endl;
	stack<int>s;               //stack<T>stk
	//入栈
	s.push(10);         //void push(int ele)
	s.push(20);
	s.push(30);
	while (!s.empty())      //bool empty()
	{
		//输出栈的元素
		cout << "栈顶的元素：" << s.top() << endl;    //int top()
		//出栈
		s.pop();          //void pop()
	}
	cout << "栈的大小：" << s.size() << endl;      //int size()
}

//queue类
void Queue_Container()
{
	queue<Person>q;                 //queue<T> q
	Person p1("tang", 30);
	Person p2("sun", 1000);
	Person p3("zhu", 900);
	Person p4("sha", 800);
	//入队
	q.push(p1);        //void push(int ele)
	q.push(p2);
	q.push(p3);
	q.push(p4);
	while (!q.empty())        //bool empty()
	{
		//输出队首元素
		cout << "队首元素------姓名：" << q.front().m_name         //T front()
			<< "    年龄：" << q.front().m_score << endl;
		cout << "队尾元素------姓名：" << q.back().m_name        //T back()
			<< "    年龄：" << q.back().m_score << endl;
		cout << endl;
		q.pop();              //void pop()
	}
	cout << "队列大小： " << q.size() << endl;        //int size()
}

//list类
void PrintList(const list<int>& l)
{
	for (list<int>::const_iterator iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << "  ";
	cout << endl;
}
void List_Container()
{
	//list构造函数
	cout << "list构造函数：" << endl;
	list<int>l1;             //list<T>lst
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	PrintList(l1);

	list<int>l2(l1.begin(), l1.end());        //list(iterator beg,iterator end)
	PrintList(l2);

	list<int>l3(l2);                   //list(const list&l)
	PrintList(l3);

	list<int>l4(10, 1000);          //list(int n,int ele)
	PrintList(l4);
//================================================================
	//list赋值和交换
	list<int>l5;
	l5 = l1;           //list& operator=(const list&l)
	PrintList(l5);
	list<int>l6;
	l6.assign(l5.begin(), l5.end());   //void assign(iterator beg,iterator end)
	PrintList(l6);
	list<int>l7;
	l7.assign(10, 100);             //void assign(int n,int ele)
	PrintList(l7);
	
	cout << "交换前： " << endl;
	PrintList(l5);
	PrintList(l7);
	cout << endl;
	l5.swap(l7);         //void swap(list&l)
	cout << "交换后：" << endl;
	PrintList(l5);
	PrintList(l7);
//======================================================
	//list大小操作
	if (l1.empty())          //bool empty()
		cout << "l1为空。" << endl;
	else
	{
		cout << "l1不为空。" << endl;
		cout << "l1得大小为：" << l1.size() << endl;       //int size()
	}
	l1.resize(10);            //void resize(int n)
	PrintList(l1);

	l1.resize(2);
	PrintList(l1);
//=====================================================
	//list插入和删除
	list<int>l8;
	//尾插
	l8.push_back(10);        //void push_back(int ele)
	l8.push_back(10);
	l8.push_back(10);
	//头插
	l8.push_front(100);         //void push_front(int ele)
	l8.push_front(200);
	l8.push_front(300);
	PrintList(l8);
	//尾删
	l8.pop_back();          //void pop_back()
	PrintList(l8);
	//头删
	l8.pop_front();           //void pop_front()
	PrintList(l8);
	//插入
	list<int>::iterator it = l8.begin();
	l8.insert(++it, 1000);         //void insert(iterator pos,int ele)
	PrintList(l8);
	//删除
	it = l8.begin();
	l8.erase(++it);        //void erase(iterator pos)
	PrintList(l8);
	//移除
	l8.push_back(10000);
	l8.push_back(10000);       
	l8.push_back(10000);
	PrintList(l8);
	l8.remove(10000);         //void remove(int ele)
	PrintList(l8);
	//清空
	l8.clear();            //void clear()
	PrintList(l8);
//=======================================================
	//list数据存储
	cout << "list数据存储：" << endl;
	list<int>l9;
	l9.push_back(10);
	l9.push_back(20);
	l9.push_back(30);
	l9.push_back(40);
	cout << "第一个元素：" << l9.front() << endl;           //void front()
	cout << "最后一个元素：" << l9.back() << endl;          //void back()
	//list容器得迭代器是双向迭代器，不支持随机访问
	//list<int>::iterator iter = l9.begin();
	//iter = iter +1;   //是错误得，不可以跳跃访问，即使+1
//========================================================
	//list反转和排序
	list<int>l10;
	l10.push_back(90);
	l10.push_back(30);
	l10.push_back(20);
	l10.push_back(70);
	PrintList(l10);
	//反转
	l10.reverse();          //void reverse()
	PrintList(l10);
	//排序
	l10.sort();               //void sort()      默认从小到大排序
	PrintList(l10);
}

//////////////////////案例////////////////////////////
class person
{
public:
	string m_name;
	int m_age;
	int m_height;

	person(string name, int age, int height)
	{
		m_name = name;
		m_age = age;
		m_height = height;
	}
};
bool comparePerson(person& p1, person& p2)
{
	if (p1.m_age == p2.m_age)
		return p1.m_height > p2.m_height;
	else
		return p1.m_age < p2.m_age;
}
void ExampleListSort()
{
	list<person>l;
	person p1("liu", 35, 175);
	person p2("cao", 45, 180);
	person p3("sun", 40, 170);
	person p4("zhao", 25, 190);
	person p5("zhang", 35, 160);
	person p6("guan", 35, 200);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	for (list<person>::iterator iter = l.begin(); iter != l.end(); iter++)
		cout << "姓名：" << iter->m_name << "  年龄： " << iter->m_age << "  身高： " << iter->m_height << endl;

	cout << "---------------------------------------" << endl;
	l.sort(comparePerson);  //排序

	for (list<person>::iterator iter = l.begin(); iter != l.end(); iter++)
		cout << "姓名：" << iter->m_name << "  年龄： " << iter->m_age << "  身高： " << iter->m_height << endl;
}
/////////////////////////////////////////////////////////////////////

//set/multiset类
void PrintSet(set<int>& s)
{
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << "   ";
	cout << endl;
}
class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
class ComparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2)
	{
		return p1.m_score > p2.m_score;
	}
};
void Set_Container()
{
	//set构造和赋值
	cout << "set构造和赋值:" << endl;
	set<int>s1;      //set<T> s
	s1.insert(10);       //void insert(int ele)   插入数据会自动排序
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	PrintSet(s1);
	//复制构造
	set<int>s2(s1);     //set(const set&s)
	PrintSet(s2);
	//赋值
	set<int>s3;
	s3 = s1;        //set& operator = (const set&s)
	PrintSet(s3);
//======================================================
	//set大小和交换
	cout << "set大小和交换：" << endl;
	if (s1.empty())                             //bool empty()
		cout << "s1为空！" << endl;
	else
	{
		cout << "s1不为空！" << endl;
		cout << "s1的大小为：" << s1.size() << endl;        //int size()
	}
	set<int>s4;
	s4.insert(10);       
	s4.insert(20);
	s4.insert(30);
	s4.insert(40);
	set<int>s5;
	s5.insert(100);     
	s5.insert(200);
	s5.insert(300);
	s5.insert(400);
	cout << "交换前:" << endl;
	PrintSet(s4);
	PrintSet(s5);
	cout << endl;
	cout << "交换后：" << endl;
	s4.swap(s5);                       //void swap(set<int>&s)
	PrintSet(s4);
	PrintSet(s5);
//=====================================================================
	//set插入和删除
	cout << "set插入和删除：" << endl;
	set<int>s6;
	//插入
	s6.insert(10);       //void insert(int elem)
	s6.insert(20);
	s6.insert(30);
	s6.insert(40);
	//删除
	s6.erase(s6.begin());       //void erase(iterator pos)
	PrintSet(s6);

	s6.erase(30);               //void erase(int ele)
	PrintSet(s6);
	//清空
	s6.clear();                //void clear()
	PrintSet(s6);
//=====================================================================
	//set查找和统计
	cout << "set查找和统计:" << endl;
	set<int>s7;
	s6.insert(10);
	s6.insert(20);
	s6.insert(30);
	s6.insert(40);
	//查找
	set<int>::iterator pos = s6.find(30);        //iterator find(int key)    返回的是迭代器
	if (pos != s7.end())
		cout << "找到了元素： " << *pos << endl;
	else
		cout << "没找到元素！" << endl;
	//统计
	int num = s7.count(30);           //int count(int key)
	cout << "num = " << num << endl;
//=====================================================================
	//set和multiset区别
	cout << "set和multiset区别:" << endl;
	set<int>s8;
	pair<set<int>::iterator, bool>ret = s8.insert(10);
	if (ret.second)
		cout << "第一次插入成功！" << endl;
	else
		cout << "第一次插入失败！" << endl;
	ret = s8.insert(10);                  //不允许插入重复的数据
	if (ret.second)
		cout << "第二次插入成功！" << endl;
	else
		cout << "第二次插入失败！" << endl;

	multiset<int>ms;
	ms.insert(10);                    //插入重复的数据
	ms.insert(10);
	for (multiset<int>::iterator iter = ms.begin(); iter != ms.end(); iter++)
		cout << *iter << "  ";
	cout << endl;
//=====================================================================
	//pair对组创建
	pair<string, int>p("Tom", 20);
	cout << "姓名：" << p.first << "   年龄： " << p.second << endl;
	pair<string, int>p2 = make_pair("Jerry", 10);
	cout << "姓名：" << p2.first << "   年龄： " << p2.second << endl;
//=====================================================================
	//set排序
	set<int>s10;
	s10.insert(10);
	s10.insert(40);
	s10.insert(20);
	s10.insert(30);
	s10.insert(50);
	PrintSet(s10);
	//指定排序规则
	set<int, MyCompare>s11;
	s11.insert(10);
	s11.insert(40);
	s11.insert(20);
	s11.insert(30);
	s11.insert(50);
	for (set<int,MyCompare>::iterator iter = s11.begin(); iter != s11.end(); iter++)
		cout << *iter << "   ";
	cout << endl;
//----------------------------------------------------------------------
	set<Person, ComparePerson>ss;
	Person p1("liu", 23);
	Person p22("guang", 27);
	Person p3("zhang", 25);
	Person p4("zhao", 21);
	ss.insert(p1);
	ss.insert(p22);
	ss.insert(p3);
	ss.insert(p4);
	for (set<Person, ComparePerson>::iterator iter = ss.begin(); iter != ss.end(); iter++)
		cout << "姓名：" << iter->m_name << "   年龄： " << iter->m_score << endl;
	cout << endl;
}

//map/multimap类
void PrintMap(map<int,int>&m)
{
	for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++)
		cout << "key = " << iter->first << "  value = " << iter->second << endl;
	cout << endl;
}
void Map_Container()
{
	//map构造、赋值
	cout << "map构造、赋值:" << endl;
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	PrintMap(m1);

	map<int, int>m2(m1);         //map(const map&m)
	PrintMap(m2);

	map<int, int>m3;
	m3 = m2;           //map& operator=(const map&m)
	PrintMap(m3);
//=====================================================
	//map插入和删除
	cout << "插入和删除:" << endl;
	map<int, int>m4;
	m4.insert(pair<int, int>(1, 10));
	m4.insert(make_pair(2, 20));
	m4.insert(map<int, int>::value_type(3, 30));
	m4[4] = 40;
	PrintMap(m4);
	//删除
	m4.erase(m4.begin());        //void erase(iterator pos)
	PrintMap(m4);

	m4.erase(3);          //void erase(int ele)
	PrintMap(m4);
	//清空
	m4.erase(m4.begin(), m4.end());     //void erase(iterator beg,iterator end)
	m4.clear();                         //void clear()
	PrintMap(m4);
//========================================================
	//map大小和交换
	cout << "map大小和交换：" << endl;
	map<int, int>m5;
	m5.insert(pair<int, int>(1, 10));
	m5.insert(pair<int, int>(2, 20));
	m5.insert(pair<int, int>(3, 30));

	if (m5.empty())                              //bool empty()
		cout << "map为空！" << endl;
	else
	{
		cout << "map不为空！" << endl;
		cout << "map的大小为：" << m5.size() << endl;    //int size()
	}
	//交换
	map<int, int>m6;
	m6.insert(pair<int, int>(4, 100));
	m6.insert(pair<int, int>(5, 200));
	m6.insert(pair<int, int>(6, 300));
	cout << "交换前：" << endl;
	PrintMap(m5);
	PrintMap(m6);
	cout << "交换后：" << endl;
	m5.swap(m6);                    //void swap(map<int,int>& m)
	PrintMap(m5);
	PrintMap(m6);
//========================================================
	//map查找和统计
	cout << "map查找和统计:" << endl;
	map<int, int>m7;
	m5.insert(pair<int, int>(1, 10));
	m5.insert(pair<int, int>(2, 20));
	m5.insert(pair<int, int>(3, 30));
	//查找
	map<int, int>::iterator pos = m7.find(3);             //iterator find(int key)

	if (pos != m7.end())
		cout << "找到元素 key = " << (*pos).first << "  value = " << (*pos).second << endl;
	else
		cout << "未找到元素" << endl;
	//统计
	int num = m7.count(3);            //int count(int key)
	cout << "num = " << num << endl;
//========================================================
	//map容器排序
	cout << "map容器排序:" << endl;
	map<int, int, MyCompare>m8;          //利用仿函数排序
	m8.insert(make_pair(1, 10));
	m8.insert(make_pair(2, 20));
	m8.insert(make_pair(3, 30));
	m8.insert(make_pair(4, 40));
	m8.insert(make_pair(5, 50));
	for (map<int, int, MyCompare>::iterator iter = m8.begin(); iter != m8.end(); iter++)
		cout << "key = " << iter->first << "   value = " << iter->second << endl;
	cout << endl;
}



//-公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
//- 员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
//- 随机给10名员工分配部门和工资
//- 通过multimap进行信息的插入 key(部门编号) value(员工)
//- 分部门显示员工信息
const int CEHUA = 0;
const int MEISHU = 1;
const int YANFA = 2;
class Worker
{
public:
	string m_name;
	int m_salary;
};
void CreateWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHI";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_name = "员工";
		worker.m_name += nameSeed[i];

		worker.m_salary = rand() % 10000 + 10000;      //10000--19999
		//将员工压入容器
		v.push_back(worker);
	}
}
//员工分组
void SetGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		//产生随机部门的编号
		int deptID = rand() % 3;    //0 1 2
		//将员工插入分组中
		//key部门编号，value具体员工
		m.insert(make_pair(deptID, *iter));
	}
}
void ShowWorkerByGroup(multimap<int, Worker>& m)
{
	// 0 A B C  1 D E   2 F G....
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);    //统计人数
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
		cout << "姓名： " << pos->second.m_name << "    工资： " << pos->second.m_salary << endl;
	cout << "--------------------------------------------" << endl;
	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);   //统计人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
		cout << "姓名： " << pos->second.m_name << "    工资： " << pos->second.m_salary << endl;
	cout << "--------------------------------------------" << endl;
	cout << "研发部门：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);   //统计人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
		cout << "姓名： " << pos->second.m_name << "    工资： " << pos->second.m_salary << endl;
}
void EmployeeGroups()
{
	srand((unsigned int)time(nullptr));
	//创建员工
	vector<Worker>vw;
	CreateWorker(vw);
	//员工分组
	multimap<int, Worker>mw;
	SetGroup(vw, mw);
	//分组显示员工
	ShowWorkerByGroup(mw);
}


int main()
{
	String_Container();      //string容器
	Vector_Container();      //vector容器
	Deque_Container();       //deque容器

	ExampleStringVectorDeque();    //评委打分例子

	Stack_Container();       //stack容器
	Queue_Container();       //queue容器
	List_Container();       //list容器

	ExampleListSort();        //链表排序例子

	Set_Container();       //set容器
	Map_Container();       //map容器

	EmployeeGroups();      //员工分组例子

	return 0;
}