#include "DblList.h"
#include "Info.cpp"
#include<iostream>
using namespace std;

//构造函数
template<class T>
DblList<T>::DblList(){
	first = new DblNode<T>();
	if(first == NULL){
		cout << "Error：存储分配错误！" << endl;
		exit(1);
	}
	first->rLink = first->lLink = first;
	WriteFile();								//从文件中读入数据到链表 
}

template<class T>
void DblList<T>::WriteFile(){
	int count = 1;
	string name,mobilephone,fixedphone,email,qq,zipcode,pinyin;
	fstream InFile("AddressBook.txt",ios::in);
	if(!InFile)	cout << "Error：文件打开失败！" << endl;
	else{
		while(!InFile.eof()){
			InFile >> name;
			InFile >> pinyin;
			InFile >> mobilephone;
			InFile >> fixedphone;
			InFile >> email;
			InFile >> qq;
			InFile >> zipcode;
			Info info(name,pinyin,mobilephone,fixedphone,email,qq,zipcode);
			Insert(count++,info,1);
			InFile.get();						//读取最后的回车符，避免重复读取最后一条数据 
			if(InFile.peek() == EOF) break;
		}
	} 
	InFile.close();
}

//析构函数：释放所有内存 
template<class T>
DblList<T>::~DblList(){
	DblNode<T> *p;
	p = first->rLink;
	while(p != first){
		p = p->rLink;
		delete p->lLink;
	}
	delete first;
	first = NULL;
}

//清空数据，保留头结点 
template<class T>
void DblList<T>::DelList(){
	DblNode<T> *p;
	p = first->rLink;
	while(p != first){
		p = p->rLink;
		delete p->lLink;
	}
	first->rLink = first->lLink = first;
}

//计算双链表的长度
template<class T>
int DblList<T>::Length()const{
	int count = 0;
	DblNode<T> *current = first->rLink;
	while(current != first){
		current = current->rLink;
		count++;
	}
	return count;
} 

//判空
template<class T>
bool DblList<T>::IsEmpty(){
	return first->rLink == first;
} 

//判满 
template<class T>
bool DblList<T>::IsFull(){
	return false;
}

//设置附加头结点地址
template<class T>
void DblList<T>::setHead(DblNode<T> *p){
	first = p;
} 

//取附加头结点地址
template<class T>
DblNode<T>* DblList<T>::getHead()const{
	return first;
} 

//在第i个结点后插入包含有值x的新结点，d=0按前驱（左）方向，d!=0按后继（右）方向 
template<class T>
bool DblList<T>::Insert(int i,const T& x,int d){
	DblNode<T> *current = Locate(i-1,d);							//查找第i个结点
	if(current == NULL)	return false;							//参数i不合理，插入失败
	DblNode<T> *newNode = new DblNode<T>(x);
	if(newNode == NULL){
		cout << "Error：存储分配失败！" << endl;
		exit(1);
	}
	if( d ){													//后继方向插入 
		newNode->rLink = current->rLink;
		current->rLink = newNode;
		newNode->rLink->lLink = newNode;
		newNode->lLink = current;
	}
	else{														//前驱方向插入 
		 newNode->lLink = current->lLink;
		 current->lLink = newNode;
		 newNode->lLink->rLink = newNode;
		 newNode->rLink = current;
	}
	return true;
} 

//删除结点
template<class T>
bool DblList<T>::Remove(DblNode<T> *current){
	if(current == NULL)	return false;							//参数i不合理，删除失败
	current->rLink->lLink = current->lLink;						//从lLink链中摘下
	current->lLink->rLink = current->rLink;						//从rLink链中摘下
	delete current;
	return true; 
}

//在链表中沿后继方向寻找等于给定值x的结点 
template<class T>
DblNode<T>* DblList<T>::Search(const string x){
	DblNode<T> *current = first->rLink;
	while( current != first ){
		if( current->data.getName() == x || current->data.getMobilePhone() == x 
			|| current->data.getFixedPhone() == x || current->data.getQQ() == x 
			|| current->data.getEmail() == x || current->data.getPinYin() == x){
			return current;										//搜索成功 
		}
		current = current->rLink;
	}
	return NULL;												//搜索失败 
}

