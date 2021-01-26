import arbor
import pandas
import seaborn


# Create a class that inherits from arbor.recipe
class single_recipe (arbor.recipe):

    # (2) Define the class constructor
    def __init__(self, cell, probes):
        # The base C++ class constructor must be called first to ensure that all memory
        # in the C++ class is initialised correctly
        arbor.recipe.__init__(self)
        self.the_cell = cell
        self.the_probes = probes

        self.the_cat = arbor.default_catalogue()

        self.the_props = arbor.cable_global_properties()
        self.the_props.set_property(Vm = -45, cm = 0.01, rL = 12000)
        self.the_props.set_ion(ion='na', int_con=10, ext_con=140, rev_pot=50, method='nernst/na')
        self.the_props.set_ion(ion='k', int_con=54.4, ext_con=2.5, rev_pot=-77)
        self.the_props.set_ion(ion='ca', int_con=5e-5, ext_con=2, rev_pot=132.5)

        #self.the_props.register(self.the_cat)


    # (3) Override the num_cells method
    def num_cells(self):
        return 1

    # (4) Override the num_sources method
    def num_sources(self, gid):
        return 1

    # (5) Override the num_targets method
    def num_targets(self, gid):
        return 0

    # (6) Override the num_targets method
    def cell_kind(self, gid):
        return arbor.cell_kind.cable

    # (7) Override the cell_description method
    def cell_description(self, gid):
        return self.the_cell

    # (8) Override the probes method
    def get_probes(self, gid):
        return self.the_probes

    # (9) Override the connections_on method
    def connections_on(self, gid):
        return []

    # (10) Override the gap_junction_on method
    def gap_junction_on(self, gid):
        return []

    # (11) Override the event_generators method
    def event_generators(self, gid):
        return []

    # (12) Overrode the global_properties method
    def global_properties(self, gid):
        return self.the_props


# (1) Define morphology of DD1 cell.
# (1.1) Create a segment tree and add segments.
tree = arbor.segment_tree()

# Soma (tag = 0) with diameter 4.20119 μm, modelled as cylinder of height 4.20119 µm and radius 2.100595 µm
# arbor.mpoint(x, y, z, radius)
s0_0 = tree.append(arbor.mnpos, arbor.mpoint(-0.9, -231.95, 6.85, 4.20119 / 2), arbor.mpoint(-0.9, -227.74881, 6.85, 4.20119 / 2), tag=0)

# describe Axon (tag=1) attached to soma
# naming of segments ax_y with a = axon, x = number of axon segment, y = neuroML segment ID
a0_7 = tree.append(s0_0,  arbor.mpoint(-9.000000e-01, -2.319500e+02, 6.850000e+00, 0.5918224163929164 / 2), arbor.mpoint(-9.000000e-01, -2.331500e+02, 7.700000e+00, 0.5918224163929164/2), tag=1)
a1_8 = tree.append(a0_7, arbor.mpoint(-9.000000e-01, -2.365500e+02, 1.020000e+01, 0.5918224163929164 / 2), tag=1)
a2_9 = tree.append(a1_8, arbor.mpoint(-9.000000e-01, -2.425500e+02, 1.470000e+01, 0.5918224163929164 / 2), tag=1)
a3_10 = tree.append(a2_9, arbor.mpoint(5.500000e-01, -2.436000e+02, 1.470000e+01, 0.5918224163929164 / 2), tag=1)
a4_11 = tree.append(a3_10, arbor.mpoint(2.900000e+00, -2.436000e+02, 1.470000e+01, 0.5918224163929164 / 2), tag=1)
a5_12 = tree.append(a4_11, arbor.mpoint(6.975000e+00, -2.435250e+02, 1.517500e+01, 0.5918224163929164 / 2), tag=1)
a6_13 = tree.append(a5_12, arbor.mpoint(1.420000e+01, -2.421500e+02, 1.920000e+01, 0.5918224163929164 / 2), tag=1)
a7_14 = tree.append(a6_13, arbor.mpoint(1.792500e+01, -2.400500e+02, 2.560000e+01, 0.5918224163929164 / 2), tag=1)
a8_15 = tree.append(a7_14, arbor.mpoint(1.950000e+01, -2.378000e+02, 3.232500e+01, 0.5918224163929164 / 2), tag=1)
a9_16 = tree.append(a8_15, arbor.mpoint(1.792500e+01, -2.355500e+02, 3.907500e+01, 0.5918224163929164 / 2), tag=1)
a10_17 = tree.append(a9_16, arbor.mpoint(1.420000e+01, -2.334500e+02, 4.550000e+01, 0.5918224163929164 / 2), tag=1)
a11_18 = tree.append(a10_17, arbor.mpoint(6.975000e+00, -2.321000e+02, 4.952500e+01, 0.5918224163929164 / 2), tag=1)
a12_19 = tree.append(a11_18, arbor.mpoint(2.900000e+00, -2.319500e+02, 4.990000e+01, 0.5918224163929164 / 2), tag=1)
a13_20 = tree.append(a12_19, arbor.mpoint(-1.000000e-01, -2.322000e+02, 4.902500e+01, 0.5918224163929164 / 2), tag=1)
a14_21 = tree.append(a12_19, arbor.mpoint(-5.000000e-01, -2.321750e+02, 4.900000e+01, 0.5918224163929164 / 2), tag=1)

