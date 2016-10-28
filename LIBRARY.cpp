#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<conio.h>
#include<time.h>
using namespace std;
#define maxbooks 5000
#define maxuses 10000
/////////////////////////////////////�ṹ��//////////////////////////////////////
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

typedef struct          //�鼮
{
	int Number;         //���
	string Name;        //����
	string Author;      //����
	string ISBN;        //ISBN
	string Publisher;   //������
	float price;        //�۸�
	int borrow;         //�Ƿ���
	Time T;             //����ʱ��
	BRORECODER BROCO;     //�����¼
}BOOK;

typedef struct     //ͼ����鼮
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

typedef struct         //�û�
{
	int num;
	string code;
	int br[6];
	int brnum;
	BORRECODER BROCO;
}USE;

typedef struct      //ͼ����û�
{
	USE Use[maxuses];
	int length;
}UseSystem;
/////////////////////////////////////�ṹ��/////////////////////////////////////
/***********************************�ļ�����************************************/
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
/***********************************�ļ�����************************************/
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
/************************************��ҳ��*************************************/
int Homepage()
{
	int m;
	system("cls");
	for(;;)
	{
		cout<<"                                   ���˵�\n\n";
		cout<<"                             1-�Թ���Ա����ϵͳ\n\n";
		cout<<"                              2-���û�����ϵͳ\n\n";
		cout<<"                                 3-�˳�ϵͳ\n\n";
		cout<<"                                     ";
		cin>>m;
		if(m==1||m==2||m==3)
		{
			return m;
			break;
		}
		else
		{
			cout<<"                            ��������";
			Sleep(1000);
		}
	}
}
/************************************��ҳ��*************************************/
/**********************************����Աҳ��***********************************/
int Adm()
{
	int m;
	char in;
	system("cls");
	for(;;)
	{
		system("cls");
	    cout<<"                                   ����Աҳ��\n\n";
		cout<<"                                   1-����ͼ��\n\n";
		cout<<"                                   2-ɾ��ͼ��\n\n";
		cout<<"                                 3-�޸�ͼ����Ϣ\n\n";
		cout<<"                                   4-���߹���\n\n";
		cout<<"                                   5-ͼ���ѯ\n\n";
		cout<<"                                 6-�޸ĵ�¼����\n\n";
		cout<<"                                  7-�������˵�\n\n";
		cout<<"                                       ";
		cin>>in;
		if(in=='1'||in=='2'||in=='3'||in=='4'||in=='5'||in=='6'||in=='7')
		{
			m=in-48;
			break;
		}
		else
		{
			cout<<endl<<"                              ��������";
			Sleep(2000);
		}
	}
	return m;
}
/**********************************����Աҳ��***********************************/
void Information(LibrarySystem &B,UseSystem &U,int i)
{
	int j;
	cout<<"                              ��  �ţ�"<<B.Book[i].Number<<endl;
	cout<<"                              ��  ����"<<B.Book[i].Name<<endl;
	cout<<"                              ��  �ߣ�"<<B.Book[i].Author<<endl;
	cout<<"                              IS  BN��"<<B.Book[i].ISBN<<endl;
	cout<<"                              �����磺"<<B.Book[i].Publisher<<endl;
	cout<<"                              ��  ��"<<B.Book[i].price<<"Ԫ"<<endl;
	cout<<"                              ��  �Σ�"<<B.Book[i].T.year<<" �� "<<B.Book[i].T.mounth<<" �� ��"<<B.Book[i].T.day<<" ��"<<endl<<endl;
	if(B.Book[i].borrow==0)
		cout<<"                              ��δ���"<<endl<<endl;
	else
	{
		j=B.Book[i].borrow;
		cout<<"                              �ѱ��û�"<<U.Use[j].num<<"���"<<endl<<endl;
	}
	cout<<"                              �����¼�������"<<B.Book[i].BROCO.BRONUM<<"��"<<endl;
	for(j=1;j<=B.Book[i].BROCO.BRONUM;j++)
	{
		cout<<"                              ********************"<<endl;
		struct tm*local;
    	local=localtime(&B.Book[i].BROCO.BOR[j].brotime);
		int n=B.Book[i].BROCO.BOR[j].number;
		cout<<"                              �����û���"<<U.Use[n].num<<endl;
		cout<<"                              ����ʱ�䣺"<<local->tm_year+1900<<"-"<<local->tm_mon+1<<"-"<<local->tm_mday<<endl;
		local=localtime(&B.Book[i].BROCO.BOR[j].rtntime);
		cout<<"                              ����ʱ�䣺";
		if(B.Book[i].BROCO.BOR[j].rtntime==0)
		{
			cout<<"��"<<endl;
			break;
		}
		cout<<local->tm_year+1900<<"-"<<local->tm_mon+1<<"-"<<local->tm_mday<<endl;
	}
	cout<<"  ****************************************************************************"<<endl;
}
/***********************************�û�����************************************/
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
	    cout<<"                                   �û���¼"<<endl<<endl;
		cout<<"                             �����û����룺";
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
				cout<<"                                   �û���¼"<<endl<<endl;
				cout<<"                             �����û����룺"<<U.Use[m].num<<endl<<endl;
				cout<<"                                 �������룺";
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
						cout<<endl<<"                             �������������㻹��"<<3-i<<"�λ��ᡣ"<<endl;
				    	Sleep(2000);
					}
					else
					{
						cout<<endl<<"                             ����������������"<<endl;
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
		    cout<<"                             �����ڸ��û���"<<endl<<endl;
			cout<<"                             1-��������"<<endl<<endl<<"                             ���������"<<endl;
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

int useSearch(LibrarySystem &B,UseSystem &U,int i)       //Ѱ��ͼ��
{
	int j,n,num;
	char m,in;
	string NAME;
	string Isbn;
	for(;;)
	{
		system("cls");
	    cout<<"                                   ����ͼ�飺"<<endl<<endl;
        cout<<"                                 1-�Ա�Ų���"<<endl<<endl;
        cout<<"                                 2-����������"<<endl<<endl;
        cout<<"                                 3-��ISBN����"<<endl<<endl;
    	cout<<"                                    4-�˳�"<<endl;
    	cout<<"                                      ";
        cin>>m;
        if(m=='1')
		{
			for(;;)
			{
				n=0;
				system("cls");
				cout<<"                                 ������:";
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
				cout<<"δ�ҵ��鼮��"<<endl<<endl;				
			    cout<<"                                 ";
			   	cout<<"  1-�˳�"<<endl<<endl;								
	    	 	cout<<"                                 ";
		   		cout<<"2-��������"<<endl;
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
		        cout<<"                                 ����������";
		    	cin>>NAME;
		        for(j=1;j<=B.length;j++)
					if(B.Book[j].Name==NAME)
					{
						n=j;
						break;
					}
				system("cls");	
			    cout<<endl<<"                                 ";
			   	cout<<"δ�ҵ��鼮��"<<endl<<endl;				
		   		cout<<"                                 ";
		   		cout<<"  1-�˳�"<<endl<<endl;								
		    	cout<<"                                 ";
		    	cout<<"2-��������"<<endl;
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
		    	cout<<"                                 ����ISBN��";
			    cin>>Isbn;
				for(j=1;j<=B.length;j++)
					if(B.Book[j].ISBN==Isbn)
					{
						n=j;
						break;
					}
				system("cls");
				cout<<endl<<"                                 ";
			    cout<<"δ�ҵ��鼮��"<<endl<<endl;				
			    cout<<"                                 ";
			    cout<<"  1-�˳�"<<endl<<endl;								
		        cout<<"                                 ";
			    cout<<"2-��������"<<endl;
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
			cout<<"                             �����������������롣";
		    Sleep(2000);
		    continue;
		}
		system("cls");
		Information(B,U,j);
		if(B.Book[j].borrow==0)
		{
			cout<<"                                 1-����"<<endl;
			cout<<"                                 ���������"<<endl;
			cout<<"                                 ";
			cin>>in;
			if(in=='1')
			{
				system("cls");
				int bn=U.Use[i].brnum;
				if(bn==5)
				{
					cout<<"                             �Բ������ٽ�ͼ���������޷��������ġ�"<<endl;
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
				cout<<"                                 ���ĳɹ�������"<<local->tm_year+1900<<"��"<<local->tm_mon+1<<"��"<<local->tm_mday<<"��ǰ�黹��";
				Sleep(3000);
				continue;
			}
			else
				continue;
		}
		else
		{
			cout<<"                                 1-��������"<<endl;
			cout<<"                                 �����ȡ��"<<endl;
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
			cout<<"                                ����"<<U.Use[i].brnum<<"�����ٽ裺"<<endl<<endl;
        	for(int j=1;j<=U.Use[i].brnum;j++)
			{
	        	int nu=U.Use[i].br[j];
	        	cout<<"                                ���Ϊ��"<<B.Book[nu].Number<<endl<<endl;
			}
        	cout<<"                                ����Ҫ�黹�ı�ţ�";
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
	        cout<<"                                ����ɹ���"<<endl<<endl;
        	if(U.Use[i].brnum)
			{
	        	cout<<"                                1-��������"<<endl<<endl;
	         	cout<<"                                ���������"<<endl<<endl;
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
			cout<<endl<<"                            ��Ŀǰû���ٽ�ͼ�飡3����Զ����ء�";
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
		cout<<"                                ����ԭʼ���룺";
		cin>>oldcode;
		if(U.Use[i].code==oldcode)
		{
			system("cls");
			cout<<"                                ���������룺";
			cin>>newcode1;
			system("cls");
			cout<<endl<<"                        ����������ȷ���޸ģ�";
			cin>>newcode2;
			if(newcode1==newcode2)
			{
				U.Use[i].code=newcode1;
				cout<<endl<<"                                �޸���ɣ����μǴ����롣"<<endl;
                Saveuse(U);
				Sleep(3000);
				break;
			}
			else
			{
				system("cls");
				cout<<"                                �������"<<endl<<endl;
				cout<<"                                1-�����޸�"<<endl<<endl;
				cout<<"                                ���������"<<endl<<endl;
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
			cout<<"                                ԭʼ������������"<<endl<<endl;
			cout<<"                                1-��������"<<endl<<endl;
			cout<<"                                ���������"<<endl<<endl;
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
	    	cout<<"                                �û���"<<U.Use[n].num;
    		cout<<"  ��ӭ����ͼ��ݣ�"<<endl<<endl;
    		cout<<"                                1-����"<<endl<<endl;
 		   	cout<<"                                2-����"<<endl<<endl;
    		cout<<"                                3-�޸�����"<<endl<<endl;
	    	cout<<"                                4-�˳��û�ϵͳ"<<endl<<endl;
			cout<<"                                5-�˳���¼"<<endl<<endl;
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
/***********************************�û�����************************************/
/***********************************ͼ�麯��************************************/
int Searchbook(LibrarySystem &B,UseSystem &U)       //Ѱ��ͼ��
{
	int n=0,j,num,book[maxbooks];
	char in;
	string NAME;
	string Isbn;
	for(;;)
	{
		system("cls");      //����
	    cout<<"                                   ����ͼ�飺"<<endl<<endl;
        cout<<"                                 1-�Ա�Ų���"<<endl<<endl;
        cout<<"                                 2-����������"<<endl<<endl;
        cout<<"                                 3-��ISBN����"<<endl<<endl;
    	cout<<"                                    4-�˳�"<<endl;
    	cout<<"                                      ";
        cin>>in;
        if(in=='1')
		{
			for(;;)
			{
				system("cls");
				cout<<"                                 ������:";
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
				    cout<<"δ�ҵ��鼮��"<<endl<<endl;				
				    cout<<"                                 ";
			    	cout<<"  1-�˳�"<<endl<<endl;								
	    		 	cout<<"                                 ";
		    		cout<<"���������"<<endl;
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
			    	cout<<"1-�˳�"<<endl<<endl;								
	    		 	cout<<"                                 ";
		    		cout<<"���������"<<endl;
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
		        cout<<"                                 ����������";
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
			    	cout<<"δ�ҵ��鼮��"<<endl<<endl;				
		    		cout<<"                                 ";
		    		cout<<"  1-�˳�"<<endl<<endl;								
			    	cout<<"                                 ";
			    	cout<<"���������"<<endl;
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
			    	cout<<"1-�˳�"<<endl<<endl;								
	    		 	cout<<"                                 ";
		    		cout<<"���������"<<endl;
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
		    	cout<<"                                 ����ISBN��";
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
				    cout<<"δ�ҵ��鼮��"<<endl<<endl;				
				    cout<<"                                 ";
				    cout<<"  1-�˳�"<<endl<<endl;								
				    cout<<"                                 ";
				    cout<<"���������"<<endl;
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
			    	cout<<"1-�˳�"<<endl<<endl;								
	    		 	cout<<"                                 ";
		    		cout<<"���������"<<endl;
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
			cout<<"                             �����������������롣";
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
	cout<<"�û���ţ�"<<U.Use[i].num<<endl<<endl;
	cout<<"                                   ";
	cout<<"���룺"<<U.Use[i].code<<endl<<endl;
	cout<<"                             ";
	if(U.Use[i].brnum==0)
	{
		cout<<"���û������ٽ�ͼ�飡"<<endl;
		cout<<"                        ";
	}
	else
	{
		cout<<"  �ٽ���Ŀ��";
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
	    	cout<<"����Ҫ��ѯ���ߺ��룺";
	        cin>>usenum;
        	for(m=1;m<=U.length;m++)
			{
				if(U.Use[m].num==usenum)
				    return m;
			}
		    cout<<endl<<"                           ";
	    	cout<<"ϵͳ�����ڸ��û���"<<endl<<endl;
	    	cout<<"                           ";
	    	cout<<"1-��������"<<endl<<endl;
	    	cout<<"                           ";
	    	cout<<"����������û�����ҳ��"<<endl<<endl;		
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
		cout<<"ϵͳ�����û���2����Զ��˳���";
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
			cout<<"ͼ����û�������"<<endl;
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
				cout<<" �������Ӷ��ߺţ�";
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
					cout<<"���û��Ѵ��ڣ�2����Զ����ء�"<<endl;
					Sleep(2000);
					continue;
				}
				else
					break;
			}
			cout<<"                               ";
			cout<<"�����û�"<<usenum<<"�����룺";
			cin>>CO;
			system("cls");
			cout<<"                               ";
			cout<<"�û���ţ�"<<usenum<<endl<<endl;
			cout<<"                                   ";
			cout<<"���룺"<<CO<<endl<<endl;
			cout<<"                                 ";
			cout<<"1-����"<<endl<<endl;
			cout<<"                             ";
			cout<<"�����ȡ��"<<endl;
			cout<<"                                      ";
			cin>>i;
			if(i=='1')
			{
				system("cls");
				U.Use[U.length+1].num=usenum;
				U.Use[U.length+1].code=CO;
				U.length++;
				cout<<"                               ";
				cout<<"����ɹ���"<<endl<<endl;
                Saveuse(U);
                Savenumber(B,U);
				cout<<"                               ";
				cout<<"1-����¼��"<<endl<<endl;
				cout<<"                               ";
				cout<<"����������û�����ҳ��"<<endl;
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
			cout<<"ϵͳ�������û���2��󷵻ء�"<<endl;
			Sleep(2000);
	    	return;
		}
    	else
		{
			cout<<"                               ";
			cout<<"����Ҫɾ���û��ı�ţ�";
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
				cout<<"���û�����δ��ͼ�顣�޷�ɾ����";
				Sleep(3000);
				continue;
			}
			if(j!=0)
			{
				useInformation(B,U,i);
		    	cout<<"                               ";
				cout<<"1-ȷ��ɾ��"<<endl<<endl;
				cout<<"                               ";
				cout<<"2-ȡ��"<<endl<<endl;
				cout<<"                               ";
				cout<<"����������û�����ҳ��"<<endl;
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
					cout<<"ɾ���ɹ���"<<endl<<endl;
					cout<<"                               ";
					cout<<"1-����ɾ��"<<endl<<endl;
					cout<<"                               ";
					cout<<"������˳�"<<endl;
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
				cout<<"δ�ҵ����û�"<<endl<<endl;
				cout<<"                               ";
				cout<<"1-��������"<<endl<<endl;
				cout<<"                               ";
				cout<<"����������û�����ҳ��"<<endl;
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
		cout<<"                               �û�����"<<endl<<endl;
		cout<<"                               1-���Ҷ���"<<endl<<endl;
		cout<<"                               2-���Ӷ���"<<endl<<endl;
		cout<<"                               3-ɾ������"<<endl<<endl;
		cout<<"                               4-�˳��û�����"<<endl;
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
			cout<<"ENTER������";
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
			cout<<"�����������������롣"<<endl;
			Sleep(2000);
			continue;
		}
	}
}
void Increasebook(LibrarySystem &B,UseSystem &U)//����ͼ��
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
                cout<<"                                   �����ţ�"<<endl<<"                                   ";
		        cin>>num;
			    for(j=1;j<=B.length;j++)
				{
					if(num==B.Book[j].Number)
					{
						cout<<"                                   ����ظ������������롣";
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
				cout<<"                                   �����ţ�"<<endl<<"                                   "<<num<<endl;
                cout<<endl<<"                                   ����ISBN��"<<endl<<"                                   ";
		        cin>>Isbn;
			    for(j=1;j<=B.length;j++)
				{
					if(Isbn==B.Book[j].ISBN)
					{
						cout<<endl<<"                                   ISBN�ظ������������롣"<<endl;
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
		    cout<<endl<<"                                   ����������"<<endl<<"                                   ";
		    cin>>NAME;
		    cout<<endl<<"                                   �������ߣ�"<<endl<<"                                   ";
		    cin>>AUTHOR;
	    	cout<<endl<<"                                   ��������磺"<<endl<<"                                   ";
	    	cin>>PUBLISHER;
		    cout<<endl<<"                                   ����۸�"<<endl<<"                                   ";
		    cin>>PRICE;
			cout<<endl<<"                                   �����Σ��Կո��������"<<endl<<"                                   ";
			cin>>YEAR>>MONTH>>DAY;
			system("cls");
			cout<<"                                     ��ţ�"<<num<<endl;
			cout<<"                                     ISBN��"<<Isbn<<endl;
			cout<<"                                     ������"<<NAME<<endl;
			cout<<"                                     ���ߣ�"<<AUTHOR<<endl;
			cout<<"                                   �����磺"<<PUBLISHER<<endl;
			cout<<"                                     �۸�"<<PRICE<<"Ԫ"<<endl;
			cout<<"                                     ���ڣ�"<<YEAR<<"��"<<MONTH<<"�µ�"<<DAY<<"��"<<endl;
			cout<<endl<<"                                     "<<"1-����"<<endl<<"                                     "<<"2-ȡ�����˳�"<<endl<<"                                     "<<"3-�����޸�"<<endl;
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
				cout<<endl<<"                                     ¼��ɹ���";
				Sleep(2000);
				system("cls");
			}
			if(in=='2')
				break;
			if(in=='3')
				continue;
		    cout<<"                                   1-����¼��"<<endl<<"                                   2-�˳�"<<endl;
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
			cout<<"ͼ���������ͼ�飡"<<endl;
			Sleep(2000);
			break;
		}
		system("cls");
		cout<<"                                 ";
		cout<<"1-ɾ���鼮"<<endl<<endl;
		cout<<"                                 ";
		cout<<"������˳�"<<endl;
		cout<<"                                     ";
		cin>>j;
		if(j=='1')
		{
			for(;;)
			{
				n=0;
		    	system("cls");
		      	cout<<"                              ";
		    	cout<<"����Ҫɾ���鼮�ı�ţ�";
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
					cout<<endl<<"                              �����ٽ裬��δ�黹���޷�ɾ����";
					Sleep(2000);
					break;
				}
		    	if(n!=0)
				{
					system("cls");
				    Information(B,U,n);
			    	cout<<"                                ";
			    	cout<<"1-ɾ��"<<endl<<endl;
				    cout<<"                                ";
				    cout<<"2-����"<<endl<<endl;
			    	cout<<"                                ";
					cout<<"������˳�"<<endl;
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
				    	cout<<"ɾ���ɹ���"<<endl;
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
	    			cout<<"δ�ҵ����Ϊ"<<num<<"��ͼ�飡"<<endl<<endl;
	    		    cout<<"                                 ";
		    		cout<<"1-��������"<<endl<<endl;
		    		cout<<"                                 ";
		    		cout<<"���������"<<endl;
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
void Revisebook(LibrarySystem &B,UseSystem &U)       //�޸���Ϣ
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
		cout<<"                           ͼ���������ͼ�飡"<<endl;
		Sleep(3000);
		return;
	}
	for(;;)
	{
		system("cls");
		cout<<"                           ������Ҫ�޸��鼮�ı��:";
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
			cout<<"δ�ҵ��鼮��"<<endl<<endl;				
		    cout<<"                                 ";
		    cout<<"  1-�˳�"<<endl<<endl;								
	    	cout<<"                                 ";
		    cout<<"2-��������"<<endl;
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
			system("cls");      //����
			Information(B,U,n);
			cout<<endl;
	    	cout<<"                                1-�޸�����"<<endl;
 		   	cout<<"                                2-�޸�����"<<endl;
	    	cout<<"                                3-�޸�ISBN"<<endl;
		    cout<<"                                4-�޸ĳ�����"<<endl;
 		   	cout<<"                                5-�޸ļ۸�"<<endl;
			cout<<"                                6-�޸�����"<<endl;
   		 	cout<<"                                7-�˳�"<<endl;
			cout<<"                                ";
		    cin>>i;
		    if(i==1)
			{
				for(;;)
				{
					system("cls");
					cout<<"                              ������������";
				    cin>>NAME;
				    cout<<endl<<"                              1-ȷ���޸�"<<endl<<"                              2-ȡ��"<<endl;
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
				    cout<<"                              ������������";
	    		    cin>>AUTHOR;
					cout<<endl;
		    	    cout<<"                              1-ȷ���޸�"<<endl<<"                              2-ȡ��"<<endl;
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
				    cout<<"                              ������ISBN��";
			        cin>>Isbn;
					cout<<endl;
			        cout<<"                              1-ȷ���޸�"<<endl<<"                              2-ȡ��"<<endl;
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
			    	cout<<"                              �����³����磺";
			        cin>>PUBLISHER;
					cout<<endl;
			        cout<<"                              1-ȷ���޸�"<<endl<<"                              2-ȡ��"<<endl;
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
				    cout<<"                              ����۸�";
			        cin>>PRICE;
					cout<<endl;
			        cout<<"                              1-ȷ���޸�"<<endl<<"                              2-ȡ��"<<endl;
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
					cout<<"                              �������ڣ��Կո������";
					cin>>YEAR>>MONTH>>DAY;
					cout<<endl<<"                              1-ȷ���޸�"<<endl<<"                              2-ȡ��"<<endl;
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
			    cout<<"                              �����������������롣"<<endl;
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
		cout<<endl<<"                           ����Ա���룺";
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
					cout<<endl<<"                           ���������㻹��"<<3-n+1<<"�λ��ᣡ"<<endl;
				cout<<endl<<"                           ����Ա���룺";
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
			system("cls");      //����
			if(n!=3)
			{
				cout<<endl<<"                           ���������㻹��"<<3-n<<"�λ��ᣡ"<<endl;
			    continue;
			}
			else
			{
				int T;
				for(T=0;T<30;T++)
				{
					system("cls");
					cout<<"\n                           ����������������"<<30-T<<"���������";
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
		cout<<"                                ������ԭʼ����:";
		for(j=0;;j++)
		{
			str[j]=getch();
			if(str[j]=='\r')
				break;
			if(str[j]==8)
			{
				system("cls");
				cout<<"                                ������ԭʼ����:";
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
			cout<<"                                ������������:";
			cin>>str1;
			system("cls");
			cout<<"                                ���ٴ�������ȷ���޸�:";
			cin>>str2;
			if(str2==str1)
			{
				system("cls");
				ofstream fout;
				fout.open("code");
				fout<<str2;
				cout<<"                                �޸ĳɹ���";
				Sleep(2000);
				break;
			}
			else
			{
				system("cls");
				cout<<"                                �������󣡷����޸ġ�";
				Sleep(2000);
				continue;
			}
		}
		else
		{
			system("cls");
			cout<<"                                ��������"<<endl<<endl;
			cout<<"                                1-�����޸�"<<endl;
			cout<<"                                ������˳�"<<endl;
			cout<<"                                ";
			cin>>in;
			if(in=='1')
				continue;
			else
				break;
		}
	}
}

/***********************************ͼ�麯��************************************/

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
		case 1:/********************************����Աϵͳ***********************************/
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
			}break;/****************************����Աϵͳ***********************************/
		case 2:/********************************����ϵͳ*************************************/
			{
				usepage(B,U,Exp);
			}break;/****************************����ϵͳ*************************************/
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
				cout<<endl<<endl<<endl<<endl<<"                                   ENTER���˳�ϵͳ";
				getchar();
				getchar();
				return 0;
			}
		}
	}
	return 0;
}