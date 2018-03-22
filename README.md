The following code loads a .csv data file into a 2D string vector.
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
each cell in the column to do this.