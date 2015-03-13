###CORE:
####Storages.h  
 * class *Storage_List<typename>* //(Linked list, связный список)
 
                  |  Storage_List()                                   |  Создать связный список.
                  |  Storage_List(const Storage_List& storage)        |  Создать копию данного связного списка.
                  |---------------------------------------------------|
        void      |  add(const Item& item)                            |  Добавить элемент в список.
        bool      |  canMove_next()                                   |  Проверить, можно ли перейти к следующему элементу.
        void      |  clear()                                          |  Очистить список.
        Item      |  get()                                            |  Получить данные текущей ячейки.
        void      |  move_next()                                      |  Перейти к следующему элементу в списке.
        void      |  remove_next()                                    |  Удалить ячейку, следующую за текущей. Первая ячейка не удаляется.
        void      |  rewind()                                         |  Вернуть счетчик списка в начало.

 * class *Storage_Array<typename>* //(Dynamiс array, динамический массив) 
 
                  |  Storage_Array()                                  |  Создать динамический массив.
                  |  Storage_Array(const Storage_Array &storage)      |  Создать копию данного динамического массива.
                  |---------------------------------------------------|
        void      |  add(const Item&)                                 |  Добавить элемент в динамический массив.
        unsigned  |  size() const                                     |  Узнать количество элементов.
                  |---------------------------------------------------|
        Item&     |  operator[] (unsigned num)                        |  Получить данные ячейки с номером num.
        void      |  operator= (const Storage_Array &storage)         |  Создать копию динамического массива через присваивание.
