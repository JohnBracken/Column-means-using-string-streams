/*The following code loads a .csv data file into a 2D string vector.
A vector is like an array but you can change it's size.  For this
code, the input/output stream library is needed to show output.
The fstream library is required to load a .csv file into memory.
The string library is required to manipulate strings in the data file.
The vector library is needed to generate the 2D vector to store the
loaded data.  The stringstream library is needed to convert each
line in the data file into a stringstream that can be further parsed
into individual columns from the data file.  Later on, some code
is shown to calculate the mean value for a column, if it contains
numbers that can be averaged.  Again, stringstream is need to
convert the string value of the number into an integer number for
each cell in the column to do this.  */

//Load needed libraries.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

//Use the standard namespace.
using namespace std;

//Main function.
int main(){

    //Load the csv file into a dataset.  In this case, the data file
    //contains 436 rows and 110 columns.
    ifstream dataset("SAVED_FINAL.csv");

    //Define a 2D vector array to contain all the data from the .csv data
    //file.  Set it up to have the same dimensions as the data file.
    //For this to work as a 2d array, a string vector has be declared
    //within another vector template.  Vector sizes can be changed,
    //unlike arrays, which must be declared with a specific size.
    vector < vector<string> > data_array;

    // Clear vector before initializing it.  This will clear the array
    //everytime the code is run.
    data_array.clear();

    //Can now fill the vector array with data from the csv file.
    while (!dataset.eof())
    {

        //The outer for loop will look for data row by row.
        for (int row_val = 0; row_val < 436; ++row_val)
        {
            //Create a string vector called row to store the current row from the
            //dataset.  This will later be parsed into the into the individual
            //cells in the row from the csv file.
            vector<string> row;

            //Create a string to store the current line (or row) in the csv file.
            string current_line;

            //Get the current row from the dataset and store it in the string 'line'.
            getline(dataset, current_line);

            //If you can't find a file dataset or there is something wrong with it, then
            //break from the program.
            if (!dataset.good())
                break;

            //Create a stringstream object from the current row that was obtained.
            //This stringstream row can then be parsed into individual cells from
            //the spreadsheet .csv file so that each cell can be put into the vector
            //array.  String stream is a library to convert between strings and
            //other data types.  The >> and << operators can be used to output and
            //input different datatypes, just like any other stream.
            //Create a stringstream to store the current line(full row) that was just obtained,
            //as a string object.
            stringstream iss_line;
            iss_line << current_line;

            //For the current row use this for loop to look at each column individually.
            for (int col = 0; col < 110; ++col)
            {
                //Create a string to contain the string value in an individual cell from
                //the dataset.
                string cell;

                //Get the current value of the cell (current column for the current row)
                //and store it in cell. A delimiter character is need to get the cell string
                //value for the current row.  In this case, the delimiter is a comma since
                //we are extracting data from a .csv file.
                getline(iss_line, cell, ',');

                //If you cant find a line or there is something wrong with it,
                //then break from the program.
                if (!iss_line.good())
                    break;

                //Insert the current value of the cell at the end of the row vector
                //and increase the size of this vector by one.
                row.push_back(cell);
            }


            // In the outer loop, push this filled out row into the end of
            //the data array vector and increment the data_array vector size by one.
            //In this case you are adding one vector row to the 2D vector data array.
            data_array.push_back(row);
        }

    }

//This code segment will sum the values in a given column,
//assuming it has numbers that can be added.

//Running tally of sum in the column.  Initialize to zero.
int colsum = 0;

//Loop to add each value in the 3rd column to the total column sum.
for(int j=1;j < 436;++j){
stringstream int_val;  //create a stringstream to store the current column value.
int add_int=0;  //Create an integer to store current column value.
int_val << data_array[j][3];  //Stream the sting value of current column cell.


//Send the string stream cell value into an integer.
//This converts the string cell value into an integer value.
int_val >> add_int;

//Add the current integer cell value to the total column sum.
colsum += add_int;
}

//Calculate the average value of the column.
//Must cast the column sum as a float first.
float mean_col;
mean_col = (float)colsum/435;

//Print out the average value of the column.
cout << mean_col << endl;


//Clear and close the data file.
dataset.clear();
dataset.close();

return(0);
}
