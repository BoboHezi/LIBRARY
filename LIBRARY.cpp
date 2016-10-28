#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<conio.h>
#include<time.h>
using namespace std;
#define maxbooks 5000
#define maxuses 10000
/////////////////////////////////////结构体//////////////////////////////////////
typedef struct
{
	int number;
	time_t brotime;
	time_t rtntime;
}BORROW_B;

typedef struct
{
	int BRONUM;
	BORROW_B BOR[10000];
}BRORECODER;

typedef struct  
{
	int year;
	int mounth;
	int day;
}Time;

typedef struct          //书籍
{
	int Number;         //编号
	string Name;        //书名
	string Author;      //作者
	string ISBN;        //ISBN
	string Publisher;   //出版社
	float price;        //价格
	int borrow;         //是否借出
	Time T;             //出版时间
	BRORECODER BROCO;     //借出记录
}BOOK;

typedef struct     //图书馆书籍
{
	BOOK Book[maxbooks];
	int length;
}LibrarySystem;

typedef struct
{
	int number;
	time_t brotime;
	time_t rtntime;
}BORROW_U;

typedef struct
{
	int BRONUM;
	BORROW_U BOR[10000];
}BORRECODER;

typedef struct         //用户
{
	int num;
	string code;
	int br[6];
	int brnum;
	BORRECODER BROCO;
}USE;

typedef struct      //图书馆用户
{
	USE Use[maxuses];
	int length;
}UseSystem;
/////////////////////////////////////结构体/////////////////////////////////////
/***********************************文件函数************************************/
void Savetimeforbook(LibrarySystem &B)
{
	int b,t;
	ofstream fout("Time recoder for books");
	for(b=1;b<=B.length;b++)
	{
		fout<<B.Book[b].BROCO.BRONUM<<" ";
		for(t=1;t<=B.Book[b].BROCO.BRONUM;t++)
		{
			fout<<B.Book[b].BROCO.BOR[t].brotime<<" ";
			fout<<B.Book[b].BROCO.BOR[t].rtntime<<" ";
			fout<<B.Book[b].BROCO.BOR[t].number<<" ";
		}
		fout<<endl;
	}
}

void Savetimeforuse(UseSystem &U)
{
	int u,t;
	ofstream fout("Time recoder for uses");
	for(u=1;u<=U.length;u++)
	{
		fout<<U.Use[u].BROCO.BRONUM<<" ";
		for(t=1;t<=U.Use[u].BROCO.BRONUM;t++)
		{
			fout<<U.Use[u].BROCO.BOR[t].brotime<<" ";
			fout<<U.Use[u].BROCO.BOR[t].rtntime<<" ";
			fout<<U.Use[u].BROCO.BOR[t].number<<" ";
		}
		fout<<endl;
	}
}

