//Maxwell Large 335
#include "avl_tree_p2a.h"
#include "sequence_map.h"
#include <iostream> 
#include <sstream>
#include <string> //needed for getline()/file stuff
//#include <vector> //needed for collecting input
#include <fstream>   //linestream()
using namespace std;

namespace //overcomplicates things
{
    // @db_filename: an input filename.
    // @a_tree: an input tree of the type TreeType. It is assumed to be
    //  empty.
    template <typename TreeType>
    void QueryTree(const string &db_filename, TreeType &a_tree) 
    {
            string db_line;//the line
            //string ignore=" ";//lines we ignore
            
            
            std::ifstream infile;
            infile.open(db_filename);
            
            if(infile.fail())
            {
            cout<<"Can not open the file!";
            infile.close();
            }
            else
            {
   for(int i=0;i<10;i++)//skip generic/useless data stamps
   {
	getline(infile,db_line);
	}
                while(getline(infile,db_line))//while there is stuff to read, put it in line (for each line in file)
                {
                    
		              std::istringstream linestream(db_line);
                    string an_enz_acro; //wanted to call it acro but gradescope is picky
                    
                    getline(linestream,an_enz_acro,'/');//read everything to the first / as the acro
                    string a_reco_seq;
                     
                    while(getline(linestream,a_reco_seq,'/'))
                    {//im prety sure getline returns 0 if it gets nothing, but if not add the next line to the while
			              //teaching_project::SequenceMap sequence=teaching_project::SequenceMap(seq,acro);
                       SequenceMap new_sequence_map(a_reco_seq,an_enz_acro);
                       a_tree.insert(new_sequence_map);//add it to the avl tree, balance() will handle balance
                    }
                }
            }
            //this snippet will stores input in a data to be used to find a correspondance later
            string key;      
            std::vector<string> your_keys;//contain input , dont need std but gradescope is mean
            
       
          //for(int  i=0;i<3;i++)
            while(cin>>key)//user may enter more than 3 
            {
            //cout<<"enter a recognition sequence or enter 'end' to exit"<<endl;
            your_keys.push_back(key);
            }
         
         
            //this will where output will be made , if a correspondancei is found or not
            for(int keyindex=0;keyindex<your_keys.size();keyindex++)
            {
            SequenceMap goal(your_keys[keyindex],"Not Found");
            cout<<a_tree.find(goal)<<endl;//outputs correspondances to user's acro ym
            }//calls find() in avl_tree_p2a.h
            
            
     }//end function
} //end namespace
 

/////////////////DONT touch main or gradescope will bark////////////////////////////////////// 
     
         int main(int argc, char **argv)
         {
          if (argc != 2) {
              cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
             return 0;
    
         }
         const string db_filename(argv[1]);
         cout << "Input filename is " << db_filename << endl;
        // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
        
       
         AvlTree<SequenceMap> a_tree;
          QueryTree(db_filename, a_tree);
     
          return 0;
         }


