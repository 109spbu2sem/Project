# Используйте ТОЛЬКО английский язык в комментариях к своему коду
#### Базовая схема проекта:

    ====================================================================  
    |..............______..............................................|  
    |.............|......|..........|=======|..........................|  
    |.............|.User.|.=.=.=.=>.|=.GUI.=|..........................|  
    |.............|______|..........|=======|..........................|  
    |................................||.../\...........................|  
    |................................||../..\..........................|  
    |............................(1).||...||...........................|  
    |................................||...||.(2).......................|   
    |...............................\../..||...........................|   
    |................................\/...||...........................|   
    |......|========|.....(3)......|========|....(4)....|========|.....|   
    |......|=.SAVE.=|.<===========.|=.CORE.=|.<========.|=.OPEN.=|.....|   
    |......|========|..............|========|...........|========|.....|   
    |..................................................................|   
    |..................................................................|   
    ====================================================================   

GUI (Graphic User Interface) - блок интерфейса пользователя, связь с разумными или не очень существами  
CORE (англ. Ядро) - блок ядра программы, ключевая часть, самая легкая в написании кода, любой сможет её сделать  
SAVE (англ. Сохранить) - блок программы, отвечающий за сохранение информации во внешние файлы  
OPEN (англ. Открыть) - блок программы, отвечающий за открытие файлов программы, восстановление состояния программы

1. GUI :\ CORE

 > * Добавить примитив (точку, отрезок, дугу окружности)  
 > * Добавить объект (параллелограм, треугольник, домик, заборчик, сердечко...)  
 > * Добавить ограничения/правила/печеньки для объекта(ов)  
 > * Изменить состояние объекта (выделить, игнорировать, изменить тип линии)  
 > * ...  
    
2. CORE :\ GUI

 > * Нарисовать объект  
 > * Вывести ошибку  
 > * ...  
 
3. CORE :\ SAVE

 > * Сохранить в файл программы
 > * Сохранить в картинку (.jpg, .png, ...)
 > * ...

4. OPEN :\ CORE

 > * Добавить примитив (точку, отрезок, дугу окружности)  
 > * Добавить объект (параллелограм, треугольник, домик, заборчик, сердечко...)  
 > * Добавить ограничения/правила/печеньки для объекта(ов)  
 > * ...  
 
Документация к функциям находится в папке doc
