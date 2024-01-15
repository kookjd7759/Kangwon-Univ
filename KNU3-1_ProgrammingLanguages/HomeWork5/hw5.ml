(* 
 * hw5.ml
 * Feel free to define any helper functions.
 * You don't need to define a recursive function if possible.
 *)

exception NotImplemented

(**********************************)
(*            Problem 1           *)
(**********************************)
module Problem1 = struct
  open Lambda
  
  let diff l1 l2 = List.filter (fun x -> not (List.mem x l2)) l1;;

  let rec checklist =
    fun e -> 
      match e with
        | Var x -> [x]
        | Lambda(x, e) -> diff (checklist e) [x]
        | App(e1, e2) -> checklist e1 @ checklist e2;;

  let rec my_length l =
    match l with
    | [] -> 0
    | h :: t -> 1 + my_length t;;
        
  let rec check : exp -> bool =
    fun e -> 
      if my_length (checklist e) = 0 then true else false;;
    
end

(**********************************)
(*            Problem 2           *)
(**********************************)
module Problem2 = struct
  open Kml
  exception Error 

  let rec eval_bop : (int -> int -> int) -> exp -> exp -> env -> value =
    fun op e1 e2 env ->
      let v1 = eval e1 env in
      let v2 = eval e2 env in
      (match v1,v2 with
      | Int n1, Int n2 -> Int (op n1 n2)
      | _ -> raise Error)

  and _Uminus = 
  fun e env ->
    let v = eval e env in
    (match v with
    | Int n -> Int (-1 * n)
    | _ -> raise Error)

  and eval_comp1 = 
    fun op e1 e2 env ->
      let v1 = eval e1 env in
      let v2 = eval e2 env in
      (match v1,v2 with
      | Int n1, Int n2 -> Bool (op n1 n2)
      | _ -> raise Error)

  and _not = 
    fun e env ->
      let v = eval e env in
      (match v with 
      | Bool n -> Bool (not n)
      | _ -> raise Error)

  and eval_comp2 = 
    fun op e1 e2 env ->
      let v1 = eval e1 env in
      let v2 = eval e2 env in
      (match v1,v2 with
      | Bool n1, Bool n2 -> Bool (op n1 n2)
      | _ -> raise Error)

  and _iszero = 
    fun e env ->
      let v = eval e env in
      (match v with
      | Int n -> if n = 0 then Bool true else Bool false
      | _ -> raise Error)

  and _if = 
    fun e1 e2 e3 env-> 
      let v = eval e1 env in
      (match v with
      | Bool true -> eval e2 env
      | Bool false -> eval e3 env
      | _ -> raise Error)

  and _let = 
    fun x e1 e2 env ->
      let v1 = eval e1 env in
      eval e2 (extend_env (x, v1) env)

  and _rec =
    fun v1 v2 e1 e2 env ->
      let clo = RecClosure (v1, v2, e1, env) in
      eval e2 (extend_env (v1, clo) env) 

  and _fun = 
    fun v e env -> 
      Closure (v, e, env)

  and _app = 
    fun e1 e2 env -> 
      let v1 = eval e1 env in
      let v2 = eval e2 env in
      match v1 with 
      | Closure (v, e, env') -> 
        eval e (extend_env (v, v2) env')
      | RecClosure (v1', v2', e, env') -> 
        eval e (extend_env (v1', v1) (extend_env (v2', v2) env'))
      | _ -> raise Error

  and eval : exp -> env -> value =
    fun exp env ->
      match exp with
      | NUM n -> Int n
      | VAR x -> apply_env env x
      | ADD (e1, e2) -> eval_bop (+) e1 e2 env
      | SUB (e1, e2) -> eval_bop (-) e1 e2 env
      | MUL (e1, e2) -> eval_bop ( * ) e1 e2 env
      | DIV (e1, e2) -> eval_bop (/) e1 e2 env
      | UMINUS e -> _Uminus e env
      | EQ (e1, e2) -> eval_comp1 (=) e1 e2 env
      | LE (e1, e2) -> eval_comp1 (<=) e1 e2 env
      | LT (e1, e2) -> eval_comp1 (<) e1 e2 env
      | GE (e1, e2) -> eval_comp1 (>=) e1 e2 env
      | GT (e1, e2) -> eval_comp1 (>) e1 e2 env
      | NOT e -> _not e env
      | OR (e1, e2) -> eval_comp2 (||) e1 e2 env
      | AND (e1, e2) -> eval_comp2 (&&) e1 e2 env
      | ISZERO e -> _iszero e env
      | IF (e1,e2,e3) -> _if e1 e2 e3 env
      | LET (x,e1,e2) -> _let x e1 e2 env
      | LETREC (v1, v2, e1, e2) -> _rec v1 v2 e1 e2 env
      | FUN (v, e) -> _fun v e env
      | APP (e1, e2) -> _app e1 e2 env
    
  let rec run : program -> value =
      fun pgm -> eval pgm empty_env
end

(***********************************)
(*            Problem 3            *)
(***********************************)
module Problem3 = struct
  open Nameless
  exception CannotTranslate
 
  type value =
    | VAR of var
  and var_env = string list

  let empty = []

  let rec var_env_lookup x e =
    match e with
    | [] -> raise CannotTranslate
    | v::t -> if x = v then 0 else 1 + var_env_lookup x t

  let var_env_extend v e = v::e

  let rec _Uminus = 
    fun e var_env -> 
      let v = eval e var_env in
      (match v with 
      | NL_NUM n -> NL_NUM (-1 * n)
      | _ -> raise CannotTranslate)

  and eval : exp -> var_env -> nl_exp =
    fun exp env ->
      match exp with
      | NUM n -> NL_NUM n
      | VAR x -> NL_VAR (var_env_lookup x env)
      | ADD (e1, e2) -> NL_ADD (eval e1 env, eval e2 env)
      | SUB (e1, e2) -> NL_SUB (eval e1 env, eval e2 env)
      | MUL (e1, e2) -> NL_MUL (eval e1 env, eval e2 env)
      | DIV (e1, e2) -> NL_DIV (eval e1 env, eval e2 env)
      | UMINUS e -> _Uminus e env
      | EQ (e1, e2) -> NL_EQ (eval e1 env, eval e2 env)
      | LE (e1, e2) -> NL_LE (eval e1 env, eval e2 env)
      | LT (e1, e2) -> NL_LT (eval e1 env, eval e2 env)
      | GE (e1, e2) -> NL_GE (eval e1 env, eval e2 env)
      | GT (e1, e2) -> NL_GT (eval e1 env, eval e2 env)
      | NOT e -> NL_NOT (eval e env)
      | OR (e1, e2) -> NL_OR (eval e1 env, eval e2 env)
      | AND (e1, e2) -> NL_AND (eval e1 env, eval e2 env)
      | ISZERO e -> NL_ISZERO (eval e env)
      | IF (e1, e2, e3) -> NL_IF (eval e1 env, eval e2 env, eval e3 env)
      | LET (e1, e2, e3) -> NL_LET (eval e2 env, eval e3 (var_env_extend e1 env))
      | FUN (e1, e2) -> NL_FUN (eval e2 (var_env_extend e1 env))
      | APP (e1, e2) -> NL_APP (eval e1 env, eval e2 env)

  let rec translate : program -> nl_program =
    fun pgm -> eval pgm empty
end

(**********************************)
(*            Problem 4           *)
(**********************************)
module Problem4 = struct
  open Nameless
  exception Error
      
  let empty = []

  let rec lookup x e =
    match e with
    | [] -> raise Error
    | v::t -> if x > 0 then lookup (x - 1) t else v

  let extend v e = v::e
  
  let rec eval_bop1 =
    fun op e1 e2 nl_env ->
      let v1 = eval e1 nl_env in
      let v2 = eval e2 nl_env in
      (match v1,v2 with
      | NL_Int n1, NL_Int n2 -> NL_Int (op n1 n2)
      | _ -> raise Error)
      
  and _Uminus = 
    fun e nl_env -> 
      let v = eval e nl_env in
      (match v with 
      | NL_Int n -> NL_Int (-1 * n)
      | _ -> raise Error)

  and eval_comp1 = 
    fun op e1 e2 nl_env ->
      let v1 = eval e1 nl_env in
      let v2 = eval e2 nl_env in
      (match v1,v2 with
      | NL_Int n1, NL_Int n2 -> NL_Bool (op n1 n2)
      | _ -> raise Error)

  and _not = 
    fun e nl_env ->
      let v = eval e nl_env in
      (match v with 
      | NL_Bool n -> NL_Bool (not n)
      | _ -> raise Error)

  and eval_comp2 = 
    fun op e1 e2 nl_env ->
      let v1 = eval e1 nl_env in
      let v2 = eval e2 nl_env in
      (match v1,v2 with
      | NL_Bool n1, NL_Bool n2 -> NL_Bool (op n1 n2)
      | _ -> raise Error)
  
  and _iszero = 
    fun e nl_env ->
      let v = eval e nl_env in
      (match v with
      | NL_Int n -> if n = 0 then NL_Bool true else NL_Bool false
      | _ -> raise Error)
  
  and _if = 
    fun e1 e2 e3 nl_env -> 
      let v = eval e1 nl_env in
      (match v with
      | NL_Bool true -> eval e2 nl_env
      | NL_Bool false -> eval e3 nl_env
      | _ -> raise Error)
  
  and _let = 
    fun e1 e2 nl_env ->
      let v1 = eval e1 nl_env in
      eval e2 (extend v1 nl_env) 

  and _fun = 
    fun e nl_env -> 
      let v' = eval e nl_env in
      NL_Closure (e, (extend v' nl_env))

  and _app = 
    fun e1 e2 nl_env -> 
      let v1 = eval e1 nl_env in
      match v1 with 
      | NL_Closure (e, nl_env') -> 
        let v = eval e nl_env' in
        eval e2 (extend v nl_env')
      | _ -> raise Error

  and eval : nl_exp -> nl_env -> nl_value =
    fun exp nl_env ->
      match exp with
      | NL_NUM n -> NL_Int n
      | NL_VAR x -> lookup x nl_env
      | NL_ADD (e1, e2) -> eval_bop1 (+) e1 e2 nl_env 
      | NL_SUB (e1, e2) -> eval_bop1 (-) e1 e2 nl_env 
      | NL_MUL (e1, e2) -> eval_bop1 ( * ) e1 e2 nl_env 
      | NL_DIV (e1, e2) -> eval_bop1 (/) e1 e2 nl_env 
      | NL_UMINUS e -> _Uminus e nl_env 
      | NL_EQ (e1, e2) -> eval_comp1 (=) e1 e2 nl_env 
      | NL_LE (e1, e2) -> eval_comp1 (<=) e1 e2 nl_env 
      | NL_LT (e1, e2) -> eval_comp1 (<) e1 e2 nl_env 
      | NL_GE (e1, e2) -> eval_comp1 (>=) e1 e2 nl_env 
      | NL_GT (e1, e2) -> eval_comp1 (>) e1 e2 nl_env 
      | NL_NOT e -> _not e nl_env 
      | NL_OR (e1, e2) -> eval_comp2 (||) e1 e2 nl_env 
      | NL_AND (e1, e2) -> eval_comp2 (&&) e1 e2 nl_env 
      | NL_ISZERO e -> _iszero e nl_env 
      | NL_IF (e1,e2,e3) -> _if e1 e2 e3 nl_env 
      | NL_LET (e1, e2) -> _let e1 e2 nl_env 
      | NL_FUN (e) -> _fun e nl_env 
      | NL_APP (e1, e2) -> _app e1 e2 nl_env 

  let rec nl_run : nl_program -> nl_value =
    fun pgm -> eval pgm empty
end