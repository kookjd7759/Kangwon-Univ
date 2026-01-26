exception NotImplemented

(*가정이 n > 0 이고, 1 + 2 + 3 + ... * n 과 같이 계산이 되어야 하기 때문에 
  0 -> 0 이 아닌 1 -> n으로 작성.
  0 -> 0 으로 작성할 시 0 + 1 + 2 + 3 + ... + n으로 계산되어 출력은 올바르지만
  불필요한 연산을 시행하기 때문에 이와 같이 작성.*)
let rec sum n =
  match n with
  | 1 -> n
  | _ -> n + sum (n - 1);;

(*가정이 n > 0 이고, 1 * 2 * 3 * ... * n 과 같이 계산이 되어야 하기 때문에 
  0 -> 1 이 아닌 1 -> n으로 작성.
  0 -> 1 으로 작성할 시 1 * 1 * 2 * 3 * ... * n으로 계산되어 출력은 올바르지만
  불필요한 연산을 시행하기 때문에 이와 같이 작성.*)
let rec fac n =
  match n with
  | 1 -> n
  | _ -> n * fac (n - 1);;

let rec fib n =
  match n with
  | 0 | 1 -> 1
  | _ -> fib (n - 1) + fib (n - 2);;

let rec gcd n m =
  match n with
  | 0 -> m
  | _ -> gcd (m mod n) n;;

let rec max l =
  match l with
  | [] -> 0
  | h :: t -> if h > max t then h else max t

type tree = Leaf of int | Node of int * tree * tree

let rec sum_tree t =
  match t with
  | Leaf tl -> tl
  | Node (n, t1, t2) -> n + sum_tree t1 + sum_tree t2;;
 
let rec depth t =
  match t with
  | Leaf _ -> 0
  | Node (_, t1, t2) -> 
    if depth t1 > depth t2 then depth t1 + 1 else depth t2 + 1;;

let rec bin_search t x = 
  match t with
  | Leaf n -> if n = x then true else false
  | Node (n, t1, t2) -> 
    if n = x then true else
      if x < n then bin_search t1 x else bin_search t2 x;; 
 
type exp =
  INT of int
| ADD of exp * exp
| SUB of exp * exp
| MUL of exp * exp
| DIV of exp * exp
| MOD of exp * exp

let rec interp ex =
  match ex with
  | INT n -> n
  | ADD (n1, n2) -> interp n1 + interp n2
  | SUB (n1, n2) -> interp n1 - interp n2
  | MUL (n1, n2) -> interp n1 * interp n2
  | DIV (n1, n2) -> interp n1 / interp n2
  | MOD (n1, n2) -> interp n1 mod interp n2;;

type formula =
  True
| False
| Neg of formula
| Or of formula * formula
| And of formula * formula
| Imply of formula * formula

let rec eval tf =
  match tf with
  | True -> true
  | False -> false
  | Neg t -> not (eval t)
  | Or (t1, t2) -> eval t1 || eval t2
  | And (t1, t2) -> eval t1 && eval t2
  | Imply (t1, t2) -> 
    if eval t1 = true && eval t2 = false then false else true;;