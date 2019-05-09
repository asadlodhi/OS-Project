#include<iostream>

struct process
{
	int num;
	int a;
	int b;
	int c;
	int ra;
	int rb;
	int rc;
	int processed;
};

struct resources
{
	int a;
	int b;
	int c;
};


using namespace std;
main()
{
	int n, impossible=0, processesFinished=0;
	resources available;
	cout<<"Set Number of Processes:";
	cin>>n;
	process p[n];
	
	//setting process names
	for(int i=0; i<n; i++)
	{
		p[i].num = i;
	}
	
	for(int i=0; i<n; i++)
	{
		cout<<"Set Allocated Resouces for Process "<<p[i].num<<endl;
		cout<<"Resource A:";
		cin>>p[i].a;
		cout<<"Resource B:";
		cin>>p[i].b;
		cout<<"Resource C:";
		cin>>p[i].c;
	}
	
	cout<<"Set Available Resources"<<endl;
	cout<<"Resource A:";
	cin>>available.a;
	cout<<"Resource B:";
	cin>>available.b;
	cout<<"Resource C:";
	cin>>available.c;
	
	for(int i=0; i<n; i++)
	{
		cout<<"Set Requested Resouces for Process "<<p[i].num<<endl;
		cout<<"Requested Resource A:";
		cin>>p[i].ra;
		cout<<"Requested Resource B:";
		cin>>p[i].rb;
		cout<<"Requested Resource C:";
		cin>>p[i].rc;
	}
	
	cout<<endl;
	
	while(processesFinished != n)
	{
		for(int i=0; i<n; i++)
		{
			if(p[i].ra <= available.a && p[i].rb <= available.b && p[i].rc <= available.c && p[i].processed == 0)
			{
				available.a = available.a + p[i].a;
				available.b = available.b + p[i].b;
				available.c = available.c + p[i].c;
				p[i].processed = 1;
				cout<<"Process "<<p[i].num<<" has been Processed"<<endl;
				processesFinished++;
			}
		}
	}
	
}
