#!/usr/bin/python

print("This will display '#define' lines which are in B and not in A so you can add those defines in A")

high_priority_file = "C:\Workspaces\pyCharm\DefinesMerger\SKEAZN642.h"
low_priotity_file = "C:\Workspaces\pyCharm\DefinesMerger\SKEAZN642_old.h"

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
    tmp = element.split(" ")[1].strip()

    if any(tmp in e for e in high_priority_defines_array):
        print(element)

    # for e in high_priority_defines_array:
    #     if tmp in (e.split(" ")[1].strip()):
    #         print(element)
    #         break

