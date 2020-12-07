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
 
#define nrn_init _nrn_init__k_fast
#define _nrn_initial _nrn_initial__k_fast
#define nrn_cur _nrn_cur__k_fast
#define _nrn_current _nrn_current__k_fast
#define nrn_jacob _nrn_jacob__k_fast
#define nrn_state _nrn_state__k_fast
#define _net_receive _net_receive__k_fast 
#define rates rates__k_fast 
#define states states__k_fast 
 
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
#define p_instances _p[2]
#define p_timeCourse_tau _p[3]
#define p_steadyState_rate _p[4]
#define p_steadyState_midpoint _p[5]
#define p_steadyState_scale _p[6]
#define q_instances _p[7]
#define q_timeCourse_tau _p[8]
#define q_steadyState_rate _p[9]
#define q_steadyState_midpoint _p[10]
#define q_steadyState_scale _p[11]
#define gion _p[12]
#define p_timeCourse_t _p[13]
#define p_steadyState_x _p[14]
#define p_rateScale _p[15]
#define p_fcond _p[16]
#define p_inf _p[17]
#define p_tauUnscaled _p[18]
#define p_tau _p[19]
#define q_timeCourse_t _p[20]
#define q_steadyState_x _p[21]
#define q_rateScale _p[22]
#define q_fcond _p[23]
#define q_inf _p[24]
#define q_tauUnscaled _p[25]
#define q_tau _p[26]
#define conductanceScale _p[27]
#define fopen0 _p[28]
#define fopen _p[29]
#define g _p[30]
#define p_q _p[31]
#define q_q _p[32]
#define temperature _p[33]
#define ek _p[34]
#define ik _p[35]
#define rate_p_q _p[36]
#define rate_q_q _p[37]
#define Dp_q _p[38]
#define Dq_q _p[39]
#define v _p[40]
#define _g _p[41]
#define _ion_ik	*_ppvar[0]._pval
#define _ion_dikdv	*_ppvar[1]._pval
 
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
 "setdata_k_fast", _hoc_setdata,
 "rates_k_fast", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gmax_k_fast", "S/cm2",
 "conductance_k_fast", "uS",
 "p_timeCourse_tau_k_fast", "ms",
 "p_steadyState_midpoint_k_fast", "mV",
 "p_steadyState_scale_k_fast", "mV",
 "q_timeCourse_tau_k_fast", "ms",
 "q_steadyState_midpoint_k_fast", "mV",
 "q_steadyState_scale_k_fast", "mV",
 "gion_k_fast", "S/cm2",
 "p_timeCourse_t_k_fast", "ms",
 "p_tauUnscaled_k_fast", "ms",
 "p_tau_k_fast", "ms",
 "q_timeCourse_t_k_fast", "ms",
 "q_tauUnscaled_k_fast", "ms",
 "q_tau_k_fast", "ms",
 "g_k_fast", "uS",
 0,0
};
 static double delta_t = 0.01;
 static double p_q0 = 0;
 static double q_q0 = 0;
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
 
