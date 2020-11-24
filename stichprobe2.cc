// fstream and iostream for reading "daten.txt" and writing 
// the sums in "datensumme.txt" and results to the terminal.
// cmath for the sqrt-function
#include <fstream>
#include <iostream>
#include <cmath>
// vector to store nine consecutive values
#include <vector>

// Main entry point
int main()
{
  /*
  EXERCISE 1 a) and 2 a)
  */
  // Variables we will need later
  double mean;
  int NTot = 0;
  std::vector<double> blockMeans, blockVariances;
  {
    // Open our data set and create 
    // the file for the resulting sums
    std::ifstream datensumme("datensumme.txt");

    // Make space for the read-in value on the stack
    int x;
    double sum = 0.; // Take double, better when do divide.

    size_t const BLOCK_SIZE = 9;
    std::vector<int> blockValues;


    while (!datensumme.eof())
    { // Loop over all the values in datensumme
      datensumme >> x;
      
      if (datensumme.fail())
      { // If there is an error (like an empty line), skip!
        continue;
      }

      blockValues.push_back(x);

      if (blockValues.size() == BLOCK_SIZE)
      { // We have nine values in blockValues! 
        // Store a mean and a variance!
        double blockMean = 0.;
        for (auto bv: blockValues)
        {
          blockMean += bv;
        }
        blockMean /= BLOCK_SIZE;

        double blockVariance = 0.;
        for (auto bv: blockValues)
        {
          blockVariance += (bv- blockMean) * (bv- blockMean);
        }
        blockVariance /= BLOCK_SIZE;

        blockMeans.push_back(blockMean);
        blockVariances.push_back(blockVariance);

        // Restore blockValues
        blockValues = std::vector<int>();
      }

      sum += x;

      NTot++; // This should add to 234 ai for normalisation.
    }
    mean = sum / NTot;
    
    std::cout << "Sum: " << sum 
      << "; NTot: "<< NTot 
      << "; Mean: " << mean << std::endl;
    std::cout << "blockVariances size: " << blockVariances.size()
      << "; blockMeans size: " << blockMeans.size() << std::endl;

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

  // Finally, store the blockMeans and blockVariances.
  // Meanwhile, also compute their means.
  size_t BLOCK_COUNT = blockMeans.size();
  double meanMeans = 0., meanVariances = 0.;
  std::ofstream mittelwerte("mittelwerte.txt");
  std::ofstream varianzen("varianzen.txt");

  for (size_t i = 0; i < BLOCK_COUNT; i++)
  {
    mittelwerte << blockMeans[i] << std::endl;
    varianzen << blockVariances[i] << std::endl;

    meanMeans += blockMeans[i];
    meanVariances += blockVariances[i];
  }
  meanMeans /= BLOCK_COUNT;
  meanVariances /= BLOCK_COUNT;

  std::cout << "meanMeans: " << meanMeans
    << ";\nmeanVariances: " << meanVariances
    << "; with Bessel: " << meanVariances * ((double)NTot / ((double)NTot - 1))
    << std::endl;

  // Ciao
  mittelwerte.close();
  varianzen.close();
  return 0;
}
