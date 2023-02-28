void verifyDistanceFromSensor(float distanceFromSensor){
  
  if(distanceFromSensor <= 200){
    
     Serial.println("reading the same distance to confirm...");
     delay(1000);
     distanceFromSensor = readUltrasonicSensor();
     Serial.print("Currently distance: "); Serial.println(distanceFromSensor);
     
     if(distanceFromSensor <= 200){ //arrumar a distancia dps

      Serial.println("Playing the first audio!");

      playAudios1();
      
     }
        
  }
  
}
