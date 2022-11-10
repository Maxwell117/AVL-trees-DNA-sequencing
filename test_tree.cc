//Maxwell Large 335
//this is basically a frontend/driver prorgram, just calling other classes
#include "avl_tree_p2b.h"
#include "sequence_map.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

namespace 
{

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree)
{
/////////////////////////////////  STEP 1
//QueryTree()
//same logic as query tree
  std::ifstream infile;
  infile.open(db_filename);
  string ignore;
  string line;
  
  for(int i=0;i<10;i++)//skip generic/useless data stamps
  {
  getline(infile,ignore);
  }
  
  
  while(getline(infile,line))
  {
    stringstream linestream;
    linestream.str(line);   //returns a string http://www.cplusplus.com/reference/sstream/stringstream/str/
    string acro;//acronym
    
    getline(linestream,acro,'/'); //get data to the left
    string recog;//get 1,2 sequences
    
    while(getline(linestream,recog,'/'))//get rightmost data
    {
    SequenceMap sequence3(recog,acro);
    a_tree.insert(sequence3);//add like query tree
    }
  }      //gradescope wont take endl
////////////////////////////////////////////////////////////////   STEP 2  
cout<<"2: "<<a_tree.NumOfNodes()<<"\n";
////////////////////////////////////////////////////////////////   STEP 3
//float internalpath=InternalPathLength(a_tree,0);   
//int n=PrintNumOfNodes(a_tree);       
//float averagedepth=internalpath/n;  

cout<<"3a: "<<a_tree.AverageDepth()<<"\n";      
cout<<"3b: "<<a_tree.AverageDepthLog2()<<"\n";       
/////////////////////////////////////////////////////////////////  STEP 4
  int successful_find=0;
  ifstream recog_file(seq_filename);//read in recognition file
  string lines;
  
  
  while(getline(recog_file,lines))
  {
    SequenceMap dummy(lines,"");
    if((dummy==a_tree.find(dummy)))//valid bc == overload
    {    
    successful_find++;    
    }
  }
  cout<<"4a: "<<successful_find<<endl;                           //endl trrying to make gradescope happy with format
  cout<<"4b: "<<float(a_tree.GetRecursiveCalls()/successful_find)<<"\n";//cast answer inyo a float to make gradescope happy

/////////////////////////////////////////////////////////////////  STEP 5
  
  string ignore2; //dont want to get mixed up from ignore from earlier part
  a_tree.ResetRecursive();//incase its not 0, might not be needed
  
  ifstream file2(seq_filename);
  string lines2="";//probably not needed but gradescope says its not working when it is
  
    int remove_count=0;

    while(getline(file2,lines2))
    {
      SequenceMap dummy2(lines2,"");

      if(a_tree.contains(dummy2))
      {
      a_tree.remove(dummy2);
      remove_count++;//keep track like before but removes rather than adds
      }
      getline(file2,ignore);//we dont care about others 
    }
    cout<<"5a: "<<remove_count<<"\n";
    cout<<"5b: "<<float(a_tree.GetRecursiveCalls()/remove_count)<<"\n";//get removes like before
/////////////////////////////////////////////////////////////////  STEP 6
//just call older functions

cout << "6a: " << a_tree.NumOfNodes()<<endl;
cout << "6b: " << a_tree.AverageDepth()<<endl;
cout << "6c: " << a_tree.AverageDepthLog2()<<endl;

}//forgot this brace 
}// end namespace
////////////////////////////////////////////////////////////////////////
                  //touch below and gradescope will get mad

      // int main(int argc, char **argv) 
//       {
//         if (argc != 3)
//         {
//          cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
//           return 0;
//         }
//         const string db_filename(argv[1]);
//       const string seq_filename(argv[2]);
//      cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
//       // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
//        AvlTree<SequenceMap> a_tree;  
//        TestTree(db_filename, seq_filename, a_tree);
//     
//         return 0;
//       }