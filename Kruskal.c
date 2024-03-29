/* Kruskals Algorithm */

#include <stdio.h>
int i, j, k, a, b, u, v, n=5, ne = 1;
int min, mincost = 0, parent[5];
int cost[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
int find(int);
int uni(int, int);
void main()
{
	//printf("Enter the no. of vertices:");
	//scanf("%d", &n);
	//printf("Enter the adjacency matrix:\n");
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			//scanf("%d", &cost[i][j]);
			if(cost[i][j] == 0)
				cost[i][j] = 999;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)
	{
		min = 999;
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				if(cost[i][j] < min)
				{
					 min = cost[i][j];
					 a = u = i;
					 b = v = j;
				}
			}
		}
		u = find(u);
		v = find(v);
		if(uni(u, v))
		{
			printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
			mincost += min;
		}
		cost[a][b] = cost[b][a] = 999;
	}
	printf("Minimum cost = %d\n", mincost);
}
int find(int i)
{
	while(parent[i])
	i = parent[i];
	return i;
}
int uni(int i, int j)
{
	if(i != j)
	{
		parent[j] = i;
		return 1;
	}
	return 0;
}