#define _cvode_ieq _ppvar[2]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"k_fast",
 "gmax_k_fast",
 "conductance_k_fast",
 "p_instances_k_fast",
 "p_timeCourse_tau_k_fast",
 "p_steadyState_rate_k_fast",
 "p_steadyState_midpoint_k_fast",
 "p_steadyState_scale_k_fast",
 "q_instances_k_fast",
 "q_timeCourse_tau_k_fast",
 "q_steadyState_rate_k_fast",
 "q_steadyState_midpoint_k_fast",
 "q_steadyState_scale_k_fast",
 0,
 "gion_k_fast",
 "p_timeCourse_t_k_fast",
 "p_steadyState_x_k_fast",
 "p_rateScale_k_fast",
 "p_fcond_k_fast",
 "p_inf_k_fast",
 "p_tauUnscaled_k_fast",
 "p_tau_k_fast",
 "q_timeCourse_t_k_fast",
 "q_steadyState_x_k_fast",
 "q_rateScale_k_fast",
 "q_fcond_k_fast",
 "q_inf_k_fast",
 "q_tauUnscaled_k_fast",
 "q_tau_k_fast",
 "conductanceScale_k_fast",
 "fopen0_k_fast",
 "fopen_k_fast",
 "g_k_fast",
 0,
 "p_q_k_fast",
 "q_q_k_fast",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 42, _prop);
 	/*initialize range parameters*/
 	gmax = 0;
 	conductance = 1e-05;
 	p_instances = 4;
 	p_timeCourse_tau = 2.25518;
 	p_steadyState_rate = 1;
 	p_steadyState_midpoint = -8.05232;
 	p_steadyState_scale = 7.42636;
 	q_instances = 1;
 	q_timeCourse_tau = 149.963;
 	q_steadyState_rate = 1;
 	q_steadyState_midpoint = -15.6456;
 	q_steadyState_scale = -9.97468;
 	_prop->param = _p;
 	_prop->param_size = 42;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
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

 void _k_fast_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", 1.0);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 42, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 k_fast /home/kharms/c302/test_cell_just_soma/x86_64/k_fast.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=k_fast type=ionChannelHH)";

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
   Dp_q = rate_p_q ;
   Dq_q = rate_q_q ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargs_ ) ;
 Dp_q = Dp_q  / (1. - dt*( 0.0 )) ;
 Dq_q = Dq_q  / (1. - dt*( 0.0 )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargs_ ) ;
    p_q = p_q - dt*(- ( rate_p_q ) ) ;
    q_q = q_q - dt*(- ( rate_q_q ) ) ;
   }
  return 0;
}
 
