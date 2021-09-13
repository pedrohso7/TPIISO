#ifndef PROCESSSIMULATION_H
#define PROCESSSIMULATION_H

#include "ProcessList.h"

//void getPID();
// void instructionsList();
// void clearMemoryGarbage(char *array, int N);
void impressProcessMemory(char **instructions, int N);//Apenas para teste
char** getInstructionsFromFile(int *NInstrucoes, char* fileName);
void getInstructionsFromKeyboard(char **instructions, int *NInstrucoes);
void formatInstruction(char *instruction, char *instructionLetter, char *firstArgument, char *secondArgument);
void runInstructionPS(char *instruction, int *n, int *d, char *mem);
int getSelfDataAndSendToLists(List *processTable, ProcessData *newElementData, Element *newElement, int *PID, int *PC, int *d, int *priority, int *state, int *timeCPU);
void processMain(char *fileName, List *processTable);
//void innerManager();


#endif //PROCESSOSIMULADO_H