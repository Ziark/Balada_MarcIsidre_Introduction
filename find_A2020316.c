//First we define the libraries
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//Function header
long find(char *string, char *substring, long int *position){

	//Passing from pointers to arrays so it's easier to work with
	char auxString[strlen(string)];
	strcpy(auxString, string);
	char auxSubstring[strlen(substring)];
	strcpy(auxSubstring, substring);

	//Defining some local variables
	
	//count counts all the times we find the substring in the string
	long count=0;
	//same checks if the substring is complete once we found the first letter in the string
	bool same;
	//found boolean is for setting position variable in case that substring length is 1
	bool found = false;
	//exist boolean is a error patch which helps solving the mistake of position -1 when at least one substring found
	bool exist = false;
	//index pointer to substring 
	int i;
	
	//Checking first the substring dimension
	if ((strlen(auxSubstring) != 0)&&(strlen(auxSubstring) <= strlen(auxString))){
		//We look for the substring in the entire string
		for (int j=0; j<strlen(auxString); j++){
			//Different cases for substring length one and more length
			if (strlen(auxSubstring)>1){
				//So we look in the string for the first letter of the substring
				if (auxString[j] == auxSubstring[0]){
					//then we guess we will have the substring
					same=true;
					//indexs i and j starts in 1 because position 0 is already checked in condition
					i=1;
					j++;
					//We start the substring search
					while (i<strlen(auxSubstring)&&(same)){
						//if it's not the substring we go out
						if (auxString[j] != auxSubstring[i]) same=false;
						//if it is we go ahead
						else{
							i++;
							j++;	
						}
					}
					//if it is the substring in the string
					if (same) {
						//if it's the first substring found we set it like this (0 position error checking for the pos calc)
						if (count == 0) (*position) = j-(strlen(auxSubstring));
						//Adding the substring found
						count++;
						//And now position can't be -1
						if (!exist) exist = true;
					}
					j--;
				//first letter of substring not found in string's actual index 
				}else{
					//so if doesn't exist any substring yet we set position -1
					if((!found)&&(!exist)) found=true;
				}
			}else {
				//And if substring length is one we look in the string for it
				if (auxString[j] == auxSubstring[0]){
					//if it's the fisrt substring found we set the position
					if (count == 0) (*position) = j-(strlen(auxSubstring)-1);
					//Adding the substring found
					count++;
				}
			}
		}
	//if substring dimension isn't acceptable position -1
	}else found = true;
	//here we officially set the position -1
	if (found) (*position)=-1;
//function returns number of times the substring is found in the string
return count;
}

//Main program
int main(int argc, char** argv) {
	//Defining some local variables
	long int pos = 0;
	long res;
	char str[30];
	char substr[10];
	//We copy the arguments from the bash script in the local variables
	strcpy(substr, argv[1]);
	strcpy(str, argv[2]);
	
	//if (ispunct(substr[0])!=0) substr[0] = '\0'; (that was testing)
	
	//Calling the function
	res = find(str, substr, &pos);
	//Screen printing of results
	printf("\n'%s' repeats in the string '%s' %ld times.", substr, str, res);	
	printf("\nfirst substring found on position: %ld\n\n", pos);
	
return 0;
}
