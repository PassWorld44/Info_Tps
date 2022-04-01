(*
Emile BONDU
longeur liste chainee
01/04/2022
*)

let longeur l = 
match l with
| [] -> 0
| x :: p -> 1 + longeur p;;
