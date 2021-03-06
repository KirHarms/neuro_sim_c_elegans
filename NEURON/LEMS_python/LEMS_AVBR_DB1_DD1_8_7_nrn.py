'''
Neuron simulator export for:

Components:
    Leak (Type: ionChannelPassive:  conductance=1.0E-11 (SI conductance))
    k_fast (Type: ionChannelHH:  conductance=1.0E-11 (SI conductance))
    k_slow (Type: ionChannelHH:  conductance=1.0E-11 (SI conductance))
    ca_boyle (Type: ionChannelHH:  conductance=1.0E-11 (SI conductance))
    ca_simple (Type: ionChannelHH:  conductance=1.0E-11 (SI conductance))
    AVBR (Type: cell)
    DB1 (Type: cell)
    DD1 (Type: cell)
    null (Type: notes)
    CaPool (Type: fixedFactorConcentrationModel:  restingConc=0.0 (SI concentration) decayConstant=0.0115943 (SI time) rho=2.38919E-4 (SI rho_factor))
    neuron_to_neuron_exc_syn (Type: expTwoSynapse:  tauRise=0.001 (SI time) tauDecay=0.005 (SI time) peakTime=0.002011797390542625 (SI time) waveformFactor=1.8691859765265255 (dimensionless) gbase=1.0000000000000001E-11 (SI conductance) erev=0.0 (SI voltage))
    neuron_to_neuron_elec_syn (Type: gapJunction:  conductance=5.000000000000001E-13 (SI conductance))
    GenericMuscleCell (Type: cell)
    offset_current (Type: pulseGenerator:  delay=0.0 (SI time) duration=2.0 (SI time) amplitude=8.7E-12 (SI current))
    AVBR_DB1_DD1_8_7 (Type: network)
    sim_AVBR_DB1_DD1_8_7 (Type: Simulation:  length=0.3 (SI time) step=1.0E-5 (SI time))


    This NEURON file has been generated by org.neuroml.export (see https://github.com/NeuroML/org.neuroml.export)
         org.neuroml.export  v1.7.0
         org.neuroml.model   v1.7.0
         jLEMS               v0.10.2

'''

import neuron

import time
import datetime
import sys

import hashlib
h = neuron.h
h.load_file("nrngui.hoc")

h("objref p")
h("p = new PythonObject()")

