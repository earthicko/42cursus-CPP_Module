# 모듈 01

## 예제 00

|제출 디렉토리|제출 파일|금지된 함수|
|-------------|---------|-----------|
|`ex00/`|`Makefile`, `main.cpp`, `Zombie.{h, hpp}`, `Zombie.cpp`,
`newZombie.cpp`, `randomChump.cpp`|없음|

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

이 함수는 한번에 `N`개의 좀비 오브젝트를 할당하고 좀비를 파라미터로 전달받은 이름으로 초기화시킨다. 마지막 좀비의 포인터를 반환한다.

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
