#include <bits/stdc++.h>
using namespace std;
#define ROW 6
#define COL 6

struct Cell
{
	int a;
	int b;
};

struct queueNode
{
	Cell pt;  
	int dist;
};

bool checkValid(int row, int col)
{
	return ((row >= 0) && (row < ROW) &&	(col >= 0) && (col < COL));
}

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
 
int bfsLee(int mat[][COL], Cell src, Cell dest)
{
 
	if (!mat[src.a][src.b] || !mat[dest.a][dest.b])
		return -1;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);
	
	visited[src.a][src.b] = true;

	queue<queueNode> q;
	
	queueNode s = {src, 0};
	q.push(s); 

	while (!q.empty())
	{
		queueNode curr = q.front();
		Cell pt = curr.pt;

		if (pt.a == dest.a && pt.b == dest.b)
			return curr.dist;
		q.pop();
 
		for (int i = 0; i < 4; i++)
		{
			int row = pt.a + rowNum[i];
			int col = pt.b + colNum[i];
			
			if (checkValid(row, col) && mat[row][col] && 
			!visited[row][col])
			{
				
				visited[row][col] = true;
				queueNode Adjcell = { {row, col},
									curr.dist + 1 };
				q.push(Adjcell);
			}
		}
	}
	return -1;
}

int main()
{
	int mat[ROW][COL] =
	{
		{ 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1 },
		{ 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1 }};
     
	Cell source = {0, 0};
	Cell dest = {2, 1};

	int dist = bfsLee(mat, source, dest);

	if (dist != -1)
		cout<< "Length of the Shortest Path will be  "<<dist ;
	else
		cout<< "Shortest Path it doesn't exist";

	return 0;
}