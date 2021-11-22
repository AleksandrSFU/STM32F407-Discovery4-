# STM32F407-Discovery4-
Приведено описание работы с аналого - цифровым преобразователем в задачи оконного анализа гармонического сигнала по критериям:  
RMS - Действующее значение сигнала за период окна анализируемой выборки. 
AVG - Среднее значение сигнала за период окна анализируемой выборки. 
Peak - Мгновенное значение сигнала в окне анализируемой выборки 
Окно прямоугольное. Уровень боковых лепестков второй гармоники -13 дБ. 

Алгоритм работы с платформой Discovery4:  
1. Команда в терминал start -пуск анализа сигнала, зажигается светодиод зеленый. 
2. Команда в терминал stop - остановка анализа данных, никаких процессов не выполняется, зажигается светодиод красный. 
3. Команда в терминал result - печать в терминал из памяти ПЗУ микроконтроллера вычисленных значений, зажигается светодиод оранжевый. 
 
Содержание темы:  
1. Двоичный файл: STM32F407_Voltmeter.bin 
2. Текст исходного кода на С++: 
3. STM32F407_Voltmeter.ino 
4. Скриншот чтения и записи в память ПЗУ на STM32F407_Voltmeter.bin файла в среде STM32Programmer 

![Скриншот STM32Programmer](https://user-images.githubusercontent.com/19923990/142849766-1db31049-9a06-4cb6-a35f-08f67d876379.png)
  |Discovery4|Stlink-v2||
  |----------|----------|
  |    VCC   |  +3.3В   |
  |    GND   |   GND    | 
  |    PA13  |  SWDIO   | 
  |    PA14  |  SWCLK   |
![Фотография соединения Discovery4 c компьютером](https://user-images.githubusercontent.com/19923990/142849794-eb21ce3c-5dc9-47af-a11b-b9aa1ba8b47f.jpg)
