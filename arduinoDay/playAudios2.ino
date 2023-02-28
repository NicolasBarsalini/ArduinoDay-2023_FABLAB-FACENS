void playAudios2()
{
  int clock_millis = 0, clock_seg = 0, clock_min = 0;
  int touch_Yes = 0;
  int touch_No = 0;
  mp3_play(3);
  delay(3200);
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
    loop();
  }

  if(touch_No == 1)
  {
    Serial.println("Touch No has been pressed!");

    question2.no++;
    EEPROM[4] = question2.no;
    Serial.print("Touches in question2 for NO: ");
    Serial.println(question2.no);
    
    mp3_play(4);
    delay(31000);
    playAudios3();
  }

  if(touch_Yes == 1)
  {
    Serial.println("Touch Yes has been pressed!");
    
    question2.yes++;
    EEPROM[3] = question2.yes;
    Serial.print("Touches in question2 for YES: ");
    Serial.println(question2.yes);    
  
    playAudios3();
  }
  
}
