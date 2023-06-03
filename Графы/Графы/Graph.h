#pragma once
#include <string>
#include <vector>
#include <queue>
#include <iterator>
#include <iomanip>
using namespace std;

template <class T>
const T Infinity = 100000000;

template <class T>
class Graph;

template <class T>
class GraphVertex {
	friend class Graph<T>;
	string name;
	T vertex_weight;
public:
	GraphVertex(const string& name, const T& vertex_weight = NULL) {
		this->name = name;
		this->vertex_weight = vertex_weight;
	}
};

template <class T>
class Graph {
protected:
	vector<vector<T>> matrix;  
	vector<GraphVertex<T>> vertexes;

	bool allVisited(const vector<bool>& visited);
	GraphVertex<T>* findNotVisited(const vector<bool>& visited, const string& current_vertex);
	int getWidth();
	void fillWeights(const string& start_vertex);
	T TMTContinue(const string& start_vertex, const string& current_vertex, vector<bool> visited, vector<GraphVertex<T>*>& route, const T& prev_route);
	void continueDFS(const string& current_vertex, vector<bool>& visited, vector<GraphVertex<T>*>& route);
public:
	Graph() {}
	~Graph() {
		for (int i = 0; i < vertexes.size(); i++)
			matrix[i].clear();
		matrix.clear();
		vertexes.clear();
	}
	void addVertex(const string& name, const T& vertex_weight = NULL);
	void addEdge(const string& start_vertex, const string& end_vertex, const T& edge_weight = 0, const bool& direction = false);
	void deleteVertex(const string& name);
	void deleteEdge(const string& start_vertex, const string& end_vertex);
	void setEdgeWeight(const string& start_vertex, const string& end_vertex, const T& edge_weight = 0, const bool& direction = false);
	void setVertexName(const string& name, const string& new_name = "");

	bool isEdge(const string& start_vertex, const string& end_vertex);
	bool isVertex(const string& name);
	bool isWeighted();

	void printMatrix();
	vector<GraphVertex<T>*> DFS(const string& start_vertex);
	vector<GraphVertex<T>*> BFS(const string& start_vertex);
	vector<GraphVertex<T>*> getNeighbours(const string& start_vertex);
	int getVertexIndex(const string& name);
	string getRouteForSearch(const vector<GraphVertex<T>*>& route);

	void Dijkstra(const string& start_vertex);
	string getAnswerForDijkstra(const vector<GraphVertex<T>*>& route);

	vector<GraphVertex<T>*> TMT(const string& start_vertex);
	vector<GraphVertex<T>*> whatNeighbour(const string& start_vertex);
	string getRouteForTMT(const vector<GraphVertex<T>*>& route);
};

template <class T>
void Graph<T>::addVertex(const string& name, const T& vertex_weight) {
	vertexes.push_back(GraphVertex<T>(name, vertex_weight));
	for (int i = 0; i < matrix.size(); i++)
		matrix[i].push_back(-1);
	matrix.push_back(vector<T>(vertexes.size(), -1));
}

template <class T>
void Graph<T>::addEdge(const string& start_vertex, const string& end_vertex, const T& edge_weight, const bool& direction) {
	int i = getVertexIndex(start_vertex);
	int j = getVertexIndex(end_vertex);
	if (direction) matrix[i][j] = edge_weight;
	else matrix[i][j] = matrix[j][i] = edge_weight;
}

template <class T>
bool Graph<T>::isVertex(const string& name) {
	return getVertexIndex(name) != -1;
}

template <class T>
void Graph<T>::printMatrix(){
	if (vertexes.size() != 0) {
		cout << "Matrix:\n";
		cout << "Signs:\n'X' - there is no path.\n'?' - the path length is not defined.\n\n";
		int width = getWidth();
		for (int i = 0; i < width; i++)
			cout << " ";
		cout << "|";
		for (int i = 0; i < vertexes.size(); i++) 
			cout << setw(width) << vertexes[i].name << "|";
		cout << endl;
		for (int i = 0; i < vertexes.size(); i++) {
			cout << vertexes[i].name;
			for (int l = 0; l < width - vertexes[i].name.size(); l++)
				cout << " ";
			cout << "|";
			for (int j = 0; j < vertexes.size(); j++) {
				if (matrix[i][j] == -1) cout << setw(width) << "X";
				else
					if (matrix[i][j] == 0) cout << setw(width) << "?";
					else cout << setw(width) << setprecision(width) << matrix[i][j];
				cout << "|";
			}
			cout << endl;
		}
	}
	else
		cout << "The matrix does not exist!\n";
	cout << endl;
}

