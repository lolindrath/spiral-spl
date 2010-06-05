%% transforms SPL code into Sigma-SPL using techniques
%% laid out in "Formal Loop Merging for Signal Transforms", Franchetti, Voronenko and Puschel

-module(sigma_spl).
%%-export([skeleton/1,ct/0,transform/1,loop_merge/1,rule]).
-compile(export_all).
-import(lists).

%% representation of the Coolie-Tukey DFT factorization 
ct() ->
	[{tensor,{dft,k},{i,m}},{t,n,m},{tensor,{i,k},{dft,m}},{l,n,k}].

simple() -> 
	[{tensor,{i,4},{dft,4}},{l,8,4}].
	%[{tensor,{i,m},{dft,n}},{l,mn,m}].

%% apply all the transformations to the formula
transform(Size, L) -> rule_35(rule_28(loop_merge(skeleton(Size, L)))).

%% Table 2 - Rules to expand the skeleton
skeleton(Size, L) -> skeleton(Size, L, []).

% Rule 20
skeleton(Size, [{tensor,A,{i,K}}|T], Result) -> skeleton(Size, T, [{sigma,Size,[{scatter,[{i,Size},{j,K}]},A,{gather,[{i,Size},{j,K}]}]}|Result]);
% Rule 21
skeleton(Size, [{tensor,{i,K},A}|T], Result) -> skeleton(Size, T, [{sigma,Size,[{scatter,[{j,K},{i,Size}]},A,{gather,[{j,K},{i,Size}]}]}|Result]);
% wrap up permutations
skeleton(Size, [{t,N,M}|T], Result) -> skeleton(Size, T, [{perm,{t,N,M}}|Result]);
skeleton(Size, [{i,K}|T], Result) -> skeleton(Size, T, [{perm,{i,K}}|Result]);
skeleton(Size, [{l,N,K}|T], Result) -> skeleton(Size, T, [{perm,{l,N,K}}|Result]);
% default - if we didn't transform it then pass it on
skeleton(Size, [H|T], Result) -> skeleton(Size, T, [H|Result]);
% SPL equation passed in is now empty, reverse the result we
% created to be in a more logical order
skeleton(_Size, [], Result) -> lists:reverse(Result).

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
%code_gen(Size, Formula) -> code_gen(Size, Formula, []).

%code_gen(Size, [H|T], Result) -> I;
%code_gen(Size, [H|T], Result) -> .






