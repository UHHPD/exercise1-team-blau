// fstream and iostream for reading "daten.txt" and writing 
// the sums in "datensumme.txt" and results to the terminal
#include <fstream>
#include <iostream>
#include <cmath>

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
      continue;
    }

    sum+=a;
    sum+=b;
    NTot++;//this should add to 234 ai for normalisation.

<<<<<<< HEAD:Exc2.cc
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
  
  double mean=sum/NTot;
  cout<<"sum "<<sum<<" ntot "<<NTot<<" mean "<<mean<<std::endl;


  std::ifstream fins("datensumme.txt");
  double variance=0;

  int ctrsumme;
  while (!fins.eof())
  { // Loop over all the values in fins
    // Collect the in pairs
    fins >> a;
    if (fins.fail()){
      cout<<"BINGO"<<endl;
      break;
    }
    ctrsumme++;
    variance+=(a-mean)*(a-mean);

    // Write the resulting sum into fout
  }

  variance/=NTot;
  cout<<"ctrsumme "<<ctrsumme<<endl;
  cout<<"variance "<< variance<<endl;
  // Clean up
  fins.close();

  cout<<"std dev "<< sqrt(variance)<<endl;


  // Ciao
  return 0;
}
