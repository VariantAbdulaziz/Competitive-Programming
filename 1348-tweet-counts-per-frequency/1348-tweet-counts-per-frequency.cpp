class TweetCounts {
    map<string, vector<int>> book;
    map<string, int> dic = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        book[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int n = dic[freq];
        vector<int> result;
        result.resize((endTime - startTime + n) / n);
        for(auto time: book[tweetName]) {
            if(startTime <= time && time <= endTime) {
                int idx = (time - startTime) / n;
                result[idx]++;
            }
        }
        return result;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */