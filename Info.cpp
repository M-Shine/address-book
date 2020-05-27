#include<iostream>
#include<string>
#include "ToPinYin.cpp"
using namespace std;
class Info{
public:
	Info(string name="NULL",string pinyin="NULL",string mobilephone="NULL",string fixedphone="NULL",string email="NULL",string qq="NULL",string zipcode="NULL"):
		Name(name),PinYin(pinyin),MobilePhone(mobilephone),FixedPhone(fixedphone),Email(email),QQ(qq),ZipCode(zipcode){}
	
	//设置姓名 
	void setName(string name){ Name = name; }
	//获取姓名 
	string getName(){ return Name; }
	
	//设置姓名的拼音 
	void setPinYin(string name){ 
		string pinyin;
		unsigned char *NAME = (unsigned char *)name.c_str();
		GetPinYin(NAME,pinyin);	
		PinYin = pinyin;
	}
	//获取姓名的拼音
	string getPinYin(){ return PinYin; } 
	
	//设置手机号码 
	void setMobilePhone(string mobilephone){ MobilePhone = mobilephone; }
	//获取手机号码 
	string getMobilePhone(){ return MobilePhone; }
	
	//设置固定电话号码 
	void setFixedPhone(string fixedphone){ FixedPhone = fixedphone; }
	//获取固定电话号码 
	string getFixedPhone(){ return FixedPhone; }
	
	//设置邮箱地址 
	void setEmail(string email){ Email = email; }
	//获取邮箱地址 
	string getEmail(){ return Email; }
	
	//设置QQ号码 
	void setQQ(string qq){ QQ = qq; }
	//获取QQ号码 
	string getQQ(){ return QQ; }
	
	//设置邮政编码 
	void setZipCode(string zipcode){ ZipCode = zipcode; }
	//获取邮政编码 
	string getZipCode(){ return ZipCode; }
	
	void Input(){
		string name,pinyin,mobilephone,fixedphone,email,qq,zipcode;
		cout << endl;
		cout << "请输入联系人姓名：";	cin >> name;			Name = name;					setPinYin(name);
		cout << "请输入手机号码：";		cin >> mobilephone;		MobilePhone = mobilephone;
		cout << "请输入固话号码：";		cin >> fixedphone;		FixedPhone = fixedphone;
		cout << "请输入邮箱地址：";		cin >> email;			Email = email;
		cout << "请输入QQ号码：";		cin >> qq;				QQ = qq;
		cout << "请输入邮政编码：";		cin >> zipcode;			ZipCode = zipcode;
	}
	
	void Output(){
		cout << "----------------------------------" << endl;
		cout << "姓名：" << Name << "(" << PinYin << ")" << endl;
		cout << "手机号码：" << MobilePhone << endl;
		cout << "固话号码：" << FixedPhone << endl;
		cout << "邮箱地址：" << Email << endl;
		cout << "QQ号码：" << QQ << endl;
		cout << "邮政编码：" << ZipCode << endl;
		cout << "----------------------------------" << endl;
	}
private:
	string Name;				//姓名 
	string PinYin;				//姓名的拼音 
	string MobilePhone;			//手机号码 
	string FixedPhone;			//固定电话号码
	string Email;				//邮箱地址
	string QQ;					//QQ号码
	string ZipCode;				//邮政编码
};
