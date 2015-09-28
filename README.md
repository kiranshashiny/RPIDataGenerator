C Client Library to generate some random numbers and publish to IBM IoTF.
========================================================================

Prerequisites :
---------------

You have installed wiringPi from git hub.

You have registered the Raspberry Pi on IBM IoTF.

This allows you to publish and subscribe to events from IBM IoTF and also enables you to turn LED or external devices from Raspberry Pi GPIO pins.

Download this code and run this on the Raspberry Pi.

Code was tested on Raspberry Pi Model B.


Usage
=-----

[root@localhost ~]# cd codedir

[root@localhost ~]# vi sensor.c <br>
Edit the part of code to reflect the correct organization, device id, and authorization code.
Save and exit.


[root@localhost ~]# make


This sample application demonstrates the Internet of Things Foundation service. The sample application connects IBM IoTF and sends event data. 

This sample is a great place to get started with the Internet of Things Foundation Service by learning how to subscribe and publish events.

                pi@raspberrypi $ sudo ./sensor
                 Calling connectiotf()
                Connecting to registered service with org 8ubmht
                the auth token being used is [kg&z3L4pxKd?_BRXXX]


