// fstream for reading "daten.txt" and writing 
// the sums in "datensumme.txt"
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>


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

  vector<double> means;
  double meannine=0;
  int nineintervals=0;
  
  while (!fin.eof())
  { // Loop over all the values in fin
    // Collect the in pairs
    fin >> a;
    fin >> b;

    if (fin.fail()){
      cout<<"BINGO"<<endl;
      break;
    }

    sum+=a;
    sum+=b;
    NTot++;//this should add to 234 ai for normalisation.

    meannine+=a;
    meannine+=b;
    nineintervals++;
    if(nineintervals==9){
      nineintervals=0;
      means.push_back(meannine/9.);
      meannine=0;
    }

    // Write the resulting sum into fout
    fout << a + b << std::endl;
  }
  
  // Clean up
  fin.close();
  fout.close();

  double meansnine=0;
  for (auto m: means){
    //cout<<"means "<< m<<endl;
    meansnine+=m;
  }
  meansnine/=26;
  cout<<"meansnine "<<meansnine<<endl;
  double mean=sum/NTot;
  cout<<"sum "<<sum<<" ntot "<<NTot<<" mean "<<mean<<std::endl;


  std::ifstream fins("datensumme.txt");
  double variance=0;

  vector<double> variances;
  double varsine=0;
  nineintervals=0;

  
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

    nineintervals++;
    varsine+=(a-mean)*(a-mean);
    if(nineintervals==9){
      nineintervals=0;
      variances.push_back(varsine/9.);
      varsine=0;
    }
    
  }

  double meaninevariance=0;
  for (auto m: variances){
    // cout<<"variances "<< m<<endl;
    meaninevariance+=m;
  }
  meaninevariance/=26;
  cout<<"meaninevariance "<< meaninevariance<<endl;
  variance/=NTot;
  cout<<"ctrsumme "<<ctrsumme<<endl;
  cout<<"variance "<< variance<<endl;
  // Clean up
  fins.close();

  cout<<"std dev "<< sqrt(variance)<<endl;


  

  
  // Ciao
  return 0;
}
