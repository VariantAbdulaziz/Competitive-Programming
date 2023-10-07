#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int height(map<string, vector<string>>& adj, string source){
    if(adj.find(source) == end(adj)) return 1;
    int result = 0;
    for(auto reposter: adj[source]){
        result = max(result, 1 + height(adj, reposter));
    }
    return result;
}


void lower_string(string& str)
{
	for(int i=0;str[i]!='\0';i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')    //checking for uppercase characters
			str[i] = str[i] + 32;         //converting uppercase to lowercase
	}
}

void solve(){
    int n;
    cin >> n;
    map<string, vector<string>> adj;
    for(int i=0; i<n; i++){
        string source, reposted, reposter;
        cin >> reposter >> reposted >> source;
        lower_string(reposter), lower_string(source);
        adj[source].push_back(reposter);
    }

    cout << height(adj, "polycarp") << endl;
}

int32_t main(){
    solve();
}