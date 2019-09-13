/*
1. fillArray(): this function needs to take input from user keyboard to fill in the arrays, and when taking input make sure only postive integers are accepted.

2. showArray(): this function needs to display the elements of the array in multuple lines (every 5 elements, print a new line, split every element with a comma except the last element),
e.g. an array {1,2,3,4,5,6,7,8,9} should print as: 1,2,3,4,5
                                                   6,7,8,9
 
3. largestElement(): this function can display the largest element of the array and its last occurance index(subscript) in the array.
 e.g. an array {4,3,1,2,4} should print: largest element is 4 and its last occurance is at subscipt 4.
 
4. equalArrays(): check whether two arrays have exactly the same elements (which means, same number of elements and also every element is also the same), and return bool value.
 
p.s. All functions above should have at least one array as parameter. Think about the parameter list for each function before you start it.

5. void getInput(int&): the function needs to be called inside function fillArray(), to get input and validate each input from user, and only positive number will be accepted.
*/


#include <iostream>
#include <cctype>
using namespace std;

// Function prototypes
void fillArray(int *, int);
void showArray(const int *, int);
void largestElement(int *, int);
bool equalArrays(int *, int, int *, int);
void getInput(int *);
int getSize(); //funtion to help get sizes for arrays.

//not possible, because array parameters are actually treated as a pointer parameter, so range-based for loop will not work
//void fillArray(int[]); //use range-based for loop
//void showArray(const int[]); //use range-based for loop
//void largestElement(int[]);//use range-based for loop
//bool equalArrays(int[], int[]);//use range-based for loop?



int main()
{
    //int SIZE1 = getSize(); //don't use this as size declarator,
    //int SIZE2 = getSize();
    //instead use named constant or interger literals as size declarator,
    //chaging SIZE1 and SIZE2 to play with different samples
    const int SIZE1 = 3;
    const int SIZE2 = 6;
    //define two arrays with two sizes
	int array1[SIZE1];
    int array2[SIZE2];
    //call function fillArray() over array1, then fill in array1
    fillArray(array1, SIZE1);
    cout << endl;
    //call function fillArray() over array2, then fill in array1
    fillArray(array2, SIZE2);
    cout << endl;
    //call function showArray() over array1
    cout << "The array is: \n";
    showArray(array1, SIZE1);
    //call function largestElement() over array1
    largestElement(array1, SIZE1);
    //call equalArrays() over array1 and array2,
    //if they share exactly the same elements, print "These two arrays are identical",
    //if not, print "These two arrays are not identical" and use showArray() to display the elements in array1 and array2 seperately
    if(equalArrays(array1, SIZE1, array2, SIZE2))
    {
        cout << "These two arrays are identical.\n";
    }
    else
    {
        cout << "These two arrays are not identical\n";
        cout << "The first one is: \n";
        showArray(array1, SIZE1);
        cout << endl;
        cout << "The second one is: \n";
        showArray(array2, SIZE2);
    }
    
	return 0;
}


int getSize()
{
    static int count = 0;
    cout << "Get array size for the " << ++count << "-th array."<<endl;
    int size=0;
    while(size <= 0)
    {
        cout << "Please input a postive integer for the size of the array: " << endl;
        cin >> size;
    }
    return size;
}

void getInput(int *num)
{
    //if input number is <= 0, keep asking user to input a new postive integer which goes into local variable num
    do {
        cout << "Please input a positive integer: ";
        cin >> *num;
    } while (*num <= 0);  //don't try characters input, put cin into fail status (inifinite loop)
}


void fillArray(int *array, int size)
{
    static int count = 0;//static local variable, used to count how many this function has been called
    cout << "Let's fill in the "<< ++count << "-th " << "integer array of size "<< size << endl;
    //increment variable count, and output proper message
    for(int i = 0; i < size; i++)
        //loop used to go over all the individual elements of the array
    {
        cout << i+1 << "-th element!" << endl;
        getInput(array+i);   //individual elements of an array can be treated as normal variable
    }
}


void showArray(const int *array1, int size)
{
    for(int i = 0; i < size; i++)
        //loop used to go over all the individual elements of the array
    {
        cout << *(array1 + i);//first output individual element in each iteration
        //depending on current element's index/subscript, choose what should be the following sign, in this case ,/newline/blank
        if((i+1)%5 == 0)//if subscript+1 is divisible by 5, that is every 5 element, print newline
        {
            cout << endl;
        }
        else //otherwise
        {
            if(i == size-1) //reach the last element (with subscript size-1, 0-based subscript, print blank)
            {
                cout <<"";
            }
            else //otherwise, print ,
            {
                cout << ",";
            }
        }
    }
}

void largestElement(int *array1, int size)
{
    int max_subscript = 0; //variable to store current maximum value's subscript, initially 0 (first element)
    int *ptr = &max_subscript;
    int max_counter = 1; //variable to store the occurance times of maximum value, start with 1
    for(int i = 1; i < size; i++)
        //loop to go over all individual elements in the array
    {
        if(*(array1 + i) > *ptr)
            //if current element is bigger than current maximum value, then update
        {
            *ptr = i; //asssign current element's subsript to current maximum value's subscript
            max_counter = 1;//reassign 1 to the occurance times of current maximum value, since now we have a new maximum value
        }
        else if(*(array1 + i) == *ptr)
            //if current element is equal than current maximum value, then update

        {
            *ptr = i;//since we want to know the last occurance, we still need to update the maximum value's subscript to current value's subscript (which is bigger than max_subscript)
            max_counter += 1; //add 1 to occurance times of current maximum value
        }
    }
    cout << "\nLargest element is " << *(array1 + *ptr) << " and its last occurance is at subscipt " << *ptr << endl;
    //cout << "it occured " << max_counter << " times." <<endl //used to show how many times the maximum value appears in the array
}

bool equalArrays(int *array1, int size1, int *array2, int size2)
{
    if(size1 != size2)
        //if sizes are not equal, arrays are not possible to equal/same, return false immediately
    {
        return false;
    }
    else //otherwise, they are of the same size
    {
        for(int i=0; i < size1; i++)
            //loop to go over all the elements in both arrays, since they are of the same size, we can use a shared subscipt to access individual elements from the two arrays (of the same subscript)
        {
            //if we run into two elements (of the same subscript) that are not equal, we know these two arrays are not equal, then return false immediately
            if(*(array1 + i) != *(array2 + i))
                return false;
        }
        return true;//if all elements are equal, return true by defaule
    }
}

