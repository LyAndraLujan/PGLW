#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int M=0;
int L=0;
int S=0;
char Reorder [1];
char InFile [80];
char Outfile [80];
string W;
string C;
string S1;


int main(int argc, char** argv)
{

cout<<"   This program reformats VCF files into LyAndra Lujan's preferred format for working with them. " <<endl;
cout<<"   Are you reordering samples based on populations?  [Y or N]" <<endl;
cin>>Reorder;

if(Reorder=="Y")
{ cout<<"   SNP data is simplified to alleles only, and then samples are reordered into population groups. " <<endl;
  cout<<"   A SamplesPop.txt file is necessary to reorder samples. "<<endl;
  cout<<"   SamplesPop.txt should have samples and populations in the preferred order. "<<endl;
  cout<<"   Start any lists with intigers with 0 not 1. " <<endl;
  cout<<"   file should have no header but be formated as: "<<endl;
  cout<<endl;
  cout<<"   OutOrder(should be in order) [tab] Population name [tab] Population number [tab] SampleID [tab] Original order [endl]" <<endl;
}
cout<<endl;

cout<<"  In file:  ";
	cin>>InFile;

ofstream fout("Simplified.txt");

ifstream fin(InFile);
if (!fin) cout<<InFile<<" not in directory         ";

cout<<"   Number of meta lines in "<<InFile<<" that need to be removed:   ";
	cin>>M;

cout<<"   Number of SNPs in "<<InFile<<":   ";
	cin>>L;

cout<<"   Number of Samples:   ";
	cin>>S;



//Throw out meta lines
	for(int i=0;i<M;i++)
	{   getline (fin,W);}

//remove #from #CHROM and insert column names
	fin>>W;
	C=W.substr(1,5);
	fout<<C<<'\t';
	for (int i=0;i<8;i++)
	{   fin>>W;
		fout<<W<<'\t';
	}
	for (int i=0;i<S;i++)
	{   fin>>W;
		fout<<W<<'\t';
	}
	fout<<endl;


//read in file	and simplify SNP data
	for(int i=0;i<L;i++)
	{
		for(int i=0;i<8;i++)
		{ fin>>W;
			fout<<W<<'\t';
		}
    fin>>W;
    fout<<W;
		for(int i=0;i<S;i++)
		{ fin>>W;
			S1=W.substr(0,3);
			fout<<'\t'<<S1;

		}
	fout<<endl;

	}
	fout.close();
	fin.close();

//reorder samples by population
if(Reorder=="Y")
{
  int R=0;

  cout<<"   Simplified.txt file made from "<<InFile<<"."<<endl;
  cout<<"   Samples will be ordered according to SamplesPop.txt file."<<endl;
  cout<<"   Number of Populations:   ";
	 cin>>R;

 int OutOrd [S];
 int Order [S];
 string Pop [S];
 string PopNum[S];
 string Samples[S];

 ifstream finO("Simplified.txt");

 ifstream finOO("SamplesPop.txt");

 ofstream foutO("Ordered.txt");

//input new order
  for (int i=0;i<S;i++)
	{   finOO>>OutOrd[i];
	    finOO>>Pop[i];
	    finOO>>PopNum[i];
		  finOO>>W;
      finOO>>Order[i];
	}

//creat row with population numbers
	for (int i=0;i<9;i++)
  {foutO<<"x\t";}

	for (int i=0;i<S;i++)
	{foutO<<PopNum[i]<<'\t';}
	foutO<<endl;

//create row with population names
	for (int i=0;i<9;i++)
	{foutO<<"x\t";}

	for (int i=0;i<S;i++)
	{foutO<<Pop[i]<<'\t';}
	foutO<<endl;

//reorder sample names
	for (int i=0;i<1;i++)
	{
		for (int i=0;i<9;i++)
		{   finO>>W;
			foutO<<W<<'\t';
		}

		for (int i=0;i<S;i++)
		{   finO>>Samples[i];}
		for (int i=0;i<S;i++)
		{   foutO<<Samples[Order[i]]<<'\t';}
	foutO<<endl;
	}


//reorder samples genotypes
	for (int i=0;i<L;i++)
	{
		for (int i=0;i<9;i++)
		{   finO>>W;
			foutO<<W<<'\t';
		}

		for (int i=0;i<S;i++)
		{   finO>>Samples[i];}
		for (int i=0;i<S;i++)
		{   foutO<<Samples[Order[i]]<<'\t';}
	foutO<<endl;
	}
  foutO.close();
  finO.close();
  finOO.close();
}

system ("PAUSE");
return EXIT_SUCCESS;
}
