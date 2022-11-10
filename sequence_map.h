#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "dsexceptions.h"
using namespace std; 
//{ namespace teahing project 
class SequenceMap
{
    public:
        /*
            THE BIG FIVE 
        */
        //copy constructor
        SequenceMap(const SequenceMap &rhs) = default;

        //copy assignment operator
        SequenceMap& operator=(const SequenceMap &rhs) = default;
 
        //move constructor
        SequenceMap(SequenceMap &&rhs) = default;

        //move assignment operator
        SequenceMap& operator=(SequenceMap &&) = default;

        //destructor
        ~SequenceMap() = default;

        //constructor 
        SequenceMap() = default;
/////////////////////////////////////DONT touch above//////////////////////////////
        //constructs a string and vector through initliazation list
        SequenceMap(const string &a_rec_seq, const string &an_enzo_acro):recognition_sequence_{a_rec_seq},enzyme_acronyms_{an_enzo_acro}
        {
        }


        //passes sequencemap(string and vector
        //returns true or false 
        // bool operator<(const SequenceMap &rhs) const
//         {
//             if(recognition_sequence_<rhs.recognition_sequence_)
//             {
//             return 1;
//             }
//             else
//             {
//             return 0;
//             }
//         }
        
    bool operator<(const SequenceMap &rhs) const
    {       
    return recognition_sequence_<rhs.recognition_sequence_;
    }
    bool operator>(const SequenceMap &rhs) const
    {
    return recognition_sequence_>rhs.recognition_sequence_;
	 }
        
        
        
        
        
        
        
        
         
        
        
        
        
        
        
        //passes cout and sequencemap(string and vector 
        //returns a cout of instanced sequencemap       
        friend ostream& operator<<(ostream &out,const SequenceMap &any_sequence) 
        {       //size() not lendgth() for vectors
            for(int z=0;z<any_sequence.enzyme_acronyms_.size()-1;z++)//size()-1 to prevent gradescope index error
            {
            out<<any_sequence.enzyme_acronyms_[z]<<" ";//gradescope wants spaces
            }
            out<<any_sequence.enzyme_acronyms_[any_sequence.enzyme_acronyms_.size()-1];
            return out;
        } 

        //passes sequencemap(string and vector
        //returns nothing
        void Merge(const SequenceMap &other_sequence)
        {
            for(int z=0;z<other_sequence.enzyme_acronyms_.size();z++)
            {//push_back is adding on to a vector
            enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[z]);
            }
        }

    private:
    
        string recognition_sequence_;
        
        
        vector<string> enzyme_acronyms_;

};

#endif //end class
//} end namespace