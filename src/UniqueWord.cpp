

#include "UniqueWord.h"
#include<iostream>
#include <string>
using namespace std;

Unique_Word::Unique_Word() {
	 WordString="";
	 NumberOfRepeating=0;
	 LastTweetNumber=0;

}
void Unique_Word::UpdateNumberOfRepeating(){
		NumberOfRepeating++;
}

void Unique_Word::UpdateLastTweetNumber(long x){
		LastTweetNumber=x;

}


void Unique_Word::UpdateWordString(string s){
	 	 WordString=s;
}


long Unique_Word::GetNumberOfRepeating(){
		return NumberOfRepeating;
}



long Unique_Word::GetLastTweetNumber(){
	 	 return LastTweetNumber;
}



string Unique_Word::GetWordString(){
	 	 return WordString;
}


void Unique_Word::Clean(){
		 WordString="";
		 NumberOfRepeating=0;
		 LastTweetNumber=0;

}



Unique_Word::~Unique_Word() {
	// TODO Auto-generated destructor stub
}

