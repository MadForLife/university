## Какво представляват класовете?  
- Класовете са потребителски дефиниран тип данни, използван за представяне на обекти от заобикалящия ни свят

## Класовете включват:  
- член-данни
- член-функции

## Членовете на класа могат да бъдат:  
- частни - private
- публични - public
- защитени - protected

## Дефиниция на клас:  
```
class <име на класа>
{
  public:
    //декларация на конструктори
    //декларация на член-функции
    
  private:
    //декларация на член-данни
    
  protected:
}
```
**Пример**  
```
class Student
{
  public:
    Student();
    Student(const char* name, int facultyNum);
    
    void read();
    void print() const;
    bool is_better_than(Student student) const;
    
  private:
    char* firstName;
    int facultyNum;
}
```

## Член-функции  
- По своето действие върху член-данните член-функциите биват
- - **Мутатори** - променят данните на обекта  
- - **Аксесори** - не променят стойностите на данните от обекта, дефинират се като константни **"const"**

## Капсулация  
- Състояние на обекта - всеки обект на клас съхранява конкретни стойности, които се задават чрез конструктора и могат да се променят чрез мутаторите
- Действието по скриване на детайли от имплементаццията се нарича капсулация
- Член-данните са част от класа, които обичайно не са видими за потребителите на класа

## Конструктор по подразбиране
- Конструкторите са специални функции, чрез които се създават и се инициализират нови обекти.  
- Конструкторите са член-функции на класа, които:
- - имат същото име, като името на класа
- - не връщат тип
- Конструктор без параметри се нарича конструктор по подразбиране `Student();`
- Извикване на конструктор по подразбиране `Student st1();`

## Пример за интерфейс на клас  
```
class Student
{
  public:
    Student();                                               //Конструктор по подразбиране
    Student(const char* name, double grade);                 //Конструктор с параметри
    
    void read();                                             //мутатор
    void setName();                                          //мутатор
    void setGrade();                                         //мутатор
    bool is_better_than(Student student) const;              //аксесор
    
    void print() const;                                      //аксесор
    char* getName() const;                                   //аксесор
    double getGrade() const;                                 //аксесор
    
    private:
      char* name;                                            //член-данна
      double grade                                           //член-данна
}
```

## Капсулация  
- Капсулацията се извършва чрез следните спецификатори за достъп  

| спецификатор | описание |
| --- | --- |
| public | членовете са достъпни навсякъде, където обект от този клас е видим |
| private | членовете са достъпни само от други членове на същия клас или приятели на класа |
| protected | членовете са достъпни от други членове на същия клас и от членовете на класовете, които наследяват този клас или приятели на класа |
- Обявените като "приятели" **"friend"** функции и други класове имат достъп до всички членове на класа. Това е нарушаване на принципа за капсулиране, но създава удобства при взаймодействие между класовете.
- Целта на капсулацията е да защити и запази целостта на обекта  
  
**Пример**  
```
Student st1("Иван Иванов", 4.89);

st1.grade += 2; //Проблем - ще получим успех 6.89
```
  
**Решение**  
Функцията `void setGrade(double grade)` ще се погрижи успехът на студента винаги да е стойност от 2 до 6

## Дефиниране на член-функции  
- Дефиницията е аналогична на дефиницията на обикновена функция, но името на член-функцията се предшества от името на класа, 
на който тя принадлежи, следвано от оператор за принадлежност `::` **"оператор за област на действие"**  
  
**Пример**  
```
void Student::print() const
{
  cout << "Име на студент: " << name << endl;
  cout << "Среден успех: " << grade << endl;
}
```

## Параметри на член-функция  
- Функцията `Student::print() const;` ще отпечата член-данните `name` и `grade` за конкретен обект.  
Извиква се през име на обект `st1.print();`  
- В кода на член-функцията обектът не се споменава, т.е обектът се явява имплицитен **"неявен"** параметър на член-функцията
- Параметър, който е изрично зададен на функцията, както е параметърът `student` във функцията `is_better_than`, се нарича експлицитен **"явен"** параметър
- Всяка член-функция има точно един имплицитен параметър и 0 или повече експлицитни параметри  
  
