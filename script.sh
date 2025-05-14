#! /bin/bash
# Global Config
LIKWID_HOME=/home/soft/likwid


# Compile
make > /dev/null

# Freq Fixed
echo "performance" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor
