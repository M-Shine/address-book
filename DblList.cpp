#include "DblList.h"
#include "Info.cpp"
#include<iostream>
using namespace std;

//���캯��
template<class T>
DblList<T>::DblList(){
	first = new DblNode<T>();
	if(first == NULL){
		cout << "Error���洢�������" << endl;
		exit(1);
	}
	first->rLink = first->lLink = first;
	WriteFile();								//���ļ��ж������ݵ����� 
}

template<class T>
void DblList<T>::WriteFile(){
	int count = 1;
	string name,mobilephone,fixedphone,email,qq,zipcode,pinyin;
	fstream InFile("AddressBook.txt",ios::in);
	if(!InFile)	cout << "Error���ļ���ʧ�ܣ�" << endl;
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
			InFile.get();						//��ȡ���Ļس����������ظ���ȡ���һ������ 
			if(InFile.peek() == EOF) break;
		}
	} 
	InFile.close();
}

//�����������ͷ������ڴ� 
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

//������ݣ�����ͷ��� 
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

//����˫����ĳ���
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

//�п�
template<class T>
bool DblList<T>::IsEmpty(){
	return first->rLink == first;
} 

//���� 
template<class T>
bool DblList<T>::IsFull(){
	return false;
}

//���ø���ͷ����ַ
template<class T>
void DblList<T>::setHead(DblNode<T> *p){
	first = p;
} 

//ȡ����ͷ����ַ
template<class T>
DblNode<T>* DblList<T>::getHead()const{
	return first;
} 

//�ڵ�i��������������ֵx���½�㣬d=0��ǰ�����󣩷���d!=0����̣��ң����� 
template<class T>
bool DblList<T>::Insert(int i,const T& x,int d){
	DblNode<T> *current = Locate(i-1,d);							//���ҵ�i�����
	if(current == NULL)	return false;							//����i����������ʧ��
	DblNode<T> *newNode = new DblNode<T>(x);
	if(newNode == NULL){
		cout << "Error���洢����ʧ�ܣ�" << endl;
		exit(1);
	}
	if( d ){													//��̷������ 
		newNode->rLink = current->rLink;
		current->rLink = newNode;
		newNode->rLink->lLink = newNode;
		newNode->lLink = current;
	}
	else{														//ǰ��������� 
		 newNode->lLink = current->lLink;
		 current->lLink = newNode;
		 newNode->lLink->rLink = newNode;
		 newNode->rLink = current;
	}
	return true;
} 

//ɾ�����
template<class T>
bool DblList<T>::Remove(DblNode<T> *current){
	if(current == NULL)	return false;							//����i������ɾ��ʧ��
	current->rLink->lLink = current->lLink;						//��lLink����ժ��
	current->lLink->rLink = current->rLink;						//��rLink����ժ��
	delete current;
	return true; 
}

//���������غ�̷���Ѱ�ҵ��ڸ���ֵx�Ľ�� 
template<class T>
DblNode<T>* DblList<T>::Search(const string x){
	DblNode<T> *current = first->rLink;
	while( current != first ){
		if( current->data.getName() == x || current->data.getMobilePhone() == x 
			|| current->data.getFixedPhone() == x || current->data.getQQ() == x 
			|| current->data.getEmail() == x || current->data.getPinYin() == x){
			return current;										//�����ɹ� 
		}
		current = current->rLink;
	}
	return NULL;												//����ʧ�� 
}

//�������ж�λ���Ϊi��>=0���Ľ�㣬d=0��ǰ�����󣩷���d!=0����̣��ң����� 
template<class T>
DblNode<T>* DblList<T>::Locate(int i,int d){
	if(i < 0)	return NULL;
	if(first->rLink == first || i == 0)	return first;
	DblNode<T> *current;
	if(d == 0)	current = first->lLink;							//��������
	else current = first->rLink;
	for(int j=1;j<i;j++){										//�������� 
		if(current == first)	break;
		else if(d == 0)		current = current->lLink;
		else	current = current->rLink;
	} 
	if(current != first)	return current;						//�����ɹ�
	else return NULL;											//����ʧ�� 
}

