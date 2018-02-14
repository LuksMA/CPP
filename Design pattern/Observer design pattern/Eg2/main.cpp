#include "Subject.h"
#include "DivObserver.h"
#include "ModObserver.h"


int main()
{
  Subject subj;
  DivObserver divObs1(&subj, 4);
  DivObserver divObs2(&subj, 3);
  ModObserver modObs3(&subj, 3);
  subj.setVal(14);
}

//14 div 4 is 3
//14 div 3 is 4
//14 mod 3 is 2
