#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
class Process{
	public:
	int pid;
	int arrivalTime;
	int burstTime;
	void input(int,int,int);
};
void Process::input(int a,int b,int c)
{
	pid = a;
	arrivalTime = b;
	burstTime =c;
}
bool SORT(Process a,Process b)
{
	if(a.burstTime!=b.burstTime)
		return a.burstTime<b.burstTime;
	if(a.arrivalTime!=b.arrivalTime)
		return a.arrivalTime<b.arrivalTime;
	return a.pid<b.pid;
}
int main()
{
	int pid,arrivalTime,burstTime;
	int nop;
	cin>>nop;
	Process P[nop];
	for(int i = 0;i<nop;i++)
	{
		cin>>pid>>arrivalTime>>burstTime;
		P[i].input(pid,arrivalTime,burstTime);
	}
	sort(P,P+nop,SORT);
	for(int i = 0;i<nop;i++)
	{
		cout<<endl<<P[i].pid<<" "<<P[i].arrivalTime<<" "<<P[i].burstTime;
		// P[i].input(pid,arrivalTime,burstTime);
	}
	return 0;
}