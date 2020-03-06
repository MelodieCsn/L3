(***** EXERCICE 1 *****)

class min (xi : int) =
object (self)
  val mutable x = xi
  method get = x
  method set n = x <- n
  method min y = if self#get < y then self#get else y
end;;

class min_zero xi =
object
  inherit min xi
  method get = 0
end;;

(*TESTS*)

let o1 = new min 4;;
let o2 = new min_zero 4;;
o1#min 2;; (*int=2*)
o1#min 7;; (*int=4*)
o2#min 2;; (*int=0*)
o2#min (-2);; (*int=-2*)

(**** Exercice 2 ****)

(* Q1 *)

class account b =
object (self)
  val mutable balance = 0.0
  method get = balance
  method deposit a = balance <- balance +. a
  method withdraw a = balance <- balance -. a
  method print = print_float balance; print_newline ()
  initializer self#deposit b
end;;

class interest_account b =
object
  inherit account b
  method interest =
    balance <- balance +. 5. *. balance /. 100.
end;;

class secure_account b =
object
  inherit account b as super
  method withdraw a =
    if (balance -. a) >= 0. then super#withdraw a
    else failwith "Not enough money!"
end;;

class bank =
object
	val mutable acc_list =[]
	method add(a:account) = acc_list <- a::acc_list
	method balance = List.fold_left (fun a b -> a +. b#get) 0. acc_list
	method print = List.iter (fun a -> a#print) acc_list
	method fees = List.iter (fun a -> a#withdraw (a#get *. 5. /. 100.)) acc_list
end;;

(*TESTS*)
(*let a = new account 50.;;
let i = new interest_account 100.;;
let s = new secure_account 150.;;
let b = new bank;;
b#add a;;
b#add (i:>account);;
b#add s;;
b#balance;;
b#print;;
b#fees;;
b#print;;*)

let acc1 = new account 100. ;;
let acc2 = new interest_account 100. ;;
let acc3 = new secure_account 3. ;;
acc1#print ;;
let b = new bank ;;
b#add acc1;;
b#add acc2;;
b#print ;;

(* Q2 *)

class ['a] collection =
object
  val mutable acc_list = []
  method add (a : 'a) = acc_list <- a::acc_list
end;;

class bank2 =
object
  inherit [account] collection
  method balance = List.fold_left (fun a b -> a +. b#get) 0. acc_list
  method print = List.iter (fun a -> a#print) acc_list
  method fees = List.iter (fun a -> a#withdraw (a#get *. 5. /. 100.)) acc_list
end;;

let b = new bank2;;
b#add a;;
b#add (i:>account);;
b#add s;;
b#balance;;
b#print;;
b#fees;;
b#print;;