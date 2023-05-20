//Rat is at top left and cheese at bottom right
//if rat is at i,j then it can move to only i+1,j or i,j+1
#include <bits/stdc++.h>
#define N 4
using namespace std;

void printSolution(int sol[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}



bool isSafe(int i,int j,int maze[N][N]){
    return(i<N && j<N &&maze[i][j]==1);
}

bool SolveMazeRec(int maze[N][N],int sol[N][N], int i ,int j){
    if(i==N-1&& j==N-1){
        sol[i][j]=1;
        return true;
    }

    if(isSafe(i,j,maze)){
        sol[i][j]=1;
        if(SolveMazeRec(maze,sol,i+1,j)==true)return true;
        if(SolveMazeRec(maze,sol,i,j+1)==true)return true;
        sol[i][j]=0;

    }
    return false;
}

bool solveMaze(int maze[N][N]){
    int sol[N][N] = { { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 } }; 
        
    if(SolveMazeRec(maze,sol,0,0)==false){
         return false;
         cout<<"Solution does not exist";
    }
    
        printSolution(sol);
        return true;

}





int main(){
    int maze[N][N] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } }; 
  
    solveMaze(maze);
return 0;
}