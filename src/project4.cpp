/============================================================================
// Name        : Project4.cpp
// Author      : Mohammad
// Version     :
// Copyright   : Your copyright notice
// Description : This is the main() project
//============================================================================

#include <iostream>

#include "UniqueWord.h"
#include "Tweet.h"
#include <cmath>
#include <fstream>
using namespace std;
#include <string>
#include <vector>

#define tweet_input  "C"
#define tweet_output  "C"


int main() {

		Tweet T1;		// Tweet is a class contains the required process to be done with a complete Tweet file
		string s;		// string to hold each word alone and analyze it
	
	// Connect to the input file to start reading the tweets
	// we can change the directory for the input file by changing tweet_input above before the main() .
		std::string input_file;
		input_file.append(tweet_input);
		input_file.append(":\\tweets.txt");
		T1.Update(input_file);



		// Now start to implement the required features
		// define two output files ft1 and ft2, assuming both of them will be in directory C
		// we can change this tweet_outpu directory from above before the main function();
		string output_file1,output_file2;
		output_file1.append(tweet_output);
		output_file1.append(":\\ft1.txt");
		output_file2.append(tweet_output);
		output_file2.append(":\\ft2.txt");
		
		//string output_file1="C:\\ft1.txt";
		//string output_file2="C:\\ft2.txt";

		T1.f1(output_file1);		// implement feature 1 and write in ft1 file
		T1.f2(output_file2);		// implement feature 2 and write in ft2 file.




	return 0;
}
