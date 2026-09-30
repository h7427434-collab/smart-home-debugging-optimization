# Week 3 - Debugging Notes

## Project
Smart Home Environment Monitoring System

## Objective

The objective of this activity is to identify common embedded-system programming errors, correct them, and improve the responsiveness and efficiency of the monitoring program.

## Bugs Identified

| Bug | Problem | Correction |
|---|---|---|
| 1 | LED pin configured as INPUT | Changed LED pin to OUTPUT |
| 2 | Buzzer pin configured as INPUT | Changed buzzer pin to OUTPUT |
| 3 | Integer arithmetic caused inaccurate temperature conversion | Used floating-point constants |
| 4 | Humidity conversion used incorrect arithmetic | Corrected the conversion formula |
| 5 | Alert thresholds were not clearly defined | Added named threshold constants |
| 6 | delay(5000) blocked the program | Replaced blocking delay with millis() |

## Debugging Process

### 1. GPIO Configuration

The LED and buzzer were incorrectly configured as inputs.

The corrected program configures both pins as outputs.

### 2. Temperature Conversion

The buggy version used integer arithmetic.

The corrected version uses floating-point constants to preserve decimal precision.

### 3. Humidity Conversion

The corrected version uses floating-point arithmetic for the humidity calculation.

### 4. Alert Thresholds

Named constants were added for temperature and humidity thresholds.

### 5. Timing Optimization

The buggy program used a blocking delay of five seconds.

The corrected program uses millis() timing so the system is more responsive.

## Expected Improvements

- Correct GPIO configuration
- Better numerical precision
- Clear threshold management
- Improved responsiveness
- Non-blocking timing
- Easier maintenance

## Conclusion

The debugging exercise demonstrates how common firmware errors can affect an embedded monitoring system. Correcting GPIO configuration, numerical calculations, threshold handling, and timing produces a cleaner and more responsive program.
