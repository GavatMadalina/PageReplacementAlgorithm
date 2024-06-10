if (referenceFound == 0)
{ // if we don't find the reference,
    miss++;
    while (1)
    {
        if (clock[index].lifes == 0)
        { // if the reference has 0 lifes, we replace it
            clock[index].value = input;
            clock[index].lifes = 1;
            break;
        }
        else
        { // if the reference has more than 0 lifes, we decrease the lifes
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