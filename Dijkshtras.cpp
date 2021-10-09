//------------------------------------------------------------------------------------
/*
9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/
//------------------------------------------------------------------------------------
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{
	int V;
	vector<vector<int> > adjL;
	vector<int> dist;
	vector<vector<int>> weight;
	public:
	Graph(int V);
	void takeInput();
	void dijkshtras(int);
	void dijkshtrasUtil(int,vector<bool> &);
};
Graph::Graph(int V)
{
	this->V = V;
	adjL = vector<vector<int>> (V);
	dist = vector<int> (V,INT_MAX);
	weight = vector<vector<int>> (V);
}
void Graph::takeInput()
{
	int temp;
	for(int i = 0;i<V;i++)
	{
		for(int j = 0;j<V;j++)
		{
		//	cout<<endl<<i<<","<<j<<" = ";
			cin>>temp;
			if(temp)
			{
				weight[i].push_back(temp);
				adjL[i].push_back(j);
			}
			else
			{
				weight[i].push_back(-1);
			}
		}
	}
}
void Graph::dijkshtras(int S)
{
	vector<bool> vis(V,false);
	queue<int> q;
	vis[S] = true;
	q.push(S);
	dist[S] = 0;
	while(!q.empty())
	{
		int curr = q.front();
		vis[curr] = true;
		q.pop();
		for(int i : adjL[curr])
		{
			if(!vis[i])
			{
				q.push(i);
				if(dist[i] > dist[curr]+weight[curr][i])
					dist[i] = dist[curr]+weight[curr][i];
			}
				
		}
		
	}
	for(int i = 0;i<V;i++)
	{
		cout<<endl;
		if(dist[i]!=INT_MAX)
		cout<<i<<" "<<dist[i];
		else
		cout<<i<<" Inf";
	}
}
int main()
{
	int v;
	cin>>v;
	Graph G(v);
	G.takeInput();
	G.dijkshtras(0);
	return 0;
}
