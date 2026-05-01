Github Repository for our code for our CF conerstone project.  Use to learn about habits 1 and 2 if you would like to learn about it.

To run:

Invoke-WebRequest -Uri "https://github.com/thecomputernerd0011/8th-grade-CF-cornerstone-2026.git" -OutFile "8th-grade-CF-cornerstone.zip"
Expand-Archive -Path "8th-grade-CF-cornerstone.zip" -DestinationPath "8th-grade-CF-cornerstone"
IN POWERSHELL:
winget install --id Microsoft.VisualStudio.2022.BuildTools --override "--passive --add Microsoft.VisualStudio.Workload.VCTools --includeRecommended"
**Then outside of powershell**
Click Start.

Search for "Developer PowerShell for VS 2022".

Open it.

**Then run these in Developer powershell**

chcp 65001

cd (file path)

cl /EHsc /I. src/parser.cpp src/renderer.cpp

.\parser.exe

**After your done if you want to delete downloaded files run in powershell:**
winget uninstall Microsoft.VisualStudio.2022.BuildTools
