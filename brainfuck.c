#include "brainfuck.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"

void execute(char * code)
{
    //detect if all loops are correctly closed
    int open_count = 0;
    int close_count = 0;
    char * code2 = code;
    while (*code2) {
        if (*code2 == '[') {
            open_count++;
        } else if (*code2 == ']') {
            close_count++;
        }
        code2++;
    }
    if(open_count == close_count)
    {
        //define cursor place
        int cursor_place = 0;
        //allocate memory to our table of pointer
        int * pointer_table = (int*) calloc(30000, sizeof(int));

        //size of code to check it and i for iterations    
        size_t size_of_code = strlen(code);
        size_t i = 0;
        //execute the code line per line
        for(; i < size_of_code ; i++)
        {
            if(code[i] == '<')
            {
                if(cursor_place == 0)
                {
                    fputs("Can't reduce cursor at 0", stderr);
                    break;
                }
                else
                {
                    cursor_place--;
                }
            }
            else if(code[i] == '>')
            {
                if(cursor_place == 30000)
                {
                    fputs("Can't increase cursor at 30000", stderr);
                    break;
                }
                else
                {
                    cursor_place++;
                }
            }
            else if(code[i] == '+')
            {
                pointer_table[cursor_place]++;
            }
            else if(code[i] == '-')
            {
                pointer_table[cursor_place]--;
            }
            else if(code[i] == '.')
            {
                putchar(pointer_table[cursor_place]);
            }
            else if(code[i] == ',')
            {
                pointer_table[cursor_place] = getchar();
            }
            else if(code[i] == '[')
            {
                if(pointer_table[cursor_place] == 0)
                {
                    size_t i2 = i + 1;
                    size_t closing_loop; //pos of the closing loop
                    int stackloop = -1; //stack thing to detect if the other [ is not of another loop in loop
                    for(; i2 < size_of_code ; i2++)
                    {
                        //printf("%c", code[i2]);
                        if(stackloop != 0)
                        {
                            if(code[i2] == '[')
                            {
                                stackloop--;
                            }
                            else if(code[i2] == ']')
                            {
                                stackloop++;
                            }
                        }
                        else
                        {
                            closing_loop = i2 - 1;
                            break;
                        }
                    }
                    i = closing_loop;
                }
            }
            else if(code[i] == ']')
            {
                if(pointer_table[cursor_place] != 0)
                {
                    size_t i2 = i - 1;
                    size_t opening_loop; //pos of the opening loop
                    int stackloop = 1; //stack thing to detect if the other [ is not of another loop in loop
                    for(; i2 > 0 ; i2--)
                    {
                        //printf("%c", code[i2]);
                        if(stackloop != 0)
                        {
                            if(code[i2] == '[')
                            {
                                stackloop--;
                            }
                            else if(code[i2] == ']')
                            {
                                stackloop++;
                            }
                        }
                        else
                        {
                            opening_loop = i2 + 1;
                            break;
                        }
                    }
                    i = opening_loop;
                }
            }
        }
        //desalocate memory to our table of pointer
        free(pointer_table);
    }
    else
    {
        fputs("missings ]", stderr);
    }
}