void Savebook(LibrarySystem &B)
{
	int i;
	ofstream fout;
	fout.open("Book");
	for(i=1;i<=B.length;i++)
	{
		fout<<B.Book[i].Author<<" ";
		fout<<B.Book[i].borrow<<" ";
		fout<<B.Book[i].ISBN<<" ";
		fout<<B.Book[i].Name<<" ";
		fout<<B.Book[i].Number<<" ";
		fout<<B.Book[i].price<<" ";
		fout<<B.Book[i].Publisher<<" ";
		fout<<B.Book[i].T.day<<" ";
		fout<<B.Book[i].T.mounth<<" ";
		fout<<B.Book[i].T.year<<endl;
	}
	fout<<flush;fout.close();
}
void Saveuse(UseSystem &U)
{
	int i,j;
	ofstream fout("Use");
	for(i=1;i<=U.length;i++)
	{
		fout<<U.Use[i].num<<" ";
		fout<<U.Use[i].code<<" ";
		if(U.Use[i].brnum==0)
			fout<<U.Use[i].brnum<<endl;
		else
			fout<<U.Use[i].brnum<<" ";
		for(j=1;j<=U.Use[i].brnum;j++)
		{
			fout<<U.Use[i].br[j];
			if(j==U.Use[i].brnum)
				fout<<endl;
			else
				fout<<" ";
		}
	}
	fout<<flush;fout.close();
}
void Savenumber(LibrarySystem &B,UseSystem &U)
{
	ofstream fout("number");
	fout<<B.length<<" "<<U.length;
	fout<<flush;fout.close();
}
void Readbook(LibrarySystem &B)
{
	int i;
	ifstream fin("Book");
	for(i=1;i<=B.length;i++)
	{
		fin>>B.Book[i].Author;
		fin>>B.Book[i].borrow;
		fin>>B.Book[i].ISBN;
		fin>>B.Book[i].Name;
		fin>>B.Book[i].Number;
		fin>>B.Book[i].price;
		fin>>B.Book[i].Publisher;
		fin>>B.Book[i].T.day;
		fin>>B.Book[i].T.mounth;
		fin>>B.Book[i].T.year;
	}
}
void Readuse(UseSystem &U)
{
	int i,j;
	ifstream fin("Use");
	for(i=1;i<=U.length;i++)
	{
		fin>>U.Use[i].num;
		fin>>U.Use[i].code;
		fin>>U.Use[i].brnum;
		for(j=1;j<=U.Use[i].brnum;j++)
			fin>>U.Use[i].br[j];
	}
}
void Readnumber(LibrarySystem &B,UseSystem &U)
{
	ifstream fin("number");
	fin>>B.length>>U.length;
}
void Readtimeforbook(LibrarySystem &B)
{
	int b,t;
	ifstream fin("Time recoder for books");
	for(b=1;b<=B.length;b++)
	{
		fin>>B.Book[b].BROCO.BRONUM;
		for(t=1;t<=B.Book[b].BROCO.BRONUM;t++)
		{
			fin>>B.Book[b].BROCO.BOR[t].brotime;
			fin>>B.Book[b].BROCO.BOR[t].rtntime;
			fin>>B.Book[b].BROCO.BOR[t].number;
		}
	}	
}
void Readtimeforuse(UseSystem &U)
{
	int u,t;
	ifstream fin("Time recoder for uses");
	for(u=1;u<=U.length;u++)
	{
		fin>>U.Use[u].BROCO.BRONUM;
		for(t=1;t<=U.Use[u].BROCO.BRONUM;t++)
		{
			fin>>U.Use[u].BROCO.BOR[t].brotime;
			fin>>U.Use[u].BROCO.BOR[t].rtntime;
			fin>>U.Use[u].BROCO.BOR[t].number;
		}
	}
}
/***********************************文件函数************************************/
void rtntimerco(LibrarySystem &B,UseSystem &U,int b,int u)
{
	long rtntime;
	int num;
	rtntime=time(NULL);
	num=B.Book[b].BROCO.BRONUM;
	B.Book[b].BROCO.BOR[num].rtntime=rtntime;
	num=U.Use[u].BROCO.BRONUM;
	U.Use[u].BROCO.BOR[num].rtntime=rtntime;
}
/************************************主页面*************************************/
int Homepage()
{
	int m;
	system("cls");
	for(;;)
	{
		cout<<"                                   主菜单\n\n";
		cout<<"                             1-以管理员进入系统\n\n";
		cout<<"                              2-以用户进入系统\n\n";
		cout<<"                                 3-退出系统\n\n";
		cout<<"                                     ";
		cin>>m;
		if(m==1||m==2||m==3)
		{
			return m;
			break;
		}
		else
		{
			cout<<"                            输入有误！";
			Sleep(1000);
		}
	}
}
/************************************主页面*************************************/
/**********************************管理员页面***********************************/
int Adm()
{
	int m;
	char in;
	system("cls");
	for(;;)
	{
		system("cls");
	    cout<<"                                   管理员页面\n\n";
		cout<<"                                   1-增加图书\n\n";
		cout<<"                                   2-删减图书\n\n";
		cout<<"                                 3-修改图书信息\n\n";
		cout<<"                                   4-读者管理\n\n";
		cout<<"                                   5-图书查询\n\n";
		cout<<"                                 6-修改登录密码\n\n";
		cout<<"                                  7-返回主菜单\n\n";
		cout<<"                                       ";
		cin>>in;
		if(in=='1'||in=='2'||in=='3'||in=='4'||in=='5'||in=='6'||in=='7')
		{
			m=in-48;
			break;
		}
		else
		{
			cout<<endl<<"                              输入有误！";
			Sleep(2000);
		}
	}
	return m;
}
/**********************************管理员页面***********************************/
void Information(LibrarySystem &B,UseSystem &U,int i)
{
	int j;
	cout<<"                              编  号："<<B.Book[i].Number<<endl;
	cout<<"                              书  名："<<B.Book[i].Name<<endl;
	cout<<"                              作  者："<<B.Book[i].Author<<endl;
	cout<<"                              IS  BN："<<B.Book[i].ISBN<<endl;
	cout<<"                              出版社："<<B.Book[i].Publisher<<endl;
	cout<<"                              价  格："<<B.Book[i].price<<"元"<<endl;
	cout<<"                              版  次："<<B.Book[i].T.year<<" 年 "<<B.Book[i].T.mounth<<" 月 第"<<B.Book[i].T.day<<" 版"<<endl<<endl;
	if(B.Book[i].borrow==0)
		cout<<"                              尚未借出"<<endl<<endl;
	else
	{
		j=B.Book[i].borrow;
		cout<<"                              已被用户"<<U.Use[j].num<<"借出"<<endl<<endl;
	}
	cout<<"                              借出记录：共借出"<<B.Book[i].BROCO.BRONUM<<"次"<<endl;
	for(j=1;j<=B.Book[i].BROCO.BRONUM;j++)
	{
		cout<<"                              ********************"<<endl;
		struct tm*local;
    	local=localtime(&B.Book[i].BROCO.BOR[j].brotime);
		int n=B.Book[i].BROCO.BOR[j].number;
		cout<<"                              借书用户："<<U.Use[n].num<<endl;
		cout<<"                              借书时间："<<local->tm_year+1900<<"-"<<local->tm_mon+1<<"-"<<local->tm_mday<<endl;
		local=localtime(&B.Book[i].BROCO.BOR[j].rtntime);
		cout<<"                              还书时间：";
		if(B.Book[i].BROCO.BOR[j].rtntime==0)
		{
			cout<<"—"<<endl;
			break;
		}
		cout<<local->tm_year+1900<<"-"<<local->tm_mon+1<<"-"<<local->tm_mday<<endl;
	}
	cout<<"  ****************************************************************************"<<endl;
}
/***********************************用户函数************************************/
int Uselogin(UseSystem &U,int Exp)
{
	ifstream fin("Expri");
	fin>>Exp;
	if(Exp)
		return Exp;
	int usenum,m=0,n,i;
	char j;
	string mima;
	for(;;)
	{
		system("cls");
	    cout<<"                                   用户登录"<<endl<<endl;
		cout<<"                             输入用户号码：";
		cin>>usenum;
		for(n=1;n<=U.length;n++)
		{
			if(U.Use[n].num==usenum)
				m=n;
		}
		if(m)
		{
			for(i=1;i<=3;i++)
			{
				system("cls");
				cout<<"                                   用户登录"<<endl<<endl;
				cout<<"                             输入用户号码："<<U.Use[m].num<<endl<<endl;
				cout<<"                                 输入密码：";
			    cin>>mima;
		        if(U.Use[m].code==mima)
				{
			    	ofstream fout;
	                fout.open("Expri");
			    	fout<<m;
					return m;
				}
			    else
				{
					if(i!=3)
					{
						cout<<endl<<"                             密码输入有误！你还有"<<3-i<<"次机会。"<<endl;
				    	Sleep(2000);
					}
					else
					{
						cout<<endl<<"                             密码输入三次有误！"<<endl;
						Sleep(4000);
						return 0;
					}
				}
				continue;
			}
		}
		else
		{
			system("cls");
		    cout<<"                             不存在该用户！"<<endl<<endl;
			cout<<"                             1-重新输入"<<endl<<endl<<"                             任意键返回"<<endl;
			cout<<"                             ";
			cin>>j;
			if(j=='1')
				continue;
			else
				break;
		}		
	}
	ofstream fout;
	fout.open("Expri");
	fout<<m;

	return m;
}
void brotimerco(LibrarySystem &B,UseSystem &U,int b,int u)
{
	long brotime;
	int i;
	brotime=time(NULL);
	i=B.Book[b].BROCO.BRONUM;
	B.Book[b].BROCO.BOR[i+1].brotime=brotime;
	B.Book[b].BROCO.BOR[i+1].number=u;
	B.Book[b].BROCO.BOR[i+1].rtntime=0;
	i=U.Use[u].BROCO.BRONUM;
	U.Use[u].BROCO.BOR[i+1].brotime=brotime;
	U.Use[u].BROCO.BOR[i+1].number=b;
	U.Use[u].BROCO.BOR[i+1].rtntime=0;
	B.Book[b].BROCO.BRONUM++;
	U.Use[u].BROCO.BRONUM++;
}