template <class T>
int Graph<T>::getWidth() {
	int max = 0;
	for (int i = 0; i < vertexes.size(); i++) {
		if (vertexes[i].name.size() > max) max = vertexes[i].name.size();
	}
	if (typeid(T) == typeid(int&)) {
		for (int i = 0; i < vertexes.size(); i++) {
			for (int j = 0; j < vertexes.size(); j++) {
				if (to_string(matrix[i][j]).size() > max) max = to_string(matrix[i][j]).size();
			}
		}
	}
	else {
		for (int i = 0; i < vertexes.size(); i++){
			for (int j = 0; j < vertexes.size(); j++){
				if (to_string(int(matrix[i][j]) + 3).size() > max)
					max = to_string(matrix[i][j]).size();
			}
		}
	}
	return max;
}

template <class T>
void Graph<T>::deleteVertex(const string& name) {
	vector<GraphVertex<T>>::template iterator v = vertexes.begin();
	vector<vector<T>>::template iterator m = matrix.begin();
	GraphVertex<T> vrtx = *v;
	int k = 0;
	while (vrtx.name != name) {
		v++;
		m++;
		k++;
		vrtx = *v;
	}
	vertexes.erase(v);
	matrix.erase(m);
	for (int i = 0; i < vertexes.size(); i++) {
		vector<T>::template iterator m1 = matrix[i].begin();
		for (int j = 0; j < k; j++)
			m1++;
		matrix[i].erase(m1);
	}
}

template <class T>
void Graph<T>::deleteEdge(const string& start_vertex, const string& end_vertex) {
	int i_1 = 0;
	int i_2 = 0;
	for (int i = 0; i < vertexes.size(); i++) {
		if (vertexes[i].name == start_vertex) i_1 = i;
		else if (vertexes[i].name == end_vertex) i_2 = i;
	}
	matrix[i_1][i_2] = -1;
}

template <class T>
void Graph<T>::setEdgeWeight(const string& start_vertex, const string& end_vertex, const T& edge_weight, const bool& direction) {
	int i_1 = 0, i_2 = 0;
	for (int i = 0; i < vertexes.size(); i++) {
		if (vertexes[i].name == start_vertex) i_1 = i;
		else if (vertexes[i].name == end_vertex) i_2 = i;
	}
	if (!direction) matrix[i_1][i_2] = matrix[i_2][i_1] = edge_weight;
	else matrix[i_1][i_2] = edge_weight;
}

template <class T>
bool Graph<T>::isEdge(const string& start_vertex, const string& end_vertex) {
	int i_1 = 0, i_2 = 0;
	for (int i = 0; i < vertexes.size(); i++) {
		if (vertexes[i].name == start_vertex) i_1 = i;
		else if (vertexes[i].name == end_vertex) i_2 = i;
	}
	return matrix[i_1][i_2] != -1;
}

template <class T>
void Graph<T>::setVertexName(const string& name, const string& new_name) {
	int i = 0;
	while (vertexes[i].name != name && i < vertexes.size())
		i++;
	vertexes[i].name = new_name;
}

template <class T>
vector<GraphVertex<T>*> Graph<T>::DFS(const string& start_vertex) {
	vector<GraphVertex<T>*> route;
	GraphVertex<T>* temp = new GraphVertex<T>(start_vertex);
	route.push_back(temp);
	vector<bool> visited(vertexes.size());
	fill(visited.begin(), visited.end(), false);
	visited[getVertexIndex(start_vertex)] = true;
	vector<GraphVertex<T>*> neighbours = getNeighbours(start_vertex);
	for (int i = 0; i < neighbours.size(); i++) {
		if (!visited[getVertexIndex(neighbours[i]->name)])
			continueDFS(neighbours[i]->name, visited, route);
	}
	return route;
}

template <class T>
void Graph<T>::continueDFS(const string& current_vertex, vector<bool>& visited, vector<GraphVertex<T>*>& route) {
	GraphVertex<T>* temp = new GraphVertex<T>(current_vertex);
	route.push_back(temp);
	visited[getVertexIndex(current_vertex)] = true;
	vector<GraphVertex<T>*> neighbours = getNeighbours(current_vertex);
	for (int i = 0; i < neighbours.size(); i++) {
		if (!visited[getVertexIndex(neighbours[i]->name)])
			continueDFS(neighbours[i]->name, visited, route);
	}
}

template <class T>
vector<GraphVertex<T>*> Graph<T>::getNeighbours(const string& start_vertex) {
	int i = getVertexIndex(start_vertex);
	vector<GraphVertex<T>*> neighbours;
	for (int j = 0; j < vertexes.size(); j++)
		if (matrix[i][j] != -1)
			neighbours.push_back(&vertexes[j]);
	return neighbours;
}

template <class T>
int Graph<T>::getVertexIndex(const string& name) {
	int i = vertexes.size() - 1;
	bool f = vertexes[i].name == name;
	while (!f && i > 0){
		i--;
		f = vertexes[i].name == name;
	}
	if (f) return i;
	else return -1;
}

template <class T>
vector<GraphVertex<T>*> Graph<T>::BFS(const string& start_vertex) {
	vector<bool> visited(vertexes.size());
	fill(visited.begin(), visited.end(), false);
	queue<GraphVertex<T>*> q;
	vector<GraphVertex<T>*> route;
	q.push(&vertexes[getVertexIndex(start_vertex)]);
	while (!q.empty()) {
		GraphVertex<T> current_vertex = *q.front();
		route.push_back(q.front());
		visited[getVertexIndex(current_vertex.name)] = true;
		q.pop();
		vector<GraphVertex<T>*> neighbours = getNeighbours(current_vertex.name);
		for (int i = 0; i < neighbours.size(); i++) {
			if (!visited[getVertexIndex(neighbours[i]->name)]) {
				visited[getVertexIndex(neighbours[i]->name)] = true;
				q.push(neighbours[i]);
			}
		}
	}
	return route;
}

template <class T>
bool Graph<T>::isWeighted() {
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[i].size(); j++)
			if (matrix[i][j] == 0) return false;
	return true;
}

template <class T>
void Graph<T>::Dijkstra(const string& start_vertex) {
	vector<bool> visited(vertexes.size());
	fill(visited.begin(), visited.end(), false);
	fillWeights(start_vertex);
	int current_index = getVertexIndex(start_vertex);
	GraphVertex<T>* current_vertex = &vertexes[current_index];
	while (!allVisited(visited)) {
		GraphVertex<T>* min_neighbour = nullptr;
		T min_weight = Infinity<T>;
		vector<GraphVertex<T>*> neighbours = getNeighbours(current_vertex->name);
		for (int i = 0; i < neighbours.size(); i++) {
			int neighbour_index = getVertexIndex(neighbours[i]->name);
			T edge_weight = matrix[current_index][neighbour_index];
			if (current_vertex->vertex_weight + edge_weight < neighbours[i]->vertex_weight) {
				neighbours[i]->vertex_weight = current_vertex->vertex_weight + edge_weight;
			}
			if (!visited[neighbour_index] && min_weight > edge_weight) {
				min_weight = neighbours[i]->vertex_weight;
				min_neighbour = neighbours[i];
			}
		}
		visited[current_index] = true;
		if (min_neighbour != nullptr) {
			current_vertex = min_neighbour;
			current_index = getVertexIndex(current_vertex->name);
		}
		else {
			if (!allVisited(visited)) {
				current_vertex = findNotVisited(visited, start_vertex);
				current_index = getVertexIndex(current_vertex->name);
			}
		}
	}
}

template <class T>
GraphVertex<T>* Graph<T>::findNotVisited(const vector<bool>& visited, const string& current_vertex) {
	vector<GraphVertex<T>*> neighbours = getNeighbours(current_vertex);
	bool f = false;
	for (int i = 0; i < neighbours.size() && !f; i++) {
		f = !visited[getVertexIndex(neighbours[i]->name)];
		if (f) return neighbours[i];
	}
	if (!f) {
		if (neighbours.size() == 0) return nullptr;
		GraphVertex<T>* V;
		for (int i = 0; i < neighbours.size() && !f; i++) {
			V = findNotVisited(visited, neighbours[i]->name);
			if (V != nullptr) return V;
		}
	}
}

template <class T>
void Graph<T>::fillWeights(const string& start_vertex) {
	for (int i = 0; i < vertexes.size(); i++) {
		if (vertexes[i].name == start_vertex)
			vertexes[i].vertex_weight = 0;
		else
			vertexes[i].vertex_weight = Infinity<T>;
	}
}

template <class T>
bool Graph<T>::allVisited(const vector<bool>& visited) {
	for (int i = 0; i < visited.size(); i++) 
		if (visited[i] == false) return false;
	return true;
}

template <class T>
vector<GraphVertex<T>*> Graph<T>::TMT(const string& start_vertex) {
	vector<GraphVertex<T>*> route;
	vector<GraphVertex<T>*> neighbours = whatNeighbour(start_vertex);
	int start_index = getVertexIndex(start_vertex);
	vector<bool> visited(vertexes.size());
	fill(visited.begin(), visited.end(), false);
	visited[start_index] = true;
	vertexes[start_index].vertex_weight = Infinity<T>;
	for (int i = 0; i < neighbours.size(); i++) {
		int neighbour_index = getVertexIndex(neighbours[i]->name);
		T edge_weight = matrix[neighbour_index][start_index];
		T neighbour_weight = TMTContinue(start_vertex, neighbours[i]->name, visited, route, edge_weight);
		if (neighbour_weight + edge_weight <= vertexes[start_index].vertex_weight)
			route.push_back(neighbours[i]);
	}
	route.push_back(&vertexes[start_index]);
	return route;
}

template <class T>
T Graph<T>::TMTContinue(const string& start_vertex, const string& current_vertex, vector<bool> visited, vector<GraphVertex<T>*>& route, const T& prev_route) {
	if (prev_route >= vertexes[getVertexIndex(start_vertex)].vertex_weight) return Infinity<T>;
	vector<GraphVertex<T>*> neighbours = whatNeighbour(current_vertex);
	int current_index = getVertexIndex(current_vertex);
	visited[current_index] = true;
	vertexes[current_index].vertex_weight = Infinity<T>;
	for (int i = 0; i < neighbours.size(); i++) {
		int neighbour_index = getVertexIndex(neighbours[i]->name);
		T edge_weight = matrix[neighbour_index][current_index];
		if (neighbours[i]->name == start_vertex) {
			if (allVisited(visited)) {
				if (prev_route + edge_weight < vertexes[getVertexIndex(start_vertex)].vertex_weight) {
					vertexes[getVertexIndex(start_vertex)].vertex_weight = prev_route + edge_weight;
					vertexes[current_index].vertex_weight = edge_weight;
					route.clear();
					route.push_back(neighbours[i]);
					return edge_weight;
				}
			}
			else {
				if (neighbours.size() == 1)
					return Infinity<T>;
			}
		}
		else {
			if (!visited[neighbour_index]) {
				T neighbour_weight = TMTContinue(start_vertex, neighbours[i]->name, visited, route, prev_route + edge_weight);
				if (neighbour_weight + edge_weight < vertexes[current_index].vertex_weight) {
					route.push_back(neighbours[i]);
					vertexes[current_index].vertex_weight = neighbour_weight + edge_weight;
				}
			}
		}
	}
	return vertexes[current_index].vertex_weight;
}

template <class T>
vector<GraphVertex<T>*> Graph<T>::whatNeighbour(const string& start_vertex) {
	int j = getVertexIndex(start_vertex);
	vector<GraphVertex<T>*> neighbours;
	for (int i = 0; i < vertexes.size(); i++)
		if (matrix[i][j] > 0) neighbours.push_back(&vertexes[i]);
	return neighbours;
}

template <class T>
string Graph<T>::getRouteForTMT(const vector<GraphVertex<T>*>& route) {
	string r = route[0]->name;
	for (int i = 1; i < route.size(); i++)
		r += " - " + route[i]->name;
	r += "\n" + to_string(matrix[getVertexIndex(route[0]->name)][getVertexIndex(route[1]->name)]);
	for (int i = 1; i < route.size() - 1; i++)
		r += " + " + to_string(matrix[getVertexIndex(route[i]->name)][getVertexIndex(route[i + 1]->name)]);
	r += " = " + to_string(route[0]->vertex_weight);
	return r;
}

template <class T>
string Graph<T>::getRouteForSearch(const vector<GraphVertex<T>*>& route) {
	string r = route[0]->name;
	for (int i = 1; i < route.size(); i++) 
		r += " - " + route[i]->name;
	return r;
}

template <class T>
string Graph<T>::getAnswerForDijkstra(const vector<GraphVertex<T>*>& route) {
	string r = "";
	for (int i = 0; i < route.size(); ++i) {
		if (i != route.size() - 1)
			r += route[i]->name + " = " + to_string(route[i]->vertex_weight) + ", ";
		else
			r += route[i]->name + " = " + to_string(route[i]->vertex_weight) + ";";
		if (i % 5 == 4)
			r += "\n";
	}
	return r;
}