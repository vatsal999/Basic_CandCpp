#include <stdio.h>
#include <string.h>
// TODO: add support for capital letters

// takes a a string => buff[]
// converts this string to relative numbers string => i.e. a becomes 1 , z becomes 26
// adds 13 to this ROT 13
// converts this new array to text string

void encrypt(char buff[]){

    for (int i = 0; i < strlen(buff); i++) {
        /* printf("buff[i] value:%c\n", buff[i]); */
        /* buff[i] = buff[i] + 13; */
        if ( buff[i] + 13 > 122){
            /* printf("Bigger than z"); */
            /* buff[i] = buff[i] - 26; */
            buff[i] = buff[i] - 13;
            /* printf("Truncated Value becomes:%c\n", buff[i]); */
        }else{
            buff[i] = buff[i] + 13;
        }

        /* printf("%c\n", buff[i]); */
    }
    printf("Final string: %s\n", buff);

}

void decrypt(char buff[]){

    for (int i = 0; i < strlen(buff); i++) {
        if ( buff[i] - 13 < 97){
            buff[i] = buff[i] + 13;
        }else{
            buff[i] = buff[i] - 13;
        }
    }
    printf("Final string:%s\n", buff);
}

int main (int argc, char *argv[])
{
    
    char buff[100];
    /* scanf("%s", buff); */ // used for scan string without space
    fgets(buff, sizeof(buff), stdin);
    // result of comparison against a string literal is unspecified 
    /* if(argv[1] == "e") */
    /*     encrypt(); */
    /* else if (argv[1] == "d") */
    /*     decrypt(); */
    if(*argv[1] == 'e')
        encrypt(buff);
    else if (*argv[1] == 'd')
        decrypt(buff);

    return 0;
}

