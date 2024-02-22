#include <stdio.h>
#include<iostream>
#include<vector>
using namespace std;

// Tamaño del laberinto
bool solveMazeUtil(vector<vector<int>>, int, int, vector<vector<int>>, int, int);


/* Una función de utilidad para imprimir la matriz de solución sol[N][N] */
void printSolution(vector<vector<int>> sol, int N, int M)
{
    cout << "\nSolucion: " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}


/* Una función de utilidad para verificar si x, y es un índice válido para el laberinto N*N */
bool isSafe(vector<vector<int>> maze, int x, int y, int N, int M){
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
    {        // if (x, y outside maze) return false
        return true;
    }
    return false;
}


/* Esta función resuelve el problema del laberinto utilizando Backtracking. principalmente
usa solveMazeUtil() para resolver el problema. Devuelve falso si no la ruta es posible, de lo
contrario, devuelve verdadero e imprime la ruta en la formade 1s. Tenga en cuenta que puede
haber más de una solución, esta función imprime una de las soluciones factibles.*/
bool solveMaze(vector<vector<int>> maze, int N, int M)
{
    vector<vector<int>> solve(N, vector<int>(M, 0));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            solve[i][j] = 0;
        }
    }
    if (solveMazeUtil(maze, 0, 0, solve, N, M) == false)
    {
        printf("No existe esta solucion");
        return false;
    }
    return true;
}


/* Una función de utilidad recursiva para resolver el problema del laberinto */
bool solveMazeUtil(vector<vector<int>> maze, int x, int y, vector<vector<int>> sol, int N, int M)
{  // if (x, y is goal) return true
    if (x == N -1 && y == M -1)
    {
        sol[x][y] = 1;
        printSolution(sol, N, M);
        return true;
    }

    if (isSafe(maze, x, y, N, M) == true)
    {    // Comprobar si laberinto[x][y] es válido
        if(sol[x][y] == 1)    // mark x, y as part of solution path
        {
            return false;
        }
        sol[x][y] = 1;

        /* Avanzar en la dirección x */

        if (solveMazeUtil(maze, x + 1, y, sol, N, M) == true)
        {
            return true;
        }

        /* Si moverse en la dirección x no da solución entonces Mover hacia abajo en la dirección y */

        if (solveMazeUtil(maze, x, y + 1, sol, N, M) == true)
        {
            return true;
        }
        if (solveMazeUtil(maze, x - 1, y, sol, N, M) == true)
        {
            return true;
        }
        if (solveMazeUtil(maze, x, y - 1, sol, N, M) == true)
        {
            return true;
        }

        /* Si ninguno de los movimientos anteriores funciona, entonces BACKTRACK: desmarque x, y
        como parte de la ruta de la solución */
        sol[x][y] = 0;
        return false;
    }
    return false;
}

// programa main para probar la función anterior
int main()
{
    int N = 0;
    int M = 0;
    while (N <=1 && M <= 1)
    {
        if(M <=1)
        {
            cout<<"Escribe el ancho del laberinto: ";
            cin>>M;
        }
        if(N <=1)
        {
            cout<<"Escribe el largo del laberinto: ";
            cin>>N;
        }
        if(N <= 1 || M <= 1)
        {
            cout<<"Alguno de los valores es invalido."<<endl<<endl;
        }
    }

    vector<vector<int>> maze(N, vector<int>(M, 0));
    int val=-1;
    cout<<"Introduce 1 para hacer valida la casilla y 0 para hacerla invalida"<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            while(val != 0 && val != 1)
            {
                cout<<"Casilla ["<<i<<"], ["<<j<<"]: ";
                cin>>val;
            }
            maze[i][j] = val;
            val = -1;
        }
    }

    solveMaze(maze,N,M);
    return 0;
}