/* This program pseudo phases haplotypes in a fasta file.
 *
 * Program written by LyAndra Lujan on 20.1.21 during a rotation in the Ting lab.
 */

 #include <iomanip>
 #include <fstream>
 #include <iostream>
 #include <string>
 #include <cstdlib>
 #include <ctime>

 using namespace std;

int N;
int P;
string W;
string Seq;
string Check;
string Allele1;
string Allele2;
string RandAllele;
string InFile;
string Outfile;

int main(int argc, char** argv)
{
  ifstream fin("test.fasta");
    if (!fin) cout<<" You done goofed!  ";

  ofstream fout("test.PH.fasta");

  getline(fin,W);
  fout<<W<<" PseudoHap\n";

// Pull out line by line appending each line to the same string. making sure it doesn't have <
  getline(fin,W);
  Check=W.substr(0,1);
  while (Check!=">")
  {
    Allele1.append(W);
    getline(fin,W);
    Check=W.substr(0,1);
  }
// If it has a < skip it but start putting lines in new string.
  getline(fin,W);
  Check=W.substr(0,1);
  while(Check=="A"||Check=="T"||Check=="C"||Check=="G")
  {
    Allele2.append(W);
    getline(fin,W);
    Check=W.substr(0,1);
  }

// Randomly pick which string is recalled at each loci.
  srand(time(0));
  for (int i=0;i<Allele1.size();i++)
  {
    if (rand()%2==0)
    {
      fout<<Allele1[i];
      if(i%80==79)
      {
        fout<<"\n";
      }
    }
    else
    {
      fout<<Allele2[i];
      if(i%80==79)
      {
        fout<<"\n";
      }
    }
  }
fin.close();
fout.close();

system ("PAUSE");
return EXIT_SUCCESS;
}
