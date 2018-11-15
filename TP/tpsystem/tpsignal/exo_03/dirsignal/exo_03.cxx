/**
 *
 * @File : 
 *
 * @Author : A. B. Dragut
 *
 * @Synopsis : modelmain
 **/

#include <string>
#include <exception>
#include <iostream>    

#include <unistd.h>     // getdtablesize()
#include <sys/time.h>   // fd_set

#include "nsSysteme.h"
#include "CExc.h"

using namespace nsSysteme;
using namespace std;

namespace {
	void Derout1 (int NumSig) {
	        cout << "début " <<endl;
		sleep 5;
		cout << "fin" << endl;
    	} // Derout()
	
	void Derout2 (int NumSig) {
		struct sigaction OldAct;
		cout << "début " <<endl;
		sleep 5;
		Sigaction(NumSig, &OldAct ,0);
		cout << "fin" << endl;
	}

}
int main(int argc, char * argv [])
{
  try {
	struct sigaction Act;
	Act.sa_flags = SA_RESETHAND;
	sigemptyset(&Act.sa_mask);
	Act.sa_handler = Derout;
	Sigaction (SIGINT, &Act, 0);
	for(;;);
	return 0;
}


///code
    
  
  catch (const CExc & Exc) {
        cerr <<Exc<< endl;
        return errno;
  }
  catch (const exception & Exc) {
        cerr << "Exception : " << Exc.what () << endl;
        return 1;
  }
  catch (...) {
        cerr << "Exception inconnue recue dans la fonction main()" 
             << endl;
        return 1;
  }


}  //  main()
