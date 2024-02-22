#include <iostream>
#include <vector>

using namespace std;

const int INF = -1;

bool isSafe(int v, int c, const vector<vector<int>> &graph,
            const vector<int> &color) {
  for (int i = 0; i < graph.size(); ++i) {
    if (graph[v][i] && c == color[i]) {
      return false;
    }
  }
  return true;
}

bool graphColoringUtil(int v, int m, vector<int> &color,
                       const vector<vector<int>> &graph) {
  if (v == graph.size()) {
    return true; // Todos los nodos están coloreados
  }

  for (int c = 0; c < m; ++c) {
    if (isSafe(v, c, graph, color)) {
      color[v] = c;
      if (graphColoringUtil(v + 1, m, color, graph)) {
        return true;
      }
      color[v] = INF; // Backtracking
    }
  }

  return false;
}

void graphColoring(const vector<vector<int>> &graph) {
  const int numNodes = graph.size();
  vector<int> color(numNodes, INF); // Inicializar

  int m = 1; // Número de colores

  while (true) {
    if (graphColoringUtil(0, m, color, graph)) {
      // La coloración es posible con m colores
      for (int i = 0; i < numNodes; ++i) {
        cout << "Node: " << i << ", Assigned Color: " << color[i] << endl;
      }
      break;
    } else {

      ++m;
      fill(color.begin(), color.end(), INF);
    }

    if (m > numNodes) {
      cout << "No es posible asignar colores a los nodos." << endl;
      break;
    }
  }
}

int main() {
  int n;
  cout << "Ingrese el número de nodos en el grafo: ";
  cin >> n;

  vector<vector<int>> graph(n, vector<int>(n, 0));

  cout << "Ingrese la matriz de adyacencia del grafo (0 o 1) separados por un "
          "espacio:"
       << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> graph[i][j];
    }
  }

  cout << "Solución de la coloración del grafo:" << endl;
  graphColoring(graph);

  return 0;
}
