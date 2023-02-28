float readUltrasonicSensor(){
  
  float aux = sensor.cm;
  sensor.microSec = ultrasonicSens.timing();
  sensor.cm = ultrasonicSens.convert(sensor.microSec, Ultrasonic::CM);
  return sensor.cm;
  
}
