#include <Windows.h>
#include <hacker.h>
#include <iostream>
#include <string>
#define WIDTH 40
#define HEIGHT 15
using namespace std;
void printInMiddle(string str){
	for(int i=0;i<(WIDTH-str.length())/2;i++){
		cout<<" ";
	}
	cout<<str<<endl;
}
void login(){
	string name,pwd;
	while(true){
		cout<<"输入账号："<<endl;
		cin>>name;
		char a[64]={0},b[64]={0};
		gets(a);//gets(a);清空缓冲区
		if(*a!=0){
			cout<<"您输入了空白字符！"<<endl
				<<"空白字符及其后内容将被舍弃"<<endl;
		}
		cout<<"输入密码："<<endl;
		cin>>pwd;
		gets(b);//gets(b);清空缓冲区
		if(*b!=0){
			cout<<"您输入了空白字符！"<<endl
				<<"空白字符及其后内容将被舍弃"<<endl;
		}
		if(name=="hacker"&&pwd=="123456"){
			cout<<"Welcome back, "<<name<<endl;
			system("pause");
			system("cls");
			return;
		}
		else{
			cout<<"账号或密码错误，重新输入！"<<endl;
			system("pause");
			system("cls");
		}
	}
}
void menuShow(){
	string menu[]={//不指定元素个数，直接赋初始值，数组大小会自动识别
		"1.404攻击",	
		"2.篡改攻击",
		"3.攻击记录",
		"4.攻击修复",
		"5.退出程序",
	};
	//VC++2010环境(win32)下：sizeof(menu)/sizeof(menu[i])=160/32=5
	//VS2019环境(X64)下：sizeof(menu)/sizeof(menu[0])=200/40=5
	//VS2019环境下(X32)：sizeof(menu)/sizeof(menu[0])=140/28=5
	int menuCount=sizeof(menu)/sizeof(menu[0]);//功能选项个数
	printInMiddle("---黑客攻击系统---");
	int maxLength=0;//菜单选项最长长度
	for(int i=0;i<menuCount;i++){
		if(menu[i].length()>maxLength){
			maxLength=menu[i].length();
		}
	}
	int leftSpace=(WIDTH-maxLength)/2;
	for(int i=0;i<menuCount;i++){//内层循环的i不影响外层的i
		for(int i=0;i<leftSpace;i++){//进入内层循环时，外层循环的变量i会暂时失效
			cout<<" ";
		}
		cout<<menu[i]<<endl;
	}
}
int menuChoose(){
	int op;
	while(true){
		cout<<"请选择操作："<<endl;
		cin>>op;
		if(cin.fail()){
			cin.clear();//清除错误标记
			cin.ignore();//清空缓冲区
			cout<<"输入错误，重新选择！"<<endl;
		}
		else{
			return op;
		}
	}
	return 0;
}
void initWindow(){
	char command[128];
	sprintf_s(command,"mode con cols=%d lines=%d",WIDTH,HEIGHT);
	system(command);//设置终端大小
}
void attack404(){
	char id[64];//网站的ID
	char response[MAXSIZE];//返回结果
	string retStr="未执行";
	printInMiddle("---网站404攻击---");
	cout<<"输入要攻击的网站ID："<<endl;//2293944134
	scanf_s("%s",id,sizeof(id));
	cout<<"正在执行404攻击..."<<endl;
	hk_404(id,response);//返回值respomse为UTF-8编码格式，VC++2010默认是GBK编码
	retStr=UTF8ToGBK(response);//转换编码
	cout<<retStr<<endl;
}
void falsifyAttack(){
	string attackTEXT;
	char id[64];
	char response[MAXSIZE];
	string retStr;
	printInMiddle("---网站篡改攻击---");
	cout<<"输入要攻击的网站ID："<<endl;
	cin>>id;
	cout<<"输入要修改的内容："<<endl;
	cin>>attackTEXT;
	GBKToUTF8(attackTEXT);//将输入的文本编码格式转化为UTF-8编码格式

	//(char*)attackTEXT.c_str()将string类型强转为char*
	hk_tamper(id,(char*)attackTEXT.c_str(),response);

	retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;
}
void attackRepair(){
	char id[64];
	char response[MAXSIZE];
	string retStr;
	printInMiddle("---网站攻击修复---");
	cout<<"输入要修复的网站ID："<<endl;
	scanf_s("%s",id,sizeof(id));
	cout<<"正在执行网站攻击修复..."<<endl;
	hk_restore(id,response);
	retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;
}
void attackRecord(){
	char id[64];
	char response[MAXSIZE];
	string retStr;
	printInMiddle("---查看攻击记录---");
	cout<<"输入要攻击的网站ID："<<endl;
	cin>>id;
	cout<<"正在执行攻击记录查询..."<<endl;
	hk_record(id, response);
	retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;
}
int main()
{
	initWindow();
	login();//登录
	while(true){
		menuShow();//打印功能列表
		int op=menuChoose();//选择攻击方式
		system("cls");
		switch(op){
		case 1:
			attack404();
			break;
		case 2:
			falsifyAttack();//篡改攻击
			break;
		case 3:
			attackRecord();//攻击记录
			break;
		case 4:
			attackRepair();//攻击修复
			break;
		case 5:
			return 0;
		default:
			cout<<"输入错误，重新选择！"<<endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}