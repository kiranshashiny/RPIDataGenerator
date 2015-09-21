all: sensor

sensor: sensor.c
	$(CC) sensor.c -I ./../ -I ./../lib ./../iotfclient.c ./../lib/MQTTClient.c ./../lib/MQTTLinux.c ./../lib/MQTTFormat.c  ./../lib/MQTTPacket.c ./../lib/MQTTDeserializePublish.c ./../lib/MQTTConnectClient.c ./../lib/MQTTSubscribeClient.c ./../lib/MQTTSerializePublish.c ./../lib/MQTTConnectServer.c ./../lib/MQTTSubscribeServer.c ./../lib/MQTTUnsubscribeServer.c ./../lib/MQTTUnsubscribeClient.c -L/usr/local/lig -lwiringPi -o $@
	strip $@
clean:
	rm -f sensor
