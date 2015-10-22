# DS18B20 sensor library for Arduino

### Advantages:

- Easy
- Async
- Sensor adresses in SRAM or Flash memory
- Easy debug with exceptions

### Disadvantages

- It does not support hardware alarms (nobody cares ;-) )

### Example

<pre>
<span style="color: #7E7E7E;">//&nbsp;Asynchronously&nbsp;reads&nbsp;the&nbsp;temperature&nbsp;from&nbsp;sensor&nbsp;DS18B20</span>

#include&nbsp;&lt;<span style="color: #CC6600;">OneWire</span>.h&gt;
#include&nbsp;&lt;<span style="color: #CC6600;">DS18B20</span>.h&gt;

<span style="color: #7E7E7E;">//&nbsp;1-Wire&nbsp;bus&nbsp;Arduino&nbsp;pin</span>
<span style="color: #CC6600;">const</span> <span style="color: #CC6600;">byte</span> ONEWIRE_PIN = 2;

<span style="color: #7E7E7E;">//&nbsp;Sensor&nbsp;address</span>
<span style="color: #7E7E7E;">//&nbsp;EXAMPLE:</span>
<span style="color: #7E7E7E;">//&nbsp;byte&nbsp;sensorAddress[8]&nbsp;=&nbsp;{0x28,&nbsp;0xB1,&nbsp;0x6D,&nbsp;0xA1,&nbsp;0x3,&nbsp;0x0,&nbsp;0x0,&nbsp;0x11};</span>
<span style="color: #CC6600;">byte</span> sensorAddress[8] = {<span style="color: #7E7E7E;">/* your sensor address here */</span>};


<span style="color: #CC6600;">OneWire</span> onewire(ONEWIRE_PIN);
<span style="color: #CC6600;">DS18B20</span> sensors(&amp;onewire);

<span style="color: #CC6600;">void</span> <span style="color: #CC6600;"><b>setup</b></span>() {
&nbsp;&nbsp;<span style="color: #CC6600;">while</span>(!<span style="color: #CC6600;"><b>Serial</b></span>);
&nbsp;&nbsp;<span style="color: #CC6600;"><b>Serial</b></span>.<span style="color: #CC6600;">begin</span>(9600);
&nbsp;&nbsp;
&nbsp;&nbsp;<span style="color: #7E7E7E;">// DS18B20 sensors setup</span>
&nbsp;&nbsp;sensors.<span style="color: #CC6600;">begin</span>();
&nbsp;&nbsp;
&nbsp;&nbsp;<span style="color: #7E7E7E;">// The first requests sensor for measurement</span>
&nbsp;&nbsp;sensors.<span style="color: #CC6600;">request</span>(sensorAddress);
}

<span style="color: #CC6600;">void</span> <span style="color: #CC6600;"><b>loop</b></span>() {
&nbsp;&nbsp;<span style="color: #7E7E7E;">// If the sesor measurement is ready, print the results</span>
&nbsp;&nbsp;<span style="color: #CC6600;">if</span> (sensors.<span style="color: #CC6600;">available</span>())
&nbsp;&nbsp;{
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color: #7E7E7E;">// Reads the temperature from sensor</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color: #CC6600;">float</span> temperature = sensors.<span style="color: #CC6600;">readTemperature</span>(sensorAddress);
&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color: #7E7E7E;">// Prints the temperature on Serial Monitor</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color: #CC6600;"><b>Serial</b></span>.<span style="color: #CC6600;">print</span>(temperature);
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color: #CC6600;"><b>Serial</b></span>.<span style="color: #CC6600;">println</span>(F(<span style="color: #006699;">" 'C"</span>));
&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color: #7E7E7E;">// Another requests sensor for measurement</span>
&nbsp;&nbsp;&nbsp;&nbsp;sensors.<span style="color: #CC6600;">request</span>(sensorAddress);
&nbsp;&nbsp;}
&nbsp;&nbsp;
&nbsp;&nbsp;<span style="color: #7E7E7E;">// Here, put your code performs without delay</span>
}

