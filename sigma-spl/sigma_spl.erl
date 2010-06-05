%% transforms SPL code into Sigma-SPL using techniques
%% laid out in "Formal Loop Merging for Signal Transforms", Franchetti, Voronenko and Puschel

-module(sigma_spl).
%%-export([skeleton/1,ct/0,transform/1,loop_merge/1,rule]).
-compile(export_all).
-import(lists).
-import(io).

%% representation of the Coolie-Tukey DFT factorization 
ct() ->
	[{tensor,{dft,k},{i,m}},{t,n,m},{tensor,{i,k},{dft,m}},{l,n,k}].

simple() -> 
	[{tensor,{i,4},{dft,2}},{l,8,4}].
	%[{tensor,{i,m},{dft,n}},{l,mn,m}].

%% apply all the transformations to the formula
transform(L) -> rule_35(rule_28(loop_merge(skeleton(L)))).

%% Table 2 - Rules to expand the skeleton
skeleton(L) -> skeleton(L, []).

% Rule 20 - for dft
skeleton([{tensor,{dft,M},{i,K}}|T], Result) -> io:format("rule 20~n"), skeleton([{sigma,K,[{scatter,[{i,M},{j,K}]},{dft,M},{gather,[{i,M},{j,K}]}]}|T], Result);
% Rule 21
skeleton([{tensor,{i,K},{dft,M}}|T], Result) -> io:format("rule 21 ~n"), skeleton([{sigma,K,[{scatter,[{j,K},{i,M}]},{dft,M},{gather,[{j,K},{i,M}]}]}|T], Result);
% wrap up permutations
skeleton([{t,N,M}|T], Result) -> skeleton([{perm,{t,N,M}}|T], Result);
skeleton([{i,K}|T], Result) -> skeleton([{perm,{i,K}}|T], Result);
skeleton([{l,N,K}|T], Result) -> io:format("wrapping L~n"), skeleton([{perm,{l,N,K}}|T], Result);
% default - if we didn't transform it then pass it on
skeleton([H|T], Result) -> skeleton(T, [H|Result]);
% SPL equation passed in is now empty, reverse the result we
% created to be in a more logical order
skeleton([], Result) -> lists:reverse(Result).

%% Table 3 - Loop merging rules
loop_merge(L) -> loop_merge(L, []).

% Distributivity Law
loop_merge([{sigma,Size,L},{perm,P}|T], Result) -> loop_merge(T, [{sigma,Size,lists:append(L,[{perm,P}])}|Result]);
loop_merge([{perm,P},{sigma,Size,L}|T], Result) -> loop_merge(T, [{sigma,Size,lists:append([{perm,P}],L)}|Result]);
loop_merge([], Result) -> lists:reverse(Result).

rule_28(L) -> rule_28(L, []).

rule_28([{gather,G},{perm,P}|T], Result) -> rule_28(T, [{gather,lists:append([{perm,P}],G)}|Result]);
% recurse through the sigma lists
rule_28([{sigma,Size,L}|T], Result) -> rule_28(T, [{sigma,Size,rule_28(L)}|Result]);
rule_28([H|T], Result) -> rule_28(T, [H|Result]);
rule_28([], Result) -> lists:reverse(Result).

%% Table 4 - Index Simplification
rule_35(L) -> rule_35(L, []).

rule_35([{perm,{l,_MN,_M}},{j,A},B|T], Result) -> rule_35(T, lists:append([{j,A},B],Result));
rule_35([{gather,L}|T], Result) -> rule_35(T, [{gather,rule_35(L)}|Result]);
rule_35([{sigma,Size,L}|T], Result) -> rule_35(T, [{sigma,Size,rule_35(L)}|Result]);
rule_35([H|T], Result) -> rule_35(T, [H|Result]);
rule_35([], Result) -> lists:reverse(Result).

%% code gen
code_gen(Formula) -> code_gen(Formula, []).

code_gen([{sigma,K,L}|T], Result) -> io:format("for(int j=0;j<~s;j++){~n", [K]), code_gen([code_gen(L)|T], Result), io:format("}~n");
code_gen([{scatter,L}|T], Result) -> io:format("for(int i=0;i<~s;i++) t0[i] = x[i+2*j];~n", []), code_gen(T, Result);
code_gen([{dft,_N}|T], Result) -> io:format("dft..~n"), code_gen(T, Result);
code_gen([{gather,L}|T], Result) -> io:format("gather...~n"), code_gen(T, Result);
code_gen([[]], Result) -> Result;
code_gen([], Result) -> Result.





%%
