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
void ignoreNewLine()
{
    while (currentChar == newLine && currentChar != MARKC)
    {
        ADV();
    }
}