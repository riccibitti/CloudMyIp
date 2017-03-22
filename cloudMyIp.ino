#include "ESP8266WiFi.h"

// WiFi parameters
const char* ssid = "yourWifi";
const char* password = "yourPassword";
String dweetThingName("yourDweetThingName");

void setup() {
  
  // Start Serial
  Serial.begin(115200);
  delay(10);
  
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}



String getIp()
{
  WiFiClient client;
  if (client.connect("api.ipify.org", 80)) 
  {
      Serial.println("connected");
      client.println("GET / HTTP/1.0");
      client.println("Host: api.ipify.org");
      client.println();
  } else {
      Serial.println("Connection to ipify.org failed");
      return String();
  }
  delay(5000);
  String line;
  while(client.available())
  {
    line = client.readStringUntil('\n');
    Serial.println(line);
  }
  return line;
}


bool dweet( String ip)
{

  WiFiClient client;
  if (!client.connect("dweet.io", 80)) 
  {
    Serial.println("dweet failed");
    return false;
  }  
  else 
  {
    Serial.println("dweeting ip address as " + dweetThingName +" [" + ip + "]" );
    
    client.println( String("GET /dweet/for/" + dweetThingName + "?IPaddress=") + ip + " HTTP/1.1");
    client.println( "Host: dweet.io" );
    client.println( "Connection: close");
    client.println("");
    client.println("");
    
    delay(1000);
  
    // Read all the lines of the reply from server and print them to Serial
    while(client.available())
    {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    };
    return true;
  }; 
}


void loop() 
{
  String ip = getIp();
  if ( ip != String() )
    dweet( ip ) ;
  // repeat after one minute
  delay(60000);
}

