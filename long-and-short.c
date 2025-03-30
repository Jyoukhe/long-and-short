#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    if(argc<3){
        printf("String or filename was not entered correctly, please try again.");
        exit(1);
        
    }
    FILE *inFile = fopen(argv[1], "r");
    FILE *shortFile = fopen(argv[2], "w");
    FILE *longFile = fopen(argv[3], "w");
    int shortCount = 0;
    int longCount = 0;
    char line[1000];
    if (!inFile||shortFile==NULL||longFile==NULL)
    {
        printf("Couldn't open one of the files provided, try again");
        exit(1);
    }
    while(fgets(line, 1000, inFile)){
       
            int length = strlen(line);
            if(length<20){
                for(int i = 0; line[i]!='\0'; i++){
                    line[i]=toupper(line[i]);
                }
                fprintf(shortFile, "%s", line);
                shortCount++;
            }
            else{
                for(int i = 0; line[i]!='\0'; i++){
                    line[i]=tolower(line[i]);
                }
                fprintf(longFile, "%s", line);
                longCount++;
            }
        
    }
    fclose(inFile);
    fclose(shortFile);
    fclose(longFile);
    printf("%d lines written to short.txt\n", shortCount);
    printf("%d lines written to long.txt\n", longCount);

}
