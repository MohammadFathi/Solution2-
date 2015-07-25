

#ifndef TWEET_H_
#define TWEET_H_

#include "UniqueWord.h"
using namespace std;
#include <string>
#include <vector>

/*This class will use one vector of type Unique_Word to save and sort only the unique words found in the tweet,txt file.
It will also use a vector of type long to save number of unique word founds in each one  tweet alone.
The index of elements in this UniqueWordsPerEachTweet is correspomg to the mnumber of the tweet in the tweets.txt file
*/


class Tweet {
	long TotalNumberOfTweets;		// Total number of tweets for this tweet object
	vector<long> UniqueWordsPerEachTweet;	// An array of unique words number in each tweet, each one element in this array is corresponding to number of unique words in each tweet number n, where n is also the index in this vector.
	vector<Unique_Word> myvector;		// An array of words that are with the tweets, each one word object contain its relevant information
	vector<Unique_Word>::iterator it;
	vector<long>::iterator itPerTweet;
	std::vector<string>::size_type Size;
public:
	Tweet();
	void Update(string);
	void f1(string );
	void f2(string);

	~Tweet();
};

#endif /* TWEET_H_ */
