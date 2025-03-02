#include <stdio.h>

int main() {
    // Créer un fichier et écrire "Bonjour" dedans
    FILE *f = fopen("Ex1.txt", "w"); // Ouvrir en mode écriture
    if (f == NULL) {
        perror("Erreur à l'ouverture du fichier");
        return 1;
    }
    fprintf(f, "Bonjour\n"); // Écrire "Bonjour" dans le fichier
    fclose(f); // Fermer le fichier

    // Ajouter "tout le monde" à la suite
    f = fopen("Ex1.txt", "a"); // Ouvrir en mode ajout
    if (f == NULL) {
        perror("Erreur à l'ouverture du fichier");
        return 1;
    }
    fprintf(f, "tout le monde\n"); // Écrire "tout le monde" dans le fichier
    fclose(f); // Fermer le fichier

    // Lire le fichier et afficher son contenu sur la console
    char ligne[256]; // Buffer pour stocker chaque ligne lue
    f = fopen("Ex1.txt", "r"); // Ouvrir en mode lecture
    if (f == NULL) {
        perror("Erreur à l'ouverture du fichier");
        return 1;
    }

    // Lire et afficher chaque ligne
    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        printf("%s", ligne); // Afficher la ligne sur la console
    }
    fclose(f); // Fermer le fichier

    char c;
    int lineCount = 0;

    f = fopen("Ex1.txt", "r"); // Ouvrir en mode lecture
    if (f == NULL) {
        perror("Erreur à l'ouverture du fichier");
        return 1;
    }

    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            lineCount++;
        }
    }

    return 0;
}