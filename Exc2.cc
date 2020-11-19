// fstream and iostream for reading "daten.txt" and writing 
// the sums in "datensumme.txt" and results to the terminal
#include <fstream>
#include <iostream>

#include <cmath>

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

    if (fin.fail())
    {
      break;
    }

    sum+=a;
    sum+=b;//add up everything    
    NTot++;//this should add to 234 ai for normalisation.

    //cout << "a: "<< a << ", b: " << b << endl;

    // Write the resulting sum into fout
    fout << a + b << std::endl;
  }

  double mean=sum/NTot;
  
  cout << "Sum: " << sum << "; ntot: "<<NTot<<" mean "<<mean<<std::endl;

  // Clean up
  fin.close();
  fout.close();

  // Open daten
  std::ifstream datensumme("datensumme.txt");
  double var = 0.f;
  while (!datensumme.eof())
  {
    double val;
    datensumme >> val;

    if (datensumme.fail())
    {
      break;
    }

    var += (val - mean) * (val - mean);
  }
  var /= NTot;
  cout << "Var: " << var << endl;
  double sigma = sqrt(var);
  cout << "sigma: " << sigma << endl;

  datensumme.close();

  // Exercise 2
  ifstream a("datensumme.txt");
  ifstream b("datensumme.txt");

  size_t counter = 0;
  


  // Ciao
  return 0;
}
