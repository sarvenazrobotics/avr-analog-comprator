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
## Features

- **Multiplexed Analog Comparison** – Uses a single analog comparator to sequentially monitor up to 6 analog input channels (ADC0–ADC5) by changing the `ADMUX` value.

- **Real-Time Visual Feedback** – Displays comparison results instantly on 6 discrete LEDs (PORTB0–PORTB5), with each LED indicating whether the corresponding input voltage exceeds the reference.

- **No ADC Required** – Leverages the analog comparator instead of the ADC peripheral, freeing the ADC for other tasks or reducing power consumption (ADC can remain disabled).

- **Low-Power Design** – Disables the ADC (`ADCSRA = 0`) and digital input buffers on comparator pins (`DIDR1`), minimizing unnecessary current draw.

- **Simple Threshold Detection** – Compares each input against a fixed reference (AIN0 pin or internal bandgap), making it ideal for threshold sensing, window detectors, or logic-level decision making.

- **Stabilized Readings** – Includes a 2ms delay after each channel switch, allowing the comparator output to settle before reading the result.

- **Compact Macros** – Uses simple preprocessor macros (`LED1(x)` through `LED6(x)`) for clean, readable LED control without function call overhead.

- **Continuous Scanning** – Runs in an infinite loop, constantly refreshing all 6 channels for up‑to‑date status indication.


