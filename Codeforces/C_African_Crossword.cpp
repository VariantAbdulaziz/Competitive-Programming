#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(int i=0; i<n; i++){
        cin >> grid[i];
    }
    vector<vector<int>> crossed(n, vector<int>(m));
    for(int i=0; i<n; i++){
        vector<int> freq(26);
        for(int j=0; j<m; j++){
            freq[grid[i][j] - 'a']++;
        }
        for(int j=0; j<m; j++){
            if(freq[grid[i][j] - 'a'] > 1){
                crossed[i][j] = 1;
            }
        }
    }
    for(int i=0; i<m; i++){
        vector<int> freq(26);
        for(int j=0; j<n; j++){
            freq[grid[j][i] - 'a']++;
        }
        for(int j=0; j<n; j++){
            if(freq[grid[j][i] - 'a'] > 1){
                crossed[j][i] = 1;
            }
        }
    }
    string result;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!crossed[i][j]) result += grid[i][j];
        }
    }
    cout << result;
}