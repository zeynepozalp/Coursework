Put this directory under your project directory.

./build.sh should run make clean and make all on everything.
run tests with
>> mdb <test.dbg>

except the adc_test.dbg

Available tests are

initconfigs.dbg: a convenient file that helps you quickly interactive debug by presetting some configs.
mdb goes into interactive mode after it executes.

rb4_stress_test: checks rb4 button against debouncing in real life. Also holds rb4
button to see if that stops program execution. The rb4_handled break must happen once
per stimulus (after stim xxxx.scl commands)

game_over_test.dbg: checks if game is over after 5 secs (inspect the stopwatch value!)

hs_passed_consistency_test.dbg: checks if second_passed break happens every 500ms.

correct_guess.dbg: checks the general program execution, where
The special number is assumed to be 4
Then it is undershot by an adc read equivalent to digit 0
Then it is overshot by an adc read equivalent to digit 9
Then it is correctly guessed.
At this point, PORTCDE should be checked to ensure that they draw the correct arrow symbols.
Then PORTJH are checked to ensure that they blink every other 500ms.

adc_test.dbg: Checks if the adc is working correctly and plots a sampling graph (optional).
To plot the graph you must have python3 and matplotlib installed:
Then run
>> mdb adc_test.dbg > adc_test.log
>> python3 plot_sinewave.py
