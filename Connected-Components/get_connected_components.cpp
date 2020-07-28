#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int> > &adj_list, int node, vector<bool> &visited,unordered_set<int>* single_component)
{
	if(visited[node]) return;
	visited[node] = true;
	single_component->insert(node);
	vector<int> adj_nodes = adj_list[node];
	for (int neighbour : adj_nodes)
	{
		dfs(adj_list, neighbour, visited, single_component);
	}
}

unordered_set<unordered_set<int> * > get_connected_components(vector<vector<int> > &adj_list, int num_nodes)
{
	vector<bool> visited(num_nodes + 1, false);
	unordered_set<unordered_set<int> *> all_components;
	for ( int node = 1 ; node <= num_nodes ; node += 1)
	{
		unordered_set<int> *single_component = new unordered_set<int>();
		dfs(adj_list,node, visited , single_component);
		if (single_component->size() > 0) 
		{
			all_components.insert(single_component);
		}
	}
	return all_components;
}


int main(int argc, char const *argv[])
{
	int num_nodes;
	cin >> num_nodes;
	
	vector<vector<int> > adj_list(num_nodes + 1);

	int egde_count;
	cin >> egde_count;
	
	for (int edge = 1; edge <= egde_count ; edge += 1)
	{
		int v1, v2;
		cin >> v1 >> v2;
		adj_list[v1].push_back(v2);
		adj_list[v2].push_back(v1);
	}
	unordered_set<unordered_set<int> * > connected_components = get_connected_components(adj_list, num_nodes);
	
	unordered_set<unordered_set<int>*>::iterator it = connected_components.begin();
	while(it != connected_components.end())
	{
		unordered_set<int>* component = *it;
		unordered_set<int>::iterator it2 = component->begin();
		while (it2 != component->end())
		{
			cout << *(it2) << " ";
			it2++;
		}
		cout << endl;
		it++;
	}



	return 0;
}