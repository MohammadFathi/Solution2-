
#include "Tweet.h"
#include "UniqueWord.h"
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>


Tweet::Tweet() {
	TotalNumberOfTweets=0;		//initiaqlly set number of analyzed tweets to zero

}












/*
 * Update() function will take the input_file location and connect to it to process the words,
 * Will work to find if this word a new word or we have analyzed before, and accordingly, update
 * in the Tweet myvector which contain all the words of the  tweet.
 * Also, will update the unique number per each tweet.
 *
 */



void Tweet::Update(string FileLocation)	{

	ifstream ifs(FileLocation.c_str());
	if(!ifs)
	{
		cout<<"File is not opened";
	}

	string OneLine,s;		// this string to save one tweet (one line from the file)
	size_t pos1,pos2 ;	// these tow size_t to convert each tweet to separate words and work for each word alone.
	long i,n;
	Unique_Word W1;		// Craeate one object of the Unique_Word to start our analysis.



while(getline(ifs,OneLine) )
{


	// for each one loop, We will first read one tweet and separate it to different words to  analyze each word
	OneLine.append(" ");
	pos2= OneLine.find(" ");	// find first space in the current line

	for(pos1=OneLine.find(OneLine[0]);pos2!=std::string::npos;)
		{
			s=OneLine.substr(pos1,pos2-pos1);	// "s" now contains one word
			pos2++;						// move the next word
			OneLine=OneLine.substr(pos2);	// update the OneLine string by removing this last word we have read
			pos1=OneLine.find(OneLine[0]);	// update pos1 to point to the first character of the OneLine after removing the last saved word.
			pos2= OneLine.find(" ");	// update pos2 to point to the first space in the new OneLine string

// Now, for each word, we will work to analyze it.



			i=0;n=0;
			W1.Clean();		// Clear all values in W1
			itPerTweet=UniqueWordsPerEachTweet.begin();

			W1.UpdateWordString(s);		// Load the new string inside the created object



	if(myvector.empty())		// if this word is the first one in the tweet, it was not found before, so insert in myvector and update relevant information
	{
		W1.UpdateNumberOfRepeating();
		W1.UpdateLastTweetNumber(TotalNumberOfTweets);

		// We are in the first tweet and this is first unique word inside it so update the corresponding element in vector UniqueWordsPerEachTweet
		UniqueWordsPerEachTweet.push_back(1);

		// This is first word in the tweet , so it was not inserted before in myvector array, insert it with its relevant information.
		myvector.push_back(W1);

	continue;
	}

	else			// if the word is not the first word in the tweet, do here
	{
		Size= myvector.size();			// get the size of the whole unique words saved before in myvector array of words
		it=myvector.begin();			// iterator at the beginning to start finding out if the current new word has been inserted before or not and to update all the corresponding elements




/*	Now, at least we have two sorted elements in the myvector sorted array. What we will do in the next, is to take each new word and compare
 * with the already inserted boundary elements to see if it was inserted before or not.
 * We need to speed up the way of finding if there is same word inserted before or not, or to find the corresponding position if this is a new word.
 *
 * What is done here , I try to divide the sorted array to two parts:
 * - The first part is 2^n elements
 * - The second part is the rest of elements in the sorted array (Size - 2^n)
 *
 * I created the first part of 2^n because it can be faster to allocate the position for the word in case we find it should be here
 * I found that accessing array with 2^n elements will be more practical and faster
 * If it is not found to be included in this first 2^n part at all, then I leave it completely for this word and move my iterator at the beginning of the second part
	Then, I repeat what I have done above , divide this second part to new two parts one with 2^n and one with the rest element, where n here is less than the one before of course.
	And repeat the checking and division until we decrease our sorted array part to only two consequent elements.
	With those two consequent elements , we can find the right position for our word or if it was inserted before.

	n is the largest number that satisfy 2^n is closest number of number 2^n multipliers to be close to the size value

	For example: say size is 142 elements
	then we have 128 = 2^7 is the closest one of 2^n multipliers to 142
	we divide the sorted array to two part : first with 128 elements and the second with only 14 elements.
	Then check if the word should be in the first part , if yes we will work only in this part of 128 elements as we did before
	If not found, then focus only in the second part of the array which now contains only 14 elements, and did as before,
	If found in the first 128 element, we will divide it two 2^6 and 2^6 and check also with each one part.
	If found in the second part, we will divide to part with 2^3 and the other one is only 6 elements and repeat the process move to the first
	part of 8 elements and start checking its boards.


	Important note, when I come to check if the word should be inside the first one part or not, I just check for the first element of this part and the first element element of the second part
	Then, if the alphabetic order for this word is not between them then the word should not be there, it should be somewhere in the second part.

	Also, it might be possible that the word is before even the first word in the sorted array, we check for this case after checking the two boundaries (beginning for the two divided parts)
	\Alo, it might be repeated before at the two boundaries beginnings, so if it is at the first element of first part or first element of the second part
	that we check at each beginning of our looping, we can then update the element and quit the searching process to speed up the process.


	*/




	if(Size>1)
	{
		i=log2(Size-1);		// Find the most close 2^n for the size of the sorted array
		n=pow(2,i);			// n now is the number of elements in the first part
	}

	
	while(Size>0)
	{

		// Check if the ASCII for this word is between first word in first part and first word of the second part
	if( (s.compare((*it).GetWordString())>0 ) &&   (s.compare((*(it+n)).GetWordString())<0)   )
		{

			if(i==0)					// i will be zero when we have only two elements (i.e two parts and each one part contains only one unique word)
			{

				// If we find the correct position, then insert this Unique Word and update corresponding information
				W1.UpdateNumberOfRepeating();


				// This is a new unique word, see if this tweet unique words number has been inserted before or not to update it.
				if(UniqueWordsPerEachTweet.size()==TotalNumberOfTweets)
					UniqueWordsPerEachTweet.push_back(1);
				else if(UniqueWordsPerEachTweet.size()==TotalNumberOfTweets+1)
					*(itPerTweet+TotalNumberOfTweets)=*(itPerTweet+TotalNumberOfTweets)+1;

				W1.UpdateLastTweetNumber(TotalNumberOfTweets);
					myvector.insert(it+1,W1);
				break;
			}

			Size=n;					// if we still did not reach to just one element per  each one part of the sorted arrays, but the word is found to be in the first part, then we work only in this first part
			i=log2(Size-1);			// find most closest 2^n for the new size
			n=pow(2,i);
			continue;

		}
	 else	// check if the ASCII order for this word is after the first word in the second part
	   if(s.compare( (*(it+n)).GetWordString())>0    )
		{
			Size=Size-n;			// it is possible also that size of second array be one which means have only one element in the second array to compare with it.
			if( i==0 || Size==1)		//// i will be zero when we have only two elements (i.e two parts and each one part contains only one unique word)
			{	// If we find the correct position, then insert this Unique Word and update corresponding information
				W1.UpdateNumberOfRepeating();
				W1.UpdateLastTweetNumber(TotalNumberOfTweets);
				myvector.insert(it+n+1,W1);


			// This is a new unique word, see if this tweet unique words number has been inserted before or not to update it.
				if(UniqueWordsPerEachTweet.size()==TotalNumberOfTweets)
						UniqueWordsPerEachTweet.push_back(1);
				else if(UniqueWordsPerEachTweet.size()==TotalNumberOfTweets+1)
						*(itPerTweet+TotalNumberOfTweets)=*(itPerTweet+TotalNumberOfTweets)+1;
				break;
			}

			it=it+n;				// if we still did not reach to just one element per  each one part of the sorted arrays, but the word is found to be in the second part, then we work only in this second part move the iterator to its beginning
			i=log2(Size-1);				// find most closest 2^n for the new size
			n=pow(2,i);
			continue;
		}

	else
	   if(s.compare( (*it).GetWordString())==0)		// if not found in any case above, it might be the same word at the beginning of the first divided part itself.
		{

		   (*it).UpdateNumberOfRepeating();
			 if((*it).GetLastTweetNumber()<TotalNumberOfTweets)   // if this word is the first unique word of itself in this tweet, Update the unique word number in this tweet.
			{
   				(*it).UpdateLastTweetNumber(TotalNumberOfTweets);
  				//see if this tweet unique words number has been inserted before or not to update it.
			   	if(UniqueWordsPerEachTweet.size()==TotalNumberOfTweets)
			   		UniqueWordsPerEachTweet.push_back(1);
			   	else if(UniqueWordsPerEachTweet.size()==TotalNumberOfTweets+1)
			   		*(itPerTweet+TotalNumberOfTweets)=*(itPerTweet+TotalNumberOfTweets)+1;
			  }
		   break;
 		}
	 else
	   if(s.compare( (*(it+n)).GetWordString())==0)	// if not found in any case above, it might be the same word at the beginning of the second divided part itself.
		{
		   (*(it+n)).UpdateNumberOfRepeating();
		     if((*(it+n)).GetLastTweetNumber()<TotalNumberOfTweets)		// if this word is the first unique word of itself in this tweet, Update the unique word number in this tweet.
			{
		   	   (*(it+n)).UpdateLastTweetNumber(TotalNumberOfTweets);
					   	   	  
   	   	   // see if this tweet unique words number has been inserted before or not to update it.
   	   			if(UniqueWordsPerEachTweet.size()==TotalNumberOfTweets)
   					UniqueWordsPerEachTweet.push_back(1);
   	   			else if(UniqueWordsPerEachTweet.size()==TotalNumberOfTweets+1)
   					*(itPerTweet+TotalNumberOfTweets)=*(itPerTweet+TotalNumberOfTweets)+1;
   			}
		   break;
	       }
	  else		//If not found in the first part or second part, It is possible that the ASCII order for this word is before any word in the whole array, check for that
	   if(s.compare( (*it).GetWordString())<0)		// we compare it with the first word at all in the sorted array
		{
		   W1.UpdateNumberOfRepeating();
		   W1.UpdateLastTweetNumber(TotalNumberOfTweets);
		   myvector.insert(it,W1);

		  // This is a new unique word, see if this tweet unique words number has been inserted before or not to update it.
			 if(UniqueWordsPerEachTweet.size()==TotalNumberOfTweets)
				 UniqueWordsPerEachTweet.push_back(1);
			else if(UniqueWordsPerEachTweet.size()==TotalNumberOfTweets+1)
				*(itPerTweet+TotalNumberOfTweets)=*(itPerTweet+TotalNumberOfTweets)+1;
			break;
		}


	}// END of one while loop to check the two parts we divided  of the sorted array, move to the next until we find the proper position for the word or find it was repeated.


}	// END of checking process for this word in the whole sorted array.


} //End of analyzing one word in one tweet, move to the next word in the same line until finish it.

			
		TotalNumberOfTweets++;
} // End of the while loop for the one line. move to the next tweet,

		ifs.close();


}	// END of Tweet::Update() member function








