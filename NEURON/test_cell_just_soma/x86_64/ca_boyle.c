/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__ca_boyle
#define _nrn_initial _nrn_initial__ca_boyle
#define nrn_cur _nrn_cur__ca_boyle
#define _nrn_current _nrn_current__ca_boyle
#define nrn_jacob _nrn_jacob__ca_boyle
#define nrn_state _nrn_state__ca_boyle
#define _net_receive _net_receive__ca_boyle 
#define rates rates__ca_boyle 
#define states states__ca_boyle 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gmax _p[0]
#define conductance _p[1]
#define e_instances _p[2]
#define e_timeCourse_tau _p[3]
#define e_steadyState_rate _p[4]
#define e_steadyState_midpoint _p[5]
#define e_steadyState_scale _p[6]
#define f_instances _p[7]
#define f_timeCourse_tau _p[8]
#define f_steadyState_rate _p[9]
#define f_steadyState_midpoint _p[10]
#define f_steadyState_scale _p[11]
#define h_alpha _p[12]
#define h_k _p[13]
#define h_ca_half _p[14]
#define h_instances _p[15]
#define h_SEC _p[16]
#define gion _p[17]
#define e_timeCourse_t _p[18]
#define e_steadyState_x _p[19]
#define e_rateScale _p[20]
#define e_fcond _p[21]
#define e_inf _p[22]
#define e_tauUnscaled _p[23]
#define e_tau _p[24]
#define f_timeCourse_t _p[25]
#define f_steadyState_x _p[26]
#define f_rateScale _p[27]
#define f_fcond _p[28]
#define f_inf _p[29]
#define f_tauUnscaled _p[30]
#define f_tau _p[31]
#define h_rateScale _p[32]
#define h_inf _p[33]
#define h_tau _p[34]
#define h_q _p[35]
#define h_fcond _p[36]
#define conductanceScale _p[37]
#define fopen0 _p[38]
#define fopen _p[39]
#define g _p[40]
#define e_q _p[41]
#define f_q _p[42]
#define temperature _p[43]
#define eca _p[44]
#define ica _p[45]
#define cai _p[46]
#define cao _p[47]
#define rate_e_q _p[48]
#define rate_f_q _p[49]
#define De_q _p[50]
#define Df_q _p[51]
#define v _p[52]
#define _g _p[53]
#define _ion_cai	*_ppvar[0]._pval
#define _ion_cao	*_ppvar[1]._pval
#define _ion_ica	*_ppvar[2]._pval
#define _ion_dicadv	*_ppvar[3]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_rates(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_ca_boyle", _hoc_setdata,
 "rates_ca_boyle", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gmax_ca_boyle", "S/cm2",
 "conductance_ca_boyle", "uS",
 "e_timeCourse_tau_ca_boyle", "ms",
 "e_steadyState_midpoint_ca_boyle", "mV",
 "e_steadyState_scale_ca_boyle", "mV",
 "f_timeCourse_tau_ca_boyle", "ms",
 "f_steadyState_midpoint_ca_boyle", "mV",
 "f_steadyState_scale_ca_boyle", "mV",
 "h_k_ca_boyle", "mM",
 "h_ca_half_ca_boyle", "mM",
 "h_SEC_ca_boyle", "ms",
 "gion_ca_boyle", "S/cm2",
 "e_timeCourse_t_ca_boyle", "ms",
 "e_tauUnscaled_ca_boyle", "ms",
 "e_tau_ca_boyle", "ms",
 "f_timeCourse_t_ca_boyle", "ms",
 "f_tauUnscaled_ca_boyle", "ms",
 "f_tau_ca_boyle", "ms",
 "h_tau_ca_boyle", "ms",
 "g_ca_boyle", "uS",
 0,0
};
 static double delta_t = 0.01;
 static double e_q0 = 0;
 static double f_q0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[4]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"ca_boyle",
 "gmax_ca_boyle",
 "conductance_ca_boyle",
 "e_instances_ca_boyle",
 "e_timeCourse_tau_ca_boyle",
 "e_steadyState_rate_ca_boyle",
 "e_steadyState_midpoint_ca_boyle",
 "e_steadyState_scale_ca_boyle",
 "f_instances_ca_boyle",
 "f_timeCourse_tau_ca_boyle",
 "f_steadyState_rate_ca_boyle",
 "f_steadyState_midpoint_ca_boyle",
 "f_steadyState_scale_ca_boyle",
 "h_alpha_ca_boyle",
 "h_k_ca_boyle",
 "h_ca_half_ca_boyle",
 "h_instances_ca_boyle",
 "h_SEC_ca_boyle",
 0,
 "gion_ca_boyle",
 "e_timeCourse_t_ca_boyle",
 "e_steadyState_x_ca_boyle",
 "e_rateScale_ca_boyle",
 "e_fcond_ca_boyle",
 "e_inf_ca_boyle",
 "e_tauUnscaled_ca_boyle",
 "e_tau_ca_boyle",
 "f_timeCourse_t_ca_boyle",
 "f_steadyState_x_ca_boyle",
 "f_rateScale_ca_boyle",
 "f_fcond_ca_boyle",
 "f_inf_ca_boyle",
 "f_tauUnscaled_ca_boyle",
 "f_tau_ca_boyle",
 "h_rateScale_ca_boyle",
 "h_inf_ca_boyle",
 "h_tau_ca_boyle",
 "h_q_ca_boyle",
 "h_fcond_ca_boyle",
 "conductanceScale_ca_boyle",
 "fopen0_ca_boyle",
 "fopen_ca_boyle",
 "g_ca_boyle",
 0,
 "e_q_ca_boyle",
 "f_q_ca_boyle",
 0,
 0};
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 54, _prop);
 	/*initialize range parameters*/
 	gmax = 0;
 	conductance = 1e-05;
 	e_instances = 2;
 	e_timeCourse_tau = 0.100027;
 	e_steadyState_rate = 1;
 	e_steadyState_midpoint = -3.3568;
 	e_steadyState_scale = 6.74821;
 	f_instances = 1;
 	f_timeCourse_tau = 150.88;
 	f_steadyState_rate = 1;
 	f_steadyState_midpoint = 25.1815;
 	f_steadyState_scale = -5.03176;
 	h_alpha = 0.282473;
 	h_k = -1.00056e-08;
 	h_ca_half = 6.41889e-08;
 	h_instances = 1;
 	h_SEC = 1000;
 	_prop->param = _p;
 	_prop->param_size = 54;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[0]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[1]._pval = &prop_ion->param[2]; /* cao */
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _ca_boyle_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", 2.0);
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 54, 5);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 ca_boyle /home/kharms/c302/test_cell_just_soma/x86_64/ca_boyle.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=ca_boyle type=ionChannelHH)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsproto_);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargs_ ) ;
   De_q = rate_e_q ;
   Df_q = rate_f_q ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargs_ ) ;
 De_q = De_q  / (1. - dt*( 0.0 )) ;
 Df_q = Df_q  / (1. - dt*( 0.0 )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargs_ ) ;
    e_q = e_q - dt*(- ( rate_e_q ) ) ;
    f_q = f_q - dt*(- ( rate_f_q ) ) ;
   }
  return 0;
}
 