# describe dendrite_2 (tag 2) attached to the soma
# naming of segments dend2_x_y with dend2 = dendrite 2, x = number of dendrite segment, y = neuroML segment ID
dend2_0_1 = tree.append(s0_0, arbor.mpoint(-9.000000e-01, -2.319500e+02, 6.850000e+00, 0.49040240753269165 / 2), arbor.mpoint(-9.000000e-01, -2.307500e+02, 6.000000e+00, 0.49040240753269165 / 2), tag=2)
dend2_1_2 = tree.append(dend2_0_1, arbor.mpoint(-1.450000e+00, -2.265000e+02, 2.850000e+00, 0.49040240753269165 / 2), tag=2)
dend2_2_3 = tree.append(dend2_1_2, arbor.mpoint(-1.450000e+00, -2.149500e+02, -5.250000e+00, 0.49040240753269165 / 2), tag=2)
dend2_3_4 = tree.append(dend2_2_3, arbor.mpoint(-1.450000e+00, -2.102000e+02, -8.400000e+00, 0.49040240753269165 / 2), tag=2)
dend2_4_5 = tree.append(dend2_3_4, arbor.mpoint(-1.450000e+00, -1.968000e+02, -1.760000e+01, 0.49040240753269165 / 2), tag=2)
dend2_5_6 = tree.append(dend2_4_5, arbor.mpoint(-1.450000e+00, -1.947500e+02, -1.895000e+01, 0.49040240753269165 / 2), tag=2)

# describe neurite_3 (tag 3) attached to axon
# naming of segments neur3_x_y with neur3 = neurite 3, x = number of neurite segment, y = neuroML segment ID
neur3_0_22 = tree.append(a14_21, arbor.mpoint(-5.000000e-01, -2.321750e+02, 4.900000e+01, 0.5836462148750231 / 2), arbor.mpoint(-7.000000e-01, -2.325000e+02, 4.910000e+01, 0.5836462148750231 / 2), tag=3)
neur3_1_23 = tree.append(neur3_0_22, arbor.mpoint(-7.000000e-01, -2.363500e+02, 5.060000e+01, 0.5836462148750231 / 2), tag=3)
neur3_2_24 = tree.append(neur3_1_23, arbor.mpoint(-7.000000e-01, -2.377500e+02, 5.105000e+01, 0.5836462148750231 / 2), tag=3)

# describe neurite_4 (tag 4) attached to axon
# naming of segments neur4_x_y with neur4 = neurite 4, x = number of neurite segment, y = neuroML segment ID
neur4_0_25 = tree.append(a14_21, arbor.mpoint(-5.000000e-01, -2.321750e+02, 4.900000e+01, 0.5747685124121756 / 2), arbor.mpoint(-7.000000e-01, -2.318500e+02, 4.890000e+01, 0.5747685124121756 / 2), tag=4)
neur4_1_26 = tree.append(neur4_0_25, arbor.mpoint(-7.000000e-01, -2.107500e+02, 4.070000e+01, 0.5747685124121756 / 2), tag=4)
neur4_2_27 = tree.append(neur4_1_26, arbor.mpoint(-7.000000e-01, -2.059500e+02, 3.770000e+01, 0.5747685124121756 / 2), tag=4)
neur4_3_28 = tree.append(neur4_2_27, arbor.mpoint(-7.000000e-01, -1.762500e+02, 1.840000e+01, 0.5747685124121756 / 2), tag=4)
neur4_4_29 = tree.append(neur4_3_28, arbor.mpoint(-7.000000e-01, -1.740500e+02, 1.700000e+01, 0.5747685124121756 / 2), tag=4)

# (1.2) Create cell morphology from segment tree.
morph = arbor.morphology(tree)

# (2) Create and populate the label dictionary.
labels = arbor.label_dict()

# Regions
labels['soma']    = '(tag 0)'
labels['axon']    = '(tag 1)'
labels['dend_2']  = '(tag 2)'
labels['neur_3']  = '(tag 3)'
labels['neur_4']  = '(tag 4)'

labels['center']  = '(location 0 0.5)'
labels['all'] = '(all)'


# Define stimulation at center of soma from t = 100 ms until t = 400 ms.
# values: 0 pA - 15 pA, steps: 1 pA
offset_values = [0.0, 0.001, 0.002, 0.003, 0.004, 0.005, 0.006, 0.007, 0.008, 0.009, 0.01, 0.011, 0.012, 0.013,
                 0.014, 0.015]




