#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _ca_boyle_reg(void);
extern void _CaPool_reg(void);
extern void _k_fast_reg(void);
extern void _k_slow_reg(void);
extern void _Leak_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," ca_boyle.mod");
    fprintf(stderr," CaPool.mod");
    fprintf(stderr," k_fast.mod");
    fprintf(stderr," k_slow.mod");
    fprintf(stderr," Leak.mod");
    fprintf(stderr, "\n");
  }
  _ca_boyle_reg();
  _CaPool_reg();
  _k_fast_reg();
  _k_slow_reg();
  _Leak_reg();
}
