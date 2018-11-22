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

int main(int argc, char * argv [])
{
  try {
		
		pid_t pidFils;

		Open("exo_01.cxx", O_RDONLY);
		Open("exo_01.cxx", O_RDONLY);
		Open("exo_01.cxx", O_RDONLY);
		Close(2)
		if ((pidFils = Fork()))
		{
			cout << "je suis le père : "<< getpid() << endl;
			cout << "j'ai un fils de pid : " << pidFils << endl;
			TestFdOuvert();
		}
		else
		{
			cout<< "je suis le fils : " << getpid() << endl;
			cout<< "j'ai un père de pid: " << getppid() << endl;
			TestFdOuvert();
		}
		


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