//在链表中定位序号为i（>=0）的结点，d=0按前驱（左）方向，d!=0按后继（右）方向 
template<class T>
DblNode<T>* DblList<T>::Locate(int i,int d){
	if(i < 0)	return NULL;
	if(first->rLink == first || i == 0)	return first;
	DblNode<T> *current;
	if(d == 0)	current = first->lLink;							//搜索方向
	else current = first->rLink;
	for(int j=1;j<i;j++){										//逐个结点检测 
		if(current == first)	break;
		else if(d == 0)		current = current->lLink;
		else	current = current->rLink;
	} 
	if(current != first)	return current;						//搜索成功
	else return NULL;											//搜索失败 
}

template<class T>
void DblList<T>::Output(){
	DblNode<T> *p = first->rLink;
	while( p != first){
		p->data.Output();
		p = p->rLink;
	}
}

//按手机号码排序（由小到大） 
template<class T>
void DblList<T>::SortByMobilePhone(){
	int k = 1;										//记录插入位置 
	int count = Length();							//记录链表长度 
	DblNode<T> *min;								//记录最小项位置 
	DblNode<T> *temp = new DblNode<T>();
	if(temp == NULL){
		cout << "Error：存储分配失败！" << endl;
		exit(1);
	}
	
	temp->rLink = first->rLink;						//用temp代替first 
	temp->rLink->lLink = temp;
	temp->lLink = first->lLink;
	temp->lLink->rLink = temp;
	
	first->rLink = first->lLink = first;			//将原双向循环链表置空 
	
	min = temp->rLink;
	for( int i=1 ;i<=count;i++ ){
		for( DblNode<T>* j = temp->rLink ; j != temp ; j = j->rLink ){
			if( min->data.getMobilePhone() >= j->data.getMobilePhone() ){
				min = j;
			}
		}
		Insert(k++,min->data,1);
		min->data.setMobilePhone("null");			//字符比数字的ASCII码大，此处可为任意英文字符 
	}
}

template<class T>
void DblList<T>::SortByFixedPhone(){
	int k = 1;										//记录插入位置 
	int count = Length();							//记录链表长度 
	DblNode<T> *min;								//记录最小项位置 
	DblNode<T> *temp = new DblNode<T>();
	if(temp == NULL){
		cout << "Error：存储分配失败！" << endl;
		exit(1);
	}
	
	temp->rLink = first->rLink;						//用temp代替first 
	temp->rLink->lLink = temp;
	temp->lLink = first->lLink;
	temp->lLink->rLink = temp;
	
	first->rLink = first->lLink = first;			//将原双向循环链表置空 
	
	min = temp->rLink;
	for( int i=1 ;i<=count;i++ ){
		for( DblNode<T>* j = temp->rLink ; j != temp ; j = j->rLink ){
			if( min->data.getFixedPhone() >= j->data.getFixedPhone() ){
				min = j;
			}
		}
		Insert(k++,min->data,1);
		min->data.setFixedPhone("null");			//字符比数字的ASCII码大，此处可为任意英文字符 
	}
}

template<class T>
void DblList<T>::SortByName(){
	int k = 1;										//记录插入位置 
	int count = Length();							//记录链表长度 
	DblNode<T> *min;								//记录最小项位置 
	DblNode<T> *temp = new DblNode<T>();
	if(temp == NULL){
		cout << "Error：存储分配失败！" << endl;
		exit(1);
	}
	
	temp->rLink = first->rLink;						//用temp代替first 
	temp->rLink->lLink = temp;
	temp->lLink = first->lLink;
	temp->lLink->rLink = temp;
	
	first->rLink = first->lLink = first;			//将原双向循环链表置空 
	
	min = temp->rLink;
	for( int i=1 ;i<=count;i++ ){
		for( DblNode<T>* j = temp->rLink ; j != temp ; j = j->rLink ){
			if( min->data.getPinYin() >= j->data.getPinYin() ){
				min = j;
			}
		}
		Insert(k++,min->data,1);
		min->data.setPinYin("~");					// ~的ASCII值比字母大 
	}
}

template<class T>
void DblList<T>::PrintFile(){
	fstream OutFile("AddressBook.txt",ios::out|ios::binary);
	if(!OutFile)	cout << "Error：文件打开失败！" << endl;
	else{
		DblNode<T> *p = first->rLink;
		//将链表数据写入到文件 
		while( p != first){
			OutFile << p->data.getName() << " ";
			OutFile << p->data.getPinYin() << " ";
			OutFile << p->data.getMobilePhone() << " ";
			OutFile << p->data.getFixedPhone() << " ";
			OutFile << p->data.getEmail() << " ";
			OutFile << p->data.getQQ() << " ";
			OutFile << p->data.getZipCode() << endl;
			p = p->rLink;
		}
	} 
	OutFile.close();
}
