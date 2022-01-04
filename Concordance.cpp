//**********************************************************************//
//** Author:Swostik Pati                                              **//
//** Date Created: 12 November, 2021                                  **//
//** Assignment 2: Computer Engineering Case Study –                  **//   
//** Concordance of a Text File                                       **//
//** ENGR-UH-1000 Computer Programming for Engineers, NYUAD           **//
//** Problem:                                                         **//
//** To create a a software that performs information retrieval       **//
//** and determines the “most important concepts” in a text file      **//
//**********************************************************************//

//Importing Required Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//Declaring function prototypes
void openFileInput(string fname, ifstream &obj);
void openFileOutput(string fname, ofstream &obj);
void getext(string &text, ifstream &data);
string *removePunc(string data, string *arrS, int &count);
string *addToList(string element, string *arrS, int count);
void sort(string *arrS, int count);
int countunique(string *arrS, int count);
void concordance(string *arrS, int count, string *arr, int *freq);
void printIntoFile(string *arr, int *freq, ofstream &odata, int ucount);
void printConc(int *freq, string *arr, int ucount);

int main()
{
    //Taking the name of the text file as input from the user
    cout << "Enter the name of the input file" << endl;
    string fname;
    cin >> fname;
    ifstream data;

    //Taking the name of the output file as input from the user
    cout << "Enter the name of the output file" << endl;
    string ofname;
    cin >> ofname;
    ofstream odata;

    //Creating a dynamic array of string datatype
    string *arrS = new string[1];

    //Calling the functions
    openFileInput(fname, data);

    string text = "";
    getext(text, data);

    int count(0);
    arrS = removePunc(text, arrS, count);
    sort(arrS, count);

    int ucount = countunique(arrS, count);

    //Creating dynamic arrays of freq (int datatype) and arr (string datatype)
    int *freq = new int[ucount];
    string *arr = new string[ucount];
    concordance(arrS, count, arr, freq);

    //Deleting dynamic array
    delete[] arrS;

    printConc(freq, arr, ucount);
    openFileOutput(ofname, odata);
    printIntoFile(arr, freq, odata, ucount);

    //Deleting the dynamic arrays
    delete[] freq;
    delete[] arr;

    //Closing the files
    data.close();
    odata.close();

    return 0;
}

void openFileInput(string fname, ifstream &obj)
{
    //Opening file
    obj.open(fname, ios::in);
    if (obj.fail())
    {
        cerr << "Error opening the file" << endl;
        exit(1);
    }
}

void openFileOutput(string fname, ofstream &obj)
{
    //Closing file
    obj.open(fname, ios::out);
    if (obj.fail())
    {
        cerr << "Error opening the file" << endl;
        exit(1);
    }
}

void getext(string &text, ifstream &data)
{
    //Taking text out into a string - all spaces are also removed
    while (!data.eof())
    {
        string a;
        data >> a;
        text += (a + " ");
    }
}

//Function to remove punctuation
string *removePunc(string text, string *arrS, int &count)
{
    //keeping a flag and initiate it
    bool flag = false;
    string word = "";
    int len = text.length();
    for (int i = 0; i < len; i++)
    {
        //storing the ASCII value of the character
        int ntext = int(tolower(text[i]));
        //checking for only lowercase letters
        if (ntext >= 97 && ntext <= 122)
        {
            //concatanating characters to form an word
            word += tolower(text[i]);
            flag = true; //flag is
        }
        else if (!(ntext >= 97 && ntext <= 122) && flag)
        {
            //count of words in the array
            count++;
            //adding words into the dynamic array
            arrS = addToList(word, arrS, count);
            word = "";
            //flag turns false and will only turn true when there is atleast one alphabet
            flag = false;
        }
    }
    return arrS;
}

//Function to add elements into the array
string *addToList(string element, string *arrS, int count)
{
    //If there are no elements in the array, the element is put into the 0th index
    if (count == 1)
    {
        arrS[0] = element;
        return arrS;
    }
    else
    {
        //Declaring a temporary dynamic array
        string *temp = new string[count];
        for (int i = 0; i < count - 1; i++)
        {
            //copying everything from the existing array
            temp[i] = arrS[i];
        }
        //Storing the extra element in the last index of the array
        temp[count - 1] = element;

        //return the address of the new array
        return temp;
    }
}

//sorting the array in alphabetical order
void sort(string *arrS, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            //checking for alphabetical order
            if (arrS[i] > arrS[j])
            {
                //interchanging values
                string temp = arrS[i];
                arrS[i] = arrS[j];
                arrS[j] = temp;
            }
        }
    }
}

//Function to count the number of unique words
int countunique(string *arrS, int count)

{
    int ucount(0); //variable to store the number of unique words
    int i = 0;     //starting a while loop as a for loop
    while (i < count)
    {
        ucount++; //incrementing the count of unique words
        int temp_i = i;
        for (int j = temp_i + 1; j < count; j++)
        {
            if (arrS[i] == arrS[j]) //checking for same words
            {
                i++;
            }
            else
            {
                break; //breaking out of the loop whenever a new unique word is encountered
            }
        }

        i++;
    }
    return ucount;
}

//Function to create the concordance array to store the unique words and their frequency
void concordance(string *arrS, int count, string *arr, int *freq)
{
    int i = 0;
    int c(0); //to keep track of the index of the array where the element needs to be stored
    int f; //to keep track of the frequency of the array

    while (i < count)
    {
        arr[c] = arrS[i]; //storing a unique word in the array
        f = 1;
        int temp_i = i;
        for (int j = temp_i + 1; j < count; j++)
        {
            if (arrS[i] == arrS[j]) //checking for repetitive words
            {
                i++;
                f++; //incrementing frequency 
            }
            else
            {
                freq[c] = f; //storing the frequency in the array
                c++; //incrementing index
                break;
            }
        }
        i++;
    }
    freq[c] = f; //storing the frequency of the last unique word
}

//Function to print concordance list along with the frequency into the file
void printIntoFile(string *arr, int *freq, ofstream &odata, int ucount)
{

    for (int i = 0; i < ucount; i++)
    {
        odata << arr[i] << "\t\t" << freq[i] << endl; //printing the concordance list into the file
    }
    cout << "\nData stored successfully in the file!" << endl;
}

//Function to output the concordance array
void printConc(int *freq, string *arr, int ucount)
{
    cout.setf(ios::left); //setting indentation left
    for (int i = 0; i < ucount; i++) 
    {
        cout << setw(20) << arr[i] << freq[i] << setw(20) << endl; //printing the concordance list in the output screen
    }
}
