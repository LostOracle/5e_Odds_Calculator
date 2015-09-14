#include <stdio.h>

int main()
{
    int target = -1;
    char input_str[255];
    int advantage = -1;
    int disadvantage;
    int modifier = -1;
    int successes = 0;
    int failures = 0;
    double odds;
    printf("**********************\n");
    printf("Odds calculator\n");
    printf("Author: Ian Carlson\n");

    //Get input
    printf("Enter target number: ");
    if(1 != scanf("%d",&target))
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Advantage? (y/n): ");
    if(1 != scanf("%s",input_str))
    {
        printf("Invalid input\n");
        return 0;
    }
    if(input_str[0] == 'y' || input_str[0] == 'Y')
        advantage = 1;
    else
        advantage = 0;

    printf("Disadvantage? (y/n): ");
    if(1 != scanf("%s",input_str))
    {
        printf("Invalid input\n");
        return 0;
    }
    if(input_str[0] == 'y' || input_str[0] == 'Y')
        disadvantage = 1;
    else
        disadvantage = 0;

    printf("Enter Modifier (Ability Mod + Proficiency): ");
    if(1 != scanf("%d",&modifier))
    {
        printf("Invalid input\n");
        return 0;
    }


    //Now, count all possible rolls
    if(disadvantage && !advantage)
    {
        int i,j;
        for(i = 1; i <= 20; i++)
            for(j = 1; j <= 20; j++)
                if(i + modifier >= target && j + modifier >= target)
                    successes++;
                else
                    failures++;
    }
    else if(advantage && !disadvantage)
    {
        int i,j;
        for(i = 1; i <= 20; i++)
            for(j = 1; j <= 20; j++)
                if(i + modifier >= target ||  j + modifier >= target)
                    successes++;
                else
                    failures++;
    }
    else
    {
        int i;
        for(i = 1; i <= 20; i++)
            if(i + modifier >= target)
                successes++;
            else
                failures++;
    }

    odds = (double)successes / (successes + failures);
    printf("Success chance: %g\n",odds);
    return 0;

}
