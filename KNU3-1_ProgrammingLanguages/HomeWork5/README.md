# Kangwon national university

3nd year 1nd semester

## Programming Languages
#### Last Homework
Grade : 85.00 / 100.00

Grade on : 2022-06-14 16:30

Graded by	: KimSeongU

### Ocaml 함수 및 재귀 연산


##### Question 1. 람다 계산식 [20점]
lambda.ml 파일에는 다음과 같은 표현식 언어가 정의되어 있다.

type exp =

Var of var

| Lambda of var * exp

| App of exp * exp

and var = string

위 정의는 아래 람다 계산식(λ-calculus)의 추상 문법 구조를 구현한 것이다.

e ::= x | λx.e | e e

수업 시간에 배운 이름 없는 함수 fun x -> e는 λx.e의 다른 표현이다. 람다 계산식은 굉장히 간단해 보이지 만 튜링 완전한(Turing-complete) 언어이며 모든 OCaml 프로그램은 의미가 동일한 람다 계산식 프로그램으로 변환될 수 있다. 람다 계산식에서 프로그램은 변수(variable)거나, 함수(function or lambda abstraction), 또는 함수 적용식(function application)이다.

이번 숙제의 첫 번째 문제는 hw5.ml 파일에 있는 Problem1 모듈에 정의된 check 함수를 완성하는 것이다.

module Problem1 = struct

open Lambda

let rec check : exp -> bool =

fun _ -> raise NotImplemented

end

check 함수는 람다 표현식이 닫혀있는지(closed) 검사한다. 즉, 인자로 주어진 표현식에 자유 변수(freevariable)가 없으면 true를, 있으면 false를 반환한다. 다음은 닫혀있는 표현식의 예이다.

• Lambda ("a", Var "a")

• Lambda ("a", Lambda ("a", Var "a"))

• Lambda ("a", Lambda ("b", App (Var "a", Var "b")))

• Lambda ("a", App (Var "a", Lambda ("b", Var "a")))

다음은 닫혀있지 않은(unclosed) 표현식의 예이다.

• Lambda ("a", Var "b")

• Lambda ("a", App (Var "a", Lambda ("b", Var "c")))

• Lambda ("a", Lambda ("b", App (Var "a", Var "c")))

##### Question 2. KML 해석기 [30점]
다음은 수업 시간에 배운 L rec 언어를 확장한 KML(Kangwon ML)의 추상 문법 구조이다.

P ::= E

E ::= n 정수

| x 변수

| E + E 덧셈식

| E − E 뺄셈식

| E ∗ E 곱셈식

| E/E 정수 나눗셈, 예: 5/2 = 2

| −E 단항 마이너스, 예: −1, −(1 + 3)

| E == E 두 정수식 값이 같으면 true, 그렇지 않으면 false

| E <= E 왼쪽 식 값이 오른쪽 식 값보다 작거나 같으면 true, 그렇지 않으면 false

| E < E 왼쪽 식 값이 오른쪽 식 값보다 작으면 true, 그렇지 않으면 false

| E >= E 왼쪽 식 값이 오른쪽 식 값보다 크거나 같으면 true, 그렇지 않으면 false

| E > E 왼쪽 식 값이 오른쪽 식 값보다 크면 true, 그렇지 않으면 false

| not E 논리 부정 NOT

| E || E 논리합 OR

| E && E 논리곱 AND

| iszero E 0 테스트

| if E then E else E 조건식

| let x = E in E 지역 변수 선언식

| let rec f x = E in E 자기 호출 함수 선언식

| fun x -> E 이름 없는 함수

| E E 함수 적용식, 함수 호출

연산자 우선 순위와 결합 규칙은 OCaml에 정의된 것과 동일하다.

kml.ml 파일에는 다음과 같이 KML의 추상 문법 구조가 OCaml 데이터 타입으로 정의되어 있다. (위문법에 정의된 순서대로 생성자가 정의되어 있음.)

type program = exp

and exp =

NUM of int

| VAR of var

| ADD of exp * exp

| SUB of exp * exp

| MUL of exp * exp

| DIV of exp * exp

| UMINUS of exp

| EQ of exp * exp

| LE of exp * exp

| LT of exp * exp

| GE of exp * exp

| GT of exp * exp

| NOT of exp

| OR of exp * exp

| AND of exp * exp

| ISZERO of exp

| IF of exp * exp * exp

| LET of var * exp * exp

| LETREC of var * var * exp * exp

| FUN of var * exp

| APP of exp * exp

and var = string

본 문제에서는 Problem2 모듈에 정의된 run 함수를 완성해야 한다.

module Problem2 = struct

open Kml

exception Error

let rec run : program -> value =

fun _ -> raise NotImplemented

end

run 함수는 Kml.program 타입의 프로그램을 입력으로 받아 이를 실행하고, 그 결과 값을 Kml.value타입의 값으로 반환한다. 강의 슬라이드에 정의되어 있는 정적 유효 범위(static scoping)를 사용하는 실행의미 구조(operational semantics)를 참고하여 run 함수를 완성하라. 새롭게 추가된 비교식, 논리식 등에대한 실행 의미 구조는 다른 표현식의 의미 구조를 참고하여 구현하라. 아래 코드는 KML로 구현한 double 함수와 이에 대응되는 OCaml AST이다.

