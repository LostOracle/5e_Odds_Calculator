#include <stdio.h>

int main()
{
    //Declare some variables because this is just C
    int target = -1;
    char input_str[255];
    int advantage = -1;
    int disadvantage;
    int modifier = -1;
    int successes = 0;
    int failures = 0;
    double odds;

    //Print a nice little header
    printf("**********************\n");
    printf("Odds calculator\n");
    printf("Author: Ian Carlson\n");

    //Get the target DC, AC, or whatever
    printf("Enter target number: ");
    if(1 != scanf("%d",&target))
    {
        printf("Invalid input\n");
        return 0;
    }

    //Check if we have advantage
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

    //Check if we have disadvantage
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

    //Get the modifier to add to the roll
    printf("Enter Modifier (Ability Mod + Proficiency): ");
    if(1 != scanf("%d",&modifier))
    {
        printf("Invalid input\n");
        return 0;
    }


    //Now, count all possible rolls
    
    //Disadvantage
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
    //Advantage
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
    //Normal
    else
    {
        int i;
        for(i = 1; i <= 20; i++)
            if(i + modifier >= target)
                successes++;
            else
                failures++;
    }
    
    //Calculate odds of success
    odds = (double)successes / (successes + failures);
    //Print them
    printf("Success chance: %g\n",odds);
    return 0;

}
