#include<bits/stdc++.h>
using namespace std;
int z;
class student
{
	int roll;
	float marks;
	char name[50];
  public:
	int getroll()
  {
    return roll;
  }
	float getmarks()
  {
	 return marks;
  }
	void getdata();
	void display();
};
void student::getdata()
{
  int troll,check[50],f,p;
  float tmarks;
  cout<<"-----------------------------------------"<<endl;
  x:
  f=1;
  cout<<"Enter Roll Number: ";
  cin>>troll;
  for(p=0;p<z;p++)
	if(troll==check[p])
		f=0;
  if(troll<=0)
  {
	  cout<<"!!!!!! Enter Valid Roll No. !!!!!!"<<endl;
	  goto x;
  }
  else if(f==0)
  {
	cout<<"!!!!!! Roll No: "<<troll<<" Already Scanned !!!!!!"<<endl;
	goto x;
  }
  else roll=troll;
  cout<<"Enter Name: ";
  cin>>name;
  y:
  cout<<"Enter Marks(-1 if absent): ";
  cin>>tmarks;
  if(tmarks<-1||tmarks>100)
    {
  	  cout<<"!!!!!! Enter Valid Marks !!!!!!"<<endl;
  	  goto y;
    }
	 else marks=tmarks;
  check[z]=roll;
  z++;
}
void student::display()
{
	cout<<roll<<"\t\t"<<name<<"\t\t";
	if(marks<0)cout<<"Absent"<<endl;
	else cout<<marks<<endl;
}
class dsclass
{
	student s[50];
	float avg,sum,count;
	int i,j,n;
  public:
  void getdata();
  void display();
  void average();
  void maxmin();
  void mode();
  void absent();
  void menu();
  void arrange();
};
void dsclass::getdata()
{
  cout<<endl<<"----------------DATA ENTRY MENU----------------"<<endl;
  label:
  cout<<"Enter The No. of Students in the Class: ";
  cin>>n;
  if(n<=0)
  {
		cout<<"!!!!! Class Cannot be Empty !!!!!"<<endl;
		goto label;
  }
  for(i=0;i<n;i++)
  s[i].getdata();
}
void dsclass::arrange()
{
	student temp;
	for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
	{
		if(s[i].getroll()>s[j].getroll())
		{
			temp=s[i];
			s[i]=s[j];
			s[j]=temp;
		}
	}
}
void dsclass::display()
{
  cout<<endl<<"Roll No.\tName\t\tMarks"<<endl;
  cout<<"-----------------------------------------------"<<endl;
  for(i=0;i<n;i++)
  s[i].display();
}
void dsclass::average()
{
  sum=0;count=0;
  for(i=0;i<n;i++)
  {
    if(s[i].getmarks()>=0)
	 {
		sum=sum+s[i].getmarks();
      count++;
    }
    avg=sum/count;
  }
  cout<<endl<<"Average Score: "<<avg<<endl;
}
void dsclass::maxmin()
{
  float max=-2,min=100;
  for(i=0;i<n;i++)
  {
	if(s[i].getmarks()>=max&&s[i].getmarks()>=0)
		max=s[i].getmarks();
	if(s[i].getmarks()<=min&&s[i].getmarks()>=0)
		min=s[i].getmarks();
	}
  cout<<endl<<"Highest Marks: "<<max<<" | Roll No(s). :";
  for(i=0;i<n;i++)
  {
		if(s[i].getmarks()==max)
		cout<<s[i].getroll()<<", ";
  }
  cout<<endl<<"Lowest Marks: "<<min<<"  | Roll No(s). :";
  for(i=0;i<n;i++)
  {
		if(s[i].getmarks()==min)
		cout<<s[i].getroll()<<", ";
  }
  cout<<endl;
}
void dsclass::mode()
{
	int f=0,c;
	float t,m[50],temp;
	for(i=0;i<n;i++)
		m[i]=s[i].getmarks();
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(m[i]>m[j])
			{
				temp=m[i];
				m[i]=m[j];
				m[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		c=0;
		if(m[i]>=0)
		for(j=0;j<n;j++)
		{
			if(m[i]==m[j])
			{
				c++;
			}
		}
		if(c>=f)
		{
			f=c;
			t=m[i];
		}
	}
	if(f>1)
	cout<<endl<<"Most Scored Marks: "<<t<<" | scored "<<f<<" times."<<endl;
	else cout<<endl<<"No Score Repeated."<<endl;
}
void dsclass:: absent()
{
	cout<<endl<<"Absent Student(s) are: ___";
	for(i=0;i<n;i++)
	{
		if(s[i].getmarks()<0)
		{
			cout<<endl<<"\t\tRoll No. "<<s[i].getroll();
		}
	}
	cout<<endl;
}
void dsclass::menu()
{
	cout<<"------------------RESULT MANAGEMENT--------------------"<<endl;
	cout<<"\tPress 1 to Enter Result"<<endl;
	cout<<"\tPress 2 to display Entire Result"<<endl;
	cout<<"\tPress 3 for Average score of the class"<<endl;
	cout<<"\tPress 4 for Highest and Lowest Score"<<endl;
	cout<<"\tPress 5 for the Marks scored by most the students"<<endl;
	cout<<"\tPress 6 for the absentee List"<<endl;
	cout<<"\tPress 0 to exit"<<endl;

}
int main()
{
	dsclass se1;
	int ch;
	se1.menu();
	label:
	cout<<endl<<"_______________________________________________";
	cout<<endl<<"Enter Choice from Menu [Press 0 to exit]: ";
	cin>>ch;
	switch(ch)
	{
		case 1: z=0;se1.getdata();se1.arrange();goto label;break;
		case 2: se1.display();goto label;break;
		case 3: se1.average();goto label;break;
		case 4: se1.maxmin();goto label;break;
		case 5: se1.mode();goto label;break;
		case 6: se1.absent();goto label;break;
		case 0: cout<<endl<<"Exiting....";break;
		default:cout<<endl<<"!!!!!!Enter a valid Choice form Menu!!!!!!";
				  goto label;
	}
	return 0;
}
