//Maxwell Large 335
#include <string>
#include <iostream>
using namespace std;
template <typename Iterator, typename object>

Iterator my_find(Iterator start,Iterator end,const object& x)
{
	Iterator i=start; 
	
    for(;i!=end;i++)//weird loop syntax but works
    {
   	   if(*i==x) 
   		{
   		break;//found x
   		}
    }
   
    return i;//return index of x
}

int main()
{
	string x; 
	cin >> x ; 
	char to_find='a' ; 
	string::iterator start=x.begin();//[0][][][]
	string::iterator end=x.end();//[][][][n]
	string::iterator its_here=my_find(start,end,to_find); 
	
	if(its_here!=x.end())//see if 'a' was found
	{
	cout<<*its_here ;//print 'a', if it was found
	}

	return 0;
}
