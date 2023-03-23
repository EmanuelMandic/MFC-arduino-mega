<h1>Measuring voltage with arduino</h1>

File organisation
 - this code is a VS Code workspace with /src folder
 - src folder contains main.cpp file
 - we are using PlatformIO and Arduino extensions to upload and compile code for arduino mega

Main.cpp
 - code for measuring volatage on A1, A2, A3, A4, A5, A6, A7, A8
 - to get the data from analog input we have analogTomVolt() function to convert analog signal to mV
 - on A0 we are getting the data for temperature
 - we are using analogToTemp() to convert analog data to °C

We are using this code to measure MFC voltage and to get the data for the analisys.
To gather the data we use VS Code Platform IO exstension - serial monitoring.
That enables us to save the data with timestamps.
Before that we used coolterm freeware.
