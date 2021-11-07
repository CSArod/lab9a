/*Name: Alejandro Rodriquez,2001889172,Lab9A
*Description: File input into a single dimension array
*Input: filename
*Output: file contents in an array forwards and backwards
*and calculates the average/max/min/sum.
*///include proper header files
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
//function prototypes
bool checkFile(const std::string &filename);
double arraySums(double arry[], int arrySize);
void outputArray(double arry[], double arrySize);
std::string getUserInput(std::string& prompt,std::string& userInput);
//
//max size of input array
const int SIZE = 100;
//global variables
double sum = 0.00;
double maxVal = -1;
double minVal = INT32_MAX;
double nums[SIZE];
int input = 0;
//
int main(){
    //local variable initialization 
    std::ifstream inputFile;
    std::string userInput;
    std::string buff;
    //
    // prompt user for a filename
    std::string prompt = "Enter a file name\n**";
    //   
    //use fuction to promt user for input and check its vaild
    std::string validInput = getUserInput(prompt,userInput);
        
            //open file check by function
            inputFile.open(validInput);
            
            // now read file until end of file
        while(std::getline(inputFile, buff))
        {
            std::stringstream iss(buff);

            double count = 0;
            if(!(iss >> count))
            {
            //will continue if error in file
            std::cout << "Error: Invalid input in file. "<< "\n";
            }
            else
            {  //sets decimal after point to correct values
            std::cout << std::setprecision(2) << std::fixed; 
               //a valid numbers
            nums[input++] = count;
            }     
        }//print count of elemets in array
        std::cout<< "\nAmount of Elements Read In: "<< input;
        std::cout<<std::endl;

            //call function to print array
            outputArray(nums,input);
            //call sums function and save into a variable
            double arrayAve = arraySums(nums, input);

            //table output containing array calculations
            std::cout << "Minimum: " << minVal << "\n";
            std::cout << "Maximum: " << maxVal << "\n";
            std::cout << "Sum: " << sum << "\n";
            std::cout << "Average: "  
            <<arrayAve/input << "\n";
        
        inputFile.close();
 
    return 0;
} /*****FUNCTIONS******/// end of main function//
//will checkfile is in directory
bool checkFile(const std::string& fileName)
{   
    std::ifstream file(fileName.c_str());
    if(file){
        return true;
    }
        return 0;
}
//function will get user input and check for validity
std::string getUserInput(std::string& prompt,std::string& userInput){ 
    do{
        std::cout<<prompt;
        std::cin>>userInput;
        std::cout<<std::endl;

        if(!checkFile(userInput)){
        std::cout<< "ERROR: Invalid file name." <<std::endl;
        }
    }while(!checkFile(userInput));
        return userInput;
}
//function will get the average of array
double arraySums(double arry[], int arraySize){
    for(int i=0; i < arraySize; i++)
    {
        sum += arry[i];

        if(maxVal < arry[i])
        {
            maxVal = arry[i];
        }
        if(minVal > arry[i])
        {
            minVal = arry[i];
        }
    }
    return sum;
}
//a function that will output both arrays
void outputArray(double arry[], double arraySize){
    std::cout << "Forwards: "; //output forward
    for(int i=0; i< arraySize; i++){
        if(i >= arraySize -1){
            std::cout << arry[i] << " ";
        }
        else
        {
        std::cout <<arry[i] << ", ";
        }
    }
    std::cout << "\n";
    std::cout << "Backwards: "; //output backwards
    for(int i=arraySize-1; i>= 0; i--){
        if(i > 0){
        std::cout << arry[i] << ", ";
        }
        else{
        std::cout << arry[i] << " ";
        }
    }
    std::cout << "\n";
}
