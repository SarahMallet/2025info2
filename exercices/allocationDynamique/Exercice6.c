#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* copier_majuscule(const char* chaine){
    int taille = strlen(chaine);
    char* phrase = (char*)malloc((taille+1)*sizeof(char));
    if(!phrase)
        return NULL;
    for(int i = 0;i<taille;i++){
        phrase[i]=toupper(chaine[i]);
    }
    return phrase;    
}

//Ex7
/*void liberer_memoire(char* ph){
    if(ph)
        free(ph);
}*/

//Ex8
char* decouper_mot(const char* phrase){
    if(!phrase)
        return NULL;
    int taille = strlen(phrase);
    char* mt = (char*)malloc(taille*sizeof(char));
    for(int i = 0;i<taille;i++){
        mt[i]=phrase[i];
        if(phrase[i]==' ')
            break;
    }
    return mt;

}

//Ex9

int main(void){
    char* phraseSimple = "salut comment ca va";
    char* phraseMajuscule = copier_majuscule(phraseSimple);
    for(int i = 0;i<strlen(phraseMajuscule);i++){
        printf("%c",phraseMajuscule[i]);
    }
    printf("\n");
    //liberer_memoire(phraseMajuscule);
    char* mot = decouper_mot(phraseSimple);
    for(int i = 0;i<strlen(mot);i++){
        printf("%c",mot[i]);
    }
    printf("\n");
    return 0;
}