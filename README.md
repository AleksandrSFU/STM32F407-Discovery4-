# STM32F407-Discovery4-
Приведено описание работы с аналого - цифровым преобразователем в задачи оконного анализа гармонического сигнала по критериям:  RMS - Действующее значение сигнала за период окна анализируемой выборки. AVG - Среднее значение сигнала за период окна анализируемой выборки. Peak - Мгновенное значение сигнала в окне анализируемой выборки Окно прямоугольное. Уровень боковых лепестков второй гармоники -13 дБ. Алгоритм работы с платформой Discovery4:  Команда в терминал start -пуск анализа сигнала, зажигается светодиод зеленый. Команда в терминал stop - остановка анализа данных, никаких процессов не выполняется, зажигается светодиод красный. Команда в терминал result - печать в терминал из памяти ПЗУ микроконтроллера вычисленных значений, зажигается светодиод оранжевый. Содержание темы:  Двоичный файл: STM32F407_Voltmeter.bin Текст исходного кода на С++: STM32F407_Voltmeter.ino Скриншот чтения и записи в память ПЗУ на STM32F407_Voltmeter.bin файла в среде STM32Programmer Структурная схема записи *bin файла внутрисхемным программатором Stlink v2.