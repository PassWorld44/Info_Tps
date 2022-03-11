(*
Emile BONDU
récursivité en ocaml
11/03/2022
*)

let fact n =
	
	let s = ref 1 in
	let a = ref 1 in
	while !a <= n do
		s := !s * !a;
		incr(a);
		done;
	!s;;

let rec fibo n =
match n with
| 0 -> 0
| 1 -> 1
| _ -> fibo (n-1) + fibo (n-2)
;;

let fibo_term n =
	let rec fib_aux n a b =
		if n = 0 then a
		else fib_aux (n-1) b (a+b)
	in fib_aux n 0 1;;

let rec mystere1 n =
match n with
| 0 -> print_newline()
| _ -> print_int n;
		print_char ' ';
		mystere1(n-1);
		print_char ' ';;

mystere1 5;;
(* compteur decrementiel ; 
rajoute autant d'espaces après la nouvelle ligne 
que le parametre *)

let minuscule c = 
char_of_int (32 + int_of_char c);;

let rec mystere2 s i =
if i = String.length s then
print_newline()
else begin
	print_char s.[i];
	s.[i] <- minuscule s.[i];
	mystere2 s (i+1);
	print_char s.[i];
end

mystere2 "BONJOUR" 0;;

(* rend en minuscule la chaine de caractere, 
et l'affiche a l'envers : les derniers appels
affichent en minuscule en premier *)

let liste_0 = 1 :: 2 :: 3 :: [];;
(* val liste_0 : int list = [1; 2; 3] *)

let liste_1 = [1;2;3];;
(* fait la meme chose *)

let liste_1 = [1,2,3];;
(* liste de taille 1 qui comporte un tuple de 3 *)

let liste_3 = 1 : 'a' :: (1,2,3) [];;
(* un seul type dedans *)

let liste_4 = [];;
(* Polymorphe !*)
2 :: liste_4;;
2. :: liste_4;;
liste_4;;
'a':: liste_4;;
liste_4;;

let liste = [5;4;3;2;1];;
let a = List.hd liste;;
(* accede a la tete de la liste *)
liste;;

let l = [];;
let b = List.hd 1;; (* 1 n'est pas une liste *)

let t = List.hd liste;;
(* val t : int = 5 *)

let liste =  [5;4;6;2;1;3];;
let a = List.nth liste 4;; (* val a : int = 1 *)
let b = List.nth liste 7;; (* echec *)

let liste_5 =
[[1;2];[1;2;3];[1;2;3;4;5;6]];;
(* val liste_5 : int list list = 
[[1; 2]; [1; 2; 3]; [1; 2; 3; 4; 5; 6]] *)

let liste_6 = [];;
let liste_6 = 5 :: liste_6;;
let liste_6 = 2 :: liste_6;;
(* val liste_6 : int list = [2;5] *)
(* Correspond a un append *)

let l1 = [1;2;3];;
let l2 = [4;5;6];;
let l3 = [7;8;9];;
let l = List.append l2 l1;;
(* val l : int list = [4; 5; 6; 1; 2; 3] *)
(* concatene deux listes *)

let ll = l @ l3 ;;
(*concatene egalement *)

let l_1 = List.map (function x -> x*x)[1;2;3;4];;
(* applique la fonc sur chaque element de la liste *)

let a = List.length [1;2;3;4];;

