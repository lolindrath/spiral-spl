-module(dft_expand).
-compile(export_all).

-import(math).
-import(lin).
-import(lists).
-import(random).

gcd(A, 0) -> A;
gcd(A, B) -> gcd(B, A rem B).

is_prime(N) -> is_prime(2, N).
is_prime(X, N) when X*X > N -> true;
is_prime(X, N) when N rem X == 0 -> false;
is_prime(X, N) -> is_prime(X+1, N).

ct(N, K, M) ->
	[{tensor,[{dft,K}],{i,M}},{t,N,M},{tensor,{i,K},[{dft,M}]},{l,N,K}].


expand(Size) -> expand([{dft,Size}], []).

expand([{dft,2}|T], _Result) -> expand(T, {dft,2});
expand([{dft,Size}|T], Result) when Size rem 2 =:= 0 -> expand(lists:flatten([ct(Size, Size div 2, Size div (Size div 2))|T]), Result);
expand([{tensor,[{dft,N}],I}|T], Result) -> expand(T, [{tensor,expand([{dft,N}], []),I}|Result]);
expand([{tensor,I,[{dft,N}]}|T], Result) -> expand(T, [{tensor,I,expand([{dft,N}], [])}|Result]);
expand([H|T], Result) when is_list(H) -> expand(T, [expand(H, [])|Result]);
expand([H|T], Result) -> expand(T, [H|Result]);
expand([], Result) when is_list(Result) -> lists:reverse(Result);
expand([], Result) -> Result.