## Пример  
```
if (st2.is_better_than(st1)) { . . . }
```

- st2 - имплицитен параметър
- st1 - експлицитен параметър

## Дефиниция на член-функция  
```
bool Student::is_better_than(Student student) const
{
  if (grade > student.grade) return true;
  return false;
}
```

## Вградени член-функции  
```
class Point
{
  public:
    Point() { x = 0; y = 0; }
    Point(int a, int b) { x = a; y = b; }
    
    **inline** int get_x() const { return x; } //inline е излишно
    int get_y() const { return y; }
    void print() const { cout << x << "," << y; }
    
    private:
      int x, y;
}
```
- Всички дефинирани по този начин член-функции на класа `Point` са `inline`
- Цел на вградените член-функции
- - Повишаване бързодействието на програмите, тъй като кода на вградените функции не са съхранява на едно място, а се копира на всяко място в паметта
на програмата, където има обръщение към функцията.

## Конструктори  

### Дейности при създаване на обекти  
- отделяне на памет
- задаване на начални стойности на член-данните
- запомняне на текущо състояние

### Инициализиране на обекти - изпълнява се от специални член-функции наречени конструктори  
- Всеки клас трябва да има поне един или повече конструктори
- Конструктор без параметри се нарича конструктор по подразбиране

### Конструктор по подразбиране - пример  
```
Student::Student()
{
  name = new char[2];
  name = " ";
  
  grade = 2;
}
```

## Деструктор
- При разрушаването на обекти се извършват заключителни действия - освобождаване на динамично заета памет, затваряне на файлове и др.
- Заключителните действия са противоположни на ефекта на инициализация
- Автоматизацията на заключителните действия се осъществява чрез деструкторите  

### Деструкторът е специална член-функция за която:  
- името и съвпада с името на класа
- името и е предшествано от знака тилда `~`
- няма тип на връщан резултат
- не приема параметри
- извиква се автоматично
  
### Извиква се при:  
- излизането от блок, в който е бил създаден обект от клас
- разрушаване на обект чрез оператор `delete` или `delete[]`

### Ако в класа липсва декларация на деструктор, то от компилатора се създава десктруктор по подразбиране  
```
Student::~Student()
{
  delete[] name;
}
```

## Предефинирани конструктори  
- C++ позволява да имаме дефинирани няколко функции с едно и също име, стига те да се различават по списъка си с параметри броя и/или типа на параметрите  
- Конструкторите с параметри могат да приемат параметри за всяка една член-данна на класа или за част от тях
  
### Пример  
`Student() и Student(char* name, double grade)`  
```
Student::Student()
{
  name = new char[2];
  name = " ";
  grade = 2;
}

Student::Student(char* name, double grade)
{
  this->name = new char[strlen(name) + 1];
  strcpy_s(this->name, strlen(name) + 1, name);
  
  if (grade >= 2 && grade <= 6) this->grade = grade;
  else if (grade < 2) this->grande = 2;
  else this->grade = 6;
}
```

## Извикване на конструктори  
```
int main()
{
  Student st1;                                    //извиква се конструктора по подразбиране
  Student st2("Иван Иванов", 5.32);               //извиква се конструктора с параметри Student(char* name, double grade)
  
  return 0;
}
```

### В определени случай един конструктор е необходимо да извика друг конструктор, за да успее да инициализира член-данните си  
```
{
  . . .
  
  name = new char[strlen(name) + 1];
  strcpy_s(this->name, strlen(name) + 1, name);
  
  if (grade >= 2 && grade <= 6) this->grade = grade;
  else if (grade < 2) this->grande = 2;
  else this->grade = 6;
  
  signin = Date(signin_year, 0, 0);               //извикване на конструктора на класа Date
  graduate = Date(graduate_year, 0, 0);           //извикване на конструктора на класа Date
  
}
```

### Опит за изчистване на обект чрез извикване на конструктор  
```
Student ivan("Иван Иванов", 4,58);

. . .

ivan.Student();                           //Грешка, констуркторите се извикват само при създаване на обект

Student temp();                           //Създава се нов обект, който е празен и се присвоява на ivan
ivan = temp;                              //присвояване
```

