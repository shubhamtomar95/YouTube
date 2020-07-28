#include <bits/stdc++.h>
using namespace std;
unordered_map<int, priority_queue<int>* > node_pq_map;

void dfs(int start_node, vector<vector<int> > &adj_list,vector<bool> &visited, priority_queue<int>* components, vector<int> &input)
{
	if(visited[start_node]) return ;	
	visited[start_node] = true;
	
	components->push(input[start_node - 1]);
	
	vector<int> adjacent = adj_list[start_node];
	if (!adjacent.size()) node_pq_map[start_node] = components;
	
	for ( int node : adjacent )
	{	
		node_pq_map[node] = components;
		dfs(node,adj_list,visited,components, input);
	}
	return ;
}

void generate_connected_components(vector<vector<int> > &adj_list, vector<int> original)
{
	int num_nodes = (int)adj_list.size() - 1;
	vector<bool> visited(num_nodes + 1, false);
	for (int node = 1 ; node <= num_nodes ; node += 1)
	{
		priority_queue<int>* single_component  = new priority_queue<int>();
 
		dfs(node, adj_list, visited, single_component, original);
	}
	return ;
}
 
vector<int> get_lexicographically_largest_permutation(int num_nodes)
{
	vector<int> solution;
 
	priority_queue<int> *max_heap;
	int number;
	int node = 0;
	
	for (int node = 1; node <= num_nodes ; node += 1)
	{
		max_heap = node_pq_map[node];
		assert(max_heap);	
		number = max_heap->top();
		solution.push_back(number);
		max_heap->pop();
	}
 
	return solution;
}
 
 
 
void solve()
{
	int size, edges;
	scanf("%d%d",&size, &edges);
	vector<int> original(size);
	for (int i = 0 ; i < size ; i++) scanf("%d", &original[i]);
	vector<vector<int> > adj_list(size + 1);
 
	for(int edge = 1 ; edge <= edges ; edge += 1)
	{
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		adj_list[v1].push_back(v2);
		adj_list[v2].push_back(v1);
	}

	generate_connected_components(adj_list,original);
	vector<int> solution = get_lexicographically_largest_permutation(size);
	for (int x : solution) cout << x << " ";
	cout << endl;
}
 
 
 
int main(int argc, char const *argv[])
{
	solve();
	return 0;
}