static int  rates ( _threadargsproto_ ) {
   p_timeCourse_t = p_timeCourse_tau ;
   p_steadyState_x = p_steadyState_rate / ( 1.0 + exp ( 0.0 - ( v - p_steadyState_midpoint ) / p_steadyState_scale ) ) ;
   p_rateScale = 1.0 ;
   p_fcond = pow( p_q , p_instances ) ;
   p_inf = p_steadyState_x ;
   p_tauUnscaled = p_timeCourse_t ;
   p_tau = p_tauUnscaled / p_rateScale ;
   q_timeCourse_t = q_timeCourse_tau ;
   q_steadyState_x = q_steadyState_rate / ( 1.0 + exp ( 0.0 - ( v - q_steadyState_midpoint ) / q_steadyState_scale ) ) ;
   q_rateScale = 1.0 ;
   q_fcond = pow( q_q , q_instances ) ;
   q_inf = q_steadyState_x ;
   q_tauUnscaled = q_timeCourse_t ;
   q_tau = q_tauUnscaled / q_rateScale ;
   rate_p_q = ( p_inf - p_q ) / p_tau ;
   rate_q_q = ( q_inf - q_q ) / q_tau ;
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
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  p_q = p_q0;
  q_q = q_q0;
 {
   ek = - 60.0 ;
   temperature = celsius + 273.15 ;
   rates ( _threadargs_ ) ;
   rates ( _threadargs_ ) ;
   p_q = p_inf ;
   q_q = q_inf ;
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
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   conductanceScale = 1.0 ;
   fopen0 = p_fcond * q_fcond ;
   fopen = conductanceScale * fopen0 ;
   g = conductance * fopen ;
   gion = gmax * fopen ;
   ik = gion * ( v - ek ) ;
   }
 _current += ik;

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
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
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
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(p_q) - _p;  _dlist1[0] = &(Dp_q) - _p;
 _slist1[1] = &(q_q) - _p;  _dlist1[1] = &(Dq_q) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/home/kharms/c302/test_cell_just_soma/k_fast.mod";
static const char* nmodl_file_text = 
  "TITLE Mod file for component: Component(id=k_fast type=ionChannelHH)\n"
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
  "    SUFFIX k_fast\n"
  "    USEION k WRITE ik VALENCE 1 ? Assuming valence = 1; TODO check this!!\n"
  "    \n"
  "    RANGE gion                           \n"
  "    RANGE gmax                              : Will be changed when ion channel mechanism placed on cell!\n"
  "    RANGE conductance                       : parameter\n"
  "    \n"
  "    RANGE g                                 : exposure\n"
  "    \n"
  "    RANGE fopen                             : exposure\n"
  "    RANGE p_instances                       : parameter\n"
  "    \n"
  "    RANGE p_tau                             : exposure\n"
  "    \n"
  "    RANGE p_inf                             : exposure\n"
  "    \n"
  "    RANGE p_rateScale                       : exposure\n"
  "    \n"
  "    RANGE p_fcond                           : exposure\n"
  "    RANGE p_timeCourse_tau                  : parameter\n"
  "    \n"
  "    RANGE p_timeCourse_t                    : exposure\n"
  "    RANGE p_steadyState_rate                : parameter\n"
  "    RANGE p_steadyState_midpoint            : parameter\n"
  "    RANGE p_steadyState_scale               : parameter\n"
  "    \n"
  "    RANGE p_steadyState_x                   : exposure\n"
  "    RANGE q_instances                       : parameter\n"
  "    \n"
  "    RANGE q_tau                             : exposure\n"
  "    \n"
  "    RANGE q_inf                             : exposure\n"
  "    \n"
  "    RANGE q_rateScale                       : exposure\n"
  "    \n"
  "    RANGE q_fcond                           : exposure\n"
  "    RANGE q_timeCourse_tau                  : parameter\n"
  "    \n"
  "    RANGE q_timeCourse_t                    : exposure\n"
  "    RANGE q_steadyState_rate                : parameter\n"
  "    RANGE q_steadyState_midpoint            : parameter\n"
  "    RANGE q_steadyState_scale               : parameter\n"
  "    \n"
  "    RANGE q_steadyState_x                   : exposure\n"
  "    RANGE p_tauUnscaled                     : derived variable\n"
  "    RANGE q_tauUnscaled                     : derived variable\n"
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
  "    p_instances = 4 \n"
  "    p_timeCourse_tau = 2.25518 (ms)\n"
  "    p_steadyState_rate = 1 \n"
  "    p_steadyState_midpoint = -8.05232 (mV)\n"
  "    p_steadyState_scale = 7.42636 (mV)\n"
  "    q_instances = 1 \n"
  "    q_timeCourse_tau = 149.963 (ms)\n"
  "    q_steadyState_rate = 1 \n"
  "    q_steadyState_midpoint = -15.6456 (mV)\n"
  "    q_steadyState_scale = -9.97468 (mV)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    \n"
  "    gion   (S/cm2)                          : Transient conductance density of the channel? Standard Assigned variables with ionChannel\n"
  "    v (mV)\n"
  "    celsius (degC)\n"
  "    temperature (K)\n"
  "    ek (mV)\n"
  "    ik (mA/cm2)\n"
  "    \n"
  "    \n"
  "    p_timeCourse_t (ms)                    : derived variable\n"
  "    \n"
  "    p_steadyState_x                        : derived variable\n"
  "    \n"
  "    p_rateScale                            : derived variable\n"
  "    \n"
  "    p_fcond                                : derived variable\n"
  "    \n"
  "    p_inf                                  : derived variable\n"
  "    \n"
  "    p_tauUnscaled (ms)                     : derived variable\n"
  "    \n"
  "    p_tau (ms)                             : derived variable\n"
  "    \n"
  "    q_timeCourse_t (ms)                    : derived variable\n"
  "    \n"
  "    q_steadyState_x                        : derived variable\n"
  "    \n"
  "    q_rateScale                            : derived variable\n"
  "    \n"
  "    q_fcond                                : derived variable\n"
  "    \n"
  "    q_inf                                  : derived variable\n"
  "    \n"
  "    q_tauUnscaled (ms)                     : derived variable\n"
  "    \n"
  "    q_tau (ms)                             : derived variable\n"
  "    \n"
  "    conductanceScale                       : derived variable\n"
  "    \n"
  "    fopen0                                 : derived variable\n"
  "    \n"
  "    fopen                                  : derived variable\n"
  "    \n"
  "    g (uS)                                 : derived variable\n"
  "    rate_p_q (/ms)\n"
  "    rate_q_q (/ms)\n"
  "    \n"
  "}\n"
  "\n"
  "STATE {\n"
  "    p_q  \n"
  "    q_q  \n"
  "    \n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "    ek = -60.0\n"
  "    \n"
  "    temperature = celsius + 273.15\n"
  "    \n"
  "    rates()\n"
  "    rates() ? To ensure correct initialisation.\n"
  "    \n"
  "    p_q = p_inf\n"
  "    \n"
  "    q_q = q_inf\n"
  "    \n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "    \n"
  "    SOLVE states METHOD cnexp\n"
  "    \n"
  "    ? DerivedVariable is based on path: conductanceScaling[*]/factor, on: Component(id=k_fast type=ionChannelHH), from conductanceScaling; null\n"
  "    ? Path not present in component, using factor: 1\n"
  "    \n"
  "    conductanceScale = 1 \n"
  "    \n"
  "    ? DerivedVariable is based on path: gates[*]/fcond, on: Component(id=k_fast type=ionChannelHH), from gates; Component(id=p type=gateHHtauInf)\n"
  "    ? multiply applied to all instances of fcond in: <gates> ([Component(id=p type=gateHHtauInf), Component(id=q type=gateHHtauInf)]))\n"
  "    fopen0 = p_fcond * q_fcond ? path based, prefix = \n"
  "    \n"
  "    fopen = conductanceScale  *  fopen0 ? evaluable\n"
  "    g = conductance  *  fopen ? evaluable\n"
  "    gion = gmax * fopen \n"
  "    \n"
  "    ik = gion * (v - ek)\n"
  "    \n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "    rates()\n"
  "    p_q' = rate_p_q \n"
  "    q_q' = rate_q_q \n"
  "    \n"
  "}\n"
  "\n"
  "PROCEDURE rates() {\n"
  "    \n"
  "    p_timeCourse_t = p_timeCourse_tau ? evaluable\n"
  "    p_steadyState_x = p_steadyState_rate  / (1 + exp(0 - (v -  p_steadyState_midpoint )/ p_steadyState_scale )) ? evaluable\n"
  "    ? DerivedVariable is based on path: q10Settings[*]/q10, on: Component(id=p type=gateHHtauInf), from q10Settings; null\n"
  "    ? Path not present in component, using factor: 1\n"
  "    \n"
  "    p_rateScale = 1 \n"
  "    \n"
  "    p_fcond = p_q ^ p_instances ? evaluable\n"
  "    ? DerivedVariable is based on path: steadyState/x, on: Component(id=p type=gateHHtauInf), from steadyState; Component(id=null type=HHSigmoidVariable)\n"
  "    p_inf = p_steadyState_x ? path based, prefix = p_\n"
  "    \n"
  "    ? DerivedVariable is based on path: timeCourse/t, on: Component(id=p type=gateHHtauInf), from timeCourse; Component(id=null type=fixedTimeCourse)\n"
  "    p_tauUnscaled = p_timeCourse_t ? path based, prefix = p_\n"
  "    \n"
  "    p_tau = p_tauUnscaled  /  p_rateScale ? evaluable\n"
  "    q_timeCourse_t = q_timeCourse_tau ? evaluable\n"
  "    q_steadyState_x = q_steadyState_rate  / (1 + exp(0 - (v -  q_steadyState_midpoint )/ q_steadyState_scale )) ? evaluable\n"
  "    ? DerivedVariable is based on path: q10Settings[*]/q10, on: Component(id=q type=gateHHtauInf), from q10Settings; null\n"
  "    ? Path not present in component, using factor: 1\n"
  "    \n"
  "    q_rateScale = 1 \n"
  "    \n"
  "    q_fcond = q_q ^ q_instances ? evaluable\n"
  "    ? DerivedVariable is based on path: steadyState/x, on: Component(id=q type=gateHHtauInf), from steadyState; Component(id=null type=HHSigmoidVariable)\n"
  "    q_inf = q_steadyState_x ? path based, prefix = q_\n"
  "    \n"
  "    ? DerivedVariable is based on path: timeCourse/t, on: Component(id=q type=gateHHtauInf), from timeCourse; Component(id=null type=fixedTimeCourse)\n"
  "    q_tauUnscaled = q_timeCourse_t ? path based, prefix = q_\n"
  "    \n"
  "    q_tau = q_tauUnscaled  /  q_rateScale ? evaluable\n"
  "    \n"
  "     \n"
  "    rate_p_q = ( p_inf  -  p_q ) /  p_tau ? Note units of all quantities used here need to be consistent!\n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    rate_q_q = ( q_inf  -  q_q ) /  q_tau ? Note units of all quantities used here need to be consistent!\n"
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