let rec double x =

if iszero x then 0 else (double (x - 1)) + 2

in double 6

LETREC ("double", "x",

IF (ISZERO (VAR "x"),

NUM 0,

ADD (APP (VAR "double", SUB (VAR "x", NUM 1)), NUM 2)),

APP (VAR "double", NUM 6))

위 OCaml 값을 run 함수의 인자로 넘겨서 실행하면 Int 12 값으로 계산되어야 한다.

##### Question 3. 이름 없는 KML 프로그램으로 번역하기 [25점]
nameless.ml 파일에는 자기 호출 함수 선언문(recursive function declaration)을 제외한 KML의 추상 문법구조가 다음과 같이 OCaml 데이터 타입으로 정의되어 있다.

type program = exp

and exp =

NUM of int

| VAR of var

| ADD of exp * exp

| SUB of exp * exp

| MUL of exp * exp

| DIV of exp * exp

| UMINUS of exp

| EQ of exp * exp

| LE of exp * exp

| LT of exp * exp

| GE of exp * exp

| GT of exp * exp

| NOT of exp

| OR of exp * exp

| AND of exp * exp

| ISZERO of exp

| IF of exp * exp * exp

| LET of var * exp * exp

| FUN of var * exp

| APP of exp * exp

and var = string

또한 이름 없는(nameless) KML 프로그램의 추상 문법 구조가 다음과 같이 정의되어 있다.

type nl_program = nl_exp

and nl_exp =

NL_NUM of int

| NL_VAR of int

| NL_ADD of nl_exp * nl_exp

| NL_SUB of nl_exp * nl_exp

| NL_MUL of nl_exp * nl_exp

| NL_DIV of nl_exp * nl_exp

| NL_UMINUS of nl_exp

| NL_EQ of nl_exp * nl_exp

| NL_LE of nl_exp * nl_exp

| NL_LT of nl_exp * nl_exp

| NL_GE of nl_exp * nl_exp

| NL_GT of nl_exp * nl_exp

| NL_NOT of nl_exp

| NL_OR of nl_exp * nl_exp

| NL_AND of nl_exp * nl_exp

| NL_ISZERO of nl_exp

| NL_IF of nl_exp * nl_exp * nl_exp

| NL_LET of nl_exp * nl_exp

| NL_FUN of nl_exp

| NL_APP of nl_exp * nl_exp

본 문제에서는 Problem3 모듈에 정의된 translate 함수를 완성해야 한다.

module Problem3 = struct

open Nameless

exception CannotTranslate

let rec translate : program -> nl_program =

fun _ -> raise NotImplemented

end

translate 함수는 Nameless.program 타입의 KML 프로그램을 인자로 받아 Nameless.nl_program 타입의 이름 없는 KML 프로그램을 반환한다. 수업 시간에 배운 내용을 바탕으로 translate 함수를 완성하라. 

예를 들어, 다음 프로그램은

LET ("x", NUM 37,

FUN ("y", LET ("z", SUB (VAR "y", VAR "x"),

SUB (VAR "x", VAR "y"))))

아래 이름 없는 프로그램으로 변환된다:

NL_LET (NL_NUM 37,

NL_FUN (NL_LET (NL_SUB (NL_VAR 0, NL_VAR 1),

NL_SUB (NL_VAR 2, NL_VAR 1))))

##### Question 4. 이름 없는 KML 해석기 [25점]
마지막 문제는 Problem4 모듈에 정의된 nl_run 함수를 완성하는 것이다.

module Problem4 = struct

open Nameless

exception Error

let rec nl_run : nl_program -> nl_value =

fun _ -> raise NotImplemented

end

nl_run 함수는 Nameless.nl_program 타입의 프로그램을 입력으로 받아 이를 실행하고, 그 결과 값을 Nameless.nl_value 타입의 값으로 반환한다. 강의 슬라이드에 정의되어 있는 실행 의미 구조를 참고하여 nl_run 함수를 완성하라. 새롭게 추가된 비교식, 논리식 등에 대한 실행 의미 구조는 다른 표현식의 의미구조를 참고하여 구현하라.

본 섹션까지의 숙제를 끝마치고 나면, (1) 임의의 KML 프로그램(자기 호출 함수가 없는)을 Problem2.run 함수로 실행해보고, (2) Problem3.translate을 이용하여 이름 없는 KML 프로그램으로 번역한 다음, (3) Problem4.nl_run을 이용하여 번역된 프로그램을 실행해볼 수 있다. 예를 들어, 아래 KML 프로그램 let pgm = LET ("x", NUM 1, VAR "x") 을 Problem2.run pgm으로 실행하면 그 결과는 Int 1이 되며, Problem4.nl_run (Problem3.translate pgm)으로 실행하면 그 결과는 NL_Int 1이 된다.