int useSearch(LibrarySystem &B,UseSystem &U,int i)       //寻找图书
{
	int j,n,num;
	char m,in;
	string NAME;
	string Isbn;
	for(;;)
	{
		system("cls");
	    cout<<"                                   查找图书："<<endl<<endl;
        cout<<"                                 1-以编号查找"<<endl<<endl;
        cout<<"                                 2-以书名查找"<<endl<<endl;
        cout<<"                                 3-以ISBN查找"<<endl<<endl;
    	cout<<"                                    4-退出"<<endl;
    	cout<<"                                      ";
        cin>>m;
        if(m=='1')
		{
			for(;;)
			{
				n=0;
				system("cls");
				cout<<"                                 输入编号:";
				cin>>num;
				for(j=1;j<=B.length;j++)
					if(B.Book[j].Number==num)
					{
						n=j;
						break;
					}
				if(n!=0)
					break;
				system("cls");
				cout<<endl<<"                                 ";
				cout<<"未找到书籍！"<<endl<<endl;				
			    cout<<"                                 ";
			   	cout<<"  1-退出"<<endl<<endl;								
	    	 	cout<<"                                 ";
		   		cout<<"2-继续查找"<<endl;
		   		cout<<"                                     ";
		       	cin>>in;
		   	    if(j=='1')
					break;
		    	else
					continue;
			}
		}
	    if(m=='2')
		{
			for(;;)
			{
				system("cls");
		        cout<<"                                 输入书名：";
		    	cin>>NAME;
		        for(j=1;j<=B.length;j++)
					if(B.Book[j].Name==NAME)
					{
						n=j;
						break;
					}
				system("cls");	
			    cout<<endl<<"                                 ";
			   	cout<<"未找到书籍！"<<endl<<endl;				
		   		cout<<"                                 ";
		   		cout<<"  1-退出"<<endl<<endl;								
		    	cout<<"                                 ";
		    	cout<<"2-继续查找"<<endl;
			   	cout<<"                                     ";
		       	cin>>in;
				n=0;
		   	    if(in=='1')
					break;
			    else
				    continue;
			}
		}
	    if(m=='3')
		{
			for(;;)
			{
				system("cls");
		    	cout<<"                                 输入ISBN：";
			    cin>>Isbn;
				for(j=1;j<=B.length;j++)
					if(B.Book[j].ISBN==Isbn)
					{
						n=j;
						break;
					}
				system("cls");
				cout<<endl<<"                                 ";
			    cout<<"未找到书籍！"<<endl<<endl;				
			    cout<<"                                 ";
			    cout<<"  1-退出"<<endl<<endl;								
		        cout<<"                                 ";
			    cout<<"2-继续查找"<<endl;
			    cout<<"                                     ";
		       	cin>>in;
				n=0;
		   	    if(in=='1')
					break;
			    else
				    continue;		
			}
		}
    	if(m=='4')
			return 0;
		if(m!='1'&&m!='2'&&m!='3'&&m!='4')
		{
			cout<<"                             输入有误！请重新输入。";
		    Sleep(2000);
		    continue;
		}
		system("cls");
		Information(B,U,j);
		if(B.Book[j].borrow==0)
		{
			cout<<"                                 1-借阅"<<endl;
			cout<<"                                 任意键返回"<<endl;
			cout<<"                                 ";
			cin>>in;
			if(in=='1')
			{
				system("cls");
				int bn=U.Use[i].brnum;
				if(bn==5)
				{
					cout<<"                             对不起！您再借图书已满。无法继续借阅。"<<endl;
						Sleep(3000);
					return 0;
				}
				B.Book[j].borrow=i;
				U.Use[i].br[bn+1]=j;
				U.Use[i].brnum++;
				time_t returntime;
				returntime=time(NULL);
				returntime+=2592000;
				struct tm*local;
				local=localtime(&returntime);
				brotimerco(B,U,j,i);
				Savebook(B);
                Saveuse(U);
				Savetimeforbook(B);
				Savetimeforuse(U);
				cout<<"                                 借阅成功！请于"<<local->tm_year+1900<<"年"<<local->tm_mon+1<<"月"<<local->tm_mday<<"日前归还。";
				Sleep(3000);
				continue;
			}
			else
				continue;
		}
		else
		{
			cout<<"                                 1-继续查找"<<endl;
			cout<<"                                 任意键取消"<<endl;
			cout<<"                                      ";
			cin>>i;
			if(i==1)
				continue;
			else
				break;
		}
     }
	return 0;
}
void huanshu(LibrarySystem &B,UseSystem &U,int i)
{
	int numb;
	char in;
	for(;;)
	{
		system("cls");
		if(U.Use[i].brnum)
		{
			cout<<"                                您有"<<U.Use[i].brnum<<"本书再借："<<endl<<endl;
        	for(int j=1;j<=U.Use[i].brnum;j++)
			{
	        	int nu=U.Use[i].br[j];
	        	cout<<"                                编号为："<<B.Book[nu].Number<<endl<<endl;
			}
        	cout<<"                                输入要归还的编号：";
        	cin>>numb;
    	    for(j=1;j<=B.length;j++)
			{
	        	if(numb==B.Book[j].Number)
				{
		        	B.Book[j].borrow=0;
		        	break;
				}
			}
	    	for(int n=1;n<=U.Use[i].brnum;n++)
		    	if(U.Use[i].br[n]==j)
				    break;
	    	for(int m=n;m<=U.Use[i].brnum-1;m++)
		    	U.Use[i].br[m]=U.Use[i].br[m+1];

	    	U.Use[i].brnum--;
			rtntimerco(B,U,j,i);

	        system("cls");
	        cout<<"                                还书成功！"<<endl<<endl;
        	if(U.Use[i].brnum)
			{
	        	cout<<"                                1-继续还书"<<endl<<endl;
	         	cout<<"                                任意键返回"<<endl<<endl;
	        	cout<<"                                ";
	        	cin>>in;
		        if(in=='1')
		    	    continue;
	        	else
		        	break;
			}
		}
		else
		{
			cout<<endl<<"                            您目前没有再借图书！3秒后自动返回。";
			Sleep(3000);
			break;
		}
	}
}
void coderevise(UseSystem &U,int i)
{
	string oldcode,newcode1,newcode2;
	char j;
	for(;;)
	{
		system("cls");
		cout<<"                                输入原始密码：";
		cin>>oldcode;
		if(U.Use[i].code==oldcode)
		{
			system("cls");
			cout<<"                                输入新密码：";
			cin>>newcode1;
			system("cls");
			cout<<endl<<"                        输入新密码确认修改：";
			cin>>newcode2;
			if(newcode1==newcode2)
			{
				U.Use[i].code=newcode1;
				cout<<endl<<"                                修改完成！请牢记此密码。"<<endl;
                Saveuse(U);
				Sleep(3000);
				break;
			}
			else
			{
				system("cls");
				cout<<"                                密码错误！"<<endl<<endl;
				cout<<"                                1-继续修改"<<endl<<endl;
				cout<<"                                任意键返回"<<endl<<endl;
				cout<<"                                ";
				cin>>j;
				if(j=='1')
					continue;
				else
					break;
			}
		}
    	else
		{
			system("cls");
			cout<<"                                原始密码输入有误！"<<endl<<endl;
			cout<<"                                1-重新输入"<<endl<<endl;
			cout<<"                                任意键返回"<<endl<<endl;
			cin>>j;
			if(j=='1')
				continue;
			else
				break;
		}
	}
}
int usepage(LibrarySystem &B,UseSystem &U,int Exp)
{
	int n=0;
	char j;
	for(;;)
	{
		if(n==0)
		{
			n=Uselogin(U,Exp);
			if(n==0)
				return 0;
		}
		else
		{
			system("cls");
	    	cout<<"                                用户："<<U.Use[n].num;
    		cout<<"  欢迎进入图书馆！"<<endl<<endl;
    		cout<<"                                1-还书"<<endl<<endl;
 		   	cout<<"                                2-借书"<<endl<<endl;
    		cout<<"                                3-修改密码"<<endl<<endl;
	    	cout<<"                                4-退出用户系统"<<endl<<endl;
			cout<<"                                5-退出登录"<<endl<<endl;
			cout<<"                                ";
			cin>>j;
			if(j=='1')
			{
				huanshu(B,U,n);
				continue;
			}
			if(j=='2')
			{
				useSearch(B,U,n);
				continue;
			}
			if(j=='3')
			{
				coderevise(U,n);
				continue;
			}
			if(j=='4')
				return 0;
			if(j=='5')
			{
				n=0;
				ofstream fout;
				fout.open("Expri");
				fout<<n;
				continue;
			}
		}
	}
}
/***********************************用户函数************************************/
/***********************************图书函数************************************/
int Searchbook(LibrarySystem &B,UseSystem &U)       //寻找图书
{
	int n=0,j,num,book[maxbooks];
	char in;
	string NAME;
	string Isbn;
	for(;;)
	{
		system("cls");      //清屏
	    cout<<"                                   查找图书："<<endl<<endl;
        cout<<"                                 1-以编号查找"<<endl<<endl;
        cout<<"                                 2-以书名查找"<<endl<<endl;
        cout<<"                                 3-以ISBN查找"<<endl<<endl;
    	cout<<"                                    4-退出"<<endl;
    	cout<<"                                      ";
        cin>>in;
        if(in=='1')
		{
			for(;;)
			{
				system("cls");
				cout<<"                                 输入编号:";
				cin>>num;
				for(j=1;j<=B.length;j++)
				{
					if(B.Book[j].Number==num)
					{
						n=j;
						break;
					}
				}
				if(n==0)
				{ 
					cout<<endl<<"                                 ";
				    cout<<"未找到书籍！"<<endl<<endl;				
				    cout<<"                                 ";
			    	cout<<"  1-退出"<<endl<<endl;								
	    		 	cout<<"                                 ";
		    		cout<<"任意键继续"<<endl;
		    		cout<<"                                     ";
		        	cin>>in;
					n=0;
		    	    if(in=='1')
						break;
			    	else
						continue;
				}
				else
				{
					system("cls");
					Information(B,U,n);
				    cout<<endl<<"                                 ";
			    	cout<<"1-退出"<<endl<<endl;								
	    		 	cout<<"                                 ";
		    		cout<<"任意键继续"<<endl;
		    		cout<<"                                     ";
		        	cin>>in;
					n=0;
					if(in=='1')
						break;
					else
						continue;
				}
			}
		}
	    if(in=='2')
		{
			for(;;)
			{
				system("cls");
		        cout<<"                                 输入书名：";
		    	cin>>NAME;
		        for(j=1;j<=B.length;j++)
				{
					if(B.Book[j].Name==NAME)
					{
						n++;
						book[n]=j;
						continue;
					}
				}
				if(n==0)
				{
				    cout<<endl<<"                                 ";
			    	cout<<"未找到书籍！"<<endl<<endl;				
		    		cout<<"                                 ";
		    		cout<<"  1-退出"<<endl<<endl;								
			    	cout<<"                                 ";
			    	cout<<"任意键继续"<<endl;
			    	cout<<"                                     ";
		        	cin>>in;
					n=0;
		    	    if(in=='1')
						break;
				    else
					    continue;
				}
				else
				{
					system("cls");
					for(j=1;j<=n;j++)
						Information(B,U,book[j]);
				    cout<<endl<<"                                 ";
			    	cout<<"1-退出"<<endl<<endl;								
	    		 	cout<<"                                 ";
		    		cout<<"任意键继续"<<endl;
		    		cout<<"                                     ";
		        	cin>>in;
					n=0;
					if(in=='1')
						break;
					else
						continue;
				}
			}
		}
	    if(in=='3')
		{
			for(;;)
			{
				system("cls");
		    	cout<<"                                 输入ISBN：";
			    cin>>Isbn;
		        for(j=1;j<=B.length;j++)
				{
					if(B.Book[j].ISBN==Isbn)
					{
						n=j;
					    break;
					}
				}
				if(n==0)
				{
					cout<<endl<<"                                 ";
				    cout<<"未找到书籍！"<<endl<<endl;				
				    cout<<"                                 ";
				    cout<<"  1-退出"<<endl<<endl;								
				    cout<<"                                 ";
				    cout<<"任意键继续"<<endl;
				    cout<<"                                     ";
		        	cin>>in;
					n=0;
		    	    if(in=='1')
						break;
				    else
					    continue;
				}
				else
				{
					system("cls");
					Information(B,U,n);
				    cout<<endl<<"                                 ";
			    	cout<<"1-退出"<<endl<<endl;								
	    		 	cout<<"                                 ";
		    		cout<<"任意键继续"<<endl;
		    		cout<<"                                     ";
		        	cin>>in;
					n=0;
					if(in=='1')
						break;
					else
						continue;
				}
			}
		}
    	if(in=='4')
			return 0;
		if(in!='1'&&in!='2'&&in!='3'&&in!='4')
		{
			cout<<"                             输入有误！请重新输入。";
		    Sleep(2000);
		    continue;
		}
}
	return n;
}
void useInformation(LibrarySystem &B,UseSystem &U,int i)
{
	system("cls");
	cout<<"                               ";
	cout<<"用户编号："<<U.Use[i].num<<endl<<endl;
	cout<<"                                   ";
	cout<<"密码："<<U.Use[i].code<<endl<<endl;
	cout<<"                             ";
	if(U.Use[i].brnum==0)
	{
		cout<<"该用户尚无再借图书！"<<endl;
		cout<<"                        ";
	}
	else
	{
		cout<<"  再借书目：";
		for(int j=1;j<=U.Use[i].brnum;j++)
		{
			int num;
			num=U.Use[i].br[j];
			cout<<B.Book[num].Name<<endl<<endl;
			if(j==U.Use[i].brnum)
			{
				cout<<"                          ";
				continue;
			}
			cout<<"                                         ";
		}
	}
	cout<<"*******************************"<<endl;
}
int Readersearch(UseSystem &U)
{
	int m,usenum;
	char n;
	if(U.length!=0)
	{
		for(;;)
		{
	        system("cls");
	    	cout<<"                           ";
	    	cout<<"输入要查询读者号码：";
	        cin>>usenum;
        	for(m=1;m<=U.length;m++)
			{
				if(U.Use[m].num==usenum)
				    return m;
			}
		    cout<<endl<<"                           ";
	    	cout<<"系统不存在该用户！"<<endl<<endl;
	    	cout<<"                           ";
	    	cout<<"1-重新输入"<<endl<<endl;
	    	cout<<"                           ";
	    	cout<<"任意键返回用户管理页面"<<endl<<endl;		
	    	cout<<"                           ";
	    	cin>>n;
	    	if(n=='1')
	    		continue;
	    	else
		    	return 0;
		}
	}
	else
	{
		system("cls");
		cout<<"                               ";
		cout<<"系统尚无用户！2秒后自动退出。";
		Sleep(2000);
		return 0;
	}
}
void Readerincrease(LibrarySystem &B,UseSystem &U)
{
	system("cls");
	int m,n,usenum;
	string CO;
	char i;
	for(;;)
	{
		if(U.length==10000)
		{
			cout<<"                               ";
			cout<<"图书馆用户已满！"<<endl;
			Sleep(2000);
			return;
		}
	    if(U.length!=10000)
		{
			for(;;)
			{
				n=0;
				system("cls");
				cout<<"                                  ";
				cout<<" 输入增加读者号：";
			    cin>>usenum;
				for(m=1;m<=U.length;m++)
				{
					if(U.Use[m].num==usenum)
					{
						n=1;
						break;
					}
				}
				if(n)
				{
					cout<<endl<<"                                   ";
					cout<<"该用户已存在！2秒后自动返回。"<<endl;
					Sleep(2000);
					continue;
				}
				else
					break;
			}
			cout<<"                               ";
			cout<<"输入用户"<<usenum<<"的密码：";
			cin>>CO;
			system("cls");
			cout<<"                               ";
			cout<<"用户编号："<<usenum<<endl<<endl;
			cout<<"                                   ";
			cout<<"密码："<<CO<<endl<<endl;
			cout<<"                                 ";
			cout<<"1-保存"<<endl<<endl;
			cout<<"                             ";
			cout<<"任意键取消"<<endl;
			cout<<"                                      ";
			cin>>i;
			if(i=='1')
			{
				system("cls");
				U.Use[U.length+1].num=usenum;
				U.Use[U.length+1].code=CO;
				U.length++;
				cout<<"                               ";
				cout<<"保存成功！"<<endl<<endl;
                Saveuse(U);
                Savenumber(B,U);
				cout<<"                               ";
				cout<<"1-继续录入"<<endl<<endl;
				cout<<"                               ";
				cout<<"任意键返回用户管理页面"<<endl;
				cout<<"                               ";
				cin>>i;
				if(i=='1')
					continue;
				else
					break;
			}
			else
				continue;
		}
	}
}
void Readerdelete(LibrarySystem &B,UseSystem &U)
{
	int usenum,i,j;
	char m,n;
	for(;;)
	{
		j=0;
		system("cls");
		if(U.length==0)
		{
	    	cout<<"                               ";
			cout<<"系统中尚无用户！2秒后返回。"<<endl;
			Sleep(2000);
	    	return;
		}
    	else
		{
			cout<<"                               ";
			cout<<"输入要删除用户的编号：";
			cin>>usenum;
			for(i=1;i<=U.length;i++)
				if(U.Use[i].num==usenum)
				{
					j=i;
					break;
				}
			if(U.Use[j].brnum!=0)
			{
				system("cls");
				cout<<endl<<"                               ";
				cout<<"该用户尚有未还图书。无法删除！";
				Sleep(3000);
				continue;
			}
			if(j!=0)
			{
				useInformation(B,U,i);
		    	cout<<"                               ";
				cout<<"1-确认删除"<<endl<<endl;
				cout<<"                               ";
				cout<<"2-取消"<<endl<<endl;
				cout<<"                               ";
				cout<<"任意键返回用户管理页面"<<endl;
				cout<<"                               ";
		    	cin>>m;
		     	if(m=='1')
				{
			    	system("cls");
			    	for(j=i;j<U.length;j++)
					{
			    		U.Use[j].num=U.Use[j+1].num;
			    		U.Use[j].code=U.Use[j+1].code;
					}
			    	U.length--;
                    Saveuse(U);
                    Savenumber(B,U);
			    	cout<<"                               ";
					cout<<"删除成功！"<<endl<<endl;
					cout<<"                               ";
					cout<<"1-继续删除"<<endl<<endl;
					cout<<"                               ";
					cout<<"任意键退出"<<endl;
					cout<<"                               ";
			    	cin>>n;
			    	if(n=='1')
						continue;
				    else
					    break;
				}
			    if(m=='2')
					continue;
				else
					break;
			}
			else
			{
				cout<<endl<<"                               ";
				cout<<"未找到该用户"<<endl<<endl;
				cout<<"                               ";
				cout<<"1-重新输入"<<endl<<endl;
				cout<<"                               ";
				cout<<"任意键返回用户管理页面"<<endl;
				cout<<"                               ";
				cin>>n;
				if(n=='1')
					continue;
				else
					break;
			}
		}
	}
}
void Readermanage(LibrarySystem &B,UseSystem &U)
{
	char c,i;
	for(;;)
	{
		system("cls");
		cout<<"                               用户管理"<<endl<<endl;
		cout<<"                               1-查找读者"<<endl<<endl;
		cout<<"                               2-增加读者"<<endl<<endl;
		cout<<"                               3-删减读者"<<endl<<endl;
		cout<<"                               4-退出用户管理"<<endl;
		cout<<"                               ";
		cin>>c;
		if(c=='1')
		{
			i=Readersearch(U);
			if(i!=0)
				useInformation(B,U,i);
			else
				continue;
			cout<<"                                    ";
			cout<<"ENTER键返回";
			getchar();
			getchar();
			continue;
		}
		if(c=='2')	
			Readerincrease(B,U);
		if(c=='3')
			Readerdelete(B,U);
		if(c=='4')
			break;
		if(c!='1'&&c!='2'&&c!='3')
		{
			system("cls");
			cout<<"                               ";
			cout<<"输入有误！请重新输入。"<<endl;
			Sleep(2000);
			continue;
		}
	}
}
void Increasebook(LibrarySystem &B,UseSystem &U)//增加图书
{
	int i,j,n,m,num;
	char in;
	string NAME;
	string AUTHOR;
	string Isbn;
	string PUBLISHER;
	int YEAR,MONTH,DAY;
	float PRICE;
	if(B.length!=10000)
	{
		for(i=B.length+1;i<=10000;i++)
		{
			for(;;)
			{
				system("cls");
                cout<<"                                   输入编号："<<endl<<"                                   ";
		        cin>>num;
			    for(j=1;j<=B.length;j++)
				{
					if(num==B.Book[j].Number)
					{
						cout<<"                                   编号重复！请重新输入。";
						Sleep(2000);
						n=0;
					    break;
					}
				    else
					{
						n=1;
					    continue;
					}
				}
				if(n)
					break;
				else
					continue;
			}
			for(;;)
			{
				system("cls");
				cout<<"                                   输入编号："<<endl<<"                                   "<<num<<endl;
                cout<<endl<<"                                   输入ISBN："<<endl<<"                                   ";
		        cin>>Isbn;
			    for(j=1;j<=B.length;j++)
				{
					if(Isbn==B.Book[j].ISBN)
					{
						cout<<endl<<"                                   ISBN重复！请重新输入。"<<endl;
						Sleep(2000);
						m=0;
					    break;
					}
				    else
					{
						m=1;
					    continue;
					}
				}
				if(m)
					break;
				else
					continue;
			}
		    cout<<endl<<"                                   输入书名："<<endl<<"                                   ";
		    cin>>NAME;
		    cout<<endl<<"                                   输入作者："<<endl<<"                                   ";
		    cin>>AUTHOR;
	    	cout<<endl<<"                                   输入出版社："<<endl<<"                                   ";
	    	cin>>PUBLISHER;
		    cout<<endl<<"                                   输入价格："<<endl<<"                                   ";
		    cin>>PRICE;
			cout<<endl<<"                                   输入版次（以空格隔开）："<<endl<<"                                   ";
			cin>>YEAR>>MONTH>>DAY;
			system("cls");
			cout<<"                                     编号："<<num<<endl;
			cout<<"                                     ISBN："<<Isbn<<endl;
			cout<<"                                     书名："<<NAME<<endl;
			cout<<"                                     作者："<<AUTHOR<<endl;
			cout<<"                                   出版社："<<PUBLISHER<<endl;
			cout<<"                                     价格："<<PRICE<<"元"<<endl;
			cout<<"                                     日期："<<YEAR<<"年"<<MONTH<<"月第"<<DAY<<"版"<<endl;
			cout<<endl<<"                                     "<<"1-保存"<<endl<<"                                     "<<"2-取消并退出"<<endl<<"                                     "<<"3-返回修改"<<endl;
			cout<<"                                     ";
			cin>>in;
			if(in=='1')
			{
				B.Book[i].Author=AUTHOR;
				B.Book[i].ISBN=Isbn;
				B.Book[i].Name=NAME;
				B.Book[i].Number=num;
				B.Book[i].price=PRICE;
				B.Book[i].Publisher=PUBLISHER;
				B.Book[i].T.day=DAY;
				B.Book[i].T.mounth=MONTH;
				B.Book[i].T.year=YEAR;
				B.Book[i].borrow=0;
				B.length++;
				Savebook(B);
                Savenumber(B,U);
				cout<<endl<<"                                     录入成功！";
				Sleep(2000);
				system("cls");
			}
			if(in=='2')
				break;
			if(in=='3')
				continue;
		    cout<<"                                   1-继续录入"<<endl<<"                                   2-退出"<<endl;
			cout<<"                                   ";
		    cin>>in;
		    if(in=='1')
				continue;
		    else if(in=='2')
			    break;
		}
	}
}
void Deletebook(LibrarySystem &B,UseSystem &U)
{
	int num,n,i;
	char j;
	for(;;)
	{
		if(B.length==0)
		{
			system("cls");
			cout<<"                                 ";
			cout<<"图书馆中尚无图书！"<<endl;
			Sleep(2000);
			break;
		}
		system("cls");
		cout<<"                                 ";
		cout<<"1-删除书籍"<<endl<<endl;
		cout<<"                                 ";
		cout<<"任意键退出"<<endl;
		cout<<"                                     ";
		cin>>j;
		if(j=='1')
		{
			for(;;)
			{
				n=0;
		    	system("cls");
		      	cout<<"                              ";
		    	cout<<"输入要删除书籍的编号：";
	        	cin>>num;
	        	for(i=1;i<=B.length;i++)
				{
	    		    if(B.Book[i].Number==num)
					{
				    	n=i;
				    	break;
					}
				}
				if(B.Book[n].borrow!=0)
				{
					cout<<endl<<"                              该书再借，尚未归还。无法删除。";
					Sleep(2000);
					break;
				}
		    	if(n!=0)
				{
					system("cls");
				    Information(B,U,n);
			    	cout<<"                                ";
			    	cout<<"1-删除"<<endl<<endl;
				    cout<<"                                ";
				    cout<<"2-返回"<<endl<<endl;
			    	cout<<"                                ";
					cout<<"任意键退出"<<endl;
					cout<<"                                ";
	    	    	cin>>j;
	    	    	if(j=='1')
					{
		    		    system("cls");
		    		    if(B.length==1)
				        	B.length=0;
			            else
						{
				        	for(;n<B.length;n++)
							{
					        	B.Book[n].Author=B.Book[n+1].Author;
					         	B.Book[n].borrow=B.Book[n+1].borrow;
				   	        	B.Book[n].ISBN=B.Book[n+1].ISBN;
				    	        B.Book[n].Name=B.Book[n+1].Name;
				   	        	B.Book[n].Number=B.Book[n+1].Number;
		 		   	    	    B.Book[n].price=B.Book[n+1].price;
			    	     		B.Book[n].T=B.Book[n+1].T;
							}
					    	B.length--;
						}
				    	cout<<"                                 ";
						Savebook(B);
                        Savenumber(B,U);
				    	cout<<"删除成功！"<<endl;
				        Sleep(2000);
					}
			        if(j=='2')
				        continue;
					else
						break;
				}
		        else
				{
			        system("cls");
			        cout<<"                                 ";
	    			cout<<"未找到编号为"<<num<<"的图书！"<<endl<<endl;
	    		    cout<<"                                 ";
		    		cout<<"1-继续查找"<<endl<<endl;
		    		cout<<"                                 ";
		    		cout<<"任意键结束"<<endl;
		    		cout<<"                                     ";
		    		Sleep(3000);
		    	    cin>>j;
		        	if(j=='1')
		    		    continue;
		    	    else
			        	break;
				}
			}
		}
		else break;			
	}
	
}
void Revisebook(LibrarySystem &B,UseSystem &U)       //修改信息
{
	int i,j,num,m=0,n=0;
	string NAME;
	string AUTHOR;
	string Isbn;
	string PUBLISHER;
	int YEAR,MONTH,DAY;
	float PRICE;
	if(B.length==0)
	{
		system("cls");
		cout<<"                           图书馆中尚无图书！"<<endl;
		Sleep(3000);
		return;
	}
	for(;;)
	{
		system("cls");
		cout<<"                           输入需要修改书籍的编号:";
		cin>>num;
		for(j=1;j<=B.length;j++)
		{
			if(B.Book[j].Number==num)
			{
				n=j;
				break;
			}
		}
		if(n==0)
		{
			cout<<endl<<"                                 ";
			cout<<"未找到书籍！"<<endl<<endl;				
		    cout<<"                                 ";
		    cout<<"  1-退出"<<endl<<endl;								
	    	cout<<"                                 ";
		    cout<<"2-继续查找"<<endl;
		    cout<<"                                     ";
		    cin>>j;
		    if(j==1)
				break;
			else
				continue;
		}
		else
			break;
	}
	if(n)
	{
		for(;;)
		{
			system("cls");      //清屏
			Information(B,U,n);
			cout<<endl;
	    	cout<<"                                1-修改书名"<<endl;
 		   	cout<<"                                2-修改作者"<<endl;
	    	cout<<"                                3-修改ISBN"<<endl;
		    cout<<"                                4-修改出版社"<<endl;
 		   	cout<<"                                5-修改价格"<<endl;
			cout<<"                                6-修改日期"<<endl;
   		 	cout<<"                                7-退出"<<endl;
			cout<<"                                ";
		    cin>>i;
		    if(i==1)
			{
				for(;;)
				{
					system("cls");
					cout<<"                              输入新书名：";
				    cin>>NAME;
				    cout<<endl<<"                              1-确认修改"<<endl<<"                              2-取消"<<endl;
					cout<<"                              ";
		  		  	cin>>j;
		   		 	if(j==1)
					{
						B.Book[n].Name=NAME;
						Savebook(B);
						break;
					}
			        if(j==2)
			    	    break;
				}
			}
	        if(i==2)
			{
			    for(;;)
				{
				    system("cls");
				    cout<<"                              输入作者名：";
	    		    cin>>AUTHOR;
					cout<<endl;
		    	    cout<<"                              1-确认修改"<<endl<<"                              2-取消"<<endl;
		    		cout<<"                              ";
		        	cin>>j;
		        	if(j==1)
					{
				        B.Book[n].Author=AUTHOR;
						Savebook(B);
					    break;
					}
			        if(j==2)
			    	    break;
				}
			}
	        if(i==3)
			{
			    for(;;)
				{
				    system("cls");
				    cout<<"                              输入新ISBN：";
			        cin>>Isbn;
					cout<<endl;
			        cout<<"                              1-确认修改"<<endl<<"                              2-取消"<<endl;
				    cout<<"                              ";
		    	    cin>>j;
		    	    if(j==1)
					{
				        B.Book[n].ISBN=Isbn;
						Savebook(B);
				    	break;
					}
			        if(j==2)
			    	    break;
				}
			}
	        if(i==4)
			{
			    for(;;)
				{
				    system("cls");
			    	cout<<"                              输入新出版社：";
			        cin>>PUBLISHER;
					cout<<endl;
			        cout<<"                              1-确认修改"<<endl<<"                              2-取消"<<endl;
			    	cout<<"                              ";
		        	cin>>j;
		        	if(j==1)
					{
				        B.Book[n].Publisher=PUBLISHER;
						Savebook(B);
					    break;
					}
			        if(j==2)
			    	    break;
				}
			}
	        if(i==5)
			{
			    for(;;)
				{
				    system("cls");
				    cout<<"                              输入价格：";
			        cin>>PRICE;
					cout<<endl;
			        cout<<"                              1-确认修改"<<endl<<"                              2-取消"<<endl;
				    cout<<"                              ";
		        	cin>>j;
		        	if(j==1)
					{
				        B.Book[n].price=PRICE;
						Savebook(B);
				    	break;
					}
			        if(j==2)
			    	    break;
				}
			}
			if(i==6)
			{
				for(;;)
				{
					system("cls");
					cout<<"                              输入日期，以空格隔开：";
					cin>>YEAR>>MONTH>>DAY;
					cout<<endl<<"                              1-确认修改"<<endl<<"                              2-取消"<<endl;
					cout<<"                              ";
					cin>>j;
		        	if(j==1)
					{
				        B.Book[n].T.year=YEAR;
						B.Book[n].T.mounth=MONTH;
						B.Book[n].T.day=DAY;
						Savebook(B);
				    	break;
					}
			        if(j==2)
			    	    break;
				}
			}
	        if(i==7)
			    break;
	        if(i!=1&&i!=2&&i!=3&&i!=4&&i!=5&&i!=6&&i!=7)
			{
			    cout<<"                              输入有误！请重新输入。"<<endl;
			    Sleep(3000);
		        continue;
			}
        }
    }
}
int Admlogin()
{
	system("cls");
	int n,bj;
	for(n=1;n<=3;n++)
	{
		bj=0;
		cout<<endl<<"                           管理员密码：";
		int i,j,m;
		char CO[20];
		char co[20];
		ifstream fin("code");
		fin>>CO;
		for(i=0;i<20;i++)
			if(CO[i]<0)
				break;
		i--;
		for(j=0;;j++)
		{
			co[j]=getch();
			if(co[j]=='\r')
				break;
			if(co[j]==8)
			{
				system("cls");
				if(n!=1)
					cout<<endl<<"                           密码有误！你还有"<<3-n+1<<"次机会！"<<endl;
				cout<<endl<<"                           管理员密码：";
				for(m=0;m<j-1;m++)
					printf("*");
				j-=2;
			}
			else
				printf("*");
		}
		for(m=0;m<i;m++)
			if(co[m]==CO[m])
				bj=1;
			else
			{
				bj=0;
				break;
			}
		if(i==j&&bj==1)
			return 1;
		else
		{
			system("cls");      //清屏
			if(n!=3)
			{
				cout<<endl<<"                           密码有误！你还有"<<3-n<<"次机会！"<<endl;
			    continue;
			}
			else
			{
				int T;
				for(T=0;T<30;T++)
				{
					system("cls");
					cout<<"\n                           密码输入三次有误！"<<30-T<<"秒后重启。";
					Sleep(1000);
				}
				break;
			}
		}
	}
}

