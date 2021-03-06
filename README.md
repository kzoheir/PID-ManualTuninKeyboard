# PID-ManualTuninKeyboard

Hello, PID tuning is tadious and requires both Manual and Automatted tuning (TWIDDLE for example)

Manual tuning is very important for 3 reasons:
* One way of Tuning the paraeters
* It gives a better understanding of the behacior of each componenet
* Used to explore different regions and may find a better local minima

It's alsways a good idea to use a combination of both, manual and then automated for find tuning

## The main issue with Manual tuning is:
* You may have to change the parameters in the code, compile and restart testing again.

## Proposed solution
* Use the keyboard to change the parameters.

## The provided code is for using keyboard on Linux machine for fine tuning

# Usage:

`P`: Increase `Kp` value 
`P`: Decrease `Kp` value 

`D`: Increase `Kd` value 
`d`: Decrease `Kd` value 

`I`: Increase `Ki` value 
`i`: Decrease `Ki` value 

`T`: Enable `TWIDDLE` (if impemented)
`t`: Disable `TWIDDLE`

* You can modify the code to instead of incrementing or decrementing a specific value it increments or decrements certain %. This will get you closer to **TWIDDLE**. You can also comment the ```cout``` statements to focus on the parameters.
* You can enhance it by:
* * adding "s" and "l" to save and load the parameters to/from the file.
* * Load the initial parameters from command line

[ Reference to kbit onLinux:](https://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html)

