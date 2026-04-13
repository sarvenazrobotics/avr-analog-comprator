##  Table of Contents

-  [Overview](#overview)
-  [Features](#features)
-  [How It Works](#how-it-works)
-  [Usage](#usage)
- [Summary](#summary)
- [Project Author](#project-author)


 ## Overview 
This AVR firmware continuously monitors six analog input channels (ADC0–ADC5) using the microcontroller's built‑in analog comparator, which is multiplexed to compare each input against the voltage on AIN0 (or an internal reference). The comparison result for each channel is displayed in real‑time on six LEDs connected to PORTB0–PORTB5: an LED turns on when the corresponding analog input voltage exceeds the reference, and off when it falls below.. By sequentially setting ADMUX to 0 through 5, reading the ACO bit in ACSR after a short stabilization delay, and using bit‑masking macros to drive the LEDs, the system provides a simple, low‑power visual indicator of relative voltage levels without requiring an analog‑to‑digital conversion.

## Features

- **Multiplexed Analog Comparison** – Uses a single analog comparator to sequentially monitor up to 6 analog input channels (ADC0–ADC5) by changing the `ADMUX` value.

- **Real-Time Visual Feedback** – Displays comparison results instantly on 6 discrete LEDs (PORTB0–PORTB5), with each LED indicating whether the corresponding input voltage exceeds the reference.

- **No ADC Required** – Leverages the analog comparator instead of the ADC peripheral, freeing the ADC for other tasks or reducing power consumption (ADC can remain disabled).

- **Low-Power Design** – Disables the ADC (`ADCSRA = 0`) and digital input buffers on comparator pins (`DIDR1`), minimizing unnecessary current draw.

- **Simple Threshold Detection** – Compares each input against a fixed reference (AIN0 pin or internal bandgap), making it ideal for threshold sensing, window detectors, or logic-level decision making.

- **Stabilized Readings** – Includes a 2ms delay after each channel switch, allowing the comparator output to settle before reading the result.

- **Compact Macros** – Uses simple preprocessor macros (`LED1(x)` through `LED6(x)`) for clean, readable LED control without function call overhead.

- **Continuous Scanning** – Runs in an infinite loop, constantly refreshing all 6 channels for up‑to‑date status indication.


  ## How It Works

The AVR microcontroller includes an internal analog comparator that compares two analog voltages: the positive input (AIN0) and the negative input (AIN1). When the voltage on AIN0 is higher than AIN1, the comparator output bit `ACO` in the `ACSR` register is set to 1; otherwise, it's 0.

This firmware extends the comparator's capability using the **Analog Comparator Multiplexer** (enabled by setting the `ACME` bit in `ADCSRB`). When `ACME` is set, the negative input of the comparator can be switched between AIN1 and any of the ADC input pins (ADC0–ADC5) by writing to the `ADMUX` register.

The program operates in a continuous loop:

1. **Select Channel** – The code writes a value (0 through 5) to `ADMUX`, routing the corresponding ADC pin (ADC0 to ADC5) to the comparator's negative input.

2. **Stabilize** – A 2ms delay allows voltages to settle and the comparator output to stabilize after the multiplexer switches.

3. **Read Result** –
ACO = 1 → AIN0 (reference) is higher than the selected input → LED ON

ACO = 0 → Selected input is higher than AIN0 (reference) → LED OFF

So the LED turns ON when the input voltage is LOWER than the reference (AIN0), not higher.

4. **Update LED** – The macro corresponding to the current channel turns the LED on (if `ACO` is 1) or off (if `ACO` is 0). The `!!` (double logical NOT) operator converts the bit value to either 0 or 1.

5. **Repeat** – Steps 1–4 repeat for channels 0 through 5, then the loop starts over, continuously refreshing all six LEDs.

The reference voltage for comparison is set by the `ACBG` bit in `ACSR`. In this code, `ACSR = 0` means `ACBG = 0`, so the positive input of the comparator is connected to the AIN0 pin. Users can apply a reference voltage to AIN0, or modify `ACSR` to use the internal 1.1V bandgap reference instead.


## Usage
- **Battery voltage monitor** – Set reference to a threshold voltage (e.g., 3.3V) and monitor multiple battery cells

- **Light sensor array** – Connect photoresistors to ADC inputs and observe which sensors are above/below a brightness threshold

- **Water level indicator** – Use probes at different heights; LEDs show which levels are submerged (low resistance = low voltage)

- **Logic probe** – Visualize high/low states of up to 6 digital or analog signals simultaneously

## Summary

This project provides a simple, efficient way to monitor up to six analog voltage levels using only the AVR microcontroller's built-in analog comparator, without requiring the ADC peripheral. By multiplexing the comparator's negative input across ADC0–ADC5 and comparing each against a reference voltage on AIN0, the firmware continuously updates six LEDs on PORTB to indicate whether each input is above or below the threshold. The code is compact, low-power, and ideal for threshold detection applications such as battery monitors, light sensors, water level indicators, or logic probes. With minimal external components (six LEDs and current-limiting resistors), this solution offers real-time visual feedback in a cost-effective and resource-efficient package.