void AdmCodeRevise()
{
	string str1,str2;
	int i,j,m,n;
	char in;
	char str[20],CO[20];
	ifstream fin("code");
	fin>>CO;
	for(n=0;CO[n]>0;n++)
	{}
	for(;;)
	{
		m=1;
		system("cls");
		cout<<"                                请输入原始密码:";
		for(j=0;;j++)
		{
			str[j]=getch();
			if(str[j]=='\r')
				break;
			if(str[j]==8)
			{
				system("cls");
				cout<<"                                请输入原始密码:";
				for(int n=1;n<j;n++)
					printf("*");
				j-=2;
			}
			else
				printf("*");
		}
		for(i=0;i<n;i++)
			if(str[i]!=CO[i])
			{
				m=0;
				break;
			}
		if(m&&j==n)
		{
			system("cls");
			cout<<"                                请输入新密码:";
			cin>>str1;
			system("cls");
			cout<<"                                请再次输入已确定修改:";
			cin>>str2;
			if(str2==str1)
			{
				system("cls");
				ofstream fout;
				fout.open("code");
				fout<<str2;
				cout<<"                                修改成功！";
				Sleep(2000);
				break;
			}
			else
			{
				system("cls");
				cout<<"                                输入有误！返回修改。";
				Sleep(2000);
				continue;
			}
		}
		else
		{
			system("cls");
			cout<<"                                密码有误！"<<endl<<endl;
			cout<<"                                1-返回修改"<<endl;
			cout<<"                                任意键退出"<<endl;
			cout<<"                                ";
			cin>>in;
			if(in=='1')
				continue;
			else
				break;
		}
	}
}

