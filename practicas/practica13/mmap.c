#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

typedef struct s
{
    char name[20];
    char lastName[20];
	unsigned int id;
    unsigned char cal;
}Student;

int main()
{
    char *fileName = "studentDb.data";
    int fd = open(fileName, O_RDWR);
    Student *pAvanzada = (Student *) mmap(NULL,5*sizeof(Student),PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
    close(fd);
    printf("First Student %s\n", pAvanzada[0].name);
    strcpy(pAvanzada[1].name,"Pedro");
    msync(pAvanzada,5 * sizeof(Student),MS_SYNC);
    munmap(pAvanzada,5 * sizeof(Student));
    return 0;
}