#include <stdio.h>

char pixel = '*';

void renderfill(int n){
    for (int i = 0; i < n - 2; i++){
        for(int j =0; j < n ; j++){
            printf("%c", pixel);
        }
        printf("\n");
    }

    //printf("%c", pixel);
}

void renderstroke(int n){
    // first line
    for ( int i = 0; i < n; i++){
        printf("%c",pixel);
    }
    printf("\n");
    //

    for ( int j = 0; j < n - 2; j++){
        printf("%c",pixel);
        for ( int k = 0; k < n - 2; k++){
            printf(" ");
        }
        printf("%c",pixel);
        printf("\n");
    }

    // last line
    for ( int l = 0; l < n; l++){
        printf("%c",pixel);
    }
    printf("\n");
    //
}

int main(){
    //  # # # #
    //  #     #
    //  #     #
    //  # # # #
    // n rows n columns
    renderstroke(5);

}
