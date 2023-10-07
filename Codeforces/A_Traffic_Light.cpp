#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        int ans = 0;

        if(c != 'g') {
            string doubled_s = s + s;
            stack<int> st;
            for(int i=0; i<2*n; i++){
                char light = doubled_s[i];
                if(light == c){
                    st.push(i);
                }
                while(light == 'g' && !st.empty()){
                    ans = max(ans, i - st.top());
                    st.pop();
                }
            }
        }
        cout << ans << '\n';
    }
}