// First Feature , f1 will take path of the outpur file to write the sorted words with corresponding number of repeating
void Tweet::f1(string FileLocation)
{

	ofstream ofs(FileLocation.c_str());
				if(!ofs)
			{
				cout<<"File is not opened";
				return;
			}
			for (vector<Unique_Word>::iterator 	it=myvector.begin();it!=myvector.end();it++)
			{
				ofs<< std::setw(16)<<std::left<<(*it).GetWordString()<<(*it).GetNumberOfRepeating()<<'\n';
			}
			ofs.close();

}


// Secod feature, will take path of output file and write median number of unique words received after many tweets
// Start with first tweet only, then first two only, then first three,,, and so one until the total received number of tweets
void Tweet::f2(string FileLocation)
{

	ofstream ofs(FileLocation.c_str());
				if(!ofs)
			{
				cout<<"File is not opened";
				return;
			}

				vector<long>::iterator it;
				long Size1=1;
				float NumberofUniqueWords=0;	// I chose this as float because sometimes, the median is not integer number



				// The work here is to go for the UniqueWordsPerEachTweet vector which now contains number of unique word in each one tweet,
				// then move for each tweet, we will have array starting from first tweet until this current tweet
				// If the number of tweets starting from the first tweet until this tweet is odd, take the middle tweet eactly
				// The corresponding number saved in this tweet Unique Words is the median for this array up to now.
				// If the number of all tweets from beginning until this current tweet is even, the take the middle two exactly
				// The average of the two numbers saved in those two tweets Unique Words Number is the median for this array up to now.


			for (vector<long>::iterator it2=UniqueWordsPerEachTweet.begin();it2!=UniqueWordsPerEachTweet.end();it2++)
			{

				// For each time we move to add new tweet to our array, begin at the first element to be able to reach the corresponding elements later.
				it=UniqueWordsPerEachTweet.begin();

				if(Size1%2==1) 	// if number of tweets is odd
				{

					it=it+(Size1-1)/2;					// reach to the middle element exactly
					NumberofUniqueWords=(*it);
					ofs<<NumberofUniqueWords<<'\n';		// write the value to the file
				}
				else			// if number of tweets is even.
				{

					it=it+(Size1)/2;					// reach to one of two the middle elements
					NumberofUniqueWords=(float)	( (*it)+(*(it-1)) )/2;
					ofs<<NumberofUniqueWords<<'\n';		// write the value to the file
				}


					Size1++;		// Update the number of tyweets we are going to check and consider.
			}		// end of one loop, move to the next.
				

					ofs.close();

}





Tweet::~Tweet() {
	// TODO Auto-generated destructor stub
}

