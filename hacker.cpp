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
		cout<<"�����˺ţ�"<<endl;
		cin>>name;
		char a[64]={0},b[64]={0};
		gets(a);//gets(a);��ջ�����
		if(*a!=0){
			cout<<"�������˿հ��ַ���"<<endl
				<<"�հ��ַ���������ݽ�������"<<endl;
		}
		cout<<"�������룺"<<endl;
		cin>>pwd;
		gets(b);//gets(b);��ջ�����
		if(*b!=0){
			cout<<"�������˿հ��ַ���"<<endl
				<<"�հ��ַ���������ݽ�������"<<endl;
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
	sprintf_s(command,"mode con cols=%d lines=%d",WIDTH,HEIGHT);
	system(command);//�����ն˴�С
}
void attack404(){
	char id[64];//��վ��ID
	char response[MAXSIZE];//���ؽ��
	string retStr="δִ��";
	printInMiddle("---��վ404����---");
	cout<<"����Ҫ��������վID��"<<endl;//2293944134
	scanf_s("%s",id,sizeof(id));
	cout<<"����ִ��404����..."<<endl;
	hk_404(id,response);//����ֵrespomseΪUTF-8�����ʽ��VC++2010Ĭ����GBK����
	retStr=UTF8ToGBK(response);//ת������
	cout<<retStr<<endl;
}
void falsifyAttack(){
	string attackTEXT;
	char id[64];
	char response[MAXSIZE];
	string retStr;
	printInMiddle("---��վ�۸Ĺ���---");
	cout<<"����Ҫ��������վID��"<<endl;
	cin>>id;
	cout<<"����Ҫ�޸ĵ����ݣ�"<<endl;
	cin>>attackTEXT;
	GBKToUTF8(attackTEXT);//��������ı������ʽת��ΪUTF-8�����ʽ

	//(char*)attackTEXT.c_str()��string����ǿתΪchar*
	hk_tamper(id,(char*)attackTEXT.c_str(),response);

	retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;
}
void attackRepair(){
	char id[64];
	char response[MAXSIZE];
	string retStr;
	printInMiddle("---��վ�����޸�---");
	cout<<"����Ҫ�޸�����վID��"<<endl;
	scanf_s("%s",id,sizeof(id));
	cout<<"����ִ����վ�����޸�..."<<endl;
	hk_restore(id,response);
	retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;
}
void attackRecord(){
	char id[64];
	char response[MAXSIZE];
	string retStr;
	printInMiddle("---�鿴������¼---");
	cout<<"����Ҫ��������վID��"<<endl;
	cin>>id;
	cout<<"����ִ�й�����¼��ѯ..."<<endl;
	hk_record(id, response);
	retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;
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
			attack404();
			break;
		case 2:
			falsifyAttack();//�۸Ĺ���
			break;
		case 3:
			attackRecord();//������¼
			break;
		case 4:
			attackRepair();//�����޸�
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