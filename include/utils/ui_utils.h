// include/utils/ui_utils.h
#ifndef UI_UTILS_H
#define UI_UTILS_H

void cleanStandardInputStream(void);
// PROMISES:
// Clears the standard inpuit stream

void clearScreen(void);
// PROMISES:
// Clears the terminal/screen for new output

void pressEnter();
// PROMISES:
// Prompts the user to press enter before continuing with the program

void displayHeader();
// PROMISES:
// Displays the start screen for the program

void printChoicePrompt();
// PROMISES:
// Displays the options for the user to select from

int menu();
// PROMISES:
// Returns user menu choice as an int
// Reprompts user on invalid menu inputs

#endif // UI_UTILS_H

