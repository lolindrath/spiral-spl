-module(dft_expand).
-compile(export_all).

-import(math).
-import(lin).
-import(lists).

ct(N, K, M) ->
	[{tensor,[{dft,K}],{i,M}},{t,N,M},{tensor,{i,K},[{dft,M}]},{l,N,K}].


expand(Size) -> expand([{dft,Size}], []).

expand([{dft,2}|T], _Result) -> io:format("base case~n"), expand(T, {dft,2});
expand([{dft,Size}|T], Result) when Size rem 2 =:= 0 -> io:format("ct expand~n"), expand(lists:flatten([ct(Size, Size div 2, Size div 2)|T]), Result);
expand([{tensor,[{dft,N}],I}|T], Result) -> io:format("tensor1 expand~n"), expand(T, [{tensor,expand([{dft,N}], []),I}|Result]);
expand([{tensor,I,[{dft,N}]}|T], Result) -> io:format("tensor2 expand~n"), expand(T, [{tensor,I,expand([{dft,N}], [])}|Result]);
expand([H|T], Result) when is_list(H) -> io:format("list~n"), expand(T, [expand(H, [])|Result]);
%expand([{ct, D1, D2}|T], Result) -> expand(T, [{ct,expand(D1,[]), expand(D2,[])}|Result]);
expand([H|T], Result) -> expand(T, [H|Result]);
expand([], Result) when is_list(Result) -> lists:reverse(Result);
expand([], Result) -> Result.





