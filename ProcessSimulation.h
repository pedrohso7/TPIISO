#ifndef PROCESSSIMULATION_H
#define PROCESSSIMULATION_H

//void getPID();
// void instructionsList();
// void clearMemoryGarbage(char *array, int N);
void getInstructions(char **instructions, int *NInstrucoes);
void formatInstruction(char *instruction, char *instructionLetter, char *firstArgument, char *secondArgument);
void runInstructionPS(char *instruction, int *n, int *d, char *mem);
void processMain();
//void innerManager();


#endif //PROCESSOSIMULADO_H