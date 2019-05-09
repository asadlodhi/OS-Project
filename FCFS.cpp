#include<iostream>

struct process
{
	char name;
	int arrivalTime;
	int burstTime;
	float turnaroundTime;
	float waitingTime;
};

using namespace std;
main()
{
	int n,a,b, minArrivalTime=-1, FCFSindex = 0, time=0, minTimeFound=0;
	float averageWait, averageTurnaround, sumWait=0, sumTurnaround=0;
	
	cout<<"Enter number of Processes:";
	cin>>n;
	process p[n], FCFS[n];
	
	//setting process names
	for(int i=0; i<n; i++)
	{
		p[i].name = 'A' + i;
	}
	
	//setting process arrival and burst times
	for(int i=0; i<n; i++)
	{
		cout<< "Enter Process "<<p[i].name<<" Arrival Time:";
		cin>>a;
		p[i].arrivalTime = a;
		cout<<"Enter Process "<<p[i].name<<" Burst Time:";
		cin>>b;
		p[i].burstTime = b;
	}
	
	//setting min arrival time
	while(minTimeFound == 0)
	{
		minArrivalTime++;
		for(int i=0; i<n; i++)
		{
			if(minArrivalTime == p[i].arrivalTime)
			{
				minTimeFound = 1;
			}
		}
	}
	
	//setting processes in FCFS order	
	while(FCFSindex != n)
	{
		for(int i=0; i<n; i++)
		{
			if(p[i].arrivalTime == minArrivalTime)
			{
				FCFS[FCFSindex] = p[i];
				FCFSindex++;
			}
		}
		minArrivalTime++;
	}
	
	time = FCFS[0].arrivalTime;
	
	//setting process turnaround times
	for(int i=0; i<n; i++)
	{
		FCFS[i].turnaroundTime = time + FCFS[i].burstTime;
		time = FCFS[i].turnaroundTime;
		
		sumTurnaround = sumTurnaround + FCFS[i].turnaroundTime;
	}
	
	time = FCFS[0].arrivalTime;
	
	//setting process waiting times
	for(int i=0; i<n; i++)
	{
		if(i==0)
		{
			FCFS[i].waitingTime = FCFS[i].turnaroundTime - FCFS[i].burstTime - time;
		}
		else
		{
			FCFS[i].waitingTime = FCFS[i].turnaroundTime - FCFS[i].burstTime;
		}
		
		sumWait = sumWait + FCFS[i].waitingTime;
	}
	
	averageWait = sumWait/n;
	averageTurnaround = sumTurnaround/n;

	cout<<endl;
	cout<<"Processes arranged in FCFS Algorithm"<<endl;
	cout<<"Process\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time"<<endl;
	
	for(int i=0; i<n; i++)
	{
		cout<<"   "<<FCFS[i].name<<"\t       "<<FCFS[i].arrivalTime<<"\t      "<<FCFS[i].burstTime
		<<"\t\t       "<<FCFS[i].waitingTime<<"\t\t"<<FCFS[i].turnaroundTime<<endl;
	}
	
	cout<<endl;
	cout<<"Average Waiting Time = "<<averageWait<<endl;
	cout<<"Average Turnaround Time = "<<averageTurnaround<<endl;

	
}
