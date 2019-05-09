#include<iostream>

struct process
{
	char name;
	int burstTime;
	float turnaroundTime;
	float waitingTime;
};

using namespace std;
main()
{
	int n,b, SJFindex = 0, time=0, minBurstTime=0, minBurstFound=0, runningTime;
	float averageWait, averageTurnaround, sumWait=0, sumTurnaround=0;
	
	cout<<"Enter number of Processes:";
	cin>>n;
	process p[n], SJF[n];
	
	//setting process names
	for(int i=0; i<n; i++)
	{
		p[i].name = 'A' + i;
	}
	
	//setting process burst times
	for(int i=0; i<n; i++)
	{
		cout<<"Enter Process "<<p[i].name<<" Burst Time:";
		cin>>b;
		p[i].burstTime = b;
	}
	
	//setting min burst time
	while(minBurstFound == 0)
	{
		minBurstTime++;
		for(int i=0; i<n; i++)
		{
			if(minBurstTime == p[i].burstTime)
			{
				minBurstFound = 1;
			}
		}
	}
	
	//setting processes in SJF order	
	while(SJFindex != n)
	{
		for(int i=0; i<n; i++)
		{
			if(p[i].burstTime == minBurstTime)
			{
				SJF[SJFindex] = p[i];
				SJFindex++;
			}
		}
		minBurstTime++;
	}
	

	//setting process turnaround times
	for(int i=0; i<n; i++)
	{
		SJF[i].turnaroundTime = time + SJF[i].burstTime;
		time = SJF[i].turnaroundTime;
		
		sumTurnaround = sumTurnaround + SJF[i].turnaroundTime;
	}
	
	
	//setting process waiting times
	for(int i=0; i<n; i++)
	{
		if(i==0)
		{
			SJF[i].waitingTime = 0;
		}
		else
		{
			SJF[i].waitingTime = SJF[i].turnaroundTime - SJF[i].burstTime;
		}
		
		sumWait = sumWait + SJF[i].waitingTime;
	}
	
	averageWait = sumWait/n;
	averageTurnaround = sumTurnaround/n;

	cout<<endl;
	cout<<"Processes arranged in SJF Algorithm"<<endl;
	cout<<"Process\t Burst Time\t Waiting Time\t Turnaround Time"<<endl;
	
	for(int i=0; i<n; i++)
	{
		cout<<"   "<<SJF[i].name<<"\t      "<<SJF[i].burstTime
		<<"\t\t       "<<SJF[i].waitingTime<<"\t\t"<<SJF[i].turnaroundTime<<endl;
	}
	
	cout<<endl;
	cout<<"Average Waiting Time = "<<averageWait<<endl;
	cout<<"Average Turnaround Time = "<<averageTurnaround<<endl;

}
