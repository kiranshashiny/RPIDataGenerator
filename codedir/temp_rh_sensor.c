#include <wiringPi.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <stdint.h>  
#include <signal.h>  
#include <math.h>  
#include "iotfclient.h"
#define PIN11 17

volatile int interrupt = 0;

#define MAX_TIME 85  
char jsonstr[200];

int random_number(int min_num, int max_num);

// Handle signal interrupt
void sigHandler(int signo) {
        printf("SigINT received.\n");
        interrupt = 1;
}

void myCallback (char* commandName, char* format, void* payload)
{
        printf("------------------------------------\n" );
        printf("The command received :: %s format %s payload (char *)%s \n", commandName, format, payload);
        //printf("format : %s\n", format);
        //printf("Payload is : %s\n", (char *)payload);

	pinMode(PIN11,OUTPUT);

	if ( strncmp (payload, "safe",4 )== 0 ) {
		printf ("  received safe\n ");
		digitalWrite(PIN11,LOW);
	} else {
		printf ("  received critical\n ");
		digitalWrite(PIN11,HIGH);
	}
        printf("------------------------------------\n" );
}

  

int random_number(int min_num, int max_num)
{
    int result=0,low_num=0,hi_num=0;
    if(min_num<max_num)
    {
        low_num=min_num;
        hi_num=max_num+1; // this is done to include max_num in output.
    } else {
        low_num=max_num+1;// this is done to include max_num in output.
        hi_num=min_num;
    }
    srand(time(NULL));
    result = (rand()%(hi_num-low_num))+low_num;
    return result;
}
  
int main(void)  
{  
       int rc = -1;
       int tempF =0;

        Iotfclient client;

        //catch interrupt signal
        signal(SIGINT, sigHandler);
        signal(SIGTERM, sigHandler);

	if ( wiringPiSetupGpio () == -1 ){
	   exit(1);
	}

        //char *configFilePath = "./device.cfg";
        //rc = initialize_configfile(&client, configFilePath);
	rc = initialize(&client,"8ubmht","iotdevice","b827eb984666","token","kg&z3L4pxKd?_BRtZm");


        if(rc != SUCCESS){
                printf("initialize failed and returned rc = %d.\n Quitting..", rc);
                return 0;
        }
	printf (" Calling connectiotf() \n");
        rc = connectiotf(&client);

        if(rc != SUCCESS){
                printf("Connection failed and returned rc = %d.\n Quitting..", rc);
                return 0;
        }

        setCommandHandler(&client, myCallback);

        while(!interrupt)
        {
                printf("Publishing the event stat with rc ");
		tempF = random_number(1,20);
		
		sprintf (jsonstr,  "{\"d\" : {\"temp\" : %d }}", tempF );
		printf  ("jsonstr [%s]\n", jsonstr );
                rc= publishEvent(&client, "status","json", jsonstr, QOS0);

                //rc= publishEvent(&client, "status","json", "{\"d\" : {\"temp\" : 34 }}", QOS0);
                printf(" %d\n", rc);
                yield(&client, 1000);
                sleep(2);
        }

        printf("Quitting!!\n");

        disconnect(&client);

        return 0;
}
