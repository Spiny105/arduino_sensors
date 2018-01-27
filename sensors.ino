#define SERIAL_BAUD_RATE  9600    

//Макросы для датчика температуры
#define TEMP_SENSOR_PIN   2     //Цифровой вход

//Макросы для датчика освещения
#define LIGHT_SENSOR_PIN  3     //Цифровой вход

//Макросы для датчика влажности
#define DRY_DIGITAL_PIN   4     //Цифровой вход
#define DRY_ANALOG_PIN    A0    //Аналоговый вход
#define DRY_THRESHOLD     900   //Порог срабатывания поливалки

//Макросы для поливалки
#define SPRINKLER_PIN     5

void setup() {
  // put your setup code here, to run once:
  Serial.begin (SERIAL_BAUD_RATE);
  pinMode(DRY_DIGITAL_PIN, INPUT);
  pinMode(TEMP_SENSOR_PIN, INPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
  pinMode(SPRINKLER_PIN, OUTPUT);
}

void loop() {
  String sensorType = "";
  int sensorValue = 0;
  //Опросить датчик влажности
  sensorValue = analogRead(DRY_ANALOG_PIN);
  sensorType = "     DRY ";
  Serial.print(sensorType);
  Serial.print(sensorValue);

  //Если влажность ниже заданной, то включить поливалку
  int sprinkler_on = (sensorValue > DRY_THRESHOLD) ? (1) : (0);
  digitalWrite(SPRINKLER_PIN, sprinkler_on);

  //Опросить датчик температуры
  sensorValue = digitalRead(TEMP_SENSOR_PIN);
  sensorType = "     TEMP ";
  Serial.print(sensorType);
  Serial.print(sensorValue);

  //Опросить датчик света
  sensorValue = digitalRead(LIGHT_SENSOR_PIN);
  sensorType = "     LIGTH ";
  Serial.print(sensorType);
  Serial.println(sensorValue);
  
  delay(2000);
}
