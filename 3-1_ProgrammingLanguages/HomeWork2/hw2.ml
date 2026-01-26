let sum n = 
  if n <= 0 then 0 
  else (n * (n + 1)) / 2;;
  
let circle r = 
  if r <= 0.0 then 0.0 
  else 3.14 *. r *. r;;
  
let concat s = "Hello " ^ s;;
  
let xor x y =
  if (x || y) then 
    if (x = true) && (y = true) then false else true
  else
    false;;
  
let triangle x y z = 
  if (x <= 0) || (y <= 0) || (z <= 0) then false
  else if (x + y) <= z then false
  else if (x + z) <= y then false
  else if (y + z) <= x then false
  else true;;
  
let int_if_then_else b x y = 
  if b then x + y else x - y;;
  
let sum_of_fun_val a b c d e = 
  let fc x = a * x * x + b * x + c in
  fc d + fc e;;
  
let comp3 a b c d = 
  let fc x = a * x * x + b * x + c in
  fc (fc (fc d));;
  
let string2 s = s ^ s;;
  
let string256 s = 
  let fc s = s ^ s in
  fc (fc (fc (fc (fc (fc (fc (fc s)))))));;