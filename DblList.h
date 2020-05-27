#include<string>
#include<iostream>
#include<fstream>
#include "DblNode.cpp"
using namespace std;

template<class T>
class DblList{
public:
	DblList();									//构造函数 
	~DblList();									//释放所有存储
	void DelList();								//释放存储，保留头结点
	int Length()const;							//计算双链表的长度
	bool IsEmpty();								//判空
	bool IsFull();								//判满（链表不会满，故返回false） 
	void setHead(DblNode<T> *p);				//设置附加头结点地址 
	DblNode<T>* getHead()const;					//取附加头结点地址
	bool Insert(int i,const T& x,int d); 		//在第i个结点后插入包含有值x的新结点，d=0按前驱（左）方向，d!=0按后继（右）方向 
	bool Remove(DblNode<T> *current);			//删除结点
	DblNode<T>* Search(const string x);			//在链表中沿后继方向寻找等于给定值x的结点 
	DblNode<T>* Locate(int i,int d);			//在链表中定位序号为i（>=0）的结点，d=0按前驱（左）方向，d!=0按后继（右）方向 
	void SortByMobilePhone();					//按手机号码排序（由小到大） 
	void SortByFixedPhone();					//按固话号码排序（由小到大） 
	void SortByName();							//按姓名的拼音排序（由小到大） 
	void Output();								//输出链表信息 
	void PrintFile();							//输出链表信息到文件 
	void WriteFile();							//读取文件信息到链表 
private:
	DblNode<T> *first;
};
