#include<iostream>
template<class T>
struct DblNode{
	T data;
	DblNode<T> *lLink,*rLink;		//链表前驱（左链）、后继（右链）指针
	DblNode(DblNode<T> *left = NULL,DblNode<T> *right = NULL):lLink(left),rLink(right){}
	DblNode(T value,DblNode<T> *left = NULL,DblNode<T> *right = NULL):data(value),lLink(left),rLink(right){} 
};
