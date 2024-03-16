#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "brainfuck.h"

int main(int argc, char * argv[])
{
    //verify if argument exists
    if(argv[1] != NULL)
    {
        //verify if file exists
        if(access(argv[1], F_OK) != -1)
        {
            //detect if it's the correct extension
            char *extension = strchr(argv[1], '.');
            if(extension != NULL && strcmp(extension, ".bf") == 0)
            {
                FILE *fp;
                long lSize;
                char *buffer;

                fp = fopen(argv[1], "r");
        
                //if error occur in reading the file
                if(fp == NULL)
                {
                    fclose(fp);
                    perror("ERROR FOR READING THE FILE");
                    return 1;
                }
                //if no error in reading the file
                else
                {
                    //take size of file
                    fseek(fp , 0L , SEEK_END);
                    lSize = ftell(fp);
                    rewind(fp);

                    // allocate memory for entire content
                    buffer = calloc( 1, lSize+1 );
                    if(!buffer)
                    {
                        fclose(fp);
                        fputs("memory alloc fails", stderr);
                        exit(1);
                    }

                    // copy the file into the buffer
                    if( 1!=fread( buffer , lSize, 1 , fp) )
                    {
                        fclose(fp);
                        free(buffer);
                        fputs("entire read fails",stderr);
                        exit(1);
                    }

                    // close file and execute brainfuck code
                    fclose(fp);
                    execute(buffer);
                }
            }
            else
            {
                fputs("The file you provided doesn't have the correct extension (.bf)", stderr);
            }
            
        }
        else
        {
            perror("Please enter a valid file");
            return 1;
        }
    }
    else
    {
        fputs("Please enter a file name", stderr);
        return 1;
    }
    return 0;
}