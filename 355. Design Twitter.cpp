#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>
#include <thread>
#include <mutex>
#include <fstream>
#include <memory>
using namespace std;

struct Tweet {
	int id;
	std::chrono::time_point<std::chrono::high_resolution_clock> tp;
	Tweet(int _id, std::chrono::time_point<std::chrono::high_resolution_clock> _tp) : id(_id), tp(_tp) {}
};

class Twitter {
private:
	unordered_map<int, vector<Tweet> > tweets;
	unordered_map<int, set<int> > followers;

public:
	/** Initialize your data structure here. */
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		tweets[userId].push_back( Tweet(tweetId, std::chrono::high_resolution_clock::now()) );
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		auto comp = [](Tweet a, Tweet b)
		{
			return a.tp > b.tp;
		};

		priority_queue< Tweet, std::vector<Tweet>, decltype(comp) > pq(comp);

		// Add my own tweets
		for (auto &t : tweets[userId]) {
			if (pq.size() < 10) {
				pq.push(t);
			}
			else if (pq.top().tp < t.tp) {
				pq.pop();
				pq.push(t);
			}
		}

		// Add my followee`s tweets
		for (auto id : followers[userId]) {
			for (auto &t : tweets[id]) {
				if (pq.size() < 10) {
					pq.push(t);
				}
				else if (pq.top().tp < t.tp) {
					pq.pop();
					pq.push(t);
				}
			}
		}

		vector<int> result;
		while (!pq.empty()) {
			result.insert(result.begin(), pq.top().id);
			pq.pop();
		}

		return result;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followerId == followeeId) return;
		
		if ( followers[followerId].find(followeeId) == followers[followerId].end() ){
			followers[followerId].insert(followeeId);
		}
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followerId == followeeId) return;
		
		auto find_it = std::find ( followers[followerId].begin(), followers[followerId].end(), followeeId );

		if (find_it != followers[followerId].end()) {
			followers[followerId].erase( find_it );
		}
	}
};

template <typename T>
void printVector(const vector<T> &v) {
	cout << "\n-------------\nVECTOR: ";
	for (auto &i : v) {
		cout << i << " ";
	}
	cout << "\n-------------\n";
}

int main(int argc, char *argv[]) {
	Twitter* obj = new Twitter();
	obj->postTweet(2,100);
	obj->postTweet(1,50);
	vector<int> feed1 = obj->getNewsFeed(1);
	printVector(feed1);
	obj->follow(1,2);
	obj->postTweet(2,60);
	feed1 = obj->getNewsFeed(1);
	printVector(feed1);
	obj->unfollow(1,2);
	vector<int> feed2 = obj->getNewsFeed(1);
	printVector(feed2);
}