
#include <bits/stdc++.h>
using namespace std;
 
void countFreq(int arr[], int n){
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++) {

        if (visited[i] == true)
            continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }
}

void count_freq(int arr[], int n){
    unordered_map<int,int>s;
    for(int i=0;i<n;i++) s[arr[i]]++;
   for(auto j:s) cout<<j.first<<" "<<j.second<<endl;;
}
 
int main()
{
    int arr[] = { 10, 20, 20, 10, 10, 20, 5, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    count_freq(arr,n);
    return 0;
}