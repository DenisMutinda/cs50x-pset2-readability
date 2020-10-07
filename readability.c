#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

float letters(string text);
float words(string text);
float sentences(string text);
int grade(float letters, float words, float sentences);

int main(void)
{
    
    // Get the input from the user.
    string text = get_string("Text: ");
    
    // Call the functions to count number of letters, words and sentences in the text.
    // Print out the answer.
    float letterCount = letters(text);
    float wordCount = words(text);
    float sentenceCount = sentences(text);
    
    // Call function to approximate grade, passing in the above values.
    int gradeLevel = grade(letterCount, wordCount, sentenceCount);
    if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", gradeLevel);
    }

    return 0;
}

float letters(string text)
{
    
    // Variable to store the actual number of letters in the string passed.
    float letters = 0;
    
    // As long as the last character is not the null terminator, keep checking the string.
    for (int i = 0; text[i] != '\0'; i++)
    {
        
        // Use the library to check whether the specific character we are on is alphanumeric.
        // If it is, increase the count on letters.
        if (isalnum(text[i]))
        {
            letters++;
        }
    }
    
    return letters;
    
}

float words(string text)
{
    // Variable to store the actual number of words in the string passed.
    float words = 0;
    
    // As long as the last character is not the null terminator, keep checking the string.
    for (int i = 0; text[i] != '\0'; i++)
    {
        
        // Check whether the specific character we are on is space (ASCII code is 32).
        // If it is, increase the count on words.
        if (text[i] == 32)
        {
            words++;
        }
    }
    
    // The last word will not have a space behind it. So we manually add one to letters to account for this.
    words++;
    
    return words;
}

float sentences(string text)
{
    // Variable to store the actual number of sentences in the string passed.
    int sentences = 0;
    
    // As long as the last character is not the null terminator, keep checking the string.
    for (int i = 0; text[i] != '\0'; i++)
    {
        
        // For the purposes of this exercise, a sentence ends with a period(.), bang(!) or question mark(?).
        // Check whether the specific character we are on is any of the three ASCII( bang = 33, period = 46, question mark = 63).
        // If it is, increase the count on sentences.
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }
    
    return sentences;
    
}

int grade(float letters, float words, float sentences)
{
    // Compute the average number of letters and sentencesper 100 words in the text input.
    float averageLetters = 100 * letters / words;
    float averageSentences   = 100 * sentences / words;
    
    // Use the Coleman-Liau index to work out the grade level for entered text.
    float grade = (0.0588 * averageLetters - 0.296 * averageSentences - 15.8);
    
    return round(grade);
}
