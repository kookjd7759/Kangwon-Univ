# Kangwon national university

3nd year 1nd semester

## Programming Languages
#### Second Homework
Grade : 100.00 / 100.00

Grade on : 2022-04-16 21:07

Graded by	: KimSeongU

### Ocaml 연산(1)

##### Question 1. [10점] 1에서 n까지의 정수의 합을 구하는 함수 sum을 작성하라.

(타입) int -> int

(설명) sum n은 n ≤ 0인 경우 0을, n > 0인 경우 n(n+1) / 2 을 반환한다.



##### Question 2. [10점] 반지름이 r인 원의 넓이를 구하는 함수 circle을 작성하라.

(타입) float -> float

(설명) circle r은 r ≤ 0.0인 경우 0.0을, r > 0.0인 경우 3.14r^2을 반환한다.



##### Question 3. [10점] 문자열의 앞에 “Hello ”를 삽입하는 함수 concat을 작성하라.

(타입) string -> string

(설명) concat s는 문자열 s의 앞에 "Hello "를 삽입한 문자열을 반환한다. (Hello 뒤에 공백문자가 있음에 유의하라.)



##### Question 4. [10점] 논리연산자 xor를 계산하는 함수 xor를 작성하라.

(타입) bool -> bool -> bool

(설명) xor x y는 불린형 값 x와 y중 하나만 true일 경우에 true를, 이외의 경우 false를 반환한다.



##### Question 5. [10점] 세 정수를 변의 길이로 가지는 삼각형이 존재하는지 확인하는 함수 triangle을 작성하라.

(타입) int -> int -> int -> bool

(설명) triangle x y z는 x, y, z중 하나라도 0 또는 음수인 경우 false를, x, y, z가 모두 양수인 경우 x, y, z를 세 변으로 가지는 삼각형이 존재하면 true를, 존재하지 않으면 false를 반환한다.



##### Question 6. [10점] 두 정수의 합과 차 중 하나를 선택하는 함수 int if then else를 작성하라.

(타입) bool -> int -> int -> int

(설명) int if then else b x y는 b가 true이면, x + y를 false이면 x − y를 반환한다.



##### Question 7. [10점] 임의의 2차 함수에 대하여 두 함수 값의 합을 구하는 함수 sum of fun val를 작성하라.

(타입) int -> int -> int -> int -> int -> int

(설명) sum of fun val a b c d e는 a, b, c를 각각 2차항, 1차항, 상수항의 계수로 갖는 2차 함수 f(x) = ax2 + bx + c에 대하여 f(d) + f(e)의 값을 반환한다.



##### Question 8. [10점] 정수를 임의의 2차 함수에 세번 적용한 값을 계산하는 함수 comp3를 작성하라.

(타입) int -> int -> int -> int -> int

(설명) comp3 a b c d는 a, b, c를 각각 2차항, 1차항, 상수항의 계수로 갖는 2차 함수 f(x) = ax2 + bx + c에 대하여 f(f(f(d)))의 값을 반환한다.



##### Question 9. [10점] 두 번 반복된 문자열을 계산하는 함수 string2를 작성하라.

(타입) string -> string

(설명) string2 s는 문자열 s가 두 번 반복된 문자열을 반환한다.



##### Question 10. [10점] 2^8(= 256)번 반복된 문자열을 계산하는 함수 string256을 작성하라.

(타입) string -> string

(설명) string256 s는 문자열 s가 2^8(= 256)번 반복된 문자열을 반환한다.

(힌트) 9번에서 작성한 함수를 활용한다.
