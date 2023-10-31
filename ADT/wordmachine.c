#include <stdio.h>

#include "wordmachine.h"
#include "charmachine.h"
#include "boolean.h"

boolean EndWord;
boolean EndInput;
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
void STARTWORDINPUT()
{
    START();
    IgnoreBlanks();
    ignoreNewLine();
    if (currentChar == MARKINPUT)
    {
        EndInput = true;
    }
    else
    {
        EndInput = false;
        CopyWordInput();
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
void ADVWORDINPUT()
// ada \n nya
{
    IgnoreBlanks();
        if (currentChar == MARKINPUT)
        {
            EndWord = true;
        }
        else
        {
            ignoreNewLine();
            CopyWordInput();
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
    while ( currentChar != newLine )
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
void CopyWordInput()
{
    int i = 0;
    while (currentChar != MARKINPUT)
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

