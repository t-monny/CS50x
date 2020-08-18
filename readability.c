#include <cs50.h>
#include <stdio.h>
#include <string.h>

// function declaration
size_t strlen (const char *s);
int count_letters (char*s);
int count_spaces (char* a);
int count_sentences (char* c);
int index (float L, float S);
int main (void)

{
    // Get text from user
    string textinput = get_string("Text: ");
    
    // Calculate number of letters from users input
    float letters = count_letters(textinput);
    //printf("%1.0f letter(s) \n", letters);
    
    // Calculate no. of spaces to calculate words (spaces+1) in text
    float spaces = count_spaces(textinput);
    float words = spaces+1;
    //printf("%1.0f words(s) \n", words);

    // Calculate the no. of sentences in the text
    float sentences = count_sentences(textinput);
    //printf("%1.0f sentence(s) \n", sentences);
    
    // Calculate letters per 100 words
    float L = (100.00/words)*letters;
    //printf("Letters per 100 words: %1.0f \n", L);
    
    // Calculate sentences per 100 words
    float S = (100/words)*sentences;
    //printf("Sentences per 100 words: %1.0f \n", S);

    // Calculate grade level = index = 0.0588 * L - 0.296 * S - 15.8
    float grade = 0.0588 * L - 0.296 * S - 15.8;
    if(grade < 1)
    {
        printf("Before Grade 1\n");
        
    }
    else if(grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %1.0f\n", grade);
    }
}
  
// Function definitions

    // Definition of count_letters
    int count_letters(char* s)
    {
        int a = 0;
        int b = 0;
        do
        {
            if ((s[a] >= 65) && (s[a] <= 90))
            {
                b++;
            }
            if ((s[a] >= 97) && (s[a] <= 122))
            {
                b++;
            }
            a++;
        }    
        while (s[a] != 0);
        return b;
    }

    // Definition of function count_spaces
    int count_spaces (char * text)
       {
           int A = 0;
           int B = 0;
                do
                {
                    if (text[B] == 32)
                    {
                       A++;
                    }
                    B ++;
                }
                while (text[B] != 0);
                return A;
        }
    
    // Definition of count_sentences
    
    int count_sentences (char * c)
    {
        int sentence = 0;
        int d = 0;
        do
        {
            if (c[d] == 46 || c[d] == 33 || c[d] == 63)
            {
                sentence ++;
            }
            d ++;
        }
        while (c[d] != 0);
        return sentence;
    }

