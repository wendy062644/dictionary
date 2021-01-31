#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <algorithm>
using namespace std;
string word,start,ans,word2;
ofstream file;
ofstream Ch;
ofstream Set;
int choose;
int menu();int error();int test();int check();int add();int del();int help();int main();int set();int organize();//宣告副程式 
int main() {
	cout<<"=====歡迎使用英文測驗====="<<endl<<"     輸入start 來開始     "<<endl;
	cin>>start;
	if(start =="start"){menu();}
	else{error();}
}
int error(){
	cout<<"**錯誤，請輸入start開始**"<<endl;
	cin>>start;
	if(start =="start"){menu();}
	else{error();}
}
int set(){
	fstream Set("Set.txt");
	cout<<"====== developing... ====="<<endl;
	menu();
}
int organize(){
	fstream Ch("Chinese.txt");
	fstream En("Vocabulary Quiz.txt");
	ofstream tem("temporarily.txt",ios::out|ios::trunc);
	string word[10000],word1[10000],word2[10000],word3;
	int a=0;
	while(!En.eof())
	{
		a++;
		Ch >> word[a];
		En >> word1[a];
		word2[a] = word1[a]; //用來和整理過的單字做對比 
	}
	sort(word1,word1+a);
	for(int b=1;a>=b;b++)
	{
		for(int c=1;a>=c;c++)
		{
			if(word1[b]==word2[c]){tem << word[c] << endl;}
		}
	}
	Ch.close();
	En.close();
	tem.close();
	ofstream En1("Vocabulary Quiz.txt",ios::out|ios::trunc);
	ofstream Ch1("Chinese.txt",ios::out|ios::trunc);
	fstream tem1("temporarily.txt");
	for(int b=1;a>=b;b++)
	{
		En1 << word1[b] <<endl;
	}
	for(int b=0;a>b;b++)
	{
		tem1 >> word3;
		Ch1 << word3 <<endl;
	}
}
int menu(){
cout<<endl;
cout<<"===========menu==========="<<endl;
cout<<"Type the number of the function you want to use."<<endl;
cout<<"1. quiz begin."<<endl;
cout<<"2. check the column of vocabulary."<<endl;
cout<<"3. add new vocabulary."<<endl;
cout<<"4. delete the vocabulary."<<endl;
cout<<"5. help."<<endl;
cout<<"6. back."<<endl;
cout<<"7. set."<<endl;
cout<<"8. organize words"<<endl;
cout<<"9. leave."<<endl;
cout<<"===========menu==========="<<endl;
cin>>choose;
if(choose==1){test();}
if(choose==2){check();}
if(choose==3){add();}
if(choose==4){del();}
if(choose==5){help();}
if(choose==6){main();}
if(choose==7){set();}
if(choose==8){organize();}
}
int help(){
	fstream Help("Help.txt");
cout<<"====== developing... ====="<<endl;
menu();
}
int check(){
	cout<<endl;
	string Chinese[99999],Voc[99999];
	fstream file("Vocabulary Quiz.txt");
	fstream Ch("Chinese.txt");
	int i=0,ii=0;
	while(!file.eof())
	{
		i++;
		file >> Voc[i];
		Ch >> Chinese[i];
	}
	cout<<"Num  Voc        Chinese"<<endl;
	while(i>1)
	{
		ii++;i--;
		cout<<" "<<std::left<<setw(4)<<ii<<std::left<<setw(10)<<Voc[ii]<<" "<<Chinese[ii]<<endl;
	}
	file.close();
	Ch.close();
	cout<<endl;
	menu();
}
int test(){
cout<<"====== developing... ====="<<endl;
menu();
}
int del(){
	cout<<"====== developing... ====="<<endl;
	fstream tem("temporarily.txt");
	fstream tem1("temporarily1.txt");
	menu();
}
int add(){
	cout<<endl;
	cout<<"Please enter new vocabulary and Chinese."<<endl;
	file.open("Vocabulary Quiz.txt", ios::app);
	Ch.open("Chinese.txt", ios::app);
	cin>>word>>word2;
	file<<word<<endl;
	Ch<<word2<<endl;
	file.close();Ch.close();
	cout<<"Continue? Yes or No."<<endl;
	cin>>ans;
	if(ans=="Yes"||ans=="yes"||ans=="YES"){add();}
	else{menu();}
}
