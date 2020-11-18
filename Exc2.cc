// fstream for reading "daten.txt" and writing 
// the sums in "datensumme.txt"
#include <fstream>
#include <iostream>


using namespace std;
// Main entry point
int main()
{
  // Open our data set and create 
  // the file for the resulting sums
  std::ifstream fin("daten.txt");
  std::ofstream fout("datensumme.txt");

  // Declare the variables for the left 
  // and right numbers on the stack
  int a, b;

  int NTot=0;
  double sum=0; //take double, better when do divide.
  
  while (!fin.eof())
  { // Loop over all the values in fin
    // Collect the in pairs
    fin >> a;
    fin >> b;

    sum+=a;
    sum+=b;//add up everything    
    NTot++;//this should add to 234 ai for normalisation.

    cout<<"a "<< a<<"B "<<b<<endl;

    // Write the resulting sum into fout
    // fout << a + b << std::endl;
  }

  double mean=sum/NTot;
  
  cout<<"sum "<<sum<<" ntot "<<NTot<<" mean "<<mean<<std::endl;
  // Clean up
  fin.close();
  fout.close();

  // Ciao
  return 0;
}