class NeuronSimulation():

    def __init__(self, tstop, dt, seed=123456789):

        print("\n    Starting simulation in NEURON of %sms generated from NeuroML2 model...\n"%tstop)

        self.setup_start = time.time()
        self.seed = seed
        self.randoms = []
        self.next_global_id = 0  # Used in Random123 classes for elements using random(), etc. 

        self.next_spiking_input_id = 0  # Used in Random123 classes for elements using random(), etc. 

        '''
        Adding simulation Component(id=sim_AVBR_DB1_DD1_8_7 type=Simulation) of network/component: AVBR_DB1_DD1_8_7 (Type: network)
        
        '''
        # ######################   Population: AVBR
        print("Population AVBR contains 1 instance(s) of component: AVBR of type: cell")

        print("Setting the default initial concentrations for ca (used in AVBR) to 0.0 mM (internal), 2.0 mM (external)")
        h("cai0_ca_ion = 0.0")
        h("cao0_ca_ion = 2.0")

        h.load_file("AVBR.hoc")
        a_AVBR = []
        h("{ n_AVBR = 1 }")
        h("objectvar a_AVBR[n_AVBR]")
        for i in range(int(h.n_AVBR)):
            h("a_AVBR[%i] = new AVBR()"%i)
            h("access a_AVBR[%i].Soma"%i)

            self.next_global_id+=1

        h("{ a_AVBR[0].position(0.0, 0.0, 0.0) }")

        h("proc initialiseV_AVBR() { for i = 0, n_AVBR-1 { a_AVBR[i].set_initial_v() } }")
        h("objref fih_AVBR")
        h('{fih_AVBR = new FInitializeHandler(0, "initialiseV_AVBR()")}')

        h("proc initialiseIons_AVBR() { for i = 0, n_AVBR-1 { a_AVBR[i].set_initial_ion_properties() } }")
        h("objref fih_ion_AVBR")
        h('{fih_ion_AVBR = new FInitializeHandler(1, "initialiseIons_AVBR()")}')

        # ######################   Population: DB1
        print("Population DB1 contains 1 instance(s) of component: DB1 of type: cell")

        print("Setting the default initial concentrations for ca (used in DB1) to 0.0 mM (internal), 2.0 mM (external)")
        h("cai0_ca_ion = 0.0")
        h("cao0_ca_ion = 2.0")

        h.load_file("DB1.hoc")
        a_DB1 = []
        h("{ n_DB1 = 1 }")
        h("objectvar a_DB1[n_DB1]")
        for i in range(int(h.n_DB1)):
            h("a_DB1[%i] = new DB1()"%i)
            h("access a_DB1[%i].Soma"%i)

            self.next_global_id+=1

        h("{ a_DB1[0].position(0.0, 0.0, 0.0) }")

        h("proc initialiseV_DB1() { for i = 0, n_DB1-1 { a_DB1[i].set_initial_v() } }")
        h("objref fih_DB1")
        h('{fih_DB1 = new FInitializeHandler(0, "initialiseV_DB1()")}')

        h("proc initialiseIons_DB1() { for i = 0, n_DB1-1 { a_DB1[i].set_initial_ion_properties() } }")
        h("objref fih_ion_DB1")
        h('{fih_ion_DB1 = new FInitializeHandler(1, "initialiseIons_DB1()")}')

        # ######################   Population: DD1
        print("Population DD1 contains 1 instance(s) of component: DD1 of type: cell")

        print("Setting the default initial concentrations for ca (used in DD1) to 0.0 mM (internal), 2.0 mM (external)")
        h("cai0_ca_ion = 0.0")
        h("cao0_ca_ion = 2.0")

        h.load_file("DD1.hoc")
        a_DD1 = []
        h("{ n_DD1 = 1 }")
        h("objectvar a_DD1[n_DD1]")
        for i in range(int(h.n_DD1)):
            h("a_DD1[%i] = new DD1()"%i)
            h("access a_DD1[%i].Soma"%i)

            self.next_global_id+=1

        h("{ a_DD1[0].position(0.0, 0.0, 0.0) }")

        h("proc initialiseV_DD1() { for i = 0, n_DD1-1 { a_DD1[i].set_initial_v() } }")
        h("objref fih_DD1")
        h('{fih_DD1 = new FInitializeHandler(0, "initialiseV_DD1()")}')

        h("proc initialiseIons_DD1() { for i = 0, n_DD1-1 { a_DD1[i].set_initial_ion_properties() } }")
        h("objref fih_ion_DD1")
        h('{fih_ion_DD1 = new FInitializeHandler(1, "initialiseIons_DD1()")}')

        # ######################   Projection: NC_DB1_DD1_Acetylcholine
        print("Adding projection: NC_DB1_DD1_Acetylcholine, from DB1 to DD1 with synapse neuron_to_neuron_exc_syn, 1 connection(s)")

        h("objectvar syn_NC_DB1_DD1_Acetylcholine_neuron_to_neuron_exc_syn[1]")

        h("objectvar netConn_NC_DB1_DD1_Acetylcholine_neuron_to_neuron_exc_syn[1]")

        # Connection 0: cell 0, seg 0 (0.5) [0.5 on a_DB1[0].Soma] -> cell 0, seg 0 (0.5) [0.5 on a_DD1[0].Soma], weight: 10.0, delay 0.0
        h("a_DD1[0].Soma syn_NC_DB1_DD1_Acetylcholine_neuron_to_neuron_exc_syn[0] = new neuron_to_neuron_exc_syn(0.5)")
        h("a_DB1[0].Soma a_DD1[0].synlist.append(new NetCon(&v(0.5), syn_NC_DB1_DD1_Acetylcholine_neuron_to_neuron_exc_syn[0], -26.0, 0.0, 10.0))")

        # ######################   Electrical Projection: NC_AVBR_DB1_Generic_GJ
        print("Adding electrical projection: NC_AVBR_DB1_Generic_GJ from AVBR to DB1, with 1 connection(s)")

        h("objectvar syn_NC_AVBR_DB1_Generic_GJ_neuron_to_neuron_elec_syn_A[1]")
        h("objectvar syn_NC_AVBR_DB1_Generic_GJ_neuron_to_neuron_elec_syn_B[1]")

        # Elect Connection 0: cell 0, seg 0 (0.5) [0.5 on a_AVBR[0].Soma] -> cell 0, seg 0 (0.5) [0.5 on a_DB1[0].Soma], weight: 3.0
        h("a_AVBR[0].Soma { syn_NC_AVBR_DB1_Generic_GJ_neuron_to_neuron_elec_syn_A[0] = new neuron_to_neuron_elec_syn(0.5) }")
        h("a_DB1[0].Soma { syn_NC_AVBR_DB1_Generic_GJ_neuron_to_neuron_elec_syn_B[0] = new neuron_to_neuron_elec_syn(0.5) }")
        h("a_AVBR[0].Soma { syn_NC_AVBR_DB1_Generic_GJ_neuron_to_neuron_elec_syn_A[0].weight = 3.0 }")
        h("a_DB1[0].Soma { syn_NC_AVBR_DB1_Generic_GJ_neuron_to_neuron_elec_syn_B[0].weight = 3.0 }")
        h("setpointer syn_NC_AVBR_DB1_Generic_GJ_neuron_to_neuron_elec_syn_A[0].vpeer, a_DB1[0].Soma.v(0.5)")
        h("setpointer syn_NC_AVBR_DB1_Generic_GJ_neuron_to_neuron_elec_syn_B[0].vpeer, a_AVBR[0].Soma.v(0.5)")

        # ######################   Electrical Projection: NC_AVBR_DD1_Generic_GJ
        print("Adding electrical projection: NC_AVBR_DD1_Generic_GJ from AVBR to DD1, with 1 connection(s)")

        h("objectvar syn_NC_AVBR_DD1_Generic_GJ_neuron_to_neuron_elec_syn_A[1]")
        h("objectvar syn_NC_AVBR_DD1_Generic_GJ_neuron_to_neuron_elec_syn_B[1]")

        # Elect Connection 0: cell 0, seg 0 (0.5) [0.5 on a_AVBR[0].Soma] -> cell 0, seg 0 (0.5) [0.5 on a_DD1[0].Soma], weight: 1.0
        h("a_AVBR[0].Soma { syn_NC_AVBR_DD1_Generic_GJ_neuron_to_neuron_elec_syn_A[0] = new neuron_to_neuron_elec_syn(0.5) }")
        h("a_DD1[0].Soma { syn_NC_AVBR_DD1_Generic_GJ_neuron_to_neuron_elec_syn_B[0] = new neuron_to_neuron_elec_syn(0.5) }")
        h("setpointer syn_NC_AVBR_DD1_Generic_GJ_neuron_to_neuron_elec_syn_A[0].vpeer, a_DD1[0].Soma.v(0.5)")
        h("setpointer syn_NC_AVBR_DD1_Generic_GJ_neuron_to_neuron_elec_syn_B[0].vpeer, a_AVBR[0].Soma.v(0.5)")

        # ######################   Electrical Projection: NC_DB1_AVBR_Generic_GJ
        print("Adding electrical projection: NC_DB1_AVBR_Generic_GJ from DB1 to AVBR, with 1 connection(s)")

        h("objectvar syn_NC_DB1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_A[1]")
        h("objectvar syn_NC_DB1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_B[1]")

        # Elect Connection 0: cell 0, seg 0 (0.5) [0.5 on a_DB1[0].Soma] -> cell 0, seg 0 (0.5) [0.5 on a_AVBR[0].Soma], weight: 3.0
        h("a_DB1[0].Soma { syn_NC_DB1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_A[0] = new neuron_to_neuron_elec_syn(0.5) }")
        h("a_AVBR[0].Soma { syn_NC_DB1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_B[0] = new neuron_to_neuron_elec_syn(0.5) }")
        h("a_DB1[0].Soma { syn_NC_DB1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_A[0].weight = 3.0 }")
        h("a_AVBR[0].Soma { syn_NC_DB1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_B[0].weight = 3.0 }")
        h("setpointer syn_NC_DB1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_A[0].vpeer, a_AVBR[0].Soma.v(0.5)")
        h("setpointer syn_NC_DB1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_B[0].vpeer, a_DB1[0].Soma.v(0.5)")

        # ######################   Electrical Projection: NC_DD1_AVBR_Generic_GJ
        print("Adding electrical projection: NC_DD1_AVBR_Generic_GJ from DD1 to AVBR, with 1 connection(s)")

        h("objectvar syn_NC_DD1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_A[1]")
        h("objectvar syn_NC_DD1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_B[1]")

        # Elect Connection 0: cell 0, seg 0 (0.5) [0.5 on a_DD1[0].Soma] -> cell 0, seg 0 (0.5) [0.5 on a_AVBR[0].Soma], weight: 1.0
        h("a_DD1[0].Soma { syn_NC_DD1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_A[0] = new neuron_to_neuron_elec_syn(0.5) }")
        h("a_AVBR[0].Soma { syn_NC_DD1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_B[0] = new neuron_to_neuron_elec_syn(0.5) }")
        h("setpointer syn_NC_DD1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_A[0].vpeer, a_AVBR[0].Soma.v(0.5)")
        h("setpointer syn_NC_DD1_AVBR_Generic_GJ_neuron_to_neuron_elec_syn_B[0].vpeer, a_DD1[0].Soma.v(0.5)")

        print("Processing 1 input lists")

        # ######################   Input List: Input_AVBR_offset_current
        # Adding single input: Component(id=0 type=input)
        h("objref Input_AVBR_offset_current_0")
        h("a_AVBR[0].Soma { Input_AVBR_offset_current_0 = new offset_current(0.5) } ")

        print("Finished processing 1 input lists")

        trec = h.Vector()
        trec.record(h._ref_t)

        h.tstop = tstop

        h.dt = dt

        h.steps_per_ms = 1/h.dt

        # ######################   Display: self.display_neurons
        self.display_neurons = h.Graph(0)
        self.display_neurons.size(0,h.tstop,-80.0,50.0)
        self.display_neurons.view(0, -80.0, h.tstop, 130.0, 80, 330, 330, 250)
        h.graphList[0].append(self.display_neurons)
        # Line, plotting: AVBR/0/AVBR/v
        self.display_neurons.addexpr("a_AVBR[0].Soma.v(0.5)", "a_AVBR[0].Soma.v(0.5)", 1, 1, 0.8, 0.9, 2)
        # Line, plotting: DB1/0/DB1/v
        self.display_neurons.addexpr("a_DB1[0].Soma.v(0.5)", "a_DB1[0].Soma.v(0.5)", 2, 1, 0.8, 0.9, 2)
        # Line, plotting: DD1/0/DD1/v
        self.display_neurons.addexpr("a_DD1[0].Soma.v(0.5)", "a_DD1[0].Soma.v(0.5)", 3, 1, 0.8, 0.9, 2)

        # ######################   Display: self.display_activity_neurons
        self.display_activity_neurons = h.Graph(0)
        self.display_activity_neurons.size(0,h.tstop,-80.0,50.0)
        self.display_activity_neurons.view(0, -80.0, h.tstop, 130.0, 80, 330, 330, 250)
        h.graphList[0].append(self.display_activity_neurons)
        # Line, plotting: AVBR/0/AVBR/caConc
        self.display_activity_neurons.addexpr("a_AVBR[0].Soma.cai(0.5)", "a_AVBR[0].Soma.cai(0.5)", 1, 1, 0.8, 0.9, 2)
        # Line, plotting: DB1/0/DB1/caConc
        self.display_activity_neurons.addexpr("a_DB1[0].Soma.cai(0.5)", "a_DB1[0].Soma.cai(0.5)", 2, 1, 0.8, 0.9, 2)
        # Line, plotting: DD1/0/DD1/caConc
        self.display_activity_neurons.addexpr("a_DD1[0].Soma.cai(0.5)", "a_DD1[0].Soma.cai(0.5)", 3, 1, 0.8, 0.9, 2)



        # ######################   File to save: AVBR_DB1_DD1_8_7.activity.dat (neurons_activity)
        # Column: AVBR/0/AVBR/caConc
        h(' objectvar v_AVBR_v_neurons_activity ')
        h(' { v_AVBR_v_neurons_activity = new Vector() } ')
        h(' { v_AVBR_v_neurons_activity.record(&a_AVBR[0].Soma.cai(0.5)) } ')
        h.v_AVBR_v_neurons_activity.resize((h.tstop * h.steps_per_ms) + 1)
        # Column: DB1/0/DB1/caConc
        h(' objectvar v_DB1_v_neurons_activity ')
        h(' { v_DB1_v_neurons_activity = new Vector() } ')
        h(' { v_DB1_v_neurons_activity.record(&a_DB1[0].Soma.cai(0.5)) } ')
        h.v_DB1_v_neurons_activity.resize((h.tstop * h.steps_per_ms) + 1)
        # Column: DD1/0/DD1/caConc
        h(' objectvar v_DD1_v_neurons_activity ')
        h(' { v_DD1_v_neurons_activity = new Vector() } ')
        h(' { v_DD1_v_neurons_activity.record(&a_DD1[0].Soma.cai(0.5)) } ')
        h.v_DD1_v_neurons_activity.resize((h.tstop * h.steps_per_ms) + 1)

        # ######################   File to save: AVBR_DB1_DD1_8_7.dat (neurons_v)
        # Column: AVBR/0/AVBR/v
        h(' objectvar v_AVBR_v_neurons_v ')
        h(' { v_AVBR_v_neurons_v = new Vector() } ')
        h(' { v_AVBR_v_neurons_v.record(&a_AVBR[0].Soma.v(0.5)) } ')
        h.v_AVBR_v_neurons_v.resize((h.tstop * h.steps_per_ms) + 1)
        # Column: DB1/0/DB1/v
        h(' objectvar v_DB1_v_neurons_v ')
        h(' { v_DB1_v_neurons_v = new Vector() } ')
        h(' { v_DB1_v_neurons_v.record(&a_DB1[0].Soma.v(0.5)) } ')
        h.v_DB1_v_neurons_v.resize((h.tstop * h.steps_per_ms) + 1)
        # Column: DD1/0/DD1/v
        h(' objectvar v_DD1_v_neurons_v ')
        h(' { v_DD1_v_neurons_v = new Vector() } ')
        h(' { v_DD1_v_neurons_v.record(&a_DD1[0].Soma.v(0.5)) } ')
        h.v_DD1_v_neurons_v.resize((h.tstop * h.steps_per_ms) + 1)

        # ######################   File to save: time.dat (time)
        # Column: time
        h(' objectvar v_time ')
        h(' { v_time = new Vector() } ')
        h(' { v_time.record(&t) } ')
        h.v_time.resize((h.tstop * h.steps_per_ms) + 1)

        self.initialized = False

        self.sim_end = -1 # will be overwritten

        setup_end = time.time()
        self.setup_time = setup_end - self.setup_start
        print("Setting up the network to simulate took %f seconds"%(self.setup_time))

        h.nrncontrolmenu()


    def run(self):

        self.initialized = True
        sim_start = time.time()
        print("Running a simulation of %sms (dt = %sms; seed=%s)" % (h.tstop, h.dt, self.seed))

        try:
            h.run()
        except Exception as e:
            print("Exception running NEURON: %s" % (e))
            return


        self.sim_end = time.time()
        self.sim_time = self.sim_end - sim_start
        print("Finished NEURON simulation in %f seconds (%f mins)..."%(self.sim_time, self.sim_time/60.0))

        try:
            self.save_results()
        except Exception as e:
            print("Exception saving results of NEURON simulation: %s" % (e))
            return


    def advance(self):

        if not self.initialized:
            h.finitialize()
            self.initialized = True

        h.fadvance()


    ###############################################################################
    # Hash function to use in generation of random value
    # This is copied from NetPyNE: https://github.com/Neurosim-lab/netpyne/blob/master/netpyne/simFuncs.py
    ###############################################################################
    def _id32 (self,obj): 
        return int(hashlib.md5(obj.encode('utf-8')).hexdigest()[0:8],16)  # convert 8 first chars of md5 hash in base 16 to int


    ###############################################################################
    # Initialize the stim randomizer
    # This is copied from NetPyNE: https://github.com/Neurosim-lab/netpyne/blob/master/netpyne/simFuncs.py
    ###############################################################################
    def _init_stim_randomizer(self,rand, stimType, gid, seed): 
        #print("INIT STIM  %s; %s; %s; %s"%(rand, stimType, gid, seed))
        rand.Random123(self._id32(stimType), gid, seed)


    def save_results(self):

        print("Saving results at t=%s..."%h.t)

        if self.sim_end < 0: self.sim_end = time.time()

        self.display_neurons.exec_menu("View = plot")
        self.display_activity_neurons.exec_menu("View = plot")

        # ######################   File to save: time.dat (time)
        py_v_time = [ t/1000 for t in h.v_time.to_python() ]  # Convert to Python list for speed...

        f_time_f2 = open('time.dat', 'w')
        num_points = len(py_v_time)  # Simulation may have been stopped before tstop...

        for i in range(num_points):
            f_time_f2.write('%f'% py_v_time[i])  # Save in SI units...
        f_time_f2.close()
        print("Saved data to: time.dat")

        # ######################   File to save: AVBR_DB1_DD1_8_7.activity.dat (neurons_activity)
        py_v_AVBR_v_neurons_activity = [ float(x ) for x in h.v_AVBR_v_neurons_activity.to_python() ]  # Convert to Python list for speed, variable has dim: concentration
        py_v_DB1_v_neurons_activity = [ float(x ) for x in h.v_DB1_v_neurons_activity.to_python() ]  # Convert to Python list for speed, variable has dim: concentration
        py_v_DD1_v_neurons_activity = [ float(x ) for x in h.v_DD1_v_neurons_activity.to_python() ]  # Convert to Python list for speed, variable has dim: concentration

        f_neurons_activity_f2 = open('AVBR_DB1_DD1_8_7.activity.dat', 'w')
        num_points = len(py_v_time)  # Simulation may have been stopped before tstop...

        for i in range(num_points):
            f_neurons_activity_f2.write('%e\t%e\t%e\t%e\t\n' % (py_v_time[i], py_v_AVBR_v_neurons_activity[i], py_v_DB1_v_neurons_activity[i], py_v_DD1_v_neurons_activity[i], ))
        f_neurons_activity_f2.close()
        print("Saved data to: AVBR_DB1_DD1_8_7.activity.dat")

        # ######################   File to save: AVBR_DB1_DD1_8_7.dat (neurons_v)
        py_v_AVBR_v_neurons_v = [ float(x  / 1000.0) for x in h.v_AVBR_v_neurons_v.to_python() ]  # Convert to Python list for speed, variable has dim: voltage
        py_v_DB1_v_neurons_v = [ float(x  / 1000.0) for x in h.v_DB1_v_neurons_v.to_python() ]  # Convert to Python list for speed, variable has dim: voltage
        py_v_DD1_v_neurons_v = [ float(x  / 1000.0) for x in h.v_DD1_v_neurons_v.to_python() ]  # Convert to Python list for speed, variable has dim: voltage

        f_neurons_v_f2 = open('AVBR_DB1_DD1_8_7.dat', 'w')
        num_points = len(py_v_time)  # Simulation may have been stopped before tstop...

        for i in range(num_points):
            f_neurons_v_f2.write('%e\t%e\t%e\t%e\t\n' % (py_v_time[i], py_v_AVBR_v_neurons_v[i], py_v_DB1_v_neurons_v[i], py_v_DD1_v_neurons_v[i], ))
        f_neurons_v_f2.close()
        print("Saved data to: AVBR_DB1_DD1_8_7.dat")

        save_end = time.time()
        save_time = save_end - self.sim_end
        print("Finished saving results in %f seconds"%(save_time))

        print("Done")

if __name__ == '__main__':

    ns = NeuronSimulation(tstop=300.0, dt=0.01, seed=123456789)

    ns.run()

