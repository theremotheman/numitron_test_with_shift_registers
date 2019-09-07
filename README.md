# Numitron iv-9 test using 4 shift registers and Arduino Uno


![](Photos/2019-09-07%2015.35.32.jpg)

Testing application for diagnosing numitron iv-9 tubes. Uses 4 shift registers and Arduino Uno.

According to documentation, the first iv-9 leg is common, second is indication dot. You need to connect common(first) to GND then every single leg to outputs of your shift register(one by one).

Use this tutorial for connecting shift registers to Arduino: https://www.arduino.cc/en/tutorial/ShiftOut and remember to use caps for the nice flicker-less experience.

Use 0.1pf caps between VCC and GND as a decoupling cap - VERY IMPORTANT for debugging, strange things may happen if you ignore this step.

Also, use something more capable than 595 shift registers - they might work but also might fail horribly killing your numitron or Arduino or PC.

Video of how it should work: https://www.youtube.com/watch?v=S2hUcF2jsSs

# A good read before recreating this project:

Decoupling caps: http://www.thebox.myzen.co.uk/Tutorial/De-coupling.html

Numitron tutorial with informative comments on HackaDay: https://hackaday.com/2011/12/21/numitron-tube-tutorial/

Very helpful documentation on iv-9, can't express my gratefulness - I would be helpless without this good man site: http://www.tube-tester.com/sites/nixie/data/IV-9/iv-9.htm

-------------------------------------------------------------------------------------------------------------------------------

My Facebook site: https://www.facebook.com/PutridDump

GOOD LUCK
