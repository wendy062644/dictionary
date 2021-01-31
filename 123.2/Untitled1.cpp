#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
using namespace std; //功能已完成:1,2,3,6,8,9
string word,start,ans,word2;
ofstream file;
ofstream Ch;
ofstream Set;
int choose;
int menu();int error();int test();int check();int add();int del();int help();int main();int set();int organize();int add1();//宣告副程式
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
int sett(){
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
	for(int b=1;a>b;b++)
	{
		for(int c=1;a>c;c++)
		{
			if(word1[b]==word2[c]){tem << word[c] << endl;break;}
		}
	}
	Ch.close();
	En.close();
	tem.close();
	ofstream En1("Vocabulary Quiz.txt",ios::out|ios::trunc);
	ofstream Ch1("Chinese.txt",ios::out|ios::trunc);
	fstream tem1("temporarily.txt");
	for(int b=1;a>b;b++)
	{
		En1 << word1[b] <<endl;
	}
	for(int b=1;a>b;b++)
	{
		tem1 >> word3;
		Ch1 << word3 <<endl;
	}
	Ch1.close();
	En1.close();
	tem1.close();
	menu();
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
if(choose==7){sett();}
if(choose==8){organize();}
}
int help(){
	fstream Help("Help.txt");
cout<<"====== developing... ====="<<endl;
menu();
}
int check(){
	cout<<endl;
	string Chinese[9999],Voc[9999];
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
    int point =0,n,nn=0;
    fstream sco("Highest score.txt");
    string st,ENG[9999],CHE[9999];
    sco>>n;
    cout<<"Rule: Score: One point for each question"<<endl<<"      Three chances"<<endl<<"      Highest score: "<<n<<endl<<"      Type start to start or leave"<<endl;
    cin>>st;
    while(st!="start"&&st!="Start"&&st!="START"){
        if(st=="leave"){break;}
        cout<<"      Type start or leave"<<endl;
        cin>>st;
    }
    if(st=="leave"){menu();}
    fstream EN("Vocabulary Quiz.txt");
    fstream CH("Chinese.txt");
    while(!EN.eof()){
        nn++;
        EN>>ENG[nn];
    }
    nn=0;
    while(!CH.eof()){
        nn++;
        CH>>CHE[nn];
    }
    int an=1,hea=3;
    while(an==1)
    {
        an=0;
        int que,cn;
        string ans;
        cout<<rand()<<endl;
        que= rand()%(nn-1)+1;
        cn=rand();
        if(cn%2==0){int wordnum=CHE[que].size();cout<<"Please Enter Chinese: "<<ENG[que]<<"    prompt: "<<wordnum<<" words"<<endl;}
        if(cn%2==1){int wordnum=ENG[que].size();cout<<"Please Enter English: "<<CHE[que]<<"    prompt: "<<wordnum<<" words"<<endl;}
        cin>>ans;
        if(cn%2==0){if(ans==CHE[que]){point++;cout<<"Score: "<<point<<endl;an=1;}}
        if(cn%2==1){if(ans==ENG[que]){point++;cout<<"Score: "<<point<<endl;an=1;}}
        if(an==0&&hea>0){hea--;if(hea>0){cout<<"You have "<<hea<<" chance"<<endl;an=1;}}
        if(an==0&&hea==0){cout<<"Game over. You get "<<point<<" point"<<endl;}
    }
    sco.close();
    ofstream sco2("Highest score.txt",ios::out|ios::trunc);
    if(point>n){sco2 << point <<endl ;}
    else{sco2 << n <<endl;}
    EN.close();
    CH.close();
    sco2.close();
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
	if(ans=="Yes"||ans=="yes"||ans=="YES"){add1();}
	else{menu();}
}
int add1(){add();}
