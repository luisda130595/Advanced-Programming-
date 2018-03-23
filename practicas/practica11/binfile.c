#include <stdio.h>

typedef struct s {
	char name[20];
	char lastName[20];
	unsigned int id;
	unsigned char cal;
} Student;

int main(){
	char * studentDb = "studentDb.data";
	FILE * data = fopen(studentDb, "bw");
	Student pavanzada[5];
	int i;
	for(i = 0; i < 5; i++){
		sprintf(pavanzada[i].name,"student%d",i);
		sprintf(pavanzada[i].name,"Perez%d",i);
		pavanzada[i].id = i*20;
		pavanzada[i].cal = 1*7;
	}
	
	data = fopen(studentDb, "wb");
	fwrite(pavanzada,sizeof(Student),5,data);
	fclose(data);

	
	return 0;
}