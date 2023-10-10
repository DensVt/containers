# Реализация контейнерных классов
- Контейнерные классы в программировании предоставляют удобные механизмы для хранения и управления наборами объектов. В зависимости от специфических требований задачи, разработчики могут выбрать наиболее подходящий контейнер.

### Основные особенности контейнеров:

- Организация объектов: Например, list может хранить любые объекты, в то время как set - только уникальные.
- Методы доступа: Каждый контейнер предоставляет свой набор методов для работы с данными.
- Итераторы: Предоставляют унифицированный доступ к элементам контейнера.
- Шаблонизация: Позволяет использовать контейнер для различных типов данных.
- Типы контейнеров: Последовательные и ассоциативные контейнеры имеют различную внутреннюю структуру и методы доступа.

### Цель - создать библиотеку контейнерных классов С++, включая:

- list (список)
- map (словарь)
- queue (очередь)
- set (множество)
- stack (стек)
- vector (вектор)
- Для каждого контейнера реализуйте соответствующие методы доступа, итераторы и другие функциональные возможности.


### Реализация

- Программа написана на C++ (стандарт C++17) с использованием компилятора gcc.
- Код размещен в папке src.
- Формат в Google Style при написании кода.
- Обязательное использование итераторов.
- Все классы шаблонизированы.
- Использование пространства имен s21 для классов.
- Покрытие всех методов контейнеров unit-тестами с использованием библиотеки GTest.
-Без использования реализации из стандартной библиотеки шаблонов (STL).
- логика работы STL (в части работы с памятью, проверок и обработки исключительных ситуаций).
- Реализация библиотеки s21_containers.h
- Реализация классов библиотеки s21_containers.h:
- list: Двусвязный список.
- map: Словарь с уникальными ключами.
- queue: Очередь с механизмом FIFO.
- set: Множество уникальных элементов.
- stack: Стек с механизмом LIFO.
- vector: Динамический массив.
- Создание заголовочного файла s21_containers.h, который включает другие заголовочные файлы (s21_list.h, s21_map.h и так далее).

### Дополнительно. Реализация библиотеки s21_containersplus.h
- дополнительные контейнеры:
- array: Статический массив.
- multiset: Множество, которое может содержать повторяющиеся элементы.
- Оформление в виде заголовочного файла s21_containersplus.h.
