#include <stdio.h>

#include "wordmachine.h"
#include "charmachine.h"
#include "boolean.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK && currentChar != MARKC)
    {
        ADV();
    }
}
void STARTWORDFILE(char filename[])
{
    STARTFILE(filename);
    IgnoreBlanks();
    ignoreNewLine();
    if (currentChar == MARKC)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordFile();
    }

}
void STARTWORD()
{
    START();
    IgnoreBlanks();
    ignoreNewLine();
    if (currentChar == MARKC)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
    
}

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARKC)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}
void ADVWORDFILE()
// ada \n nya
{
    IgnoreBlanks();
        if (currentChar == MARKC)
        {
            EndWord = true;
        }
        else
        {
            ignoreNewLine();
            CopyWordFile();
        }
}
void CopyWord()
{
    int i = 0;
    while (currentChar != MARKC && currentChar != BLANK)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax)
    {
        i = NMax;
    }
    currentWord.Length = i;
}
void CopyWordFile()
{
    int i = 0;
    while (currentChar != MARKC && currentChar != newLine)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax)
    {
        i = NMax;
    }
    currentWord.Length = i;
}
void ignoreNewLine()
{
    while (currentChar == newLine && currentChar != MARKC)
    {
        ADV();
    }
}