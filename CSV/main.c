#include <stdio.h> //for fopen(), fclose(), fprint(), fgets()
#include <stdlib.h> //for atof()
#include <string.h> //for strncmp(), strtok()
#include "main.h"

int main() 
{
    char input_filename[] = "Input.csv";
    char output_filename[] = "Output.csv";

    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) 
    {
        printf("Unable to open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) 
    {
        printf("Unable to open output file.\n");
        fclose(input_file);
        return 1;
    }

    Queue queue;
    queue.front = 0;
    queue.back = -1;
    queue.size = 0;

    int skip_first_line = 1; 
    fprintf(output_file, "Wejście;Avg;Max;Min;\n");

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)) 
    {
        
        if (skip_first_line) 
        {
            skip_first_line = 0;
            if(strncmp(line, "Wejście", 7) == 0) 
                continue;
        }

        double value = atof(strtok(line, ";"));

        addToQueue(&queue, value);

        double average = calcAvg(&queue);
        double maximum = calcMax(&queue);
        double minimum = calcMin(&queue);

        fprintf(output_file, "%.2f; %.2f; %.2f; %.2f;\n", value, average, maximum, minimum);
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}

// A function that fills a queue with sent values.
// Params: queue - data queue, value - sent value
void addToQueue(Queue *queue, double value) 
{
    if (queue->size == WINDOW_SIZE) 
    {
        queue->front = (queue->front + 1) % WINDOW_SIZE;
    }
    else 
    {
        queue->size++;
    }

    queue->back = (queue->back + 1) % WINDOW_SIZE;
    queue->values[queue->back] = value;
}

// A function that calculates and returns a moving average
// Params: queue - data queue
double calcAvg(const Queue *queue) 
{
    double sum = 0.0;
    for (int i = 0; i < queue->size; ++i) 
    {
        sum += queue->values[(queue->front + i) % WINDOW_SIZE];
    }
    return sum / queue->size;
}

// A function that calculates and returns a moving maximum
// Params: queue - data queue
double calcMax(const Queue *queue) 
{
    double max = queue->values[queue->front];
    for (int i = 1; i < queue->size; ++i) 
    {
        double value = queue->values[(queue->front + i) % WINDOW_SIZE];
        if (value > max) 
        {
            max = value;
        }
    }
    return max;
}

// A function that calculates and returns a moving minimum
// Params: queue - data queue
double calcMin(const Queue *queue) 
{
    double min = queue->values[queue->front];
    for (int i = 1; i < queue->size; ++i) 
    {
        double value = queue->values[(queue->front + i) % WINDOW_SIZE];
        if (value < min) 
        {
            min = value;
        }
    }
    return min;
}