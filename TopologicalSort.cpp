#include<iostream>
#include<list>
#include<iterator>
#include<vector>
#include<stack>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	void TSUtil(int v,bool *vis,stack<int> &st);
	public:
		Graph(int V);
		void addEdge(int u,int v);
		void TSort();
		void ShowAdjList();
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int> [V];
}
void Graph::addEdge(int u,int v)
{
	cout<<endl<<"Adding (u,v) : ("<<u<<","<<v<<")"<<endl;
	adj[u].push_back(v);
}
void Graph::TSUtil(int v,bool vis[], stack<int> &st)
{
	vis[v] = true;
	list<int>::iterator i;
	for(i = adj[v].begin();i!= adj[v].end();i++)
		if(!vis[*i])
			TSUtil(*i,vis,st);
	st.push(v);
}
void Graph::TSort()
{
	bool *vis = new bool [V];
	for(int i = 0;i<V;i++)
		vis[i] = false;
	stack<int> st;
	for(int i = 0;i<V;i++)
		if(!vis[i])
			TSUtil(i,vis,st);
	while(!st.empty())
	{
		cout<<endl<<st.top();
		st.pop();
	}
}
void Graph::ShowAdjList()
{
	for(int i =0;i<V;i++)
	{
		cout<<endl<<i<<":";
		list<int>::iterator j;
		for(j = adj[i].begin();j!=adj[i].end();j++)
		{
			cout<<*j<<"-->";
		}
	}
}
int main(void)
{
	int V,E,u,v;
	cin>>V>>E;
	Graph G1(V);
	for(int i = 0;i<E;i++)
		G1.addEdge(u , v&(INT_MAX|scanf("%d",&u)|scanf("%d",&v)));
	G1.ShowAdjList();
	G1.TSort();
}



