</pre>

### Framework:

<pre>
#include&nbsp;&lt;<span style="color: #CC6600;">OneWire</span>.h&gt;
#include&nbsp;&lt;<span style="color: #CC6600;">DS18B20</span>.h&gt;

<span style="color: #CC6600;">const</span> <span style="color: #CC6600;">byte</span> ONEWIRE_PIN = 2;

<span style="color: #CC6600;">OneWire</span> onewire(ONEWIRE_PIN);
<span style="color: #CC6600;">DS18B20</span> sensors(&amp;onewire);

<span style="color: #CC6600;">void</span> <span style="color: #CC6600;"><b>setup</b></span>() {
&nbsp;&nbsp;<span style="color: #7E7E7E;">// put your setup code here, to run once:</span>
&nbsp;&nbsp;sensors.<span style="color: #CC6600;">begin</span>();

}

<span style="color: #CC6600;">void</span> <span style="color: #CC6600;"><b>loop</b></span>() {
&nbsp;&nbsp;<span style="color: #7E7E7E;">// put your main code here, to run repeatedly:</span>

}

</pre>

### Reference:

<pre>
<span style="color: #CC6600;">DS18B20</span> sensors(&amp;onewire);

</pre>
Constructor

Argument: Pointer to OneWire object

Return: New DS18B20 object

<pre>
&nbsp;&nbsp;sensors.<span style="color: #CC6600;">begin</span>();

</pre>
Setup for all ds19b20 sensors in 1-Wire bus.

Argument: quality - measurement resolution in bits (from 9 to 12)

Return: 

true 

- if all operations were successful

false 
- when the bus is physically damaged
- when devices not respond
- when device address is not valid
- when no devices detected

<pre>
sensors.<span style="color: #CC6600;">request</span>();

</pre>
Request for temperature measurements on all devices

Return:

true 

- if operation were successful

false 

- if devices have different ways of power (combinations of normal and parasite in one bus)
- if devices not responding

<pre>
sensors.<span style="color: #CC6600;">request</span>(address);

</pre>
Request for temperature measurements on device

Argument: Pointer to an array of device address

Return:
true 

- if operation were successful

false 

- if device not responding

<pre>
sensors.<span style="color: #CC6600;">request</span>(<span style="color: #006699;">FA</span>(address));

</pre>
Request for temperature measurements on device

Argument: Pointer to an array in flash memory of device address

Return:

true 

- if operation was successful

false 

- if device not responding

<pre>
sensors.<span style="color: #CC6600;">available</span>();

</pre>
Checks if devices completed the measurement

Return:

true 

- the measurement was completed

false 

- the measurement wasn't completed

<pre>
sensors.<span style="color: #CC6600;">readTemperature</span>(address);

</pre>
Read temperature from device

Argument: Pointer to an array of device address

Return: temperature in degrees Celsius
If the temperature is TEMP_ERROR value - measurement failed because:

- the bus is physically damaged
- devices are not responding
- data from the device is not valid
- no device found with given address

<pre>
sensors.<span style="color: #CC6600;">readTemperature</span>(<span style="color: #006699;">FA</span>(address));

</pre>
Read temperature from device

Argument: Pointer to an array in flash memory of device address

Return: temperature in degrees Celsius
If the temperature is TEMP_ERROR value - measurement failed because:

- the bus is physically damaged
- devices not respond
- when data from the device is not valid
- when not detect device of thad address

<pre>
<span style="color: #006699;">FA</span>(address)

</pre>
Pointer type to an array in flash memory of device address

<pre>
<span style="color: #006699;">E</span>(function(...));

</pre>
Exceptions catcher
Checks for errors and prints it on Serial Monitor with line number

<pre>
<span style="color: #006699;">TE</span>(temperature);

</pre>
Temperature value exception catcher
Checks the wrong temperature and prints it on Serial Monitor with line number

