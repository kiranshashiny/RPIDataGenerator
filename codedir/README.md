C Client Library to generate some random numbers and publish to IBM IoTF.
========================================================================

Usage
-----


[root@localhost ~]# make


This sample application demonstrates the Internet of Things Foundation Publish and subscribe service. The sample application connects to the Quickstart service and sends event data. To connect to the Quickstart service, you must provide an unique identifier for the device.


		pi@raspberrypi $ sudo ./sensor
		 Calling connectiotf() 
		Connecting to registered service with org 8ubmht
		the auth token being used is [kg&z3L4pxKd?_BXXX]
		Publishing the event stat with rc jsonstr [{"d" : {"temp" : 2 }}]
		publishTopic = iot-2/evt/status/fmt/json
		 0
		Publishing the event stat with rc jsonstr [{"d" : {"temp" : 10 }}]
		publishTopic = iot-2/evt/status/fmt/json
		 0
		^CSigINT received.
		Quitting!!
		
