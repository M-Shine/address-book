#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "DblList.cpp"
using namespace std;

void OutputInfo(DblList<Info>& dl);		//输出联系人信息 
void NewInfo(DblList<Info>& dl);		//新建联系人信息 
void UpdateInfo(DblList<Info>& dl);		//更新联系人信息 
void SearchInfo(DblList<Info>& dl);		//查找联系人 
void RemoveInfo(DblList<Info>& dl);		//删除联系人 

int main(){
	DblList<Info> dl;
	int select = 1;
	while(select){
		system("cls");
		cout << "--------------- 通讯录 ---------------" << endl << endl;
		cout << "------- 请输入编号进行相关操作 -------" << endl << endl; 
		cout << "1.显示所有联系人信息" << endl << endl;
		cout << "2.增加新的联系人" << endl << endl;
		cout << "3.修改联系人信息" << endl << endl;
		cout << "4.查找联系人" << endl << endl;
		cout << "5.删除联系人" << endl << endl; 
		cout << "0.退出系统" << endl << endl;
		cout << "请输入操作编号：";
		while( !(cin >> select) || select < 0 || select > 5 ){			//限制用户输入 
			cout << endl << "输入有误，请重新输入：";
			cin.clear();												//更改cin的状态标示符
			cin.sync();													//清除缓存区的数据流
		}
		switch(select){
			case 0 : break;
			case 1 : OutputInfo(dl); break;
			case 2 : NewInfo(dl);    break;
			case 3 : UpdateInfo(dl); break;
			case 4 : SearchInfo(dl); break;
			case 5 : RemoveInfo(dl); break;
			default: break;
		}
	}
	dl.PrintFile();
	system("pause");
	return 0;
}

//输出联系人信息  
void OutputInfo(DblList<Info>& dl){
	int s = 1;
	system("cls");
	cout << endl << "当前联系人个数：" << dl.Length() << endl;
	dl.Output();
	cout << endl;
	while(s){
		cout << "更改排列方式：" << endl << endl;
		cout << "1.按手机号码升序排列" << endl << endl;
		cout << "2.按固话号码升序排列" << endl << endl;
		cout << "3.按姓名的拼音升序排列" << endl << endl; 
		cout << "0.返回" << endl << endl;
		cout << "请输入操作序号：";
		while( !(cin >> s) || s < 0 || s > 3 ){							//限制用户输入 
			cout << endl << "输入有误，请重新输入：";
			cin.clear();												//更改cin的状态标示符
			cin.sync();													//清除缓存区的数据流
		}
		switch(s){
			case 0 : break;
			case 1 : dl.SortByMobilePhone(); 
					 system("cls");
					 cout << endl << "当前联系人个数：" << dl.Length() << endl;
					 dl.Output();
					 break;
			case 2 : dl.SortByFixedPhone();
					 system("cls");
					 cout << endl << "当前联系人个数：" << dl.Length() << endl;
					 dl.Output();
					 break;
			case 3 : dl.SortByName();
					 system("cls");
					 cout << endl << "当前联系人个数：" << dl.Length() << endl;
					 dl.Output();
					 break;
			default : break;
		}
	}
}

//新建联系人信息
void NewInfo(DblList<Info>& dl){
	system("cls");
	Info info;
	info.Input();
	if(dl.Insert(dl.Length()+1,info,1))	cout << endl << "操作成功！" << endl << endl;
	else cout << endl << "操作失败！" << endl << endl;
	Sleep(250); 
}

//更新联系人信息  
void UpdateInfo(DblList<Info>& dl){
	system("cls");
	string message;
	cout << endl << "请输入要修改的联系人的姓名（或 拼音 或 手机号码 或 固话号码 或 QQ号码 或 邮箱地址）：";	cin >> message;
	if(dl.Search(message)){
		int s = 1;
		string temp;
		DblNode<Info> *p = dl.Search(message);
		while(s){
			system("cls");
			cout << endl << "将要修改以下联系人信息" << endl;
			p->data.Output();
			cout << endl;
			cout << "1.修改联系人姓名" << endl << endl;
			cout << "2.修改联系人手机号码" << endl << endl;
			cout << "3.修改联系人固话号码" << endl << endl;
			cout << "4.修改联系人邮箱地址" << endl << endl;
			cout << "5.修改联系人QQ号码" << endl << endl;
			cout << "6.修改联系人邮政编码" << endl << endl;
			cout << "0.返回" << endl << endl;
			cout << "请输入要修改的数据编号：";
			while( !(cin >> s) || s < 0 || s > 6 ){						//限制用户输入 
				cout << endl << "输入有误，请重新输入：";
				cin.clear();											//更改cin的状态标示符
				cin.sync();												//清除缓存区的数据流
			}
			switch(s){
				case 0 : break;
				case 1 : cout << endl << "请输入联系人姓名："; cin >> temp; p->data.setName(temp); p->data.setPinYin(temp); break;
				case 2 : cout << endl << "请输入联系人手机号码："; cin >> temp; p->data.setMobilePhone(temp); break;
				case 3 : cout << endl << "请输入联系人固话号码："; cin >> temp; p->data.setFixedPhone(temp); break;
				case 4 : cout << endl << "请输入联系人邮箱地址："; cin >> temp; p->data.setEmail(temp); break;
				case 5 : cout << endl << "请输入联系人QQ号码："; cin >> temp; p->data.setQQ(temp); break;
				case 6 : cout << endl << "请输入联系人邮政编码："; cin >> temp; p->data.setZipCode(temp); break;
				default : break;
			}
			cout << endl << "操作成功！" << endl;
		}
	}
}

//查找联系人
void SearchInfo(DblList<Info>& dl){
	system("cls");
	string message;
	cout << endl << "请输入要搜索的联系人的姓名（或 拼音 或 手机号码 或 固话号码 或 QQ号码 或 邮箱地址）：";	cin >> message;
	cout << endl;
	if(dl.Search(message)){
		dl.Search(message)->data.Output();
	}
	else{
		cout << endl << "联系人不存在！" << endl;
	}
	cout << endl;
	system("pause");
}

//删除联系人 
void RemoveInfo(DblList<Info>& dl){
	system("cls");
	string message;
	cout << endl << "请输入要修改的联系人的姓名（或 拼音 或 手机号码 或 固话号码 或 QQ号码 或 邮箱地址）：";	cin >> message;
	if(dl.Search(message)){
		char s;
		DblNode<Info> *p = dl.Search(message);
		system("cls");
		cout << endl << "将要删除以下联系人信息" << endl;
		p->data.Output();
		cout << endl << "输入Y确定删除,输入其它任意键返回：";	cin >> s;
		if( s == 'Y' || s == 'y' ){
			dl.Remove(p);
			cout << endl << "删除成功！" << endl << endl;
			Sleep(250);
		}
		else{
			cout << endl << "取消操作..." << endl << endl;
			Sleep(250);
		}
	}
	else cout << endl << "联系人不存在！" << endl << endl;
	Sleep(250);
}
