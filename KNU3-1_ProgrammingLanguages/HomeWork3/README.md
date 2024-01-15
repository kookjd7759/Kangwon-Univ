# Kangwon national university

3nd year 1nd semester

## Programming Languages
#### Third Homework
Grade : 100.00 / 100.00

Grade on : 2022-04-30 16:53

Graded by	: KimSeongU

### Ocaml 연산(2) 및 데이터 구조

##### Question 1. Recursive functions on integers

##### Question 1.1. sum for adding integers 1 to n (inclusive) [10점]

(타입) sum : int -> int

(설명) sum n returns Sumation i=1 to n i. 공식을 사용하지 말고 자기호출 함수로 작성할 것.
(가정) n > 0.




##### Question 1.2. fac for factorials [10점]
(타입) fac: int -> int

(설명) fac n returns Πi=1 to n i. 즉, 1 × . . . × n을 자기호출 함수로 계산할 것.

(가정) n > 0.




##### Question 1.3. fib for Fibonacci numbers [10점]
(타입) fib: int -> int

(설명)

fib n returns fib (n − 1) + fib (n − 2) when n ≥ 2.

fib n returns 1 if n = 0 or n = 1.

(가정) n ≥ 0.




##### Question 1.4. 최대공약수를 계산하는 gcd 함수 [10점]
(타입) gcd: int -> int -> int

(설명) gcd m n는 유클리드 호제법을 이용하여 m과 n의 최대공약수를 반환한다.

(가정) m ≥ 0, n ≥ 0, m + n > 0.




##### Question 1.5. max for finding the largest integer in a list of integers [10점]
(타입) max: int list -> int

(설명) max l returns the largest integer in the list l. If an empty list is given, return 0.

(가정) Every element in a given list is greater than or equal to 0.





##### Question 2. Functions on binary trees
아래는 이진 나무 구조를 정의하는 타입 정의이다. 리프 노드(leaf node)도 정수 값을 인자로 가짐에 유의하라.

type tree = Leaf of int | Node of int * tree * tree

##### Question 2.1 sum tree for computing the sum of integers stored in a binary tree [10점]
(타입) sum tree : tree -> int

(설명) sum tree t returns the sum of integers stored in the tree t.

(실행 예) sum tree (Node (7, Node (3, Leaf 1, Leaf 2), Leaf 4)) returns 17.




##### Question 2.2. depth for computing the depth of a tree [10점]
(타입) depth : tree -> int

(설명) depth t returns the length of the longest path from the root to leaf.

(실행 예) depth (Node (7, Node (3, Leaf 1, Leaf 2), Leaf 4)) returns 2.




##### Question 2.3. bin search for searching an element in a binary search tree [10점]
(타입) bin search : tree -> int -> bool

(설명) bin search t x returns true if the number x is found in the binary search tree t; otherwise it returns false.

(가정) t는 이진 검색 나무: t의 모든 내부 노드(internal node) t; 0에 대해, t0의 왼쪽 하위 나무에 있는 노드들은 t0에 저장된 정수 값보다 작은 값을 가지며, t0의 오른쪽 하위 나무에 있는 노드들은 t0에 저장된 정수값보다 큰 값을 갖는다. 또한 이진 검색 나무의 노드들에 저장된 정수 값들은 모두 다르다고 가정하라.

(실행 예) 

bin search (Node (4, Node (2, Leaf 1, Leaf 3), Leaf 7)) 2 returns true.

bin search (Node (4, Node (2, Leaf 1, Leaf 3), Leaf 7)) 5 returns false.




##### Question 3. Arithmetic expressions
Consider the following type definition for arithmetic expressions.

type exp =

INT of int

| ADD of exp * exp

| SUB of exp * exp

| MUL of exp * exp

| DIV of exp * exp

| MOD of exp * exp




##### Question 3.1. interp for computing the value of an arithmetic expression [10점]
(타입) interp : exp -> int

(설명) interp e returns the integer value of the arithmetic expression e.

(실행 예) interp (ADD (SUB (INT 100, INT 10), MUL (INT 2, INT 8))) returns 106.




##### Question 4. Propositional logic
Consider the following type definition for propositional logic.

type formula =

True

| False

| Neg of formula

| Or of formula * formula

| And of formula * formula

| Imply of formula * formula





##### Question 4.1 eval for computing the boolean value of a formula [10점]
(타입) eval : formula -> bool

(설명) eval f returns the boolean value of the formula f.

(실행 예) eval (Imply (And (True, Or (True, False)), False)) returns false.
