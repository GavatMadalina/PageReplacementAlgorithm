#include <stdio.h>
#include <stdlib.h>

typedef struct reference
{
    int value;
    int lifes;
} reference;

int main()
{
    int frameNr;
    int input;
    int miss = 0;
    scanf("%d", &frameNr);
    struct reference *clock = (reference *)malloc(frameNr * sizeof(reference));
    for (int i = 0; i < frameNr; i++)
    {
        clock[i].value = 0;
        clock[i].lifes = 0;
    }

    int index = 0;
    while (1)
    {
        if (scanf("%d", &input) == EOF)
        {
            break;
        }

        int referenceFound = 0;
        // check if reference is in the frame
        for (int i = 0; i < frameNr; i++)
        {
            // if we find the reference, we increase the life and break the loop
            if (clock[i].value == input)
            {
                clock[i].lifes = 1;
                referenceFound = 1;
                break;
            }
        }

        if (referenceFound == 0) // if we don't find the reference,
        {
            miss++;
            while (1)
            {
                if (clock[index].lifes == 0) // if the reference has 0 lifes, we replace it
                {
                    clock[index].value = input;
                    clock[index].lifes = 1;
                    break;
                }
                else // if the reference has more than 0 lifes, we decrease the lifes
                {
                    clock[index].lifes = 0;
                }

                if (index == frameNr - 1)
                {
                    index = 0;
                }
                else
                {
                    index++;
                }
            }
        }
    }

    free(clock);
    printf("%d\n", miss);

    return 0;
}