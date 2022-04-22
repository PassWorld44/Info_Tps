(*
Emile BONDU
enregistrements et types abstraits
08/04/2022*)

let t = (1,2,3);;
(*val t : int * int * int = (1, 2, 3)*)

let v = (1, "bonjour", 'e', 3.14, true)
(* val v : int * string * char * float * bool = (1, "bonjour", 'e', 3.14, true)*)
(* On peut donc utuliser ça pour stoquer plusieurs types ! *)

let (a, b, c, d, e) =v;;
(* déstructurer le n-uplet : recuperer ses valeurs
	dans des simples variables *)
c;;

let rec division n m =
	if n < m then (0,n)
	else let (q, r) = division(n-m) m 
		in (q+1, r);;
(* on peut faire de la div euclidienne *)

division 15 6;;

let f1 x y = x + y;;
let f2 (x, y) = x + y;;

f1 1 2;;
f2 (1,2);;

type complexe = {re : float ; im : float};;
(* equivalent des structs *)

let z = {re = 1.; im = -1.};;

z.re;;
z.im;;

z.re = 0.5;; (* -: bool = false *)
z.re := 0.5;; (* est un float : non mutable *)
z.re <- 0.5;; (* non mutable *)

type personne = {nom : string ; mutable age : int};;
(* il faut déclarer dans le type si on veut un type mutable *)
(* et il vaut mieux garder un max de trucs 
	mutables si on veut stoquer ce type d'info 
	de manière durable aussi cela dit *)

let p = { nom = "Martin" ; age = 19};;
p.age;;
p.age <- 20;;
p.age;;
(* c'est bien mutable *)

(* les references sont des enregistrements polymorphes *)

type figure =
|Valet |Dame | Roi |As;;
(* equivalent a une enum *)

let valeur_figure f =
	match f with
	|As -> 14
	|Roi -> 13
	|Dame -> 12
	|Valet -> 11;;
(* pas de corespondance deja prefaite
	avec un nombre comme en c *)

let carte = Dame;;
valeur_figure carte;;

type monType = 
| Vide
| Int of int
| Paire of int*int;;
(* type monType = Vide | Int of int | Paire of int * int  *)
(* permet de creer des constucteurs *)

let a = Int 3;;
let b = Paire(2,3);;
let c = Vide;;

(* EXEMPLES *)
type nombre =
| Entier of int
| Reel of float;;

let addition_nombre x y =
match (x, y) with
|Entier x, Entier y -> Entier (x + y)
|Entier x, Reel y -> Reel (float_of_int x +. y)
|Reel x, Entier y-> Reel ( x +. float_of_int y)
|Reel x, Reel y-> Reel (x +. y);;
(* cette syntaxe n'est pas intuitive mais ok *)

let a = Reel 2.;;
let b = Entier 2;;

let c = addition_nombre a b;;

(a, b);;

type liste = 
| NIL
| Cons of int * liste ;;

let l1 = Cons (1, NIL);;
let l2 = Cons (1, Cons(2, Cons(3, NIL)));;

l1;; (* val l1 : liste = Cons (1, NIL) *)
l2;; (* val l2 : liste = Cons (1, Cons (2, Cons (3, NIL)) *)

let rec longeur l =
match l with
| NIL -> 0
| Cons (x, q) -> 1 + longeur q ;;

longeur l1;;
longeur l2;;

type 'a liste = 
| NIL 
| Cons of 'a * 'a liste;;
(* polymorphique car type inféré plus tard *)

let l1 = Cons("Bonjour", NIL);;
(* val l1 : string liste = Cons ("Bonjour", NIL) *)
let l2 = Cons(1, Cons(2, Cons(3, NIL)));;
(* val l2 : int liste = Cons (1, Cons (2, Cons (3, NIL)) *)
let l3 = Cons(1, Cons("Bonjour", Cons(3.14, NIL)));;
(* non possible car une liste reste d'un type unique *)

