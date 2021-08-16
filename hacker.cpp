#include <iostream>
#include <string>
#include <Windows.h>
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
			cout<<"输入的内容包含空白字符！"<<endl
				<<"默认保留首个非空字符串"<<endl;
		}
		cout<<"输入密码："<<endl;
		cin>>pwd;
		gets(b);//gets(b);清空缓冲区
		if(*b!=0){
			cout<<"输入的内容包含空白字符！"<<endl
				<<"默认保留首个非空字符串"<<endl;
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
	sprintf(command,"mode con cols=%d lines=%d",WIDTH,HEIGHT);
	system(command);//设置终端大小
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
			printInMiddle("该功能正在开发中，敬请期待！");
			break;
		case 2:
			printInMiddle("该功能正在开发中，敬请期待！");
			break;
		case 3:
			printInMiddle("该功能正在开发中，敬请期待！");
			break;
		case 4:
			printInMiddle("该功能正在开发中，敬请期待！");
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