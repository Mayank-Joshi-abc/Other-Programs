#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
class DSDS{
	int V;
	vector<int> parent;
	vector<pair<int,int>> edge;
	int findParent(int u);
	public:
		DSDS(int V);
		void Display();
		int Union(int u , int v);
		void addEdge(int u,int v);
		void setup();
};
DSDS::DSDS(int V)
{
	this->V = V;
	int i = 0;
	while(i<V)
	{
		parent.push_back(-1);
		i++;
	}
}
void DSDS::Display()
{
	cout<<endl;
	for(int i=0;i<V;i++)
		cout<<setw(3)<<i;
	cout<<endl;
	for(int i=0;i<V;i++)
		cout<<setw(3)<<parent[i];
	cout<<endl;
}
int DSDS::Union(int u,int v)
{
	int pu = findParent(u);
	int pv = findParent(v);
	if(pu == pv)
	{
		cout<<"\nCycle detected\n";
		return 0;
	}
	else
		pu<pv?parent[v]=u:parent[u]=v;
	return 1;
}
void DSDS::addEdge(int u,int v)
{
	edge.push_back({u,v});
}
int DSDS::findParent(int u)
{
	if(parent[u] == -1)
		return u;
	else
		return findParent(parent[u]);
}
void DSDS::setup()
{
	for(int i = 0; i != edge.size()&&Union(edge[i].first,edge[i].second); i++);
}
int main()
{
	int V,E;
	int u,v;
	cin>>V>>E;
	DSDS G(V);
	for(int i =0;i<E;i++)
		G.addEdge(u,v&(INT_MAX|scanf("%d%d",&u,&v)));
	G.Display();
	G.setup();
	G.Display();
	return 0;
}
