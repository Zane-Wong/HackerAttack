#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name,pwd;
	while(true){
		cout<<"�����˻���"<<endl;
		cin>>name;
		cout<<"�������룺"<<endl;
		cin>>pwd;
		if(name=="hacker"&&pwd=="123456"){
			cout<<"Welcome back, "<<name<<endl;
			system("pause");
			system("cls");
			break;
		}
		else{
			cout<<"Wrong account or password,try aggain!"<<endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}