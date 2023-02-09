# 모듈 01

Memory allocation, pointers to members, references, switch statement

## 예제 00

|제출 디렉토리|제출 파일|금지된 함수|
|-------------|---------|-----------|
|`ex00/`|`Makefile`, `main.cpp`, `Zombie.{h, hpp}`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`|없음|

`Zombie` 클라스를 구현하고 다음의 속성을 추가한다.

- `private` 스트링 `name` 속성
- `void announce( void );` 멤버 함수

`announce()`의 출력값은 다음과 같다.

```
<name>: BraiiiiiiinnnzzzZ...
```

꺽쇠 `<``>`는 출력하지 않는다. `Foo`라는 이름의 좀비의 출력값은 다음과 같다.

```
Foo: BraiiiiiiinnnzzzZ...
```

다음의 함수를 구현하라.

- `Zombie* newZombie( std::string name );`
  - 좀비를 생성하고 이름을 부여하여 반환한다. 이 좀비는 함수 바깥에서 사용될 수 있다.
- `void randomChump( std::string name );`
  - 좀비를 생성하고 이름을 부여한 후 `announce()`를 호출한다.

이 예제의 요점은 좀비를 스택이나 힙 중 어느 곳에 할당하는 것이 더 좋은 지 결정하는 것이다.

필요 없어진 좀비는 소멸되어야 한다. 디버그를 위해 소멸자가 좀비의 이름을 출력해야 한다.

## 예제 01

|제출 디렉토리|제출 파일|금지된 함수|
|-------------|---------|-----------|
|`ex01/`|`Makefile`, `main.cpp`, `Zombie.{h, hpp}`, `Zombie.cpp`,
`zombieHorde.cpp`|없음|

적절한 파일 내에 다음 함수를 구현하라.

```cpp
Zombie* zombieHorde( int N, std::string name );
```

이 함수는 한번에 `N`개의 좀비 오브젝트를 할당하고 좀비를 파라미터로 전달받은 이름으로 초기화시킨다. 첫번째 좀비의 포인터를 반환한다.

`zombieHorde()` 함수가 의도한대로 작동하는지 시험할 수 있는 테스트를 작성한다. 각 좀비에 대해 `announce()`를 호출해본다.

모든 좀비를 `delete`하고 메모리 누수를 검사해야한다.

## 예제 02

|제출 디렉토리|제출 파일|금지된 함수|
|-------------|---------|-----------|
|`ex02/`|`Makefile`, `main.cpp`|없음|

다음 사항을 포함한 프로그램을 작성하라.

- 스트링 변수 `"HI THIS IS BRAIN"`
- 스트링의 포인터 `stringPTR`
- 스트링의 레퍼런스 `stringREF`

이 프로그램은 다음 사항을 출력한다.

- 스트링의 메모리 주소
- `stringPTR`가 담은 메모리 주소
- `stringREF`가 담은 메모리 주소
- 스트링의 값
- `stringPTR`가 가리키는 주소의 값
- `stringREF`가 가리키는 주소의 값

이 예제의 목적은 레퍼런스가 무엇인지 이해하는 것이다.

## ex03

|Turn-in directory|Files to turn in|Forbidden functions|
|-------------|---------|-----------|
|`ex03/`|`Makefile`, `main.cpp`, `Weapon.{h, hpp}`, `Weapon.cpp`, `HumanA.{h, hpp}`, `HumanA.cpp`, `HumanB.{h`, `hpp}`, `HumanB.cpp`|None|

Implement a `Weapon` class that has:

- A `private` attribute type, which is a `string`.
- A `getType()` member function that returns a `const` reference to type.
- A `setType()` member function that sets type using the new one passed as parameter.

Now, create two classes: `HumanA` and `HumanB`. They both have a Weapon and a name. They also have a member function `attack()` that displays (of course, without the angle brackets):

```
<name> attacks with their <weapon type>
```

`HumanA` and `HumanB` are almost the same except for these two tiny details:

- While `HumanA` takes the Weapon in its constructor, `HumanB` doesn’t.
- `HumanB` may not always have a Weapon, whereas `HumanA` will always be armed.

If your implementation is correct, executing the following code will print an attack with "crude spiked club" then a second attack with "some other type of club" for both test cases:

```cpp
int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
```

Don’t forget to check for memory leaks.

> In which case do you think it would be best to use a pointer to Weapon? And a reference to Weapon? Why? Think about it before starting this exercise.

## ex04

|Turn-in directory|Files to turn in|Forbidden functions|
|-------------|---------|-----------|
|`ex04/`|`Makefile`, `main.cpp`, `*.cpp`, `*.{h, hpp}`|`std::string::replace`|

Create a program that takes three parameters in the following order: a `filename` and two `strings`, `s1` and `s2`.

It will open the file `<filename>` and copies its content into a new file
`<filename>.replace`, replacing every occurrence of `s1` with `s2`.


Using C file manipulation functions is forbidden and will be considered cheating. All the member functions of the class `std::string` are allowed, except `replace`. Use them wisely!

Of course, handle unexpected inputs and errors. You have to create and turn in your own tests to ensure your program works as expected.

## ex05

|Turn-in directory|Files to turn in|Forbidden functions|
|-------------|---------|-----------|
|`ex05/`|`Makefile`, `main.cpp`, `Harl.{h, hpp}`, `Harl.cpp`|None|

Do you know Harl? We all do, do we? In case you don’t, find below the kind of comments Harl makes. They are classified by levels:

- `"DEBUG"` level: Debug messages contain contextual information. They are mostly used for problem diagnosis.
  - Example: "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
- `"INFO"` level: These messages contain extensive information. They are helpful for tracing program execution in a production environment.
  - Example: "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
- `"WARNING"` level: Warning messages indicate a potential issue in the system. However, it can be handled or ignored.
  - Example: "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
- `"ERROR"` level: These messages indicate an unrecoverable error has occurred. This is usually a critical issue that requires manual intervention.
  - Example: "This is unacceptable! I want to speak to the manager now."

You are going to automate Harl. It won’t be difficult since it always says the same things. You have to create a Harl class with the following private member functions:

- `void debug( void );`
- `void info( void );`
- `void warning( void );`
- `void error( void );`

Harl also has a public member function that calls the four member functions above depending on the level passed as parameter:

`void complain( std::string level );`

The goal of this exercise is to use pointers to member functions. This is not a suggestion. Harl has to complain without using a forest of `if`/`else if`/`else`. It doesn’t think twice!

Create and turn in tests to show that Harl complains a lot. You can use the examples of comments listed above in the subject or choose to use comments of your own.

## ex06

|Turn-in directory|Files to turn in|Forbidden functions|
|-------------|---------|-----------|
|`ex06/`|`Makefile`, `main.cpp`, `Harl.{h, hpp}`, `Harl.cpp`|None|

Sometimes you don’t want to pay attention to everything Harl says. Implement a system to filter what Harl says depending on the log levels you want to listen to.

Create a program that takes as parameter one of the four levels. It will display all messages from this level and above. For example:

```
$> ./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years whereas you started working here since last month.
[ ERROR ]
This is unacceptable, I want to speak to the manager now.
$> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```

Although there are several ways to deal with Harl, one of the most effective is to SWITCH it off.

Give the name harlFilter to your executable.

You must use, and maybe discover, the switch statement in this exercise.

> You can pass this module without doing exercise 06.
