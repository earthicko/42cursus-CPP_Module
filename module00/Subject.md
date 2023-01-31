# 모듈 00

Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff

## 예제 00

|제출 디렉토리|제출 파일|금지된 함수|
|-------------|---------|-----------|
|`ex00/`|`Makefile`, `megaphone.cpp`|없음|

다음과 같이 동작하는 프로그램을 작성하라.

```bash
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

## 예제 01

|제출 디렉토리|제출 파일|금지된 함수|
|-------------|---------|-----------|
|`ex01/`|`Makefile`, `*.cpp`, `*.{h, hpp}`|없음|

전화번호부 소프트웨어처럼 작동하는 프로그램을 작성하라.

다음 두 클라스를 구현하라.
- `PhoneBook`
  - 연락처의 배열을 가지고 있다.
  - 최대 8개의 연락처를 저장할 수 있다. 사용자가 9번째 연락처를 저장하려 할 시 가장 오래된 것을 새 연락처로 교체한다.
  - 동적 할당은 금지되어 있다.
- `Contact`
  - 전화번호부의 연락처를 상징한다.

전화번호부 및 연락처의 개체를 생성할 때는 반드시 `PhoneBook` 클라스를 사용해야 한다. 클라스를 자유롭게 설계하되 클라스 내부에서만 사용될 것들은 private하고, 그렇지 않은 것들은 public하다는 점을 주지하라.

프로그램이 시작하면 전화번호부는 비어 있고 사용자에게 다음 3 종류의 명령을 입력할 수 있는 프롬프트를 제공한다. 이 프로그램은 ADD, SEARCH, EXIT 명령을 지원한다.

- ADD: 새 연락처 추가
  - 이 명령을 입력하면 프롬프트에 새 연락처의 항목들을 하나씩 입력할 수 있다. 모든 항목을 입력하면 전화번호부에 연락처를 추가한다.
  - 연락처의 항목은 first name, last name, nickname, phone number, darkest secret이다. 빈 항목이 존재할 수 없다.
- SEARCH: 특정 연락처를 표시
  - 저장된 연락처를 index, first name, last name, nickname의 4개 행으로 표시한다.
  - 각 행은 10개 문자 너비를 차지한다. | 문자로 행을 나눈다. 텍스트를 오른쪽 정렬한다. 텍스트가 행보다 길 경우 표시할 수 있는 만큼만 표시하고 마지막 문자는 .으로 대체한다.
  - 그 다음 표시할 연락처의 index를 프롬프트를 통해 입력받는다. 인덱스가 범위를 벗어나거나 잘못된 값일 시 프로그램의 행동을 정의해야 한다. 그렇지 않을 시 연락처의 정보를 한 줄에 하나씩 표시한다.
- EXIT
  - 프로그램이 종료되며 연락처 정보는 저장하지 않는다.
- 이외 입력은 무시된다.

명령이 올바르게 실행되었다면 프로그램은 다음 명령을 기다려야 한다.

실행 파일에 적절한 이름을 부여한다.

> http://www.cplusplus.com/reference/string/string/
> http://www.cplusplus.com/reference/iomanip/

## 예제 02

|제출 디렉토리|제출 파일|금지된 함수|
|-------------|---------|-----------|
|`ex02/`|`Makefile`, `Account.cpp`, `Account.hpp`, `tests.cpp`|없음|

> `Account.hpp`, `tests.cpp`, 로그 파일을 인트라넷 페이지에서 다운로드할 수 있다.

`tests.cpp`를 컴파일하면 `Account.cpp` 파일이 유실되었다는 것을 확인할 수 있다. `Account.hpp`와 로그 파일을 참조하여 `Account` 클라스가 어떻게 구현되었는지 유추할 수 있다.

`Account.cpp`를 작성하라. 프로그램의 출력값은 타임스탬프를 제외하고 로그 파일과 동일해야 한다.

> 소멸자의 호출 순서는 컴파일러나 운영 체제에 따라 달라질 수 있다.
> 
> 예제 02를 수행하지 않아도 이 모듈을 통과할 수 있다.
