import neuron
from neuron import h, gui
import pprint
from neuron.units import ms, mV
import matplotlib.pyplot as plt
import pandas as pd

print(neuron.__version__)

# define sections
soma = h.Section(name = 'soma')
axon = h.Section(name = 'axon')
dend2 = h.Section(name = 'dend2')
neur3 = h.Section(name = 'neur3')
neur4 = h.Section(name = 'neur4')




# define soma morphology
soma.pt3dclear()
soma.pt3dadd(-0.9, -231.95, 6.85, 4.20119)
soma.pt3dadd(-0.9, -227.74881, 6.85, 4.20119)

# define axon morphology
axon.pt3dclear()
axon.pt3dadd(-0.9, -231.95, 6.85, 0.78102493)
axon.pt3dadd(-0.9, -233.15, 7.7, 0.78102493)
axon.pt3dadd(-0.9, -236.55, 10.2, 0.64031243)
axon.pt3dadd(-0.9, -242.55, 14.7, 0.5744563)
axon.pt3dadd(0.55, -243.6, 14.7, 0.5744563)
axon.pt3dadd(2.9, -243.6, 14.7, 0.56568545)
axon.pt3dadd(6.975, -243.525, 15.175, 0.622495)
axon.pt3dadd(14.2, -242.15, 19.2, 0.5744563)
axon.pt3dadd(17.925, -240.05, 25.6, 0.5408327)
axon.pt3dadd(19.5, -237.8, 32.325, 0.60207975)
axon.pt3dadd(17.925, -235.55, 39.075, 0.50497526)
axon.pt3dadd(14.2, -233.45, 45.5, 0.5744563)
axon.pt3dadd(6.975, -232.1, 49.525, 0.81547534)
axon.pt3dadd(2.9, -231.95, 49.9, 0.36055514)
axon.pt3dadd(-0.1, -232.2, 49.025, 0.42720017)
axon.pt3dadd(-0.5, -232.175, 49.0, 0.68007356)

# define dend2 morphology
dend2.pt3dclear()
dend2.pt3dadd(-0.9, -231.95, 6.85, 0.64031243)
dend2.pt3dadd(-0.9, -230.75, 6.0, 0.64031243)
dend2.pt3dadd(-1.45, -226.5, 2.85, 0.46904156)
dend2.pt3dadd(-1.45, -214.95, -5.25, 0.4358899)
dend2.pt3dadd(-1.45, -210.2, -8.4, 0.5)
dend2.pt3dadd(-1.45, -196.8, -17.6, 0.5)
dend2.pt3dadd(-1.45, -194.75, -18.95, 0.4358899)

# define neur3 morphology
neur3.pt3dclear()
neur3.pt3dadd(-0.5, -232.175, 49.0, 0.68007356)
neur3.pt3dadd(-0.7, -232.5, 49.1, 0.56568545)
neur3.pt3dadd(-0.7, -236.35, 50.6, 0.5744563)
neur3.pt3dadd(-0.7, -237.75, 51.05, 0.6480741)

# define neur4 morphology
neur4.pt3dclear()
neur4.pt3dadd(-0.5, -232.175, 49.0, 0.68007356)
neur4.pt3dadd(-0.7, -231.85, 48.9, 0.5744563)
neur4.pt3dadd(-0.7, -210.75, 40.7, 0.5744563)
neur4.pt3dadd(-0.7, -205.95, 37.7, 0.5744563)
neur4.pt3dadd(-0.7, -176.25, 18.4, 0.5744563)
neur4.pt3dadd(-0.7, -174.05, 17.0, 0.5744563)

# connect sections
axon.connect(soma)
dend2.connect(soma)
neur3.connect(axon)
neur4.connect(axon)

# add all sections to a section list
all = h.SectionList()
all.append(soma)
all.append(axon)
all.append(dend2)
all.append(neur3)
all.append(neur4)


# add mechanisms
for section in all:
    # add mechanisms
    section.insert('Leak')
    section.gmax_Leak = 2.0E-5  # [S cm-2]
    section.e_Leak = -50.0      # [mV]

    section.insert('k_slow')
    section.gmax_k_slow = 0.0019999999   # [S cm-2]
    section.ek = -60.0                   # [mV]

    section.insert('k_fast')
    section.gmax_k_fast = 2.0E-4         # [S cm-2]
    section.ek = -60.0                   # [mV]

    section.insert('ca_boyle')
    section.gmax_ca_boyle = 0.0019999999   # [S cm-2]
    section.eca = 40.0                     # [mV]

    section.insert('CaPool')

    # set initial membrane potential [mV]
    section.v = -45.0

    # set initial calcium ion concentration [mM]
    section.cai = 0.0
    section.cao = 2.0

    # set specific axial resistance [ohm cm]
    section.Ra = 12000.0

    # set capacitance [uF cm-2]
    section.cm = 1.0

    print(section.name())
    print("diameter: ", section.diam, "\n")


iclamp = h.IClamp(soma(0.5))
iclamp.delay = 100
iclamp.dur = 300
iclamp.amp = 0.007


v = h.Vector().record(soma(0.5)._ref_v)             # Membrane potential vector
t = h.Vector().record(h._ref_t)                     # Time stamp vector

h.load_file('stdrun.hoc')
h.dt = 0.1
h.finitialize(-45 * mV)
h.continuerun(500 * ms)
h.tstop = 500
h.steps_per_ms = 1 / h.dt

mem_pot_data = pd.DataFrame(data = {"time [ms]" : t, "potential [mV]" : v})
print(mem_pot_data.head())

mem_pot_data.to_json('/home/kharms/Desktop/BA/difference_data/NEURON_Py_interface_7_0.json', double_precision=5)

#fig, ax = plt.subplots(1, 1, figsize = (15, 5))
#ax.plot(t, v)
#plt.show()

#print(len(t))


#print(soma.L)
#print(soma.diam)

h.topology()

