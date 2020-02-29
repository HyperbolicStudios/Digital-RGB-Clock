#define WIFI_NAME "Arnoga-2.4"
#define WIFI_PASSWORD "Arnoga1998"
#define DEVICE_ID 1
#define DEVICE_NAME "Google_ESP"
#define TOKEN "~696446_Em2yyqzqc5Z6"

#define Relay_1 D1
#include <RemoteMe.h>
#include <RemoteMeSocketConnector.h>
#include <ESP8266WiFi.h>

#define LED LED_BUILTIN

RemoteMe& remoteMe = RemoteMe::getInstance(TOKEN, DEVICE_ID);

//*************** CODE FOR COMFORTABLE VARIABLE SET *********************

inline void setRelay_1(boolean b) {remoteMe.getVariables()->setBoolean("Relay_1", b); }

//*************** IMPLEMENT FUNCTIONS BELOW *********************

void onRelay_1Change(boolean b) {
	Serial.printf("onRelay_1Change: b: %d\n",b);
  if (b==true) {
    digitalWrite(LED, LOW);
  }
  else {
    digitalWrite(LED, HIGH);
  }
}




void setup() {
	Serial.begin(9600);
  pinMode(LED, OUTPUT);
	WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

	while (WiFi.status() != WL_CONNECTED) {
		delay(100);
	}

	remoteMe.getVariables()->observeBoolean("Relay_1" ,onRelay_1Change);

	remoteMe.setConnector(new RemoteMeSocketConnector());
	remoteMe.sendRegisterDeviceMessage(DEVICE_NAME);
}


void loop() {
	remoteMe.loop();
}
