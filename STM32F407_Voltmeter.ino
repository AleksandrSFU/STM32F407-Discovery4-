// Автор кода: Александр Дранишников.
// Оборудование: Discovery4, микроконтроллер STM32F407 ядро Cortex M4.

#define Vin PA0   // Номер пина АЦП канала 0 на STM32F407
#define led1 PD12 // Светодиод GREEN
#define led2 PD13 // Светодиод ORANGE
#define led3 PD14 // Светодиод RED
#define led4 PD15 // Светодиод BLUE

int PA0_get;   // Переменная потока данных канала PA0 АЦП
float PA0_Vin; // Напряжение на входе PA0
float rms;     // RMS - Действующее значение за период
float avg;     // AVG - Среднее значение за период
float none = 0;// MAX - Мгновенное значения за период

unsigned long time1;    // Таймер задачи №1
unsigned long time2;    // Таймер задачи №2
#define time1_per 39285 // Время интегрирования: 1/(40*70/(40+70)) Гц = 39285 мкс

void setup() {
  Serial.begin(115200); //  Скорость UART, бод/сек
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  if (Serial.available() > 0){
    String bufString = Serial.readString();
    if (bufString == "start"){
        digitalWrite(led2, LOW); digitalWrite(led1, HIGH); digitalWrite(led3, LOW);
        if (micros() - time1 > time1_per){// ЗАДАЧА №1
          PA0_get = analogRead(Vin);        // Считывание данных с АЦП канал PA0
          PA0_Vin = PA0_get*0.0008056640625;// Пересчет отсчетов в напряжение, В
          time1 = micros();               // сброс таймера
          rms += pow(PA0_Vin,2 );         // Накопление суммы на интервале окна от 0 до time1_RMS
          avg += PA0_Vin;                 // Накопление суммы на интервале окна от 0 до time1_AVG
          none = max(abs(PA0_Vin), none);
        }
        rms = sqrt(rms/(time1_per*1000000));// Период, с
        avg = avg/(time1_per*1000000);      // Период, с
        digitalWrite(led2, LOW); digitalWrite(led1, LOW); digitalWrite(led3, LOW);
    }
    if (bufString == "stop"){
      digitalWrite(led2, LOW); digitalWrite(led1, LOW); digitalWrite(led3, HIGH);
    }
    if (bufString == "result"){
        digitalWrite(led2, HIGH); digitalWrite(led1, LOW); digitalWrite(led3, LOW);
        Serial.print("RMS: "); Serial.println(rms);
        Serial.print("AVG: "); Serial.println(avg);
        Serial.print("none:"); Serial.println(none);       
    }
    // default: // статус: idle - ничего не делает
  }
}
