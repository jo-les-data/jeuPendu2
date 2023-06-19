#include <stdio.h>
#include <stdlib.h>

//get a random number.
int randNb(int lower, int upper)
{
    int random = rand(); 
    int r = (random % (upper - lower + 1)) + lower;
    //int r = rand();
    printf("%d\n", r);
    return r;
}

// get word at a given line #
char* getWord(int line)
{
    FILE* fichier = NULL;
   // int numb = 30;
    int lineNumb = 0;
    char* word = "";

    errno_t error_code = fopen_s(&fichier, "mots.txt", "r");

    if (error_code != 0)
    {
        printf("Error !\n");
    }
    else
    {
       // printf("I opened the file!\n");

        char chunk[128];
        while ((fgets(chunk, sizeof(chunk), fichier) != NULL) && (lineNumb < line)) {
            word = chunk;
           // printf("%d\n", lineNumb);
            //printf("%s\n", word);
            lineNumb++;
        }
        //printf("%s\n", word);
        fclose(fichier);
    }

	return word;
}


//check word, if too short, search again
/*checkWord(char* word)
{

}*/



//get word until conditions are met.

char* recupWord()
{

    int line = randNb(0, 22735);
    char* word = getWord(line);
    return word;

}
