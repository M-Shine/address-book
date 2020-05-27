#include<iostream>
#include<string>
#include "ToPinYin.cpp"
using namespace std;
class Info{
public:
	Info(string name="NULL",string pinyin="NULL",string mobilephone="NULL",string fixedphone="NULL",string email="NULL",string qq="NULL",string zipcode="NULL"):
		Name(name),PinYin(pinyin),MobilePhone(mobilephone),FixedPhone(fixedphone),Email(email),QQ(qq),ZipCode(zipcode){}
	
	//�������� 
	void setName(string name){ Name = name; }
	//��ȡ���� 
	string getName(){ return Name; }
	
	//����������ƴ�� 
	void setPinYin(string name){ 
		string pinyin;
		unsigned char *NAME = (unsigned char *)name.c_str();
		GetPinYin(NAME,pinyin);	
		PinYin = pinyin;
	}
	//��ȡ������ƴ��
	string getPinYin(){ return PinYin; } 
	
	//�����ֻ����� 
	void setMobilePhone(string mobilephone){ MobilePhone = mobilephone; }
	//��ȡ�ֻ����� 
	string getMobilePhone(){ return MobilePhone; }
	
	//���ù̶��绰���� 
	void setFixedPhone(string fixedphone){ FixedPhone = fixedphone; }
	//��ȡ�̶��绰���� 
	string getFixedPhone(){ return FixedPhone; }
	
	//���������ַ 
	void setEmail(string email){ Email = email; }
	//��ȡ�����ַ 
	string getEmail(){ return Email; }
	
	//����QQ���� 
	void setQQ(string qq){ QQ = qq; }
	//��ȡQQ���� 
	string getQQ(){ return QQ; }
	
	//������������ 
	void setZipCode(string zipcode){ ZipCode = zipcode; }
	//��ȡ�������� 
	string getZipCode(){ return ZipCode; }
	
	void Input(){
		string name,pinyin,mobilephone,fixedphone,email,qq,zipcode;
		cout << endl;
		cout << "��������ϵ��������";	cin >> name;			Name = name;					setPinYin(name);
		cout << "�������ֻ����룺";		cin >> mobilephone;		MobilePhone = mobilephone;
		cout << "������̻����룺";		cin >> fixedphone;		FixedPhone = fixedphone;
		cout << "�����������ַ��";		cin >> email;			Email = email;
		cout << "������QQ���룺";		cin >> qq;				QQ = qq;
		cout << "�������������룺";		cin >> zipcode;			ZipCode = zipcode;
	}
	
	void Output(){
		cout << "----------------------------------" << endl;
		cout << "������" << Name << "(" << PinYin << ")" << endl;
		cout << "�ֻ����룺" << MobilePhone << endl;
		cout << "�̻����룺" << FixedPhone << endl;
		cout << "�����ַ��" << Email << endl;
		cout << "QQ���룺" << QQ << endl;
		cout << "�������룺" << ZipCode << endl;
		cout << "----------------------------------" << endl;
	}
private:
	string Name;				//���� 
	string PinYin;				//������ƴ�� 
	string MobilePhone;			//�ֻ����� 
	string FixedPhone;			//�̶��绰����
	string Email;				//�����ַ
	string QQ;					//QQ����
	string ZipCode;				//��������
};
