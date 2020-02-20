#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void translate2ascii(char c)
{
    printf("%d ", (int)c);
}

int ascii2binary(int num)
{
    if (num < 2)
    {
        return num;
    }
    return ascii2binary(num / 2) * 10 + num % 2;
}

int strLength(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

void char2ascii(int firstflag, int secondflag, char str[], char **link1, char **link2)
{
    char letters[256];
    int j;
    if (firstflag == 0) /*first option-char2ascii*/
    {
        if (secondflag == 0)
        { /*no input or output files*/
            char ch;
            while ((ch=getchar()) != EOF){
                if(ch!='\r'&&ch!='\n') {
                    translate2ascii(ch);
                    j = scanf("%s", letters);
                    j = strLength(letters);
                    int i;
                    for (i = 0; i < j; i++) {
                        translate2ascii(letters[i]);
                    }
                }
            }
        }
        else if (secondflag == 1)
        { /*there is an input file*/
            FILE *fp = fopen(link1, "r");

            if (fp == NULL)
            {
                perror("Error while opening the file.\n");
                exit(EXIT_FAILURE);
            }

            char ch;
            while ((ch=fgetc(fp)) != EOF) {
                if (ch != '\r' && ch != '\n') {
                    translate2ascii(ch);
                }
            }
            fclose(fp);
        }
        else if (secondflag == 2)
        { /*there is an output file*/
            FILE *fp = fopen(link1, "w");

            if (fp == NULL)
            {
                perror("Error while opening the file.\n");
                exit(EXIT_FAILURE);
            }
            char ch;
            while ((ch=getchar()) != EOF){
                if(ch!='\r'&&ch!='\n') {
                    fprintf(fp, "%d ", (int) ch);
                    j = scanf("%s", letters);
                    j = strLength(letters);
                    int i;
                    for (i = 0; i < j; i++) {
                        fprintf(fp, "%d ", (int) letters[i]);
                    }
                }
            }
        }
        else if (secondflag == 3)
        { /*both input and output files*/
            FILE *ifp = fopen(link1, "r");
            FILE *ofp = fopen(link2, "w");

            if (ifp == NULL || ofp == NULL)
            {
                perror("Error while opening one of the files.\n");
                exit(EXIT_FAILURE);
            }

            char ch;
            while ((ch=fgetc(ifp)) != EOF){
                if(ch!='\r'&&ch!='\n') {
                    fprintf(ofp, "%d ", (int) ch);
                }
            }
            fclose(ifp);
            fclose(ofp);
        }
    }
    else if (firstflag == 1) /* second option. the question is which one: */
    {
        if (secondflag == 0) /*second (1) option-ascii2binary*/
        {
            char ch;
            while ((ch=getchar()) != EOF){
                if(ch!='\r'&&ch!='\n') {
                    printf("%d ", ascii2binary((int) ch));
                    j = scanf("%s", letters);
                    j = strLength(letters);
                    int i;
                    for (i = 0; i < j; i++) {
                        printf("%d ", ascii2binary((int) letters[i]));
                    }
                }
            }
        }
        else if (secondflag == 1) /*second (2) option-ascii2binary but input from a file*/
        {
            FILE *fp = fopen(link1, "r");

            if (fp == NULL)
            {
                perror("Error while opening the file.\n");
                exit(EXIT_FAILURE);
            }

            char ch;
            while ((ch=fgetc(fp)) != EOF){
                if(ch!='\r'&&ch!='\n') {
                    printf("%d ", ascii2binary((int) ch));
                }
            }
            fclose(fp);
        }
        else if (secondflag == 2) /*second (3) option-ascii2binary but output to a file*/
        {
            FILE *fp = fopen(link1, "w");

            if (fp == NULL)
            {
                perror("Error while opening the file.\n");
                exit(EXIT_FAILURE);
            }
            char ch;
            while ((ch=getchar()) != EOF){
                if(ch!='\r'&&ch!='\n') {
                    j = scanf("%s", letters);
                    j = strLength(letters);
                    fprintf(fp, "%d ", ascii2binary((int) ch));
                    int i;
                    for (i = 0; i < j; i++) {
                        fprintf(fp, "%d ", ascii2binary((int) letters[i]));
                    }
                }

            }
            fclose(fp);
        }
        else if (secondflag == 3)
        { /*both input and output files*/
            FILE *ifp = fopen(link1, "r");
            FILE *ofp = fopen(link2, "w");

            if (ifp == NULL || ofp == NULL)
            {
                perror("Error while opening one of the files.\n");
                exit(EXIT_FAILURE);
            }

            char ch;
            while ((ch=fgetc(ifp)) != EOF){
                if(ch!='\r'&&ch!='\n') {
                    fprintf(ofp, "%d ", ascii2binary((int) ch));
                }
            }
            fclose(ifp);
            fclose(ofp);
        }
    }

    else if (firstflag == 2) /* third option. the question is which one: */
    {
        if (secondflag == 0) /*third (1) option-upper-lower/lower-upper*/
        {
            char ch;
            while ((ch=getchar()) != EOF){
                if(ch!='\r'&&ch!='\n') {
                    if (isupper((int) ch)) {
                            printf("%c", tolower((int) ch));
                        } else {
                            if (islower((int) ch)) {
                                printf("%c", toupper((int) ch));
                            } else {
                                printf("%c", ch);
                            }
                        }
                    j = scanf("%s", letters);
                    j = strLength(letters);
                    int i;
                    for (i = 0; i < j; i++) {
                        if (isupper((int) letters[i])) {
                            printf("%c", tolower((int) letters[i]));
                        } else {
                            if (islower((int) letters[i])) {
                                printf("%c", toupper((int) letters[i]));
                            } else {
                                printf("%c", letters[i]);
                            }
                        }
                    }
                }
            }
        }
        else if (secondflag == 1) /*third (2) option-upper-lower/lower-upper but input from a file*/
        {
            FILE *fp = fopen(link1, "r");

            if (fp == NULL)
            {
                perror("Error while opening the file.\n");
                exit(EXIT_FAILURE);
            }

            char ch;
            while ((ch=fgetc(fp)) != EOF) {
                if (ch != '\r' && ch != '\n') {
                    if (isupper((int) ch)) {
                        printf("%c", tolower((int) ch));
                    } else {
                        if (islower((int) ch)) {
                            printf("%c", toupper((int) ch));
                        } else {
                            printf("%c", ch);
                        }
                    }
                }
            }
            fclose(fp);
        }
        else if(secondflag==2) /*third (3) option-upper-lower/lower-upper but output to a file*/
        {
            FILE *fp = fopen(link1, "w");

            if (fp == NULL)
            {
                perror("Error while opening the file.\n");
                exit(EXIT_FAILURE);
            }
            char ch;
            while ((ch=getchar()) != EOF) {
                if (ch != '\r' && ch != '\n') {
                    if (isupper((int) ch)) {
                            fprintf(fp, "%c", tolower((int) ch));
                        } else {
                            if (islower((int) ch)) {
                                fprintf(fp, "%c", toupper((int) ch));
                            } else {
                                fprintf(fp, "%c", ch);
                            }
                        }
                    j = scanf("%s", letters);
                    j = strLength(letters);
                    int i;
                    for (i = 0; i < j; i++) {
                        if (isupper((int) letters[i])) {
                            fprintf(fp, "%c", tolower((int) letters[i]));
                        } else {
                            if (islower((int) letters[i])) {
                                fprintf(fp, "%c", toupper((int) letters[i]));
                            } else {
                                fprintf(fp, "%c", letters[i]);
                            }
                        }
                    }
                }
            }
            fclose(fp);
        }
        else if(secondflag==3){/*both input and output files*/
            FILE *ifp = fopen(link1, "r");
            FILE *ofp = fopen(link2, "w");

            if (ifp == NULL || ofp == NULL)
            {
                perror("Error while opening one of the files.\n");
                exit(EXIT_FAILURE);
            }

            char ch;
            while ((ch=fgetc(ifp)) != EOF) {
                if (ch != '\r' && ch != '\n') {
                    if (isupper((int) ch)) {
                        fprintf(ofp, "%c", tolower((int) ch));
                    } else {
                        if (islower((int) ch)) {
                            fprintf(ofp, "%c", toupper((int) ch));
                        } else {
                            fprintf(ofp, "%c", ch);
                        }
                    }
                }
            }

            fclose(ifp);
            fclose(ofp);
        }
    }
}

int main(int argc, char **argv)
{
    char *str[8];
    int i;
    for (i = 0; i < 8; i++)
    {
        str[i] = 0;
    }
    if (argc == 1) /*first option-char2ascii*/
        char2ascii(0, 0, str, "", "");
    else if (argc == 2) /* second or third (1) option. the question is which one: */
    {
        if (strcmp(argv[1], "-b") == 0)
            char2ascii(1, 0, str, "", "");
        else if (strcmp(argv[1], "-c") == 0)
            char2ascii(2, 0, str, "", "");
    }
    else if (argc == 3)
    { /*char2ascii, but with input/output file*/
        if (strcmp(argv[1], "-o") == 0)
            char2ascii(0, 2, str, argv[2], "");
        else
            char2ascii(0, 1, str, argv[2], "");
    }
    else if (argc == 4) /*options that are using files*/
    {
        if (strcmp(argv[1], "-b") == 0 && strcmp(argv[2], "-o") == 0)
            char2ascii(1, 2, str, argv[3], "");
        else if (strcmp(argv[1], "-b") == 0 && strcmp(argv[2], "-i") == 0)
            char2ascii(1, 1, str, argv[3], "");
        else if (strcmp(argv[1], "-c") == 0 && strcmp(argv[2], "-o") == 0)
            char2ascii(2, 2, str, argv[3], "");
        else
            char2ascii(2, 1, str, argv[3], "");
    }
    else if (argc == 5) /*a special case in which we have 2 files and in the char2ascii case*/
        char2ascii(0, 3, str, argv[2], argv[4]);

    else
    {
        if (strcmp(argv[1], "-b") == 0) /*read from and write to a file*/
            char2ascii(1, 3, str, argv[3], argv[5]);
        else
            char2ascii(2, 3, str, argv[3], argv[5]);
    }
    return 0;
}
/*
firstflag explained:
0-char2ascii
2-char2binary
3-upper->lower/lower->upper

secondflag explained:
0-from user,print into the terminal
1-from file,print into the terminal
2-from user,write into a file
3-from file, write into a file
*/
