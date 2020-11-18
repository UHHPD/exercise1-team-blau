// fstream for reading "daten.txt" and writing 
// the sums in "datensumme.txt"
#include <fstream>

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

  while (!fin.eof())
  { // Loop over all the values in fin
    // Collect the in pairs
    fin >> a;
    fin >> b;

    // Write the resulting sum into fout
    fout << a + b << std::endl;
  }

  // Clean up
  fin.close();
  fout.close();

  // Ciao
  return 0;
}