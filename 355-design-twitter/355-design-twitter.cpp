struct User{
    vector<pair<int,int>> tweetid; // time, tweetId
    set<int> follow;
};
class Twitter {
    map<int,User> user; // userId, User obj
    int time; // time
public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        if(user.find(userId) == user.end())
        {
            User  obj;
            user[userId] = obj;
        }
        user[userId].tweetid.push_back({time,tweetId});
        // cout<<user.size()<<" ";
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        // for()
        int n = user[userId].tweetid.size();
        for(int i=n-1;i>=max(0,n-10);i--)
            pq.push(user[userId].tweetid[i]);
        for(auto a:user[userId].follow)
        {
            n = user[a].tweetid.size();
            for(int i=n-1;i>=max(0,n-10);i--)
                pq.push(user[a].tweetid[i]);
        }
        n = pq.size();
        for(int i=n-1;i>=max(0,n-10);i--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(user.find(followerId) == user.end())
        {
            User  obj;
            user[followerId] = obj;
        }
        if(user.find(followeeId) == user.end())
        {
            User  obj;
            user[followeeId] = obj;
        }
        user[followerId].follow.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user[followerId].follow.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */