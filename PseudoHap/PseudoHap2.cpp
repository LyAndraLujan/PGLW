#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int P=1;
int D=1;
int N=0;
string W;
string Seq;
string InFile;
string Outfile;
string Check;
string Allele1;
string Allele2;

int main(int argc, char** argv)
{
  cout<<" This program takes a fasta file with unhaplotyped sequences and randomly assigns haplotypes.  "<<endl;
  cout<<" This version can only run .fasta files with one pair. "<<endl;

  cout<<" How many .fasta files are you running? ";
  cin>>N;

  cout<<" Configuration file should be formatted as:sequence.fasta[tab]outfile[tab]\n";
  cout<<" Configuration file: ";
    cin>> InFile;
  ifstream fin0(InFile);
    if (!fin0) cout<<"  config file not in directory. "<<endl;

  for (int i=0;i<N;i++)
  {
    fin0>>Seq;
    ifstream fin(Seq);
    fin0>>Outfile;
    ofstream fout(Outfile);

    getline(fin,W);
    getline(fin,W);
    while (W.size()==80)
    {
      P+=1;
      getline(fin,W);
      Check=W.substr(0,1);
    }

    fin.clear();
    fin.seekg(0,fin.beg);

    getline(fin,W);
    fout<<">chr1"<<endl;

    getline(fin,Allele1);
    for (int i=0;i<P;i++)
    {
      D+=1;
      for (int i=0;i<P;i++)
      {
        getline(fin,W);
      }
      getline(fin,Allele2);

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

      for (int i=0;i<D;i++)
      {
        getline(fin,W);
      }
      getline(fin,Allele1);
    }

  P=1;
  D=1;
  Check.clear();
  Allele1.clear();
  Allele2.clear();
  fin.close();
  fout.close();
  }

  fin0.close();

  system ("PAUSE");
  return EXIT_SUCCESS;
}