static int  rates ( _threadargsproto_ ) {
   double _lcaConc ;
 _lcaConc = cai ;
   e_timeCourse_t = e_timeCourse_tau ;
   e_steadyState_x = e_steadyState_rate / ( 1.0 + exp ( 0.0 - ( v - e_steadyState_midpoint ) / e_steadyState_scale ) ) ;
   e_rateScale = 1.0 ;
   e_fcond = pow( e_q , e_instances ) ;
   e_inf = e_steadyState_x ;
   e_tauUnscaled = e_timeCourse_t ;
   e_tau = e_tauUnscaled / e_rateScale ;
   f_timeCourse_t = f_timeCourse_tau ;
   f_steadyState_x = f_steadyState_rate / ( 1.0 + exp ( 0.0 - ( v - f_steadyState_midpoint ) / f_steadyState_scale ) ) ;
   f_rateScale = 1.0 ;
   f_fcond = pow( f_q , f_instances ) ;
   f_inf = f_steadyState_x ;
   f_tauUnscaled = f_timeCourse_t ;
   f_tau = f_tauUnscaled / f_rateScale ;
   h_rateScale = 1.0 ;
   h_inf = 1.0 / ( 1.0 + ( exp ( ( h_ca_half - _lcaConc ) / h_k ) ) ) ;
   h_tau = 0.0 * h_SEC ;
   h_q = h_inf ;
   h_fcond = 1.0 + ( ( h_q - 1.0 ) * h_alpha ) ;
   rate_e_q = ( e_inf - e_q ) / e_tau ;
   rate_f_q = ( f_inf - f_q ) / f_tau ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cai = _ion_cai;
  cao = _ion_cao;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cai = _ion_cai;
  cao = _ion_cao;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 2);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 3, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  e_q = e_q0;
  f_q = f_q0;
 {
   eca = 40.0 ;
   temperature = celsius + 273.15 ;
   rates ( _threadargs_ ) ;
   rates ( _threadargs_ ) ;
   e_q = e_inf ;
   f_q = f_inf ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  cai = _ion_cai;
  cao = _ion_cao;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   conductanceScale = 1.0 ;
   fopen0 = e_fcond * f_fcond * h_fcond ;
   fopen = conductanceScale * fopen0 ;
   g = conductance * fopen ;
   gion = gmax * fopen ;
   ica = gion * ( v - eca ) ;
   }
 _current += ica;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  cai = _ion_cai;
  cao = _ion_cao;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dica;
  _dica = ica;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ica += ica ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  cai = _ion_cai;
  cao = _ion_cao;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(e_q) - _p;  _dlist1[0] = &(De_q) - _p;
 _slist1[1] = &(f_q) - _p;  _dlist1[1] = &(Df_q) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/home/kharms/c302/test_cell_just_soma/ca_boyle.mod";
