#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "...";
const char* password =  "...";

WiFiUDP Udp;
unsigned int localUdpPort = 20777;  // local port to listen on
char incomingPacket[1289];  // buffer for incoming packets
//UDPPacket incomingPacket;
char  replyPacekt[] = "Hi there! Got the message :-)";  // a reply string to send back

WiFiClient espClient;
 
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
//  Serial.printf("Now listening at IP %s, UDP port %d\n", espClient.localIP().toString().c_str(), localUdpPort);

  delay(2000);
}
 
void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    // receive incoming UDP packets
   Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 1289);
    if (len > 0){
      incomingPacket[len] = 0;
     Serial.println("LEN 0");
    }
    Serial.println("LEN NÃO 0");
    float gear = tmp_pckt->m_gear;
    Serial.println(gear);
  }
}
