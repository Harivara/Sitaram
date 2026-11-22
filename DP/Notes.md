## In distinct subsequence problem we count the No.of distinct subsequneces
if(A[i]==B[i]){
    int pick=fun(i-1,j-1,A,B);
    int notpick=fun(i-1,j,A,B);
    return pick+notpick;
}
else{
    int notpick=fun(i-1,j,A,B);
    return notpick;
}

## We do return pick+notpick instead of max(pick,notpick)
## Because it is a counting problem
## max(pick,notpick) or min(pick,notpick) is used in Optimisation.

## BASE TEMPLATE
// int pick = 0;

// if (A[i-1] == B[j-1]) {
//     pick = solve(i-1, j-1, A, B);
// }

// int notPick = solve(i-1, j, A, B);

// return pick + notPick;