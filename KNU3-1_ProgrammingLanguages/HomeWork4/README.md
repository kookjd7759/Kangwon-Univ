# Kangwon national university

3nd year 1nd semester

## Programming Languages
#### Fourth Homework
Grade : 100.00 / 100.00

Grade on : 2022-05-26 16:25

Graded by	: KimSeongU

### Ocaml 함수 및 재귀 연산

##### Question 1. list add for adding each pair of integers from two lists [7점]
(타입) list add: int list -> int list -> int list

(설명) list add [a; b; c; ...] [x; y; z; ...] returns [a + x; b + y; c + z; ...].

If one list is longer than the other, the remaining list of elements is appended to the result.

(실행 예) list add [1; 2] [3; 4; 5] returns [4; 6; 5].




##### Question 2. insert for inserting an element into a sorted list [7점]
(타입) insert: int -> int list -> int list

(설명) insert m l inserts m into a sorted list l. The resultant list is also sorted.

(가정) The list l is sorted in ascending order.

(실행 예) insert 3 [1; 2; 4; 5] returns [1; 2; 3; 4; 5].




##### Question 3. insort for insertion sort [7점]
(타입) insort: int list -> int list

(설명) insort l returns a sorted list of elements in l.

(실행 예) insort [3; 7; 5; 1; 2] returns [1; 2; 3; 5; 7].

##### Question 4. ltake for taking the list of the first n elements of l [7점]
(타입) ltake: ’a list -> int -> ’a list

(설명) ltake l n returns the list of the first n elements of l. If n is larger than the length of l, then return l.

(실행 예)

ltake [3; 7; 5; 1; 2] 3 returns [3; 7; 5].

ltake [3; 7; 5; 1; 2] 7 returns [3; 7; 5; 1; 2].

ltake ["h"; "y"; "e"; "o"; "n"; "s"; "e"; "u"; "n"; "g"] 5 returns ["h"; "y"; "e"; "o"; "n"].

(가정) n ≥ 0




##### Question 5 lall for examining a list [7점]
(타입) lall : (’a -> bool) -> ’a list -> bool

(설명) lall f l returns true if for every element x of l, f x evaluates to true; otherwise it returns false. In other words, lall f l tests if all elements in l satisfy the predicate f.

(실행 예) 

lall (fun x -> x > 0) [] evaluates to true.

lall (fun x -> x > 0) [1; 2; 3] evaluates to true.

lall (fun x -> x > 0) [1; -2; 3] evaluates to false.




##### Question 6. lmap for converting a list into another list [7점]
(타입) lmap : (’a -> ’b) -> ’a list -> ’b list

(설명) lmap f l applies f to each element of l from left to right, returning the list of results.

(실행 예) lmap (fun x -> x + 1) [1; 2; 3] returns [2; 3; 4].




##### Question 7. lfilter for filtering a list [7점]
(타입) lfilter : (’a -> bool) -> ’a list -> ’a list

(설명) lfilter p l returns every element of l that satisfies the predicate p.

(실행 예) lfilter (fun x -> x > 2) [0; 1; 2; 3; 4; 5] returns [3; 4; 5].




##### Question 8. ltabulate [7점]
(타입) ltabulate : int -> (int -> ’a) -> ’a list

(설명) ltabulate n f applies f to each element of a list [0; 1; ...; n-1].

(실행 예) ltabulate 4 (fun x -> x * x) returns [0; 1; 4; 9].

(가정) n ≥ 0




##### Question 9. lrev for reversing a list [7점]
(타입) lrev: ’a list -> ’a list

(설명) lrev l reverses l.

(실행 예) lrev [1; 2; 3; 4] returns [4; 3; 2; 1].




##### Question 10. lconcat for concatenating a list of lists [7점]
(타입) lconcat : ’a list list -> ’a list

(설명) lconcat l concatenates all elements of l.

(실행 예) lconcat [[1; 2; 3]; [6; 5; 4]; [9]] returns [1; 2; 3; 6; 5; 4; 9].




##### Question 11. lfoldl for left folding a list [7점]
(타입) lfoldl: (’a * ’b -> ’b) -> ’b -> ’a list -> ’b

(설명) lfoldl f e l takes e and the first item of l and applies f to them, then feeds the function with this result and the second argument and so on.
lfoldl f e [x1; x2; ...; xn] returns f(xn, ..., f(x2, f(x1, e))...) or e if the list is empty.

(실행 예) 

lfoldl (fun (x, y) -> x - y) 0 [1; 2; 3] returns 2.




##### Question 12. lzip for pairing corresponding members of two lists [7점]
(타입) lzip: ’a list -> b’ list -> (’a * ’b) list

(설명) lzip [x1; · · ·; xn] [y1; · · ·; yn] returns [(x1, y1); · · ·; (xn, yn)]. If two lists differ in length, ignore surplus elements.

(실행 예) lzip ["A"; "B"; "C"; "D"] [1; 2; 3; 4; 5; 6] returns [("A", 1); ("B", 2); ("C", 3); ("D", 4)].




##### Question 13. split for splitting a list into two lists [8점]
(타입) split: ’a list -> ’a list * ’a list

(설명) split l returns a pair of two lists. The first list consists of elements in odd positions and the second consists of elements in even positions in a given list respectively. For an empty list, split returns ([ ], [ ]).

(실행 예) split [1; 3; 5; 7; 9; 11] returns ([1; 5; 9], [3; 7; 11]).

(가정) 입력으로 주어지는 리스트의 길이는 짝수.




##### Question 14. cartprod for the Cartesian product of two sets [8점]
(타입) cartprod: ’a list -> ’b list -> (’a * ’b) list

(설명) cartprod S T returns the set of all pairs (x, y) with x ∈ S and y ∈ T.

The order of elements is important:

cartprod [x1; · · · ; xn] [y1; · · · ; yn] returns [(x1, y1); · · · ; (x1, yn); (x2, y1); · · · ; (xn, yn)].

(실행 예) cartprod [1; 2] [3; 4; 5] returns [(1, 3); (1, 4); (1, 5); (2, 3); (2, 4); (2, 5)].
