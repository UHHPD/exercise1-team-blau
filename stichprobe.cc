// fstream and iostream for reading "daten.txt" and writing 
// the sums in "datensumme.txt" and results to the terminal.
// cmath for the sqrt-function
#include <fstream>
#include <iostream>
#include <cmath>

// Main entry point
int main()
{
  /*
  EXERCISE 1 a)
  */
  // Variables we will need later
  double mean;
  int NTot = 0;
  {
    // Open our data set and create 
    // the file for the resulting sums
    std::ifstream datensumme("datensumme.txt");

    // Make space for the read-in value on the stack
    int x;
    double sum = 0.; // Take double, better when do divide.

    
    while (!datensumme.eof())
    { // Loop over all the values in datensumme
      datensumme >> x;
      
      if (datensumme.fail())
      { // If there is an error (like an empty line), skip!
        continue;
      }

      sum += x;

      NTot++; // This should add to 234 ai for normalisation.
    }
    mean = sum / NTot;
    
    std::cout << "Sum: " << sum 
      << "; NTot: "<< NTot 
      << "; Mean: " << mean << std::endl;

    // Close datensumme
    datensumme.close();
  }

  /*
  EXERCISE 1 b) and c)
  */
  {
    // Open datensumme.txt
    std::ifstream datensumme("datensumme.txt");
    double var = 0.f;

    while (!datensumme.eof())
    { // Again, read all values from datensumme
      double val;
      datensumme >> val;

      if (datensumme.fail())
      { // If there is an error (like an empty line), skip!
        continue;
      }

      var += (val - mean) * (val - mean);
    }
    var /= NTot;

    double sigma = std::sqrt(var);

    std::cout << "Var: " << var << "; sigma: " << sigma << std::endl;

    datensumme.close();
  }

  // Ciao
  return 0;
}
