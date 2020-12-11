import arbor as arb
import pandas as pd
import seaborn as sns
import numpy as np
import matplotlib.pyplot as plt

tree = arb.segment_tree()
# Soma (tag = 0) with diameter 4.20119 μm, modelled as cylinder of height 4.20119 µm and radius 2.100595 µm
s0_0 = tree.append(arb.mnpos, arb.mpoint(-0.9, -231.95, 6.85, 4.20119 / 2), arb.mpoint(-0.9, -227.74881, 6.85, 4.20119 / 2), tag=0)

# Associate labels to tags
labels = arb.label_dict({'soma':   '(tag 0)',
                         'axon':   '(tag 1)',
                         'dend_2': '(tag 2)',
                         'neur_3': '(tag 3)',
                         'neur_4': '(tag 4)',
                         'center': '(location 0 0.5)',})

morph = arb.morphology(tree)
dd1_cell = arb.cable_cell(morph, labels)
#dd1_cell.compartments_length(20) # discretisation strategy: max compartment length (um)
dd1_cell.set_properties(Vm = -45, cm = 0.01, rL = 12000)

# neuroML: <channelDensity id="Leak_all" ionChannel="Leak" condDensity="0.02 mS_per_cm2" erev="-50 mV" ion="non_specific"/>
# neuroML: <channelDensity id="k_slow_all" ionChannel="k_slow" condDensity="2 mS_per_cm2" erev="-60 mV" ion="k"/>
# neuroML: <channelDensity id="k_fast_all" ionChannel="k_fast" condDensity="0.2 mS_per_cm2" erev="-60 mV" ion="k"/>
# neuroML: <species id="ca" concentrationModel="CaPool" ion="ca" initialConcentration="0 mM" initialExtConcentration="2E-6 mol_per_cm3"/>
dd1_cell.set_ion('ca', int_con=0.0, ext_con=2.0)
#cell.set_ion('ca', int_con=5e-5, ext_con=2.0, method=arb.mechanism('nernst/x=ca'))
# neuroML: <channelDensity id="ca_boyle_all" ionChannel="ca_boyle" condDensity="2 mS_per_cm2" erev="40 mV" ion="ca"/>

dd1_cell.paint('"soma"', 'Leak')
dd1_cell.paint('"soma"', 'k_slow')
dd1_cell.paint('"soma"', 'k_fast')
dd1_cell.paint('"soma"', 'CaPoolTH')
dd1_cell.paint('"soma"', 'ca_boyle')

dd1_cell.place('"center"', arb.iclamp(100, 300, 0.007))  #0.001
dd1_cell.place('"center"', arb.spike_detector(-26))

m = arb.single_cell_model(dd1_cell)
m.probe('voltage', '"center"', frequency=100000)
m.run(tfinal=500)

df = pd.DataFrame({'t/ms': m.traces[0].time, 'U/mV': m.traces[0].value})

#ref = pd.read_table('/home/kharms/c302/test_cell_just_soma/DD1_7_0.dat', usecols=[0, 1], header=None, names=['t/ms', 'U/mV'])
#ref = pd.read_table("/home/kharms/c302/test_cell_just_soma/DD1_7_0.dat", header = None)
#ref.dropna(axis = 1, inplace = True)
#ref.rename(columns = {0 : 't/ms', 1 : 'U/mV'}, inplace = True)
#print(ref)



fg, ax = plt.subplots()
#ref.plot(ax=ax, x='t/ms', y='U/mV', label='Reference', linewidth = 2)
df.plot(ax=ax, x='t/ms', y='U/mV', label='Arbor')
fg.savefig('worm-dd1.pdf')

