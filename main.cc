//Brendan Burke
//ECE 2620
//Lab 4
#include<fstream> //header file required for opening file streams
#include <iostream>
//NULL already defined as 0
using namespace std;

/*findmax function accepts five values as input (any type) and returns the
 * largest of the five (same type)*/
template<typename T>
T findmax(T x1,T x2,T x3, T x4, T x5){
	T max=0;
	if(max<=x1){
		max=x1;}
	if(max<=x2){
		max=x2;}
	if(max<=x3){
		max=x3;}
	if(max<=x4){
		max=x4;}
	if(max<=x5){
		max=x5;}
	return max;
}

int main()
{

ifstream infile; //use provided class to create stream object for reading
ofstream outfile; //use provided class to create stream object for writing

infile.open("lab4_input.txt");
int n,x,count; //declare int variables
int large,x1,x2,x3,x4,x5; /*declare variables; if want to handle input file with
		* data type besides int, change the types of these vars to correspond*/

while(!infile.eof()) /*goes until end of input file, counting the total number
		* number of data items*/
{
	infile >> x;
	count++;
}
infile.close();
n=count/5; //5 items per line, so dividing count by 5 gives # of lines, n

//(original procedure to obtain n commented out:)
//cout << "How many lines, n, are in the input file?" << endl;
//cin >> n; //user inputs number of lines of input file, n

infile.open("lab4_input.txt");
outfile.open("lab4_output.txt");
int *p=new int[n]; //dynamically allocated array

if (infile.is_open()) //checks if file is really open
  {
    cout << "File successfully opened";
  }
else
  {
    cout << "Error opening file";
  }
if(p!=NULL){
	for(int i=0;i<n;++i){
		infile >> x1 >> x2 >> x3 >> x4 >> x5; //read from file
		large = findmax(x1,x2,x3,x4,x5);
		*(p+i)=large;//stores largest # of line as first element of array
		outfile << *(p+i) << " " << endl;}} //write to file
else{
	cout << "Memory space not allocated by OS" << endl;}

delete[] p;//deletes dynamically created array
infile.close();
outfile.close();
	return 0;
}

