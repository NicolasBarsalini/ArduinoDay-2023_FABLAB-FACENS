void playAudios1()
{
  int clock_millis = 0, clock_seg = 0, clock_min = 0;
  int touch_Yes = 0;
  int touch_No = 0;
  mp3_play(1);
  digitalWrite(poster, HIGH); //turn on the led of the poster
  delay(4200);
  Serial.print("Waiting touch Yes/No");
  
  while(touch_Yes == 0 && touch_No == 0 && clock_min < 1)
  {
    if(digitalRead(touch1yes) == HIGH)
      touch_Yes = 1;
      
    if(digitalRead(touch2no) == HIGH)
      touch_No = 1;
      
    Serial.print("TouchYes: "); Serial.println(touch_Yes);
    Serial.print("TouchNo: "); Serial.println(touch_No);

    delay(200);

    if(clock_millis >= 5){
      clock_millis = 0;
      clock_seg++;
      Serial.print("Clock: "); Serial.print(clock_min); Serial.print(":"); Serial.println(clock_seg);
    }
    else{
      clock_millis++;
    }
    if(clock_seg >= 60){
      clock_seg = 0;
      clock_millis = 0;
      clock_min++;
      Serial.print("Clock: "); Serial.print(clock_min); Serial.print(":"); Serial.println(clock_seg);
    }
  }

  if(clock_min == 1){
    annulled++;
    EEPROM[7] = annulled;
    Serial.print("Clock: "); Serial.print(clock_min); Serial.print(":"); Serial.println(clock_seg);
    Serial.println("ANNULLED!");
    digitalWrite(poster, LOW);
    loop();
  }

  if(touch_Yes == 1)
  {
    Serial.println("Touch yes has been pressed!");

    question1.yes++;
    EEPROM[1] = question1.yes;
    Serial.print("Touches in question1 for YES: ");
    Serial.println(question1.yes);
        
    mp3_play(2);
    delay(14800);
    playAudios2();
 }

  if(touch_No == 1)
  {
    Serial.println("Touch No has been pressed!");
        
    question1.no++;
    EEPROM[2] = question1.no;
    Serial.print("Touches in question1 for NO: ");
    Serial.println(question1.no);
        
    mp3_play(7);
    delay(3200);
    digitalWrite(poster, LOW);
  }
  
}
