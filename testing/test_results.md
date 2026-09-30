# Week 3 - Test Results

## Project
Smart Home Environment Monitoring System

## Testing Objective

The objective is to verify the corrected and optimized monitoring program and compare its expected behavior with the buggy version.

## Test Cases

| Test ID | Test | Expected Result | Actual Result | Status |
|---|---|---|---|---|
| T01 | Verify LED pin configuration | LED operates as an output | Pending testing | Pending |
| T02 | Verify buzzer pin configuration | Buzzer operates as an output | Pending testing | Pending |
| T03 | Test temperature calculation | Decimal temperature calculation works correctly | Pending testing | Pending |
| T04 | Test humidity calculation | Humidity calculation works correctly | Pending testing | Pending |
| T05 | Test temperature alert | Alert activates above threshold | Pending testing | Pending |
| T06 | Test humidity alert | Alert activates above threshold | Pending testing | Pending |
| T07 | Test monitoring interval | Readings occur at the defined interval | Pending testing | Pending |

## Performance Comparison

The buggy version uses a blocking `delay()` function, while the corrected version uses `millis()` for non-blocking timing.

Actual performance measurements will be added after testing.

## Evidence

Screenshots, serial-monitor output, or simulator results will be added after testing.

## Conclusion

The corrected program will be tested to verify its functionality and responsiveness before the final report is prepared.
