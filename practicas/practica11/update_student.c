#include <stdio.h>

typedef struct s {
	char name[20];
	char lastName[20];
	unsigned int id;
	unsigned char cal;
}Student;

int main(){
	Student myStudent;
	char *studentDb = "studentDb.data";
	char *lastName = "Perez2";
	FILE *data;
	
	data = fopen(studentDb , "rb");
	while(1){
		fread(&myStudent, sizeof(Student), 1, data);
		if(feof(data)){
			break;
		}
		if(!strcmp(myStudent, lastName, lastName)){
			sprintf(myStudent.name, "Pedro");
			fseek(data,-1*sizeof(Student),1,SEEK_CUR);
			fwrite(&myStudent,sizeof(Student),1,data);
			break;
		}
	}
	fclose(data);
	return 0;
}