#! /bin/bash
# Global Config
LIKWID_HOME=/home/soft/likwid

# Clean Up
make purge > /dev/null

# Compile
make > /dev/null

# Freq Fixed
echo "performance" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor

# Call program
likwid-perfctr --output flops_dp.txt -C 0 -g FLOPS_DP -m ./resolveEDO < edo.dat

# Final
# Restore the original value
echo "powersave" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor
