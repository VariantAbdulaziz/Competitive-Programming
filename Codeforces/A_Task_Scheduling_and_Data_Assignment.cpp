#include <bits/stdc++.h>
#define int int64_t

using namespace std;

struct Comp {
    bool operator()(tuple<int, int,  int> const& p, tuple<int, int, int> const& q)
    {
        return get<1>(p) < get<1>(q) || (get<1>(p) == get<1>(q) && get<0>(q) > get<0>(q));
    }
};

vector<int> assign_disk(vector<int>& score, vector<int>& speed, vector<int> capacity, vector<int>& data, vector<vector<int>>& data_dep){
    int l = score.size();
    priority_queue<tuple<int, int>> q;
    for(int i=1; i<l; i++){
        if(score[i])
            q.push({score[i] * data[i], i});
    }
    vector<int> disk_assignment(l);
    capacity[0] = -1;
    speed[0] = -1;
    while(!q.empty()){
        auto [s, j] = q.top(); q.pop();
        int best = 0;
        for(int i=1; i<capacity.size(); i++){
            if(speed[i] > speed[best] && capacity[i] >= data[j]){
                best = i;
            }
        }
        capacity[best] -= data[j];
        disk_assignment[j] = best;
    }
    speed[0] = 0;
    return disk_assignment;
}

void ranking(vector<int>& result, vector<vector<int>>& affitive_machines, vector<vector<int>>& data_dep, vector<vector<int>>& task_dep,
            vector<int>& task_size, vector<int>& speed, vector<int>& data, vector<int>& power, vector<int>& z,
            vector<vector<int>>& forward_data, vector<vector<int>>& forward_task){
    
    vector<int> score(result.size(), 0);

    vector<int> ordering;
    queue<int> q;
    for(int i=1; i<result.size(); i++){
        score[i] += data_dep[i].size() + task_dep[i].size();
        if(!score[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr = q.front(); q.pop();
        ordering.push_back(curr);
        for(auto each: forward_data[curr]){
            score[each]--;
            if(!score[each]){
                q.push(each);
            }
        }
        for(auto each: forward_task[curr]){
            score[each]--;
            if(!score[each]){
                q.push(each);
            }
        }
    }
    reverse(begin(ordering), end(ordering));

    for(auto i: ordering){
        int run = task_size[i];
        for(auto j: data_dep[i]){
            run += ceil((double)data[j]/speed[z[j]]);
        }
        run += ceil((double)data[i]/speed[z[i]]);

        for(auto j: forward_data[i]){
            run += result[j];
        }
        for(auto j: forward_task[i]){
            if(!binary_search(forward_data[i].begin(), forward_data[i].end(), j))
                run += result[j];
        }
        result[i] = run;
    }
}

int32_t main(){
    int l; cin >> l;
    vector<int> task_size(l+1), data(l+1);
    vector<vector<int>> affitive_machines(l+1);
    for(int j=0; j<l; j++){
        int i, k;
        cin >> i;
        cin >> task_size[i] >> data[i];
        cin >> k;
        while(k--){
            int machine;
            cin >> machine;
            affitive_machines[i].push_back(machine);
        }
    }

    int n; cin >> n;
    vector<int> power(n+1);
    for(int i=0; i<n; i++){
        int j;
        cin >> j;
        cin >> power[j];
    }
    for(int i=0; i<=l; i++){
        sort(begin(affitive_machines[i]), end(affitive_machines[i]), [&](const int a, const int b){
            return power[a] < power[b];
        });
    }

    int m; cin >> m;
    vector<int> speed(m+1), capacity(m+1);
    for(int i=0; i<m; i++){
        int k; cin >> k;
        cin >> speed[k] >> capacity[k];
    }

    int M; cin >> M;
    vector<vector<int>> data_dep(l+1), task_dep(l+1), forward_data(l+1), forward_task(l+1);
    while(M--){
        int i, j;
        cin >> i >> j;
        data_dep[j].push_back(i);
        forward_data[i].push_back(j);
    }
    int N; cin >> N;
    while(N--){
        int i, j;
        cin >> i >> j;
        task_dep[j].push_back(i);
        forward_task[i].push_back(j);
    }
    vector<int> score(l+1);
    for(int i=1; i<=l; i++){
        
        score[i]++;
        for(auto dep: data_dep[i]){
            score[dep]++;
        }
    }

    vector<int> z = assign_disk(score, speed, capacity, data, data_dep);
    vector<int> x(l+1), y(l+1);
    vector<int> book(l+1);
    // vector<int> bs(l+1), cs(l+1), ds(l+1);
    ranking(book, affitive_machines, data_dep, task_dep, task_size, speed, data, power, z, forward_data, forward_task);
    for(int i=0; i<=l; i++){
        sort(begin(forward_data[i]), end(forward_data[i]), [&](const int a, const int b){
            return book[a] < book[b];
        });
        sort(begin(forward_task[i]), end(forward_task[i]), [&](const int a, const int b){
            return book[a] < book[b];
        });
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Comp> q;
    

    for(int i=1; i<=l; i++){
        score[i] = 0;
        score[i] += data_dep[i].size() + task_dep[i].size();
        if(score[i] == 0){
            q.push({x[i], book[i], i});
        }
    }
    vector<int> machine_lock(n+1);
    machine_lock[0] = numeric_limits<int>::max();
    while(!q.empty()){
        auto [a, size_i, i] = q.top(); q.pop();
        // cout << i << " ";
        int best = 0;
        int best_expected = numeric_limits<int>::max();
        for(auto j: affitive_machines[i]){
            int candidate = max(machine_lock[j], a);
            if(candidate < best_expected || (candidate == best_expected && power[j] > power[best])){
                best = j;
                best_expected = candidate;
            }
        }
        a = max(machine_lock[best], a);
        y[i] = best;

        // x[i] = a;
        int b = a;
        for(auto dep: data_dep[i]){
            b += ceil((double)data[dep]/speed[z[dep]]);
        }
        
        // bs[i] = b;
        int c = b + ceil((double)task_size[i]/power[best]);
        for(auto dep: forward_task[i]){
            x[dep] = max(x[dep], c);
            score[dep]--;
            if(score[dep] == 0){
                q.push({x[dep], book[dep], dep});
            }
        }
        // cs[i] = c;
        int d = c + ceil((double)data[i]/z[i]);
        // ds[i] = d;
        machine_lock[best] = d;
        for(auto dep: forward_data[i]){
            x[dep] = max(x[dep], d);
            score[dep]--;
            if(score[dep] == 0){
                q.push({x[dep], book[dep], dep});
            }
        }
    }
    // cout << endl;
    for(int i=1; i<=l; i++){
        cout << i << " " << x[i] << " ";
        // cout << book[i] << " ";
        // cout << bs[i] << " " << cs[i]  << " " << ds[i] << " ";
        cout << y[i] << " " << z[i] << endl;
    }
}
