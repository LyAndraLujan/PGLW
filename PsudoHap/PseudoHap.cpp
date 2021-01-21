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

int P;
string W;
string Check;
string Allele1;
string Allele2;
string RandAllele;
string InFile;

int main(int argc, char** argv)
{

cout<<" This program takes a fasta file with unhaplotyped sequences and randomly assigns haplotypes.  "<<endl;
cout<<" Input file: ";
  cin>>InFile;
ifstream fin(InFile);
  if (!fin) cout<<" You done goofed!  ";

ofstream fout("FakeHap.fasta");

//copy for each sequence in the file
cout<<" How many pairs of sequences are in the file?  ";
  cin>>P;

for(int i=0;i<P;i++)
{
cout<<" Working on pair "<<i<<" of "<<P<<endl;
//pull out first line and use it for new file header
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
}
cout<<" \n The out file will be FakeHap.fasta. "<<endl;
system ("PAUSE");
return EXIT_SUCCESS;
}
