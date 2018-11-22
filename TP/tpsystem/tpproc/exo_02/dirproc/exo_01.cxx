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

namespace{

bool pere;

 void Derout (int NumSig)
    {   
		cout<<endl;
        cout << "Signal " << strsignal(NumSig)<<" "<<NumSig << " recu par le " 
             << (Pere ? "pere " : "fils ") << " de pid = " 
             << setw (5) << ::getpid ()    << endl;

    } // Derout()
}

int main(int argc, char * argv [])
{
  try {
		pid_t pidFils;
		if ((pidFils = Fork()))
		{
			pere =true;
			cout << "je suis le père : "<< getpid() << endl;
			cout << "j'ai un fils de pid : " << pidFils << endl;
		}
		else
		{
			pere=false;
			Signal(SIGTSTP, SIG_DFL
			cout<< "je suis le fils : " << getpid() << endl;
			cout<< "j'ai un père de pid: " << getppid() << endl;
			
		}

		for(;;);
		


///code
    return 0;
  }
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
