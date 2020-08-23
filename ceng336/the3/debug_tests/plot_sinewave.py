import re
import matplotlib.pyplot as plt
from itertools import accumulate
from statistics import mean,stdev

adc_value_prog = re.compile(r'^adc_value=\n(?P<value>[0-9]*)$',re.M)
stopwatch_prog = re.compile(r'Stopwatch cycle count = (?P<value>[0-9]*)')

with open('adc_test.log','r') as f:
    logstring = f.read()
with open('sinewave.dat') as f:
    pin_values = [int(i[:-4]) for i in f.readlines()]

adc_values = [float(i)*5000/1024 for i in adc_value_prog.findall(logstring)]
stopwatch_values = [float(i)*1e-4 for i in stopwatch_prog.findall(logstring)]
print('adc sampling period mean:', mean(stopwatch_values),'ms')
pin_times = list(range(0,2000))
print('adc sampling period stddev:', stdev(stopwatch_values),'ms')
plt.plot(pin_times,pin_values,color='red',label='AN12 Analog Value')
plt.stem(list(accumulate(stopwatch_values)),adc_values,label='ADC Converted Value')
plt.xlabel('t (ms)')
plt.ylabel('V (mV)')
plt.xlim(0,2000)
plt.ylim(0,6000)
plt.legend(loc='upper right')
plt.show()