template<class T>
void DblList<T>::Output(){
	DblNode<T> *p = first->rLink;
	while( p != first){
		p->data.Output();
		p = p->rLink;
	}
}

//���ֻ�����������С���� 
template<class T>
void DblList<T>::SortByMobilePhone(){
	int k = 1;										//��¼����λ�� 
	int count = Length();							//��¼������ 
	DblNode<T> *min;								//��¼��С��λ�� 
	DblNode<T> *temp = new DblNode<T>();
	if(temp == NULL){
		cout << "Error���洢����ʧ�ܣ�" << endl;
		exit(1);
	}
	
	temp->rLink = first->rLink;						//��temp����first 
	temp->rLink->lLink = temp;
	temp->lLink = first->lLink;
	temp->lLink->rLink = temp;
	
	first->rLink = first->lLink = first;			//��ԭ˫��ѭ�������ÿ� 
	
	min = temp->rLink;
	for( int i=1 ;i<=count;i++ ){
		for( DblNode<T>* j = temp->rLink ; j != temp ; j = j->rLink ){
			if( min->data.getMobilePhone() >= j->data.getMobilePhone() ){
				min = j;
			}
		}
		Insert(k++,min->data,1);
		min->data.setMobilePhone("null");			//�ַ������ֵ�ASCII��󣬴˴���Ϊ����Ӣ���ַ� 
	}
}

template<class T>
void DblList<T>::SortByFixedPhone(){
	int k = 1;										//��¼����λ�� 
	int count = Length();							//��¼������ 
	DblNode<T> *min;								//��¼��С��λ�� 
	DblNode<T> *temp = new DblNode<T>();
	if(temp == NULL){
		cout << "Error���洢����ʧ�ܣ�" << endl;
		exit(1);
	}
	
	temp->rLink = first->rLink;						//��temp����first 
	temp->rLink->lLink = temp;
	temp->lLink = first->lLink;
	temp->lLink->rLink = temp;
	
	first->rLink = first->lLink = first;			//��ԭ˫��ѭ�������ÿ� 
	
	min = temp->rLink;
	for( int i=1 ;i<=count;i++ ){
		for( DblNode<T>* j = temp->rLink ; j != temp ; j = j->rLink ){
			if( min->data.getFixedPhone() >= j->data.getFixedPhone() ){
				min = j;
			}
		}
		Insert(k++,min->data,1);
		min->data.setFixedPhone("null");			//�ַ������ֵ�ASCII��󣬴˴���Ϊ����Ӣ���ַ� 
	}
}

template<class T>
void DblList<T>::SortByName(){
	int k = 1;										//��¼����λ�� 
	int count = Length();							//��¼������ 
	DblNode<T> *min;								//��¼��С��λ�� 
	DblNode<T> *temp = new DblNode<T>();
	if(temp == NULL){
		cout << "Error���洢����ʧ�ܣ�" << endl;
		exit(1);
	}
	
	temp->rLink = first->rLink;						//��temp����first 
	temp->rLink->lLink = temp;
	temp->lLink = first->lLink;
	temp->lLink->rLink = temp;
	
	first->rLink = first->lLink = first;			//��ԭ˫��ѭ�������ÿ� 
	
	min = temp->rLink;
	for( int i=1 ;i<=count;i++ ){
		for( DblNode<T>* j = temp->rLink ; j != temp ; j = j->rLink ){
			if( min->data.getPinYin() >= j->data.getPinYin() ){
				min = j;
			}
		}
		Insert(k++,min->data,1);
		min->data.setPinYin("~");					// ~��ASCIIֵ����ĸ�� 
	}
}

template<class T>
void DblList<T>::PrintFile(){
	fstream OutFile("AddressBook.txt",ios::out|ios::binary);
	if(!OutFile)	cout << "Error���ļ���ʧ�ܣ�" << endl;
	else{
		DblNode<T> *p = first->rLink;
		//����������д�뵽�ļ� 
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
