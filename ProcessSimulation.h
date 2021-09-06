#ifndef PROCESSSIMULATION_H
#define PROCESSSIMULATION_H

void getPID();
void clearMemoryGarbage(char *array, int N);
void formatInstruction(char *instruction, char *instructionLetter, char *firstArgument, char *secondArgument);
void runInstruction(char *instruction, int *n, int *d, char *mem);
void getInstructions(char **instructions, int *NInstrucoes);
void processMain();
void innerManager();


#endif //PROCESSOSIMULADO_H