for j, value in enumerate(offset_values):

    # (3) Create and populate the decor.
    decor = arbor.decor()

    # Set properties of the cell.
    # neuroML: <specificCapacitance value="1 uF_per_cm2"/>, <initMembPotential value="-45 mV"/>, <resistivity value="12 kohm_cm"/>
    # Vm = initial membrane potential (-45 mV)
    # cm = membrane capacitance (0.01 F / m²)
    # rL = axial resistivity of cable (12000 Ohm * cm)
    # tempK = temperature in Kelvin (not provided by c302)
    decor.set_property(Vm=-45, cm=0.01, rL=12000)

    # Paint density mechanisms. In the c302 approximation the C. elegans cell is assumed to possess mechanisms that are the same throughout
    # the cell membrane.
    decor.paint('"all"', 'Leak')
    decor.paint('"all"', 'k_slow')
    decor.paint('"all"', 'k_fast')
    decor.paint('"all"', 'CaPoolTH')
    decor.paint('"all"', 'ca_boyle')

    # Set calcium ion concentration.
    decor.set_ion('ca', int_con=0, ext_con=2.0)


    # Place stimulus and a spike detector.
    # Stimulation at the center of the soma from t = 100 ms until t = 400 ms.
    # offset current "value"
    decor.place('"center"', arbor.iclamp(100, 300, value))

    # Spike detection at center of soma.
    decor.place('"center"', arbor.spike_detector(-26))

    #define CV policy and add it to decor
    #policy = arbor.cv_policy_every_segment('(all)')
    policy = arbor.cv_policy_fixed_per_branch(1, '(all)')
    #policy = arbor.cv_policy_max_extent(1.0)
    decor.discretization(policy)

    # (4) Create cell.
    dd1_cell = arbor.cable_cell(morph, labels, decor)

    # (5) Create probes for membrane voltage and calcium ion concentration.
    voltage_probe = arbor.cable_probe_membrane_voltage('"center"')
    ca_conc_probe = arbor.cable_probe_ion_int_concentration('"center"', "ca")


    # Instantiate recipe
    # Pass the probe in a list because that it what single_recipe expects.
    #recipe = single_recipe(dd1_cell, [voltage_probe]) #, ca_conc_probe])
    recipe = single_recipe(dd1_cell, [voltage_probe, ca_conc_probe])

    context = arbor.context()

    domains = arbor.partition_load_balance(recipe, context)

    sim = arbor.simulation(recipe, domains, context)

    # Instruct the simulation to record the spikes
    sim.record(arbor.spike_recording.all)

    # Instruct the simulation to sample the probe (0, 0)
    # at a regular schedule with period = 0.1 ms (1000 Hz)
    voltage_probe_id = arbor.cell_member(0,0)
    ca_conc_probe_id = arbor.cell_member(0,1)

    volt_handle = sim.sample(voltage_probe_id, arbor.regular_schedule(0.1))
    ca_conc_handle = sim.sample(ca_conc_probe_id, arbor.regular_schedule(0.1))

    handles = [volt_handle, ca_conc_handle]

    sim.run(tfinal=500, dt=0.1)

    spikes = sim.spikes()

    # Print the number of spikes.
    print(len(spikes), 'spikes recorded:')

    # Print the spike times.
    for s in spikes:
        print(s)

    volt_data = []
    volt_meta = []
    for d, m in sim.samples(volt_handle):
       volt_data.append(d)
       volt_meta.append(m)

    conc_data = []
    conc_meta = []
    for d, m in sim.samples(ca_conc_handle):
       conc_data.append(d)
       conc_meta.append(m)

    df = pandas.DataFrame()
    for i in range(len(volt_data)):
        df = df.append(pandas.DataFrame({'t/ms': volt_data[i][:, 0], 'U/mV': volt_data[i][:, 1], '[Ca] / mM':conc_data[i][:, 1], 'Location': str(volt_meta[i])}))
        #df = df.append(pandas.DataFrame({'t/ms': data[i][:, 0], 'U/mV': data[i][:, 1], 'Ca/mM':data[i][:, 2], 'Location': str(meta[i])}))

    print(df.head())

    #seaborn.relplot(data=df, kind="line", x="t/ms", y="U/mV", hue="Location", col="Variable", ci=None).savefig('single_cell_detailed_recipe_result.svg')
    seaborn.relplot(data=df, kind="line", x="t/ms", y="U/mV", hue="Location", ci=None).savefig('single_cell_detailed_recipe_voltage_result_' + str(j) + '_0.svg')
    seaborn.relplot(data=df, kind="line", x="t/ms", y="[Ca] / mM", hue="Location", ci=None).savefig('single_cell_detailed_recipe_ca_conc_result_' + str(j) + '_0.svg')

    # Store results for later processing.
    df.to_csv('DD1_with_recipe_results_' + str(j) + '_0.csv', float_format='%g')