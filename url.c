/*
    This program is written in C
    It scan file name and urls, make urls into a pure host and save it into a file.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2048
int main (int argc, char *argv[]) {
    char string[MAX];
    int count = 0;
    int length;
    int id = 1;
    //int file_len;
    //int agv_len;
    if (argc == 2) {
        /*
        agv_len = strlen(argv[1]);
        file_len = agv_len + 4;
        char file_name[file_len];
        strcpy(file_name, argv[1]);
        file_name[agv_len] = '.';
        file_name[agv_len + 1] = 't';
        file_name[agv_len + 2] = 'x';
        file_name[agv_len + 3] = 't';
        */
        FILE *fp = fopen(argv[1], "a");
        
        
        while (scanf("%s", string) != EOF) {
            /*while (string[count] != '\0') { 
                printf("%c %d\n", string[count], count);
                count++;
            }
            */
            count = 4;
            length = strlen(string);
            //printf("%s", string);
            if (string[count] == 's') {
                count = count + 4;
                while (count < length) {
                    if (string[count] == '/') {
                        //printf("1%c %d break", string[count], count);
                        break;
                    }
                    fprintf(fp, "%c", string[count]);
                    count++;
                    
                }
            }
            else {
                count = count + 3;
                while (count < length) {
                    //printf("%c", string[count]);
                    if (string[count] == '/') {
                        break;
                        //printf("2%c %d break", string[count], count);
                    }
                    fprintf(fp, "%c", string[count]);
                    count++;
                }
            }
            fprintf(fp, "\n");
            id++;
        }
    }
    fclose(fp);

}