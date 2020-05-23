//Sitio Web con Practicas de Arduino, FPGA, MATLAB y 
//temas sobre Electrónica Digital, Analogica, Procesamiento Digital de Señales, 
//Comunicaciones, etc.
//www.slideshare.net/FerMarcos2

//Sitio Web Curriculum
//www.linkedin.com/in/FerMarcos2

//Canal Youtube
//www.youtube.com/channel/UCLGgLo5SKhDz3cae4YOQosg

char num[]={0x7E,0x0C,0xB6,0x9E,0xCC,0xDA,0xFA,0x0E,0xFE,0xDE};
String snum="";
void setup(){
  DDRD=B11111111; //Digital Ports 7-1  OUTPUT
  DDRB=B111111;   //Digital Ports 13-8 OUTPUT
}
void loop(){
  for(int count=0;count<100;count++){ //Count 0 to 99
    String scount=String(count);
    for(int repeat=0;repeat<map(analogRead(A0),0,1023,1,150);repeat++){ //Speed Control with Analog Read
      for(int i=0;i<scount.length();i++){
        snum=scount[i];
        PORTD=num[snum.toInt()];
        int n=pow(2,scount.length()-i-1)+.5;
        PORTB=B111111-byte(n);
        delay(5/scount.length());
        PORTB=B111111;
      }
    }
  }
}
