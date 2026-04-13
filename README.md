##  Table of Contents

-  [Overview](#overview)
-  [Features](#features)
-  [How It Works](#how-it-works)
-  [Usage](#usage)
- [Summary](#summary)
- [Project Author](#project-author)


 ## Overview 
This AVR firmware continuously monitors six analog input channels (ADC0–ADC5) using the microcontroller's built‑in analog comparator, which is multiplexed to compare each input against the voltage on AIN0 (or an internal reference). The comparison result for each channel is displayed in real‑time on six LEDs connected to PORTB0–PORTB5: an LED turns on when the corresponding analog input voltage exceeds the reference, and off when it falls below.
