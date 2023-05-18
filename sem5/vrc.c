#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// to perform vcr and calculate the parity bit
void vcr(char data[])
{
    int i, count = 0;
    for (i = 0; data[i] != '\0'; i++)
    {
        if (data[i] == '1')
            count++;
        else
            continue;
    }
    // we are implementing the even parity
    if (count % 2 == 0)
        data[i] = '0';
    else
        data[i] = '1';

    // putting the null character in the string to show the end of the string
    data[i + 1] = '\0';
}

bool checkVcr(char data[])
{
    int n, i, count = 0;
    for (i = 0; data[i] != '\0'; i++)
    {
        if (data[i] == '1')
            count++;
        else
            continue;
    }

    if (count % 2 == 0)
        return true;
    else
        return false;
}

void createError(char data1[])
{
    int j = 0;
    int n = strlen(data1);
    for (int i = 0; i < 3; i++)
    {
        if (data1[j] == '1')
        {
            data1[j] = '0';
        }

        else
            data1[j] = '1';

        j = (i + 113) % n;
    }
}
int main()
{
    char input[100], temp[100];
    printf("Enter the data to be sent: ");
    scanf("%s", input);
    vcr(input);

    printf("The data sent is: %s\n", input);

    // now we are going to intentionally create some errors
    strcpy(temp, input);

    createError(temp);

    printf("Data after adding some errors is: %s\n", temp);
    if (checkVcr(temp))
        printf("Recived data has no error\n");

    else
        printf("Received data has errors\n");
    return 0;
}