/***********************************图书函数************************************/

UseSystem U;
LibrarySystem B;
int main()
{
	Readnumber(B,U);
	Readuse(U);
	Readbook(B);
	Readtimeforbook(B);
	Readtimeforuse(U);
	int back1,back2,Exp;

	for(;;)
	{
		back1=Homepage();
		switch(back1)
		{
		case 1:/********************************管理员系统***********************************/
			{
				if(Admlogin())
				{
					for(;;)
					{
						back2=Adm();
			     	    switch(back2)
						{
						case 1:Increasebook(B,U);break;
			    	    case 2:Deletebook(B,U);break;
			       	    case 3:Revisebook(B,U);break;
				        case 4:Readermanage(B,U);break;
	    		        case 5:Searchbook(B,U);break;
		    	        case 6:AdmCodeRevise();break;
		    			case 7:back2=0;;break;
						}
						if(back2==0)
							break;
					}
				break;
				}
			}break;/****************************管理员系统***********************************/
		case 2:/********************************读者系统*************************************/
			{
				usepage(B,U,Exp);
			}break;/****************************读者系统*************************************/
		case 3:
			{
				system("cls");
				Savebook(B);
                Saveuse(U);
                Savenumber(B,U);
				Savetimeforbook(B);
				Savetimeforuse(U);
				ofstream fout;
				fout.open("Expri");
				fout<<"0";
				cout<<endl<<endl<<endl<<endl<<"                                   ENTER键退出系统";
				getchar();
				getchar();
				return 0;
			}
		}
	}
	return 0;
}