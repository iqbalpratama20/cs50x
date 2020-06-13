#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

// Declaring function that will be created below the main function
int letters_count(string text);
int words_count(string text);
int sentences_count(string text);
float get_index(string text);

int main(void)
{
    // Get text from user
    string text = get_string("Text: ");

    // Get grade by using get_index function
    float grade = get_index(text);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.f\n", grade);
    }
}

// Create a function to count the number of letter(s) in a given string
int letters_count(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count += 1;
        }
    }
    return count;
}

// Create a function to count the number of word(s) in a given string
int words_count(string text)
{
    int count = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            count += 1;
        }
    }
    return count;
}

// Create a function to count the number of sentence(s) in a given string
int sentences_count(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count += 1;
        }
    }
    return count;
}

// Create function to get text grade
float get_index(string text)
{
    // Calculating the average number of letters per 100 words in the text
    float L = ((float) letters_count(text) / words_count(text)) * 100;
    // Calculating the average number of sentences per 100 words in the text
    float S = ((float) sentences_count(text) / words_count(text)) * 100;

    // Calculating grade index by using Coleman-Liau algorithm
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    // Return grade value to be used in the main function
    return round(index);
}
