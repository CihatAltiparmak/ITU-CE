#include <stdio.h>

typedef struct word {
    char* data;
} word;

typedef struct sentence {
    word* data;
    int word_count;
}i sentence;

typedef struct paragraph {
    sentence* data;
    int sentence_count;
} paragraph;

typedef struct document {
    paragraph* data;
    int paragraph_count;
} document;

document get_document(char *text)
{
    // word parsing
    for (int i = 0; text[i] != '\0'; i++) {
        if()
    }
}

word kth_word_in_mth_sentence_of_nth_paragraph(document Doc, int k, int m, int n)
{
}

sentence kth_sentence_in_mth_paragraph(document Doc, int k, int m)
{
}

paragraph kth_paragraph(document Doc, int k)
{
}

int main() 
{


    char* text = "Thinking of you is pretty hopeful.It is like listening to the most beautiful song from the most beautiful voice on earth.\nBut hope is not enough for me anymore.\nI don’t want to listen to songs anymore.I want to sing.\0"; 
    
    printf("%s\n\n", text);
    
    int choice;
    printf("Query Type: ");
    scanf("%d", &choice);

    int k, m, n;
    if(choice == 1) {
        scanf("%d", &k);
    } else if(choice == 2) {
        scanf("%d %d", &k, &m);
    } else if(choice == 3) {
        scanf("%d %d %d", &k, &m, &n);
    }  
}