## Конструктор с инициализиращ списък  
- Целта му е да създаде конструктор, който инициализира член-данните преди тялото на конструктора  
```
Point::Point(int x, int y) : x(x), y(y) {}
```

## Конструктор с подразбиращи се параметри  
- C++ поддържа функции с подразбиращи се параметри, като за тях се задават подразбиращи се стойности
- Подразбиращи се стойности се използват само ако при извикването на функцията не се зададе стойност
- Задаване на подразбираща се стойност за параметър се извършва чрез включване на конкретната стойност за параметъра в прототипа на конструктора или в заглавието на неговата дефиниция

```
class Point
{
  private:
    int x, y;
    
  public:
    Point(int x = 0, int y = 0);
}
```

- Конструкторът `Point(int x = 0, int y = 0)` е както конструктор с параметри, така и конструктор по подразбиране
- При копиране на обекти се извършва по битово копиране на съдържанието на тяло на обекта на ново място в паметта

## Случай при които се налага копиране на обекти  
- присвояване между еднотипни обекти
- предаване на обект като параметър по стойност във функция 
- при присвояване копираната двоична последователност става ново съдържание на обекта, стоящ от ляво на операцията за присвояване. Този обект се деструктурира при напускане на неговота област на действие

```
  Point a;
  Point b(4, 7);
  
  a = b;
  
  a.print();
  b.print();
```
- при предаване на обект като фактически параметър по стойност, двоичното съдържание на обекта се копира в стековата рамка на извикваната функция. Това копие се деструкторира автоматично и задължително
при излизане от функцията, преди разпадане на нейната стекова рамка

## Копиране на обекти - проблеми  
- При копиране ако копието споделя общи ресурси с оригинал (най-често ако има динамична памет), автоматично извикване на деструктор за копиран обект, може да повреди оригинала  
  
![shared-memory-cpp-white](https://user-images.githubusercontent.com/35624178/214884807-c62e7fef-7f43-449b-b3f7-ce9de026613b.png)  
  
- Извикване на деструктор за копието  
    
  ![shared-memory-corrupt](https://user-images.githubusercontent.com/35624178/214890338-bfd0f98f-d713-46f3-878c-fd0ba11a91e3.png)

  
- Резултат - повреда на оригинала  
  
![shared-memory-corrupted-final](https://user-images.githubusercontent.com/35624178/214888727-339e2e96-e0e0-4844-a626-308829484d6c.png)




## Копиращ конструктор  
- за избягване на по битово копиране не обекти в C++ е предвиден специален конструктор - копиращ конструктор
- той приема като параметър обект от същия клас, предаван по адрес

```
Student (const Student& rhs)
{
  name = new char[strlen(rhs.name) + 1];
  strcpy(name, rhs.name);
  
  grade = rhs.grade;
}
```
- ако е дефиниран копиращ конструктор компилаторът автоматично и задължително го прилага вместо да копира бит по бит
- синтаксис - `<име на клас>(const <име на клас>&, <име на обект>) { <тяло> }`  

### Пример за извикване на копиращ конструктор  
```
Student st1;          //конструктор по подразбиране
Student s2 = s1;      //извиква се копиращ конструктор и за обект s2 се копират данните от обект s1
Student s3(s1);       //тук също се извиква копиращ конструктор и за обект s3 се копират данните от обект s1
```

## Указател **this**  
- всяка член-функция на клас поддържа допълнителен формален параметър - указател с име **this**  
- **this** е от тип <име_на_клас>* за член-функциите, които са мутатори
- **this** е от тип const <име_на_клас>* за член-функциите за достъп

```
void Student::setGrade(double grade)
{
  if (grad >= 2 && grade <=6) this->grade = grade;
  else if (grade < 2) this-> grade = 2;
  else this->grade = 6;
}
```

## Ключовата дума **explicit**
- едноаргументните конструктори могат да се използват за неявно преобразуване на типа на обектите от един тип в друг
- това може да се ограничи и да се "заставят" едноаргументните конструктори и да използват само за създаване на нови обектим, чрез ключовата дума **explicit**
