#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <SPI.h>
#include <Ethernet.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature suhu(&oneWire);
float celcius=0;


byte mac[] ={ 0xDE,0xAD,0xBE,0xEF,0xFE,0xED};
char server [] = "192.168.1.11";
IPAddress ip (192,168,1,99); 

  unsigned int i;
  unsigned int z;
  unsigned long ADC_NTU[1];
  
  float ntu;
  int keterangan = 0;
  int ledh = 6;
  int ledm = 7;
  int buzzer = 8;



void setup() {

  pinMode(ledh, OUTPUT);
  pinMode(ledm, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  suhu.begin();
  lcd.begin();
  lcd.setCursor(4, 0);
  lcd.print("TURBITOR");
  delay (100);
  lcd.setCursor(2, 7);
  lcd.print(server);
  delay (3000);
  
  EthernetClient client;
  Ethernet.begin(mac, ip); 
  
  if (client.connect(server, 80)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Connected");
     tone(buzzer,  700,70);
  delay (4000);
  loop();
    
 }else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Connecting");
    lcd.setCursor(0,1);
    lcd.print("     Failed");
    digitalWrite(ledh, HIGH);
    digitalWrite(ledm, HIGH);
    tone(buzzer,  900,700);
    delay (3000);
   setup();
  }

lcd.clear();
}


void loop(){
  Data_CEL();
}


void Data_CEL (){ 

  for(i=0;i<1;i++) {

 suhu.requestTemperatures(); 
 celcius=suhu.getTempCByIndex(0);
    }
    

      EthernetClient client;
  client.connect(server, 80);{ 
 client.println("GET /pdam/include/insertsuhu.php?celcius="+(String(celcius))+ "&adc="+ (String (z)));
  }
 
