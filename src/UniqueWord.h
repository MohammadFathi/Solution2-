

#ifndef UNIQUEWORD_H_
#define UNIQUEWORD_H_
#include<string>
using namespace std;

/* Unique_Word class, is representing each oe word with it required information.*/


class Unique_Word {
	string WordString;			// the word string itself.
	long NumberOfRepeating;			// How many times were this word repeated in the whole tweets.txt file up to now.
	long LastTweetNumber;		        // Last tweet number we found this word during our analysis, if not found before it will be initially zero.

public:

	Unique_Word() {
		 WordString="";
		 NumberOfRepeating=0;
		 LastTweetNumber=0;
	}
	
	void UpdateNumberOfRepeating(){
			NumberOfRepeating++;
	}

	void UpdateLastTweetNumber(long x){
			LastTweetNumber=x;

	}


	void UpdateWordString(string s){
		 	 WordString=s;
	}


	long GetNumberOfRepeating(){
			return NumberOfRepeating;
	}



	long GetLastTweetNumber(){
		 	 return LastTweetNumber;
	}



	string GetWordString(){
		 	 return WordString;
	}


	void Clean(){
			WordString="";
			NumberOfRepeating=0;
			LastTweetNumber=0;

	}
	~Unique_Word(){}
};

#endif /* UNIQUEWORD_H_ */
