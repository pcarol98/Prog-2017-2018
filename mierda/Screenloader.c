#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#define MAX_IMG 250
#define MAX_DOTS 18

void print_lscreen(FILE * f);

int main(void){
    char * filenom = "image1.txt";
    FILE * f = NULL;

    if((f = fopen(filenom,"r")) == NULL){
        printf("Error opening %s\n",filenom);
        return 1;
    }

    print_lscreen(f);
    fclose(f);

    return 0;
}

void print_lscreen(FILE * f){
    char image[MAX_IMG];
    char dots[MAX_DOTS];
    float percent = 1;
    int i;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    for (i = 0; i <= MAX_DOTS; i++) {
      dots[i] = '\0';
    }

    dots[0] = '.';
    i = 1;
    while (i <= MAX_DOTS) {
      percent = (float)i/MAX_DOTS *100;
      printf("LOADING %s %.01f%c", dots, percent,'%');
      Sleep(250);
      dots[i] = '.';
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      i++;
    }

    PlaySound(TEXT("Transformers_title.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    while(fgets(image, sizeof(image), f) != NULL){
      printf("%s",image);
    }
    Sleep(4000);

}
