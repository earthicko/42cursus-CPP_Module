# 알고리즘

## float -> fixed

### 0. 예외 처리

- 사인 비트 외 모든 비트가 0일 시 `0`
- 지수 비트가 모두 1일 시 `exception`
- 지수 비트가 모두 0이고 맨티시가 모두 0은 아닐 시 서브노멀
  - 암시적으로 붙는 `1`을 없애고 지수를 `-126`로 세팅

### 1. 맨티사의 비트 패턴

- 서브노멀일 시 `a = 0`, 그 외 `a = 1`
- `[b:x]`는 맨티사 비트에서 복사

```
0000 0000 abcd efgh ijkl mnop qrst uvwx
```

### 2. 지수 추출

- 서브노멀일 시 `-126`, 그 외 `지수 비트에서 추출한 값 - 127`

### 3. 시프트

```
0000 0000 a.bcd efgh ijkl mnop qrst uvwx (2^0)
0000 0000 0000 0000 0000 000a.bcde fghi (>> 15)
0000 0000 abc.d efgh ijkl mnop qrst uvwx (2^2)
0000 0000 0000 0000 0000 0abc.defg hijk (>> 13)
```

지수가 `e`일 시 `(23 - nfracts) - e`번 우측으로 시프트

## fixed -> float

```
 seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm    meaning
31                              0    bit #

s = sign bit, e = exponent, m = mantissa
```

### 0. 예외 및 부호 처리

- 0일시 `0` 반환
- 음수일 시 사인 비트 `1`로 설정 후 원 수 부호 뒤집음
- 양수일 시 사인 비트 `0`로 설정

### 1. 지수 처리

```
                    15      8
                    i       n         0
                    |       |         |
abcd efgh ijkl mnop qrst uvwx.yzab cdef
```

가장 먼저 등장하는 `1`의 위치를 `[i]`라 하였을 시 `i - nFracts`번 소수점을 좌측으로 이동시켜야함, 지수는 `i - nFracts`가 됨

- 지수가 `-126` 이상이면
  - 지수에 `127`을 더한 값을 지수 비트에 세트
  - [2-1. 정상 맨티사 처리]로 진행
- 지수가 `-126` 미만이면
  - 지수 비트에 `0`을 세트
  - [2-2. 서브노멀 맨티사 처리]로 진행

### 2-1. 정상 맨티사 처리

`[i]`번 비트 오른쪽의 비트부터 우측으로 맨티사 비트의 개수만큼 맨티사 비트에 복사

```
                    15      8
                    i       n         0
                    |       |         |
abcd efgh ijkl mnop qrst uvwx.yzab cdef
          23
          |
seee eeee emmm mmmm mmmm mmmm mmmm mmmm
```

- 원본 수를 `FLOAT_BITPOS_EXP - i`번 좌측으로 시프트
- `[0:FLOAT_BITPOS_EXP]` 비트만 남김 (`FLOAT_MANTISSA_MASK`)
- 비트 복사

### 2-2. 서브노멀 맨티사 처리

`[nFracts - 127]`부터 우측으로 맨티사 비트의 개수만큼 맨티사 비트에 복사

- 좌측으로 `FLOAT_BITPOS_EXP - (_nFracts - FLOAT_EXP_SHIFT)`만큼 시프트
- `[0:FLOAT_BITPOS_EXP]` 비트만 남김 (`FLOAT_MANTISSA_MASK`)
- 비트 복사
