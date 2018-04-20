#!/usr/bin/python

# caffedrine@github.com

import sys          # to pass arguments
import os.path      # to check wether file exists or not

if len(sys.argv) < 2:
    print("Usage: merger.py low_priotity_file.h high_priority_file.h")
    print("  - low_priority_file = the file whose defines will be copied in the other")
    print("  - high_priority_file = the missing defines from this file will be written in output from low priority file")
    sys.exit(1)

print("// Generated with merger.py")
print("// This will display '#define' lines which are in B and not in A so you can add those defines in A")

low_priotity_file = sys.argv[2]
high_priority_file = sys.argv[1]
output_file = "C:\Workspaces\pyCharm\DefinesMerger\common_defines.h"

print("Got: " + high_priority_file + " - " + low_priotity_file)

if not (os.path.isfile(high_priority_file) and os.path.isfile(low_priotity_file)):
    print("Invalid files!\n")
    sys.exit(1)

high_priority_defines_array = []
low_priority_defines_array = []

# Read high priority file
with open(high_priority_file) as lines:
    for line in lines:
        if "#define" in line.lower():
            high_priority_defines_array.append(line.replace("\n", ""))

# Read low priority lines to array
with open(low_priotity_file) as lines:
    for line in lines:
        if "#define" in line.lower():
            low_priority_defines_array.append((line.replace("\n", "")))

# Print elements which needs to ne added
for element in low_priority_defines_array:
    # split element. eg: "#define FSL_FEATURE_ADC16_HAS_PGA (0)" will extract "FSL_FEATURE_ADC16_HAS_PGA"
    if element.split(" ")[1].strip():
        tmp = element.split(" ")[1].strip()
    elif element.split(" ")[2].strip():
        tmp = element.split(" ")[2].strip()
    else:
        continue

    foundFlag = 0
    for e in high_priority_defines_array:
        if tmp in e:
            foundFlag = 1
            break
        else:
            foundFlag = 0
    if foundFlag is 0:
        print(element)

        # Then append elements to a file
        with open(output_file, "a+") as f:
            f.write(element + "\n")


