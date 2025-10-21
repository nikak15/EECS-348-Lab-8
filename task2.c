#include <stdio.h>//

int main(){
    double temp;
    char scale;
    char convert;
    double finaltemp;
    double tempC;
    char *category;
    char *advisory;


    printf("Enter the temperature value: ");
    while (scanf("%lf", &temp) != 1) {
        printf("Invalid input. Please enter a numeric temperature value: ");
        while(getchar() != '\n'); 
    }
    while (1){
        printf("Enter the original scale (C, F, or K): ");
        scanf(" %c", &scale);
        if (scale == 'C' || scale == 'F' || scale == 'K'){
            break;
        } else {
            printf("Invalid scale. Please enter C, F, or K.\n");
        }
    }
    
    while (1){
        printf("Enter the scale to convert to (C, F, or K): ");
        scanf(" %c", &convert);

        if (convert == 'C' || convert == 'F' || convert == 'K'){
            break;
        } else {
            printf("Invalid scale. Please enter C, F, or K.\n");
        }
    }

    
    if (scale == 'F'){
        tempC =  (temp - 32) * 5.0/ 9.0;
    } else if (scale == 'K'){
        tempC = temp - 273.15;
    } else {
        tempC = temp;
    }


    if (tempC < 0){
        category = "Freezing";
        advisory = "Wear a heavy coat";
    } else if (tempC < 10){
        category = "Cold";
        advisory = "It is cold outside";
    } else if (tempC < 25){
        category = "Comfortable";
        advisory = "it is nice outside";
    } else if (tempC < 35){
        category = "Hot";
        advisory = "it is hot outside";
    } else {
        category = "extreme heat";
        advisory = "drink a lot of water";
    }

    
    if (convert == 'F'){
        finaltemp = (tempC *9.0/ 5.0) + 32;
    } else if (convert == 'K'){
        finaltemp = tempC + 273.15;
    } else{
        finaltemp = tempC;
    }

    printf("Converted temperature: %.2f %c\n", finaltemp, convert);
    printf("Temperature category: %s\n", category);
    printf("Weather advisory: %s\n", advisory);

}