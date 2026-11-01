### Arduino morse translator

**Component:**
* Arduino UNO R3
* Two state button
* Push Button
* Buzzer
* Led
* OLED screen 0,94"
* Jumper wires

**Connection:**
* Push Button &rarr; GPIO 10
* Two state button &rarr; GPIO 2
* Buzzer &rarr; GPIO 6
* Led &rarr; PIN 6 (cathode-220ohm resistance)
* OLED 0,94" &rarr; SCL A5 - SDA A4

_**Notes**:
It is a Text-to-Morse & Morse-To-Text translator , the mode is defined by the state of a 2-State-Button connected directly to the arduino and setted as a INPUT_PULLUP , the same is for the push button (so it return 0 when pressed and 1 when not pressed). You can change the dot and dash sensitivity by changing DOT(line 17) and DASH(line 18) macro_

###### open source is love <3
###### README.md made with [Markdown Live Preview](https://markdownlivepreview.com/)

