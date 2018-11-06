/*
	Submitted by : VASHU DEV 
	Roll no		 : 41
	Question no. : 5 - Program to test whether sequence(of events) 1 is a subsequence of sequence(of events) 2
*/

#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;

bool isSubsequence(vector<string> s1, vector<string> s2)
{
/*
        Objective       : test whether sequence(of events) 1 is a subsequence of sequence(of events) 2
        Input parameters: s1, sequence first
        				  s2, sequence second
        Return Value    : boolean
    */	
	int j = 0;
	 
	for(int i=0; i<s2.size() && j<s1.size(); i++){	//Traverse s2 and s1
		if(s1[j].compare(s2[i]) == 0)				//Compare current event of s2 with first unmatched char of s1
			j++;									//if matched then move ahead in s1 (matching is case sensitive)
	}
	
	return ( j==s1.size() ); // Return true, if all events of s1 were found in s2 in same order 
}


//******************************
//main function
//******************************

int main()
{
	 /*
        Objective       : test whether sequence(of events) 1 is a subsequence of sequence(of events) 2
        Input parameters: None
        Return Value    : Integer
    */

	vector<string>	s1, s2;
	cout<<"\n\nEnter sequence first\n ";
	while(true){
		string event;
		cout<<"\nEnter next event( -1 to stop ): ";
		cin>>event;
		if(event.compare("-1") == 0)		
			break;
		s1.push_back(event);
	}
	
	cout<<"\n\nEnter sequence second \n ";
	while(true){
		string event;
		cout<<"\nEnter next event( -1 to stop ): ";	
		cin>>event;
		if(event.compare("-1") == 0)		
			break;
		s2.push_back(event);
	}
	
	if( isSubsequence(s1, s2))							// isSubsequence returns 'TRUE' if s1 is  subsequence of s2.
		cout<<"\n\nYes, sequence 1 is a subsequence of sequence 2.";
	else
		cout<<"\n\nNo, sequence 1 is not a subsequence of sequence 2.";
		
	return 0;
}
