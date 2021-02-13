#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int P=1;
int E=0;
int H=0;
int D=1;
string W;
string Check;
string Allele1;
string Allele2;

int main(int argc, char** argv)
{
  ifstream fin("indiv1.fa");
  if (!fin) cout<<" you done goofed!  ";

  ofstream fout("indiv1_PH.fa");

  getline(fin,W);
  H=W.size();
  getline(fin,W);
  while (W.size()==80)
  {
    P+=1;
    getline(fin,W);
    Check=W.substr(0,1);
  }
  E=W.size();

  fin.clear();
  fin.seekg(0,fin.beg);

  getline(fin,W);
  fout<<W<<" PseudoHap\n";

  getline(fin,Allele1);
  for (int i=0;i<P;i++)
  {
    D+=1;
    for (int i=0;i<P;i++)
    {
      getline(fin,W);
    }
    getline(fin,Allele2);
cout<<Allele1<<endl;
cout<<Allele2<<endl;
    srand(time(0));
    for (int i=0;i<Allele1.size();i++)
    {
      if (rand()%2==0)
      {
        fout<<Allele1[i];
      }
      else
      {
         fout<<Allele2[i];
       }
    }
    fout<<'\n';

    fin.clear();
    fin.seekg(0,fin.beg);
    // fin.read(B,2);
    for (int i=0;i<D;i++)
    {
      getline(fin,W);
   }
    getline(fin,Allele1);

  }

  fin.close();
  fout.close();

  system ("PAUSE");
  return EXIT_SUCCESS;
}
