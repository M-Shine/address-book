#include<string>
#include<iostream>
#include<fstream>
#include "DblNode.cpp"
using namespace std;

template<class T>
class DblList{
public:
	DblList();									//���캯�� 
	~DblList();									//�ͷ����д洢
	void DelList();								//�ͷŴ洢������ͷ���
	int Length()const;							//����˫����ĳ���
	bool IsEmpty();								//�п�
	bool IsFull();								//�����������������ʷ���false�� 
	void setHead(DblNode<T> *p);				//���ø���ͷ����ַ 
	DblNode<T>* getHead()const;					//ȡ����ͷ����ַ
	bool Insert(int i,const T& x,int d); 		//�ڵ�i��������������ֵx���½�㣬d=0��ǰ�����󣩷���d!=0����̣��ң����� 
	bool Remove(DblNode<T> *current);			//ɾ�����
	DblNode<T>* Search(const string x);			//���������غ�̷���Ѱ�ҵ��ڸ���ֵx�Ľ�� 
	DblNode<T>* Locate(int i,int d);			//�������ж�λ���Ϊi��>=0���Ľ�㣬d=0��ǰ�����󣩷���d!=0����̣��ң����� 
	void SortByMobilePhone();					//���ֻ�����������С���� 
	void SortByFixedPhone();					//���̻�����������С���� 
	void SortByName();							//��������ƴ��������С���� 
	void Output();								//���������Ϣ 
	void PrintFile();							//���������Ϣ���ļ� 
	void WriteFile();							//��ȡ�ļ���Ϣ������ 
private:
	DblNode<T> *first;
};
