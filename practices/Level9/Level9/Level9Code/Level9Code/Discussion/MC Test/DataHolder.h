//

#ifndef DataHolder_HPP
#define DataHolder_HPP

//#include <algorithm> // for max()
using namespace std;

// Encapsulate all data in one place
struct DataHolder
{
	// For Path
	double Sout;
	double Sumout;
	double Avegout;
	
	// Interval 
	double St;		// down and out barrier
	double gent;		// dividend
	double dtt;	// scale factor in CEV model
	
	// Print Path
	void PrintPath(void)
	{ 
		cout << Sout << " " << Sumout << " " << Avegout << endl;  
	}

	// Print Interval
	void PrintInterval(void)
	{ 
		cout << St << " " << gent << " " << dtt << endl;  
	}
};

#endif