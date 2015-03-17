# PAINT

## Что должна делать программа?
1. Рисовать примитивы, менять их расположение  
2. Выделять и удалять нарисованные примитивы  
3. Позволять задавать правила, которым должны удовлетворять объекты (причем только те, которые возможны для выбранного типа объектов)  
4. Сохранять результаты работы в файлы с возможностью дальнейшей работы с ними  

## Скриншот макета GUI  

![Screenshot](https://github.com/109spbu2sem/Project/blob/GUI/qt/screenshot.png?raw=true "Screenshot")

## Структура
###### Неактуальные файлы отмечены тильдой (~)
    main.cpp  
    /include  
      Structures.h  
      ~Storage.h  
      Storage_Template.h  
      ~LinkedList.h  
      LinkedList_Template.h   
      ~TreeStorage.h  
    /src  
      DynArrayP.cpp  
      DynArrayS.cpp  
      LinkedList.cpp  
      ~TreeStorage.cpp  
    /qt
      main.cpp  
      main.qml  
      qml.qrc  
      Paint.pro  
      Paint.pro.user  
      deployment.pri  
      screenshot.png  
    /test  
      ~test.cpp  
    ReadMe.md  
