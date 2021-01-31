#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;
string word,start,ans,word2;
ofstream file;
ofstream Ch;
ofstream Set;
int choose;
int menu();int error();int test();int check();int add();int del();int help();int main();int set();//宣告副程式 
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
	ifstream Set("Set.txt");
	
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
cout<<"8. leave."<<endl;
cout<<"===========menu==========="<<endl;
cin>>choose;
if(choose==1){test();}
if(choose==2){check();}
if(choose==3){add();}
if(choose==4){del();}
if(choose==5){help();}
if(choose==6){main();}
}
int help(){
cout<<"====== developing... ====="<<endl;
}
int check(){
	cout<<endl;
string Chinese[99999],Voc[99999];
	ifstream file("Vocabulary Quiz.txt");
	ifstream Ch("Chinese.txt");
	int n,m;
	file >> n;
	Ch >> m;
	for(int ii = 0;n > ii;ii++)
	{
		file >> Voc[ii];
		Ch >> Chinese[ii];
	}
	for(int i = 0;n > i;i++)
	{
		cout<<std::left<<setw(4)<<i<<std::left<<setw(10)<<Voc[i]<<" "<<Chinese[i]<<endl;
	}
	file.close();
	Ch.close();
	cout<<endl;
	menu();
}
int test(){
cout<<"====== developing... ====="<<endl;
}
int del(){
	string Chinese[99999],Voc[99999];
	ifstream file("Vocabulary Quiz.txt");
	ifstream Ch("Chinese.txt");
	int n,m;
	file >> n;
	Ch >> m;
	for(int ii = 0;n > ii;ii++)
	{
		file >> Voc[ii];
		Ch >> Chinese[ii];
	}
	for(int i = 0;n > i;i++)
	{
		cout<<std::left<<setw(4)<<i<<std::left<<setw(10)<<Voc[i]<<" "<<Chinese[i]<<endl;
	}
}
int add(){
	cout<<endl;
	cout<<"Please enter new vocabulary and Chinese."<<endl;
	file.open("Vocabulary Quiz.txt", ios::app);
	Ch.open("Chinese.txt", ios::app);
	cin>>word>>word2;
	file<<word;
	Ch<<word2;
	int n=0,m=0;
	fstream file("Vocabulary Quiz.txt");
	fstream Ch("Chinese.txt");
	file >> n; //紀錄英文單字數量 
	Ch >> m; //紀錄中文單字數量
	file.close();Ch.close();
	n++; m++;
	string line,line2;
	int nn=0,mm=0;
	fstream file1("Vocabulary Quiz.txt");
	fstream outfile("temporarily.txt",ios::out|ios::trunc);
	while(!file1.eof())
	{
		getline(file1,line);
		if(nn!=0){outfile<<line<<endl;}
		else{outfile<<n<<endl;}
		nn++;
	}
	file1.close(); outfile.close();
	ofstream outfile1("Vocabulary Quiz.txt",ios::out|ios::trunc);
	fstream file2("temporarily.txt");
	while(!file2.eof())
	{
		getline(file2,line);
		outfile1<<line<<endl;
	}
	file2.close(); outfile1.close();
	fstream file3("Chinese.txt");
	fstream outfile2("temporarily1.txt",ios::out|ios::trunc);
	while(!file3.eof())
	{
		getline(file3,line);
		if(mm!=0){outfile2<<line<<endl;}
		else{outfile2<<m<<endl;}
		mm++;
	}
	file3.close(); outfile2.close();
	ofstream outfile3("Chinese.txt",ios::out|ios::trunc);
	fstream file4("temporarily1.txt");
	while(!file4.eof())
	{
		getline(file4,line);
		outfile3<<line<<endl;
	}
	file4.close(); outfile3.close();
	cout<<"Continue? Yes or No."<<endl;
	cin>>ans;
	if(ans=="Yes"||ans=="yes"||ans=="YES"){add();}
	else{menu();}
}
