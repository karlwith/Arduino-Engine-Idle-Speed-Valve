# Arduino-Engine-Idle-Speed-Valve
Code and schematic used to actuate a solenoid valve routed in parallel with the throttle body used to regulate the idle speed of an engine. Project inspiration was to replace the failed and unservicable stock idle control system from a 1985 BMW E30 318i with the M10B18 engine. Control logic is governed by the analog signal from the coolant temperature thermistor. 

Given the car battery of ~12V and Arduino running on 5V, a voltage regulator was used to provide 5V to the Arduino. A voltage divider was implemented to scale the analog signal to under 5V for the Arduinos onboard ADC and a 5V relay used for the Arduino to switch the 12V solenoid valve. Melodic tones from a piezo buzzer provide feedback to the driver.

Initially, the cold engine idle speed with the valve open was 850rpm leading to a warm engine idle of 1400rpm which was then throttled by the closed valve down to 1100rpm. 
Through testing the orifice inside the solenoid valve was relaxed from 2.5mm to 3.5mm to achieve an ideal cold and warm engine idle speed of 850rpm.

Further work in progress includes replicating the Arduino UNO system on a perma proto circuit board, using a ATmega328 microcontroller, 16MHz clock crystal, etc to create a lower profile embedded system.

![circuit (1)](https://user-images.githubusercontent.com/65951397/117573018-146e3e00-b119-11eb-919d-5638da6f2ca9.png)

Current Arduino UNO Implimentation

![Picture1](https://user-images.githubusercontent.com/65951397/119221767-35308d80-bb34-11eb-890b-dccbf96e1cd3.png)

Planned ATmega328P Implementation (using Perma Proto board)
