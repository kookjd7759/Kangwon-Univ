exception NotImplemented

let rec list_add l1 l2 = 
  match l1, l2 with 
  | [], [] -> []
  | h1::t1, h2::t2 -> h1 + h2 :: list_add t1 t2
  | h1::t1, [] -> h1 :: list_add t1 []
  | [], h2::t2 -> h2 :: list_add [] t2;;

let rec insert m l = 
  match l with 
  | [] -> [m]
  | h::t -> if h > m then m::h::t else h::insert m t;;

let rec insort l = 
  match l with
  | [] -> []
  | h::t -> insert h (insort t);;

let rec ltake l n = 
  match l with 
  | [] -> []
  | h::t -> if n > 0 then h::(ltake t (n - 1)) else [];;

let rec lall f l = 
  match l with 
  | [] -> true
  | h::t -> if f h then lall f t else false;;

let rec lmap f l = 
  match l with 
  | [] -> []
  | h::t -> f h :: lmap f t;;

let rec lfilter p l = 
  match l with 
  | [] -> []
  | h::t -> if p h then h::lfilter p t else lfilter p t;;

let rec ltabulate n f = 
  match n with 
  | 0 -> []
  | n' -> ltabulate (n' - 1) f @ [f (n' - 1)];;

let rec lrev l = 
  match l with
  | [] -> []
  | h::t -> lrev t @ [h];;

let rec lconcat l = 
  match l with 
  | [] -> []
  | h::t -> h @ lconcat t;;

let rec lfoldl f e l = 
  match l with 
  | [] -> e
  | h::t -> lfoldl f (f (h, e)) t;;

let rec lzip l1 l2 = 
  match l1, l2 with
  | [], [] -> []
  | h1::t1, h2::t2 -> (h1, h2)::lzip t1 t2
  | _, _ -> [];;

let rec split l = 
  match l with
  | [] -> [], []
  | h1::h2::t -> 
    let l1, l2 = split t in
      (h1::l1), (h2::l2)
  | _ -> [], [];;

let rec cartprod l1 l2 = 
  match l1, l2 with
  | [], [] -> []
  | h1::t1, h2::t2 -> (h1,h2)::(cartprod [h1] t2)@(cartprod t1 l2)
  | _, _ -> [];;