(*
Emile BONDU
exponentiation rapide
04/04/2022
*)

let rec expo_rapide x n =
match n with
| 0 -> 1
| 1 -> x
| _ -> (expo_rapide x (n/2)) * ( expo_rapide x (n - n/2) );;
