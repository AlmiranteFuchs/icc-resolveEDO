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
likwid-perfctr --output flops_dp.txt -C 0 -g FLOPS_DP -m ./resolveEDO < edos.dat > resolveEDO_saida.txt

# Builds output
grep FP_ARITH_INST_RETIRED_SCALAR_DOUBLE flops_dp.txt | awk -F '|' '{gsub(/ /, "", $2); gsub(/ /, "", $4); print $2 "," $4}' > tmp && mv tmp flops_dp.txt

cat resolveEDO_saida.txt
cat flops_dp.txt

# Final
# Restore the original value
echo "powersave" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor
