#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>
#include "Set.h"
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"

template <typename T = int>
class Graph {
protected:
  std::vector<std::vector<T>> adjMatrix;
  int numVertices;
  bool isDirected;
  bool isWeighted;

  struct Edge {
    int src, dest;
    T weight;
    
    Edge(int s, int d, T w) : src(s), dest(d), weight(w) {}
    
    bool operator>(const Edge& other) const {
      return weight > other.weight;
    }

    bool operator<(const Edge& other) const {
      return weight < other.weight;
    }
  };

  void DFSRecIt(int vertex, std::vector<bool>& visited) {
    visited[vertex] = 1;
    std::cout << "Analizando " << vertex << ": " << std::endl;
    for(int i = 0; i < numVertices; ++i) {
      if(adjMatrix[vertex][i] != 0 && adjMatrix[vertex][i] != std::numeric_limits<T>::max()) {
        if(!visited[i]) {
          std::cout << "Vamos a apilar recursivamente " << i << std::endl;
          DFSRecIt(i, visited);
        }
      }
    }

    return;
  }

  void topologicalSortRec(int vertex, std::vector<bool>& visited, Stack<int>& result) {
    visited[vertex] = true;
    
    for(int i = 0; i < numVertices; ++i) {
      if(adjMatrix[vertex][i] != 0 && adjMatrix[vertex][i] != std::numeric_limits<T>::max()) {
        if(!visited[i]) {
          topologicalSortRec(i, visited, result);
        }
      }
    }
    
    result.push(vertex);
  }

  int findParent(std::vector<int>& parent, int i) {
    if(parent[i] != i)
      parent[i] = findParent(parent, parent[i]);
    return parent[i];
  }

  void unionSets(std::vector<int>& parent, std::vector<int>& rank, int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);
    
    if(rank[xroot] < rank[yroot]) {
      parent[xroot] = yroot;
    } else if(rank[xroot] > rank[yroot]) {
      parent[yroot] = xroot;
    } else {
      parent[yroot] = xroot;
      rank[xroot]++;
    }
  }

public:
  Graph(int vertices, bool directed = false, bool weighted = false) 
    : numVertices(vertices), isDirected(directed), isWeighted(weighted) {
    
    T infinity = weighted ? std::numeric_limits<T>::max() : T(0);
    adjMatrix.resize(vertices, std::vector<T>(vertices, infinity));
    
    for(int i = 0; i < vertices; ++i)
      adjMatrix[i][i] = T(0);
  }

  void addEdge(int src, int dest, T weight = T(1)) {
    if(src < 0 || src >= numVertices || dest < 0 || dest >= numVertices)
      throw std::runtime_error("Vértice inválido");
    
    adjMatrix[src][dest] = weight;
    
    if(!isDirected)
      adjMatrix[dest][src] = weight;
  }

  void removeEdge(int src, int dest) {
    if(src < 0 || src >= numVertices || dest < 0 || dest >= numVertices)
      throw std::runtime_error("Vértice inválido");
    
    T infinity = isWeighted ? std::numeric_limits<T>::max() : T(0);
    adjMatrix[src][dest] = infinity;
    
    if(!isDirected)
      adjMatrix[dest][src] = infinity;
  }

  bool hasEdge(int src, int dest) {
    if(src < 0 || src >= numVertices || dest < 0 || dest >= numVertices)
      return false;
    
    T infinity = isWeighted ? std::numeric_limits<T>::max() : T(0);
    return adjMatrix[src][dest] != infinity && adjMatrix[src][dest] != T(0);
  }

  T getWeight(int src, int dest) {
    if(src < 0 || src >= numVertices || dest < 0 || dest >= numVertices)
      throw std::runtime_error("Vértice inválido");
    
    return adjMatrix[src][dest];
  }

  Set<int> getNeighbors(int vertex) {
    if(vertex < 0 || vertex >= numVertices)
      throw std::runtime_error("Vértice inválido");
    
    Set<int> neighbors;
    T infinity = isWeighted ? std::numeric_limits<T>::max() : T(0);
    
    for(int i = 0; i < numVertices; ++i) {
      if(i != vertex && adjMatrix[vertex][i] != infinity && adjMatrix[vertex][i] != T(0))
        neighbors.insert(i);
    }
    
    return neighbors;
  }

  void BFS(int startVertex) {
    Queue<int> Q;
    std::vector<bool> visited;
    visited.resize(this->numVertices, 0);
    Q.enqueue(startVertex);
    visited[startVertex] = 1;

    while(!Q.isEmpty()) {
      int u = Q.dequeue();
      std::cout << "Analizando " << u << ": " << std::endl;
      for(int i = 0; i < this->numVertices; ++i) {
        if((adjMatrix[u][i] != 0 && adjMatrix[u][i] != std::numeric_limits<T>::max()) && visited[i] == 0) {
          visited[i] = 1;
          Q.enqueue(i);
          std::cout << "Vamos a encolar " << i << std::endl;
        }
      }
    }

    return;
  }

  void DFSRec(int startVertex) {
    std::vector<bool> visited(numVertices, 0);
    return DFSRecIt(startVertex, visited);
  }

  void DFS(int startVertex) {
    Stack<int> S;
    std::vector<bool> visited;
    visited.resize(numVertices, 0);
    S.push(startVertex);
    visited[startVertex] = 1;

    while(!S.isEmpty()) {
      int u = S.pop();
      std::cout << "Analizando " << u << ": " << std::endl;
      for(int i = 0; i < numVertices; ++i) {
        if(adjMatrix[u][i] != 0 && adjMatrix[u][i] != std::numeric_limits<T>::max() && visited[i] == 0) {
          visited[i] = 1;
          S.push(i);
          std::cout << "Vamos a apilar " << i << std::endl;
        }
      }
    }

    return;
  }

  void topologicalSort(int startVertex) {
    std::vector<bool> visited(numVertices, false);
    Stack<int> result;
    
    topologicalSortRec(startVertex, visited, result);
    
    std::cout << "Topological sort: ";
    while(!result.isEmpty()) {
      std::cout << result.pop() << " ";
    }
    std::cout << std::endl;
  }

  Set<Edge> kruskal() {
    if(isDirected)
      throw std::runtime_error("Kruskal solo funciona en grafos no dirigidos");
    
    // TODO: implementar Kruskal usando Set para el MST
    Set<Edge> MST;
    return MST;
  }

  Set<Edge> prim(int startVertex = 0) {
    if(isDirected)
      throw std::runtime_error("Prim solo funciona en grafos no dirigidos");
    
    // TODO: implementar Prim usando Set para visited y MST
    Set<Edge> MST;
    return MST;
  }

  std::vector<T> dijkstra(int startVertex) {
    // TODO: implementar Dijkstra usando Set para visited
    std::vector<T> distances(numVertices, std::numeric_limits<T>::max());
    distances[startVertex] = T(0);
    
    return distances;
  }

  void print() {
    std::cout << "Matriz de Adyacencia:" << std::endl;
    std::cout << "   ";
    for(int i = 0; i < numVertices; ++i)
      std::cout << " [" << i << "]";
    std::cout << std::endl;
    
    for(int i = 0; i < numVertices; ++i) {
      std::cout << "[" << i << "]";
      for(int j = 0; j < numVertices; ++j) {
        if(isWeighted && adjMatrix[i][j] == std::numeric_limits<T>::max())
          std::cout << "  ∞ ";
        else
          std::cout << "  " << adjMatrix[i][j] << " ";
      }
      std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;
  }

  int getNumVertices() const { return numVertices; }
  bool getIsDirected() const { return isDirected; }
  bool getIsWeighted() const { return isWeighted; }
};