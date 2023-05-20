#include <bits/stdc++.h> 
using namespace std; 
#define N 9 

bool isSafe(int grid[N][N],int row, int col, int num) 
    { 
     
        for (int d = 0; d < N; d++)  
        { 
            
            if (grid[row][d] == num) { 
                return false; 
            } 
        } 
  
        for (int r = 0; r < N; r++)  
        { 
               
            if (grid[r][col] == num)  
            { 
                return false; 
            } 
        }  
        int s = (int)sqrt(N); 
        int rs = row - row % s; 
        int cs = col - col % s; 
  
        for (int r = rs; 
             r < rs + s; r++)  
        { 
            for (int d = cs; 
                 d < cs + s; d++)  
            { 
                if (grid[r][d] == num)  
                { 
                    return false; 
                } 
            } 
        } 
  
        return true; 
    } 

bool solve(int grid[N][N],int n) 
{ 
	    int row = -1; 
        int col = -1; 
        bool isEmpty = true; 
        for (int i = 0; i < n; i++)  
        { 
            for (int j = 0; j < n; j++)  
            { 
                if (grid[i][j] == 0)  
                { 
                    row = i; 
                    col = j; 
                    isEmpty = false; 
                    break; 
                } 
            } 
            if (!isEmpty) { 
                break; 
            } 
        } 
  
        if (isEmpty)  
        { 
            return true; 
        } 
        
        for (int num = 1; num <= n; num++)  
        { 
            if (isSafe(grid, row, col, num))  
            { 
                grid[row][col] = num; 
                if (solve(grid, n))  
                { 
                    
                    return true; 
                } 
                else 
                { 
                    grid[row][col] = 0; 
                } 
            } 
        } 
        return false; 
} 

void printGrid(int grid[N][N]) 
{ 
	for (int row = 0; row < N; row++) 
	{ 
		for (int col = 0; col < N; col++) 
			cout << grid[row][col] << " "; 
		cout << endl; 
	} 
} 
 
int main() 
{ 
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; 
	if (solve(grid,N) == true) 
		printGrid(grid); 
	else
		cout << "No solution exists"; 

	return 0; 
} 