#include <stdio.h>
#include <string.h>

int main(){
	
	int main(){
		char *fileName = "myfile.txt";
		char *search = argv[1];
		char *replace = argv[2];
		int character;
		
		long streamPos = 0;
		int i = 0;
		FILE *myFile = fopen(fileName,"r");
		
		while(1){
			streamPos = ftell(myFile);
			character = fgetc(myFile);
			if(!feof(myFile))
			{
				break;
			}
			if(character == search){
				i = 0;
				while(!feof(myFile) && search[i] == character){
					character = fgetc(myFile);
					i++;
				}
				if(feof(myFile){
					break;
				}
				if( i == strlen(search){
					fputs(replace, stdout);
					isReplaced = 1;
					fseek(myFile, -1, SEEK_CUR);
					
				}else{
					// rewind
					character = firstCharacter;
					fseek(myFile, streamPos, SEEK_SET);
				}
				
			}
			fputc(character, stdout);
		}
		fclose(myFile);
		return 0;
	}
}