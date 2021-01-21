/* This program pulls out the "header line" plus the meta line above it and the first 3 SNPs
 of VCF files and puts them into a text file for viewing.

Written by LyAndra Lujan on 10/29/20 during work in the Singh lab on the HORMA
domain protien project, it's first use was for C. elegans population genetics.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int M=0;
char InFile [80];
string W;

int main(int argc, char** argv)
{

cout<<"   This program pulls out the header line of VCF files for viewing in excel. " <<endl;
cout<<"   The outfile is HeaderLine.txt. " <<endl;

cout<<"  In file:  ";
	cin>>InFile;

ofstream fout("Just_a_Peak.txt");

ifstream fin(InFile);
if (!fin) cout<<"You biffed it!	"<<InFile<<" not in directory         "<<endl;

cout<<"   Number of meta lines in vcf"<<endl;
	cin>>M;


//Throw out meta data
	for(int i=0;i<M-1;i++)
	{   getline (fin,W);}

//Create file with header, plus one line before it and three lines below.
	for(int i=0;i<5;i++)
	{		getline (fin,W);
			fout<<W<<endl;
	}

fout.close();
fin.close();

system ("PAUSE");
return EXIT_SUCCESS;
}