static const char* nmodl_file_text = 
  "TITLE Mod file for component: Component(id=ca_boyle type=ionChannelHH)\n"
  "\n"
  "COMMENT\n"
  "\n"
  "    This NEURON file has been generated by org.neuroml.export (see https://github.com/NeuroML/org.neuroml.export)\n"
  "         org.neuroml.export  v1.7.0\n"
  "         org.neuroml.model   v1.7.0\n"
  "         jLEMS               v0.10.2\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "    SUFFIX ca_boyle\n"
  "    USEION ca READ cai,cao WRITE ica VALENCE 2 ? Assuming valence = 2 (Ca ion); TODO check this!!\n"
  "    \n"
  "    RANGE gion                           \n"
  "    RANGE gmax                              : Will be changed when ion channel mechanism placed on cell!\n"
  "    RANGE conductance                       : parameter\n"
  "    \n"
  "    RANGE g                                 : exposure\n"
  "    \n"
  "    RANGE fopen                             : exposure\n"
  "    RANGE e_instances                       : parameter\n"
  "    \n"
  "    RANGE e_tau                             : exposure\n"
  "    \n"
  "    RANGE e_inf                             : exposure\n"
  "    \n"
  "    RANGE e_rateScale                       : exposure\n"
  "    \n"
  "    RANGE e_fcond                           : exposure\n"
  "    RANGE e_timeCourse_tau                  : parameter\n"
  "    \n"
  "    RANGE e_timeCourse_t                    : exposure\n"
  "    RANGE e_steadyState_rate                : parameter\n"
  "    RANGE e_steadyState_midpoint            : parameter\n"
  "    RANGE e_steadyState_scale               : parameter\n"
  "    \n"
  "    RANGE e_steadyState_x                   : exposure\n"
  "    RANGE f_instances                       : parameter\n"
  "    \n"
  "    RANGE f_tau                             : exposure\n"
  "    \n"
  "    RANGE f_inf                             : exposure\n"
  "    \n"
  "    RANGE f_rateScale                       : exposure\n"
  "    \n"
  "    RANGE f_fcond                           : exposure\n"
  "    RANGE f_timeCourse_tau                  : parameter\n"
  "    \n"
  "    RANGE f_timeCourse_t                    : exposure\n"
  "    RANGE f_steadyState_rate                : parameter\n"
  "    RANGE f_steadyState_midpoint            : parameter\n"
  "    RANGE f_steadyState_scale               : parameter\n"
  "    \n"
  "    RANGE f_steadyState_x                   : exposure\n"
  "    RANGE h_alpha                           : parameter\n"
  "    RANGE h_k                               : parameter\n"
  "    RANGE h_ca_half                         : parameter\n"
  "    RANGE h_instances                       : parameter\n"
  "    RANGE h_SEC                             : parameter\n"
  "    \n"
  "    RANGE h_tau                             : exposure\n"
  "    \n"
  "    RANGE h_inf                             : exposure\n"
  "    \n"
  "    RANGE h_rateScale                       : exposure\n"
  "    \n"
  "    RANGE h_fcond                           : exposure\n"
  "    \n"
  "    RANGE h_q                               : exposure\n"
  "    RANGE e_tauUnscaled                     : derived variable\n"
  "    RANGE f_tauUnscaled                     : derived variable\n"
  "    RANGE conductanceScale                  : derived variable\n"
  "    RANGE fopen0                            : derived variable\n"
  "    \n"
  "}\n"
  "\n"
  "UNITS {\n"
  "    \n"
  "    (nA) = (nanoamp)\n"
  "    (uA) = (microamp)\n"
  "    (mA) = (milliamp)\n"
  "    (A) = (amp)\n"
  "    (mV) = (millivolt)\n"
  "    (mS) = (millisiemens)\n"
  "    (uS) = (microsiemens)\n"
  "    (molar) = (1/liter)\n"
  "    (kHz) = (kilohertz)\n"
  "    (mM) = (millimolar)\n"
  "    (um) = (micrometer)\n"
  "    (umol) = (micromole)\n"
  "    (S) = (siemens)\n"
  "    \n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    \n"
  "    gmax = 0  (S/cm2)                       : Will be changed when ion channel mechanism placed on cell!\n"
  "    \n"
  "    conductance = 1.0E-5 (uS)\n"
  "    e_instances = 2 \n"
  "    e_timeCourse_tau = 0.100027 (ms)\n"
  "    e_steadyState_rate = 1 \n"
  "    e_steadyState_midpoint = -3.3568 (mV)\n"
  "    e_steadyState_scale = 6.74821 (mV)\n"
  "    f_instances = 1 \n"
  "    f_timeCourse_tau = 150.88 (ms)\n"
  "    f_steadyState_rate = 1 \n"
  "    f_steadyState_midpoint = 25.1815 (mV)\n"
  "    f_steadyState_scale = -5.03176 (mV)\n"
  "    h_alpha = 0.282473 \n"
  "    h_k = -1.00056E-8 (mM)\n"
  "    h_ca_half = 6.41889E-8 (mM)\n"
  "    h_instances = 1 \n"
  "    h_SEC = 1000 (ms)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    \n"
  "    gion   (S/cm2)                          : Transient conductance density of the channel? Standard Assigned variables with ionChannel\n"
  "    v (mV)\n"
  "    celsius (degC)\n"
  "    temperature (K)\n"
  "    eca (mV)\n"
  "    ica (mA/cm2)\n"
  "    \n"
  "    cai (mM)\n"
  "    \n"
  "    cao (mM)\n"
  "    \n"
  "    \n"
  "    e_timeCourse_t (ms)                    : derived variable\n"
  "    \n"
  "    e_steadyState_x                        : derived variable\n"
  "    \n"
  "    e_rateScale                            : derived variable\n"
  "    \n"
  "    e_fcond                                : derived variable\n"
  "    \n"
  "    e_inf                                  : derived variable\n"
  "    \n"
  "    e_tauUnscaled (ms)                     : derived variable\n"
  "    \n"
  "    e_tau (ms)                             : derived variable\n"
  "    \n"
  "    f_timeCourse_t (ms)                    : derived variable\n"
  "    \n"
  "    f_steadyState_x                        : derived variable\n"
  "    \n"
  "    f_rateScale                            : derived variable\n"
  "    \n"
  "    f_fcond                                : derived variable\n"
  "    \n"
  "    f_inf                                  : derived variable\n"
  "    \n"
  "    f_tauUnscaled (ms)                     : derived variable\n"
  "    \n"
  "    f_tau (ms)                             : derived variable\n"
  "    \n"
  "    h_rateScale                            : derived variable\n"
  "    \n"
  "    h_inf                                  : derived variable\n"
  "    \n"
  "    h_tau (ms)                             : derived variable\n"
  "    \n"
  "    h_q                                    : derived variable\n"
  "    \n"
  "    h_fcond                                : derived variable\n"
  "    \n"
  "    conductanceScale                       : derived variable\n"
  "    \n"
  "    fopen0                                 : derived variable\n"
  "    \n"
  "    fopen                                  : derived variable\n"
  "    \n"
  "    g (uS)                                 : derived variable\n"
  "    rate_e_q (/ms)\n"
  "    rate_f_q (/ms)\n"
  "    \n"
  "}\n"
  "\n"
  "STATE {\n"
  "    e_q  \n"
  "    f_q  \n"
  "    \n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "    eca = 40.0\n"
  "    \n"
  "    temperature = celsius + 273.15\n"
  "    \n"
  "    rates()\n"
  "    rates() ? To ensure correct initialisation.\n"
  "    \n"
  "    e_q = e_inf\n"
  "    \n"
  "    f_q = f_inf\n"
  "    \n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "    \n"
  "    SOLVE states METHOD cnexp\n"
  "    \n"
  "    ? DerivedVariable is based on path: conductanceScaling[*]/factor, on: Component(id=ca_boyle type=ionChannelHH), from conductanceScaling; null\n"
  "    ? Path not present in component, using factor: 1\n"
  "    \n"
  "    conductanceScale = 1 \n"
  "    \n"
  "    ? DerivedVariable is based on path: gates[*]/fcond, on: Component(id=ca_boyle type=ionChannelHH), from gates; Component(id=e type=gateHHtauInf)\n"
  "    ? multiply applied to all instances of fcond in: <gates> ([Component(id=e type=gateHHtauInf), Component(id=f type=gateHHtauInf), Component(id=h type=customHGate)]))\n"
  "    fopen0 = e_fcond * f_fcond * h_fcond ? path based, prefix = \n"
  "    \n"
  "    fopen = conductanceScale  *  fopen0 ? evaluable\n"
  "    g = conductance  *  fopen ? evaluable\n"
  "    gion = gmax * fopen \n"
  "    \n"
  "    ica = gion * (v - eca)\n"
  "    \n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "    rates()\n"
  "    e_q' = rate_e_q \n"
  "    f_q' = rate_f_q \n"
  "    \n"
  "}\n"
  "\n"
  "PROCEDURE rates() {\n"
  "    LOCAL caConc\n"
  "    \n"
  "    caConc = cai\n"
  "    \n"
  "    e_timeCourse_t = e_timeCourse_tau ? evaluable\n"
  "    e_steadyState_x = e_steadyState_rate  / (1 + exp(0 - (v -  e_steadyState_midpoint )/ e_steadyState_scale )) ? evaluable\n"
  "    ? DerivedVariable is based on path: q10Settings[*]/q10, on: Component(id=e type=gateHHtauInf), from q10Settings; null\n"
  "    ? Path not present in component, using factor: 1\n"
  "    \n"
  "    e_rateScale = 1 \n"
  "    \n"
  "    e_fcond = e_q ^ e_instances ? evaluable\n"
  "    ? DerivedVariable is based on path: steadyState/x, on: Component(id=e type=gateHHtauInf), from steadyState; Component(id=null type=HHSigmoidVariable)\n"
  "    e_inf = e_steadyState_x ? path based, prefix = e_\n"
  "    \n"
  "    ? DerivedVariable is based on path: timeCourse/t, on: Component(id=e type=gateHHtauInf), from timeCourse; Component(id=null type=fixedTimeCourse)\n"
  "    e_tauUnscaled = e_timeCourse_t ? path based, prefix = e_\n"
  "    \n"
  "    e_tau = e_tauUnscaled  /  e_rateScale ? evaluable\n"
  "    f_timeCourse_t = f_timeCourse_tau ? evaluable\n"
  "    f_steadyState_x = f_steadyState_rate  / (1 + exp(0 - (v -  f_steadyState_midpoint )/ f_steadyState_scale )) ? evaluable\n"
  "    ? DerivedVariable is based on path: q10Settings[*]/q10, on: Component(id=f type=gateHHtauInf), from q10Settings; null\n"
  "    ? Path not present in component, using factor: 1\n"
  "    \n"
  "    f_rateScale = 1 \n"
  "    \n"
  "    f_fcond = f_q ^ f_instances ? evaluable\n"
  "    ? DerivedVariable is based on path: steadyState/x, on: Component(id=f type=gateHHtauInf), from steadyState; Component(id=null type=HHSigmoidVariable)\n"
  "    f_inf = f_steadyState_x ? path based, prefix = f_\n"
  "    \n"
  "    ? DerivedVariable is based on path: timeCourse/t, on: Component(id=f type=gateHHtauInf), from timeCourse; Component(id=null type=fixedTimeCourse)\n"
  "    f_tauUnscaled = f_timeCourse_t ? path based, prefix = f_\n"
  "    \n"
  "    f_tau = f_tauUnscaled  /  f_rateScale ? evaluable\n"
  "    h_rateScale = 1 ? evaluable\n"
  "    h_inf = 1 / (1 + (exp( ( h_ca_half  - caConc) /  h_k ))) ? evaluable\n"
  "    h_tau = 0 *  h_SEC ? evaluable\n"
  "    h_q = h_inf ? evaluable\n"
  "    h_fcond = 1 +(( h_q -1) *  h_alpha ) ? evaluable\n"
  "    \n"
  "     \n"
  "    rate_e_q = ( e_inf  -  e_q ) /  e_tau ? Note units of all quantities used here need to be consistent!\n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    rate_f_q = ( f_inf  -  f_q ) /  f_tau ? Note units of all quantities used here need to be consistent!\n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "}\n"
  "\n"
  ;
#endif
