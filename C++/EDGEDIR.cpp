#include <bits/stdc++.h>

using namespace std;

bool edgeDiscovered(int a, int b, std::set < long long >& validEdges){
	if(validEdges.find(a*100000ll + b) != validEdges.end()){
		return true;
	}
	return false;
}

void dfs(int n, int root, vector < bool >& isNodeDiscovered, vector < vector < int > >& edges,std::vector < std::vector < int > >& outgoingEdges, std::set < long long >& validEdges){
	isNodeDiscovered[n] = true;
	for(int i = 0; i < outgoingEdges[n].size(); i++){
		if(!isNodeDiscovered[outgoingEdges[n][i]]){
			dfs(outgoingEdges[n][i], n, isNodeDiscovered, edges, outgoingEdges, validEdges);
		}
	}

	std::vector < int > remainingEdges{};
	for(int i = 0; i < outgoingEdges[n].size(); i++){
		if(outgoingEdges[n][i] != root && !edgeDiscovered(n, outgoingEdges[n][i], validEdges) && !edgeDiscovered(outgoingEdges[n][i], n, validEdges)){
			remainingEdges.push_back(outgoingEdges[n][i]);
		}
	}

	if(remainingEdges.size()%2){
		for(int i = 0; i < remainingEdges.size(); i++){
			validEdges.insert(n*100000ll + remainingEdges[i]);
		}
		validEdges.insert(n*100000ll + root);
	}
	else{
		for(int i = 0; i < remainingEdges.size(); i++){
			validEdges.insert(n*100000ll + remainingEdges[i]);
		}
	}
}

void f(){
	int n, m;
	cin >> n >> m;
	if(m%2){
		int j, k;
		for(int i = 0; i < m; i++){
			std::cin >> j >> k;
		}
		std::cout << "-1\n";
		return;
	}
	std::vector < bool > isNodeDiscovered(n, false);
	std::vector < std::vector < int > > edges(m, std::vector < int >(2, 0));
	vector < std::vector < int > > outgoingEdges(n);
	for(int i = 0; i < m; i++){
		cin >> edges[i][0] >> edges[i][1];
		edges[i][0]--;
		edges[i][1]--;
		outgoingEdges[edges[i][0]].push_back(edges[i][1]);
		outgoingEdges[edges[i][1]].push_back(edges[i][0]);
	}

	std::set < long long > validEdges{};
	dfs(0, 0, isNodeDiscovered, edges, outgoingEdges, validEdges);
	for(int i = 0; i < m; i++){
		if(edgeDiscovered(edges[i][0], edges[i][1], validEdges)){
			cout << "1 ";
		}
		else{
			std::cout << "0 ";
		}
	}
	std::cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		f();
	}
	return 0;
}
