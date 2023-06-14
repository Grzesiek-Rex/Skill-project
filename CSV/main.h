#ifndef MAIN_H
#define MAIN_H

#define MAX_LINE_LENGTH 50
#define WINDOW_SIZE 500

typedef struct 
{
    double values[WINDOW_SIZE];
    int front;
    int back;
    int size;
} Queue;

void addToQueue(Queue *queue, double value);
double calcAvg(const Queue *queue);
double calcMax(const Queue *queue);
double calcMin(const Queue *queue);

#endif  // MAIN_H