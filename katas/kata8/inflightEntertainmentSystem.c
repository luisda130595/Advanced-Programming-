#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

char watchTwoMovies(int flightLength, int m, int *movie_lengths){
	// table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[flightLength+1];
 
    // Base case (If given value V is 0)
    table[0] = 0;
 
    // Initialize all table values as Infinite
    int counter;
    for (counter=1; counter<=flightLength; counter++)
        table[counter] = INT_MAX;
        
    //See if there's any value that equals the flightLength
    int counter1;
    for(counter1=0; counter1 < m; counter1++){
    	if(movie_lengths[counter1] == flightLength){
    		movie_lengths[counter1] = movie_lengths[counter1]+1;
    	}
    		
    }
 
    // Compute minimum coins required for all
    // values from 1 to V
    int i;
    for (i=1; i<=flightLength; i++)
    {
        // Go through all coins smaller than i
        int j;
        for (j=0; j<m; j++)
          if (movie_lengths[j] <= i)
          {
              int sub_res = table[i-movie_lengths[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
	
	int numberOfMovies = table[flightLength];
	printf("Number of movies is: %d\n",numberOfMovies);
	if(!numberOfMovies==2){
		return TRUE;
	}else{
		return FALSE;
	}
	
}

int main(){
	int movie_lengths[] = {30,50,65,70,85,90,120,150};
	//int movie_lengths[] = {9,6,5,1};
	int sizeOfArray = sizeof(movie_lengths)/sizeof(movie_lengths[0]);
	printf("M is: %d\n",sizeOfArray);
	int flight_length = 150;
	char watchTwoMovies_bool = watchTwoMovies(flight_length, sizeOfArray, movie_lengths);
	if(watchTwoMovies_bool){
		printf("You can watch two movies\n");
	}
	
	return 0;
}