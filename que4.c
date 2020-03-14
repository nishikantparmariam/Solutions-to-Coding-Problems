/*

ES-215 | COMPUTER ORGANIZATION AND ARCHITECTURE | SOLUTION TO QUESTION 4

NISHIKANT PARMAR - 18110108 (nishikant.parmar@iitgn.ac.in)

References Used for C Code for reading from file and writing to file - 

1) https://riptutorial.com/c/example/8274/get-lines-from-a-file-using-getline--
2) https://stackoverflow.com/questions/15822660/how-to-parse-a-string-separated-by-commas
3) https://stackoverflow.com/questions/1861152/problem-writing-array-of-doubles-to-a-file


READ ME -

1) Please use appropriate name for the read file (data.csv here)
2) (Assumption) In this question, I have set the value of Harmonic Mean or Geometric Mean to 'zero' if they do not exist 
3) Floating point precision is till 6th decimal point

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main(){

    //Initialise pointer to the file from where to read values
    FILE *fileToRead = fopen("data.csv", "r");  

    //Initialise pointer to the file to write answers
    FILE *fileToWrite = fopen("ans.csv", "w"); 
    
    if(fileToRead==NULL){  

        //Check if the read file is present or not
        printf("Error in reading file or file not found!");

        
    } else {

        //Initialise pointer that will store all characters of a single line from the reading file
        char *line = NULL;

        //Initialise integral type variable to store size of 'line' in bytes
        size_t len = 0;

        while(getline(&line, &len, fileToRead)>=0){ 
            
            //Check if we have not reached end of file and move to the next line in each iteration of the loop
            
            //Now, process a single line stored in the form of character in 'line' variable

            //Initialise total sum of one data set = 0
            double sum = 0;

            //Initialise total inverse sum of one data set = 0
            double inverseSum = 0;

            //Initialise total product sum of one data set = 1
            double product = 1;  

            //Variable to keep whether all values are non-zero or not                      
            bool areAllNonZero = true;            

            //Initialise number of values in one data set in the single line
            int N = 0;

            //Pointer to store the characters comming from one single line
            char *charPointer;            

            //Intialise it to all characters till the first comma (,) 
            charPointer = strtok(line, ",");
            //Hence, 'charPointer' now stores the characters of the first value of the line in the single data set

            while(charPointer!=NULL){               

                //Check if the 'charPointer' does not become NULL, if it becomes then break the loop, otherwise extract the value one by one in loop

                //Pointer to store extra characters then data value while extracting a the data value from 'charPointer' which stores the data value in the form of characters
                //Anyway we won't be using this pointer                
                char *useless;

                //Extracting the data value from 'charPointer' that has value in the form of character or character+newline(\n) when 'charPointer' reaches at the last data value of the single line
                double dataValue = strtod(charPointer, &useless);                  

                //Adding this value to total sum
                sum = sum + dataValue;

                
                if(dataValue != 0.0) {

                    //If the dataValue is non-zero then add it to the inverseSum by reciprocating it
                    inverseSum = inverseSum + (1.0/dataValue);

                } else {

                    //Since, this dataValue is zero, hence there is atleast one value which is zero, therefore setting 'areAllNonZero' to false
                    areAllNonZero = false;

                }

                //Multiplying the dataValue to the total product
                product = product * dataValue;
                
                //Increasing the number of values by one
                N++;
                
                //Advancing the 'charPointer' to store the next data value in the form of character till the next comma(,)
                charPointer = strtok(NULL, ",");

            }          

            if(N>0){

                //Check if N > 0 i.e. number of values must be > 0 to calculate Arithmatic Mean

                //Initialise variables to store answers of AM, GM and HM
                double AM;
                double GM;
                double HM;

                //Formula for AM
                AM = sum/N;  

                if(product <= 0 && N > 1){

                    //If the total product is negetive or zero and N > 1 then GM is not defined, hence setting it to zero 
                    GM = 0;

                } else {

                    //Calculating GM if exists
                    GM = pow(product, 1.0/N);

                }

                if(areAllNonZero){

                    //HM exists only if all of the values are non-zero
                    HM = N/inverseSum;

                } else {

                    //If there exists atleast one value that is zero, then HM is not defined, hence setting it to zero
                    HM = 0;
                }

                //Writing comma separated final values of AM, GM, and HM in the read file with a new line                                
                fprintf(fileToWrite,"%f,%f,%f\n", AM, GM, HM);
            }                                              
        }        
    }

    //Close the file to read
    fclose(fileToRead);   

    //Close the file to write
    fclose(fileToWrite);

    return 0;
}