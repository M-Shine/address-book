#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "DblList.cpp"
using namespace std;

void OutputInfo(DblList<Info>& dl);		//�����ϵ����Ϣ 
void NewInfo(DblList<Info>& dl);		//�½���ϵ����Ϣ 
void UpdateInfo(DblList<Info>& dl);		//������ϵ����Ϣ 
void SearchInfo(DblList<Info>& dl);		//������ϵ�� 
void RemoveInfo(DblList<Info>& dl);		//ɾ����ϵ�� 

int main(){
	DblList<Info> dl;
	int select = 1;
	while(select){
		system("cls");
		cout << "--------------- ͨѶ¼ ---------------" << endl << endl;
		cout << "------- �������Ž�����ز��� -------" << endl << endl; 
		cout << "1.��ʾ������ϵ����Ϣ" << endl << endl;
		cout << "2.�����µ���ϵ��" << endl << endl;
		cout << "3.�޸���ϵ����Ϣ" << endl << endl;
		cout << "4.������ϵ��" << endl << endl;
		cout << "5.ɾ����ϵ��" << endl << endl; 
		cout << "0.�˳�ϵͳ" << endl << endl;
		cout << "�����������ţ�";
		while( !(cin >> select) || select < 0 || select > 5 ){			//�����û����� 
			cout << endl << "�����������������룺";
			cin.clear();												//����cin��״̬��ʾ��
			cin.sync();													//�����������������
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

//�����ϵ����Ϣ  
void OutputInfo(DblList<Info>& dl){
	int s = 1;
	system("cls");
	cout << endl << "��ǰ��ϵ�˸�����" << dl.Length() << endl;
	dl.Output();
	cout << endl;
	while(s){
		cout << "�������з�ʽ��" << endl << endl;
		cout << "1.���ֻ�������������" << endl << endl;
		cout << "2.���̻�������������" << endl << endl;
		cout << "3.��������ƴ����������" << endl << endl; 
		cout << "0.����" << endl << endl;
		cout << "�����������ţ�";
		while( !(cin >> s) || s < 0 || s > 3 ){							//�����û����� 
			cout << endl << "�����������������룺";
			cin.clear();												//����cin��״̬��ʾ��
			cin.sync();													//�����������������
		}
		switch(s){
			case 0 : break;
			case 1 : dl.SortByMobilePhone(); 
					 system("cls");
					 cout << endl << "��ǰ��ϵ�˸�����" << dl.Length() << endl;
					 dl.Output();
					 break;
			case 2 : dl.SortByFixedPhone();
					 system("cls");
					 cout << endl << "��ǰ��ϵ�˸�����" << dl.Length() << endl;
					 dl.Output();
					 break;
			case 3 : dl.SortByName();
					 system("cls");
					 cout << endl << "��ǰ��ϵ�˸�����" << dl.Length() << endl;
					 dl.Output();
					 break;
			default : break;
		}
	}
}

//�½���ϵ����Ϣ
void NewInfo(DblList<Info>& dl){
	system("cls");
	Info info;
	info.Input();
	if(dl.Insert(dl.Length()+1,info,1))	cout << endl << "�����ɹ���" << endl << endl;
	else cout << endl << "����ʧ�ܣ�" << endl << endl;
	Sleep(250); 
}

//������ϵ����Ϣ  
void UpdateInfo(DblList<Info>& dl){
	system("cls");
	string message;
	cout << endl << "������Ҫ�޸ĵ���ϵ�˵��������� ƴ�� �� �ֻ����� �� �̻����� �� QQ���� �� �����ַ����";	cin >> message;
	if(dl.Search(message)){
		int s = 1;
		string temp;
		DblNode<Info> *p = dl.Search(message);
		while(s){
			system("cls");
			cout << endl << "��Ҫ�޸�������ϵ����Ϣ" << endl;
			p->data.Output();
			cout << endl;
			cout << "1.�޸���ϵ������" << endl << endl;
			cout << "2.�޸���ϵ���ֻ�����" << endl << endl;
			cout << "3.�޸���ϵ�˹̻�����" << endl << endl;
			cout << "4.�޸���ϵ�������ַ" << endl << endl;
			cout << "5.�޸���ϵ��QQ����" << endl << endl;
			cout << "6.�޸���ϵ����������" << endl << endl;
			cout << "0.����" << endl << endl;
			cout << "������Ҫ�޸ĵ����ݱ�ţ�";
			while( !(cin >> s) || s < 0 || s > 6 ){						//�����û����� 
				cout << endl << "�����������������룺";
				cin.clear();											//����cin��״̬��ʾ��
				cin.sync();												//�����������������
			}
			switch(s){
				case 0 : break;
				case 1 : cout << endl << "��������ϵ��������"; cin >> temp; p->data.setName(temp); p->data.setPinYin(temp); break;
				case 2 : cout << endl << "��������ϵ���ֻ����룺"; cin >> temp; p->data.setMobilePhone(temp); break;
				case 3 : cout << endl << "��������ϵ�˹̻����룺"; cin >> temp; p->data.setFixedPhone(temp); break;
				case 4 : cout << endl << "��������ϵ�������ַ��"; cin >> temp; p->data.setEmail(temp); break;
				case 5 : cout << endl << "��������ϵ��QQ���룺"; cin >> temp; p->data.setQQ(temp); break;
				case 6 : cout << endl << "��������ϵ���������룺"; cin >> temp; p->data.setZipCode(temp); break;
				default : break;
			}
			cout << endl << "�����ɹ���" << endl;
		}
	}
}

//������ϵ��
void SearchInfo(DblList<Info>& dl){
	system("cls");
	string message;
	cout << endl << "������Ҫ��������ϵ�˵��������� ƴ�� �� �ֻ����� �� �̻����� �� QQ���� �� �����ַ����";	cin >> message;
	cout << endl;
	if(dl.Search(message)){
		dl.Search(message)->data.Output();
	}
	else{
		cout << endl << "��ϵ�˲����ڣ�" << endl;
	}
	cout << endl;
	system("pause");
}

//ɾ����ϵ�� 
void RemoveInfo(DblList<Info>& dl){
	system("cls");
	string message;
	cout << endl << "������Ҫ�޸ĵ���ϵ�˵��������� ƴ�� �� �ֻ����� �� �̻����� �� QQ���� �� �����ַ����";	cin >> message;
	if(dl.Search(message)){
		char s;
		DblNode<Info> *p = dl.Search(message);
		system("cls");
		cout << endl << "��Ҫɾ��������ϵ����Ϣ" << endl;
		p->data.Output();
		cout << endl << "����Yȷ��ɾ��,����������������أ�";	cin >> s;
		if( s == 'Y' || s == 'y' ){
			dl.Remove(p);
			cout << endl << "ɾ���ɹ���" << endl << endl;
			Sleep(250);
		}
		else{
			cout << endl << "ȡ������..." << endl << endl;
			Sleep(250);
		}
	}
	else cout << endl << "��ϵ�˲����ڣ�" << endl << endl;
	Sleep(250);
}
