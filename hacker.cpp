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
		cout<<"�����˺ţ�"<<endl;
		cin>>name;
		char a[64]={0},b[64]={0};
		gets(a);//gets(a);��ջ�����
		if(*a!=0){
			cout<<"��������ݰ����հ��ַ���"<<endl
				<<"Ĭ�ϱ����׸��ǿ��ַ���"<<endl;
		}
		cout<<"�������룺"<<endl;
		cin>>pwd;
		gets(b);//gets(b);��ջ�����
		if(*b!=0){
			cout<<"��������ݰ����հ��ַ���"<<endl
				<<"Ĭ�ϱ����׸��ǿ��ַ���"<<endl;
		}
		if(name=="hacker"&&pwd=="123456"){
			cout<<"Welcome back, "<<name<<endl;
			system("pause");
			system("cls");
			return;
		}
		else{
			cout<<"�˺Ż���������������룡"<<endl;
			system("pause");
			system("cls");
		}
	}
}
void menuShow(){
	string menu[]={//��ָ��Ԫ�ظ�����ֱ�Ӹ���ʼֵ�������С���Զ�ʶ��
		"1.404����",	
		"2.�۸Ĺ���",
		"3.������¼",
		"4.�����޸�",
		"5.�˳�����",
	};
	//VC++2010����(win32)�£�sizeof(menu)/sizeof(menu[i])=160/32=5
	//VS2019����(X64)�£�sizeof(menu)/sizeof(menu[0])=200/40=5
	//VS2019������(X32)��sizeof(menu)/sizeof(menu[0])=140/28=5
	int menuCount=sizeof(menu)/sizeof(menu[0]);//����ѡ�����
	printInMiddle("---�ڿ͹���ϵͳ---");
	int maxLength=0;//�˵�ѡ�������
	for(int i=0;i<menuCount;i++){
		if(menu[i].length()>maxLength){
			maxLength=menu[i].length();
		}
	}
	int leftSpace=(WIDTH-maxLength)/2;
	for(int i=0;i<menuCount;i++){//�ڲ�ѭ����i��Ӱ������i
		for(int i=0;i<leftSpace;i++){//�����ڲ�ѭ��ʱ�����ѭ���ı���i����ʱʧЧ
			cout<<" ";
		}
		cout<<menu[i]<<endl;
	}
}
int menuChoose(){
	int op;
	while(true){
		cout<<"��ѡ�������"<<endl;
		cin>>op;
		if(cin.fail()){
			cin.clear();//���������
			cin.ignore();//��ջ�����
			cout<<"�����������ѡ��"<<endl;
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
	system(command);//�����ն˴�С
}
int main()
{
	initWindow();
	login();//��¼
	while(true){
		menuShow();//��ӡ�����б�
		int op=menuChoose();//ѡ�񹥻���ʽ
		system("cls");
		switch(op){
		case 1:
			printInMiddle("�ù������ڿ����У������ڴ���");
			break;
		case 2:
			printInMiddle("�ù������ڿ����У������ڴ���");
			break;
		case 3:
			printInMiddle("�ù������ڿ����У������ڴ���");
			break;
		case 4:
			printInMiddle("�ù������ڿ����У������ڴ���");
			break;
		case 5:
			return 0;
		default:
			cout<<"�����������ѡ��"<<endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}